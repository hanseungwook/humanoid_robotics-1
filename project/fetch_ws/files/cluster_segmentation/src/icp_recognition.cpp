/*

Author: Kathleen Lee and Seungwook Han 

*/

#include <ros/ros.h>
#include <ros/common.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/point_cloud_conversion.h>
#include <pcl_conversions/pcl_conversions.h>
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <obj_recognition/SegmentedClustersArray.h>
#include <pcl/io/vtk_lib_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/conversions.h>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseStamped.h>
#include <std_msgs/Header.h>
#include <tf2/convert.h>
#include <tf2/convert.h>
#include <tf2_eigen/tf2_eigen.h>
#include <visualization_msgs/Marker.h>
#include <algorithm> 
#include <pcl/common/projection_matrix.h>
#include <pcl/common/centroid.h>
#include <pcl/common/common.h>

/*
- Check if cloud_in gives correct post 
- Find minimum score and update minCloud outside of for loop --> publish marker
*/

class icp_recognition {

public:

    explicit icp_recognition(ros::NodeHandle nh) : m_nh(nh) {
        // define the subscriber and publisher
        m_clusterSub = m_nh.subscribe("/obj_recognition/pcl_clusters", 1, &icp_recognition::cluster_cb, this);
	// Visualize marker in rviz 
	posePub = m_nh.advertise<geometry_msgs::PoseStamped>("pose_stamp",1);
	vis_pub = m_nh.advertise<visualization_msgs::Marker>("pose_marker",1);
}

private:

    ros::NodeHandle m_nh;
    ros::Subscriber m_clusterSub;
    ros::Publisher posePub;
    ros::Publisher vis_pub;

    void cluster_cb(const obj_recognition::SegmentedClustersArray& cluster_msg);

}; // end class definition

// define callback function
void icp_recognition::cluster_cb (const obj_recognition::SegmentedClustersArray& cluster_msg)
{
    // Frame id
    const std::string myFrame = "/base_link";

    pcl::PointCloud<pcl::PointXYZ>::Ptr minCloud (new pcl::PointCloud<pcl::PointXYZ>);	
    float minCount = 100000;	    

    for(const sensor_msgs::PointCloud2 &cluster : cluster_msg.clusters) {
        // Container for original & filtered data
        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_in (new pcl::PointCloud<pcl::PointXYZ>);
        pcl::fromROSMsg(cluster, *cloud_in);

        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out (new pcl::PointCloud<pcl::PointXYZ>);
        // Print attributes of input cloud
        std::cout << "Saved " << cloud_in->points.size () << " data points to input:"
                  << std::endl;

	// Convert candidate meshes to cloud
        const std::string meshFileName = "/home/kathleen/humanoid_robotics/project/fetch_ws/src/ycb_meshes/mustard/meshes/mustard.ply";

	// Load .ply file into pointcloud
	pcl::PolygonMesh objectMesh;
	pcl::io::loadPolygonFilePLY(meshFileName, objectMesh);
	std::cout << "loaded PLY FILE";        
	pcl::fromPCLPointCloud2(objectMesh.cloud, *cloud_out);
	cloud_out->header.frame_id = myFrame;        

	// Run ICP algorithm and print score
	pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
        icp.setInputSource(cloud_in);
        icp.setInputTarget(cloud_out);
        pcl::PointCloud<pcl::PointXYZ> Final;
        icp.align(Final);
        std::cout << " has converged:" << icp.hasConverged() << " score: " <<
                  icp.getFitnessScore() << std::endl;
        
	// Get final transformed matrix4f
	//std::cout << icp.getFinalTransformation() << std::endl;
	//Eigen::Matrix4f trans = icp.getFinalTransformation();
	
	// Find minimum score and corresponding point cloud 
	if((icp.getFitnessScore() < minCount) == 1){
		minCount = icp.getFitnessScore();
		minCloud = cloud_in;
	}

	
      }	

	// Find centroid of point cloud and fill values in Vector4f 
	Eigen::Vector4f centroid; 
	pcl::compute3DCentroid(*minCloud, centroid);
	std::cout << "Centroid coordinates: " << centroid << std::endl; 
	
	// Publish marker in frame "head_camera_rgb_optical_frame" 
	visualization_msgs::Marker marker; 
	marker.header.frame_id = myFrame;
	marker.header.stamp = ros::Time();
	marker.ns = "my_namespace";
	marker.id = 0;
	marker.type = visualization_msgs::Marker::SPHERE;
	marker.action = visualization_msgs::Marker::ADD;
	marker.pose.position.x = centroid(0);
	marker.pose.position.y = centroid(1);
	marker.pose.position.z = centroid(2);
	marker.pose.orientation.x = 0.0;
	marker.pose.orientation.y = 0.0;
	marker.pose.orientation.z = 0.0;
	marker.pose.orientation.w = 1.0; 
	marker.scale.x = 0.1;
	marker.scale.y = 0.1;
	marker.scale.z = 0.1;
	marker.color.a = 1.0;
	marker.color.r = 0.0;
	marker.color.g = 1.0;
	marker.color.b = 0.0;

	geometry_msgs::PoseStamped poseSt; 
	poseSt.header.frame_id = myFrame;
	poseSt.header.stamp = ros::Time::now();
	poseSt.pose.position.x = centroid(0);
	poseSt.pose.position.y = centroid(1);
	poseSt.pose.position.z = centroid(2);
	poseSt.pose.orientation.y = 0.0;
	poseSt.pose.orientation.z = 0.0;
	poseSt.pose.orientation.w = 1.0;

	// Publish marker 
	vis_pub.publish(marker);

	std::cout << poseSt << std::endl;
	posePub.publish(poseSt);
}



int main (int argc, char** argv)
{
	
    // Initialize ROS	
    ros::init (argc, argv, "ICPRecognition");
    ros::NodeHandle nh;

    // Object for icp_recognition 
    icp_recognition recognizer(nh);

    while(ros::ok())
        ros::spin ();

}
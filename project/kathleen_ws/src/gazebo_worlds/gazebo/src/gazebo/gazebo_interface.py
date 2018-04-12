#! /usr/bin/env python
# Wrappers around the services provided by rosified gazebo

import roslib; roslib.load_manifest('gazebo')

import sys
import rospy
import os

from gazebo_msgs.msg import *
from gazebo_msgs.srv import *
from geometry_msgs.msg import Point, Pose, Quaternion, Twist, Wrench


def spawn_gazebo_model_client(model_name, model_xml, robot_namespace, initial_pose, reference_frame, gazebo_namespace):
    rospy.loginfo("waiting for service %s/spawn_gazebo_model"%gazebo_namespace)
    rospy.wait_for_service(gazebo_namespace+'/spawn_gazebo_model')
    try:
      spawn_gazebo_model = rospy.ServiceProxy(gazebo_namespace+'/spawn_gazebo_model', SpawnModel)
      resp = spawn_gazebo_model(model_name, model_xml, robot_namespace, initial_pose, reference_frame)
      print "spawn status: ", resp.status_message
      return resp.success
    except rospy.ServiceException, e:
      print "Service call failed: %s"%e

def spawn_urdf_model_client(model_name, model_xml, robot_namespace, initial_pose, reference_frame, gazebo_namespace):
    rospy.loginfo("waiting for service %s/spawn_urdf_model"%gazebo_namespace)
    rospy.wait_for_service(gazebo_namespace+'/spawn_urdf_model')
    try:
      spawn_urdf_model = rospy.ServiceProxy(gazebo_namespace+'/spawn_urdf_model', SpawnModel)
      resp = spawn_urdf_model(model_name, model_xml, robot_namespace, initial_pose, reference_frame)
      print "spawn status: ", resp.status_message
      return resp.success
    except rospy.ServiceException, e:
      print "Service call failed: %s"%e

def set_model_configuration_client(model_name, model_param_name, joint_names, joint_positions, gazebo_namespace):
    rospy.loginfo("waiting for service %s/set_model_configuration"%gazebo_namespace)
    rospy.wait_for_service(gazebo_namespace+'/set_model_configuration')
    try:
      set_model_configuration = rospy.ServiceProxy(gazebo_namespace+'/set_model_configuration', SetModelConfiguration)
      resp = set_model_configuration(model_name, model_param_name, joint_names, joint_positions)
      print "set model configuration status: ", resp.status_message
      return resp.success
    except rospy.ServiceException, e:
      print "Service call failed: %s"%e


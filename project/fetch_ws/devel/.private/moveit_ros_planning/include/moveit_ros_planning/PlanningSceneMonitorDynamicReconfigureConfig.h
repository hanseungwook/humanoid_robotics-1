//#line 2 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
// 
// File autogenerated for the moveit_ros_planning package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

#ifndef __moveit_ros_planning__PLANNINGSCENEMONITORDYNAMICRECONFIGURECONFIG_H__
#define __moveit_ros_planning__PLANNINGSCENEMONITORDYNAMICRECONFIGURECONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace moveit_ros_planning
{
  class PlanningSceneMonitorDynamicReconfigureConfigStatics;
  
  class PlanningSceneMonitorDynamicReconfigureConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l, 
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      
      virtual void clamp(PlanningSceneMonitorDynamicReconfigureConfig &config, const PlanningSceneMonitorDynamicReconfigureConfig &max, const PlanningSceneMonitorDynamicReconfigureConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const PlanningSceneMonitorDynamicReconfigureConfig &config1, const PlanningSceneMonitorDynamicReconfigureConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, PlanningSceneMonitorDynamicReconfigureConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const PlanningSceneMonitorDynamicReconfigureConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, PlanningSceneMonitorDynamicReconfigureConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const PlanningSceneMonitorDynamicReconfigureConfig &config) const = 0;
      virtual void getValue(const PlanningSceneMonitorDynamicReconfigureConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level, 
          std::string a_description, std::string a_edit_method, T PlanningSceneMonitorDynamicReconfigureConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T (PlanningSceneMonitorDynamicReconfigureConfig::* field);

      virtual void clamp(PlanningSceneMonitorDynamicReconfigureConfig &config, const PlanningSceneMonitorDynamicReconfigureConfig &max, const PlanningSceneMonitorDynamicReconfigureConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const PlanningSceneMonitorDynamicReconfigureConfig &config1, const PlanningSceneMonitorDynamicReconfigureConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, PlanningSceneMonitorDynamicReconfigureConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const PlanningSceneMonitorDynamicReconfigureConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, PlanningSceneMonitorDynamicReconfigureConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const PlanningSceneMonitorDynamicReconfigureConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const PlanningSceneMonitorDynamicReconfigureConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, PlanningSceneMonitorDynamicReconfigureConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    template<class T, class PT>
    class GroupDescription : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, PlanningSceneMonitorDynamicReconfigureConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<PlanningSceneMonitorDynamicReconfigureConfig::AbstractGroupDescriptionConstPtr> groups;
    };
    
class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(PlanningSceneMonitorDynamicReconfigureConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("publish_planning_scene"==(*_i)->name){publish_planning_scene = boost::any_cast<bool>(val);}
        if("publish_planning_scene_hz"==(*_i)->name){publish_planning_scene_hz = boost::any_cast<double>(val);}
        if("publish_geometry_updates"==(*_i)->name){publish_geometry_updates = boost::any_cast<bool>(val);}
        if("publish_state_updates"==(*_i)->name){publish_state_updates = boost::any_cast<bool>(val);}
        if("publish_transforms_updates"==(*_i)->name){publish_transforms_updates = boost::any_cast<bool>(val);}
      }
    }

    bool publish_planning_scene;
double publish_planning_scene_hz;
bool publish_geometry_updates;
bool publish_state_updates;
bool publish_transforms_updates;

    bool state;
    std::string name;

    
}groups;



//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool publish_planning_scene;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double publish_planning_scene_hz;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool publish_geometry_updates;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool publish_state_updates;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      bool publish_transforms_updates;
//#line 218 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("PlanningSceneMonitorDynamicReconfigureConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const PlanningSceneMonitorDynamicReconfigureConfig &__max__ = __getMax__();
      const PlanningSceneMonitorDynamicReconfigureConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const PlanningSceneMonitorDynamicReconfigureConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const PlanningSceneMonitorDynamicReconfigureConfig &__getDefault__();
    static const PlanningSceneMonitorDynamicReconfigureConfig &__getMax__();
    static const PlanningSceneMonitorDynamicReconfigureConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();
    
  private:
    static const PlanningSceneMonitorDynamicReconfigureConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void PlanningSceneMonitorDynamicReconfigureConfig::ParamDescription<std::string>::clamp(PlanningSceneMonitorDynamicReconfigureConfig &config, const PlanningSceneMonitorDynamicReconfigureConfig &max, const PlanningSceneMonitorDynamicReconfigureConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class PlanningSceneMonitorDynamicReconfigureConfigStatics
  {
    friend class PlanningSceneMonitorDynamicReconfigureConfig;
    
    PlanningSceneMonitorDynamicReconfigureConfigStatics()
    {
PlanningSceneMonitorDynamicReconfigureConfig::GroupDescription<PlanningSceneMonitorDynamicReconfigureConfig::DEFAULT, PlanningSceneMonitorDynamicReconfigureConfig> Default("Default", "", 0, 0, true, &PlanningSceneMonitorDynamicReconfigureConfig::groups);
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.publish_planning_scene = 0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.publish_planning_scene = 1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.publish_planning_scene = 0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PlanningSceneMonitorDynamicReconfigureConfig::AbstractParamDescriptionConstPtr(new PlanningSceneMonitorDynamicReconfigureConfig::ParamDescription<bool>("publish_planning_scene", "bool", 1, "Set to True to publish Planning Scenes", "", &PlanningSceneMonitorDynamicReconfigureConfig::publish_planning_scene)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PlanningSceneMonitorDynamicReconfigureConfig::AbstractParamDescriptionConstPtr(new PlanningSceneMonitorDynamicReconfigureConfig::ParamDescription<bool>("publish_planning_scene", "bool", 1, "Set to True to publish Planning Scenes", "", &PlanningSceneMonitorDynamicReconfigureConfig::publish_planning_scene)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.publish_planning_scene_hz = 0.1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.publish_planning_scene_hz = 100.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.publish_planning_scene_hz = 4.0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PlanningSceneMonitorDynamicReconfigureConfig::AbstractParamDescriptionConstPtr(new PlanningSceneMonitorDynamicReconfigureConfig::ParamDescription<double>("publish_planning_scene_hz", "double", 2, "Set the maximum frequency at which planning scene updates are published", "", &PlanningSceneMonitorDynamicReconfigureConfig::publish_planning_scene_hz)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PlanningSceneMonitorDynamicReconfigureConfig::AbstractParamDescriptionConstPtr(new PlanningSceneMonitorDynamicReconfigureConfig::ParamDescription<double>("publish_planning_scene_hz", "double", 2, "Set the maximum frequency at which planning scene updates are published", "", &PlanningSceneMonitorDynamicReconfigureConfig::publish_planning_scene_hz)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.publish_geometry_updates = 0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.publish_geometry_updates = 1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.publish_geometry_updates = 1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PlanningSceneMonitorDynamicReconfigureConfig::AbstractParamDescriptionConstPtr(new PlanningSceneMonitorDynamicReconfigureConfig::ParamDescription<bool>("publish_geometry_updates", "bool", 3, "Set to True to publish geometry updates of the planning scene", "", &PlanningSceneMonitorDynamicReconfigureConfig::publish_geometry_updates)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PlanningSceneMonitorDynamicReconfigureConfig::AbstractParamDescriptionConstPtr(new PlanningSceneMonitorDynamicReconfigureConfig::ParamDescription<bool>("publish_geometry_updates", "bool", 3, "Set to True to publish geometry updates of the planning scene", "", &PlanningSceneMonitorDynamicReconfigureConfig::publish_geometry_updates)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.publish_state_updates = 0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.publish_state_updates = 1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.publish_state_updates = 0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PlanningSceneMonitorDynamicReconfigureConfig::AbstractParamDescriptionConstPtr(new PlanningSceneMonitorDynamicReconfigureConfig::ParamDescription<bool>("publish_state_updates", "bool", 4, "Set to True to publish geometry updates of the planning scene", "", &PlanningSceneMonitorDynamicReconfigureConfig::publish_state_updates)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PlanningSceneMonitorDynamicReconfigureConfig::AbstractParamDescriptionConstPtr(new PlanningSceneMonitorDynamicReconfigureConfig::ParamDescription<bool>("publish_state_updates", "bool", 4, "Set to True to publish geometry updates of the planning scene", "", &PlanningSceneMonitorDynamicReconfigureConfig::publish_state_updates)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.publish_transforms_updates = 0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.publish_transforms_updates = 1;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.publish_transforms_updates = 0;
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(PlanningSceneMonitorDynamicReconfigureConfig::AbstractParamDescriptionConstPtr(new PlanningSceneMonitorDynamicReconfigureConfig::ParamDescription<bool>("publish_transforms_updates", "bool", 5, "Set to True to publish geometry updates of the planning scene", "", &PlanningSceneMonitorDynamicReconfigureConfig::publish_transforms_updates)));
//#line 293 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(PlanningSceneMonitorDynamicReconfigureConfig::AbstractParamDescriptionConstPtr(new PlanningSceneMonitorDynamicReconfigureConfig::ParamDescription<bool>("publish_transforms_updates", "bool", 5, "Set to True to publish geometry updates of the planning scene", "", &PlanningSceneMonitorDynamicReconfigureConfig::publish_transforms_updates)));
//#line 246 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 246 "/opt/ros/kinetic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(PlanningSceneMonitorDynamicReconfigureConfig::AbstractGroupDescriptionConstPtr(new PlanningSceneMonitorDynamicReconfigureConfig::GroupDescription<PlanningSceneMonitorDynamicReconfigureConfig::DEFAULT, PlanningSceneMonitorDynamicReconfigureConfig>(Default)));
//#line 356 "/opt/ros/kinetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<PlanningSceneMonitorDynamicReconfigureConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__); 
    }
    std::vector<PlanningSceneMonitorDynamicReconfigureConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<PlanningSceneMonitorDynamicReconfigureConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    PlanningSceneMonitorDynamicReconfigureConfig __max__;
    PlanningSceneMonitorDynamicReconfigureConfig __min__;
    PlanningSceneMonitorDynamicReconfigureConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const PlanningSceneMonitorDynamicReconfigureConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static PlanningSceneMonitorDynamicReconfigureConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &PlanningSceneMonitorDynamicReconfigureConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const PlanningSceneMonitorDynamicReconfigureConfig &PlanningSceneMonitorDynamicReconfigureConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const PlanningSceneMonitorDynamicReconfigureConfig &PlanningSceneMonitorDynamicReconfigureConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const PlanningSceneMonitorDynamicReconfigureConfig &PlanningSceneMonitorDynamicReconfigureConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<PlanningSceneMonitorDynamicReconfigureConfig::AbstractParamDescriptionConstPtr> &PlanningSceneMonitorDynamicReconfigureConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<PlanningSceneMonitorDynamicReconfigureConfig::AbstractGroupDescriptionConstPtr> &PlanningSceneMonitorDynamicReconfigureConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const PlanningSceneMonitorDynamicReconfigureConfigStatics *PlanningSceneMonitorDynamicReconfigureConfig::__get_statics__()
  {
    const static PlanningSceneMonitorDynamicReconfigureConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = PlanningSceneMonitorDynamicReconfigureConfigStatics::get_instance();
    
    return statics;
  }


}

#endif // __PLANNINGSCENEMONITORDYNAMICRECONFIGURERECONFIGURATOR_H__

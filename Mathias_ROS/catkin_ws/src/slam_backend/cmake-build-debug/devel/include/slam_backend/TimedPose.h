// Generated by gencpp from file slam_backend/TimedPose.msg
// DO NOT EDIT!


#ifndef SLAM_BACKEND_MESSAGE_TIMEDPOSE_H
#define SLAM_BACKEND_MESSAGE_TIMEDPOSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace slam_backend
{
template <class ContainerAllocator>
struct TimedPose_
{
  typedef TimedPose_<ContainerAllocator> Type;

  TimedPose_()
    : time(0.0)
    , dist(0.0)
    , steer(0.0)  {
    }
  TimedPose_(const ContainerAllocator& _alloc)
    : time(0.0)
    , dist(0.0)
    , steer(0.0)  {
  (void)_alloc;
    }



   typedef double _time_type;
  _time_type time;

   typedef double _dist_type;
  _dist_type dist;

   typedef double _steer_type;
  _steer_type steer;





  typedef boost::shared_ptr< ::slam_backend::TimedPose_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::slam_backend::TimedPose_<ContainerAllocator> const> ConstPtr;

}; // struct TimedPose_

typedef ::slam_backend::TimedPose_<std::allocator<void> > TimedPose;

typedef boost::shared_ptr< ::slam_backend::TimedPose > TimedPosePtr;
typedef boost::shared_ptr< ::slam_backend::TimedPose const> TimedPoseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::slam_backend::TimedPose_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::slam_backend::TimedPose_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace slam_backend

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'slam_backend': ['/home/gilberg96/catkin_ws/src/slam_backend/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::slam_backend::TimedPose_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::slam_backend::TimedPose_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::slam_backend::TimedPose_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::slam_backend::TimedPose_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::slam_backend::TimedPose_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::slam_backend::TimedPose_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::slam_backend::TimedPose_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ff0135fc4887cc9d2384b602ae553afb";
  }

  static const char* value(const ::slam_backend::TimedPose_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xff0135fc4887cc9dULL;
  static const uint64_t static_value2 = 0x2384b602ae553afbULL;
};

template<class ContainerAllocator>
struct DataType< ::slam_backend::TimedPose_<ContainerAllocator> >
{
  static const char* value()
  {
    return "slam_backend/TimedPose";
  }

  static const char* value(const ::slam_backend::TimedPose_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::slam_backend::TimedPose_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 time\n"
"float64 dist\n"
"float64 steer\n"
;
  }

  static const char* value(const ::slam_backend::TimedPose_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::slam_backend::TimedPose_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.time);
      stream.next(m.dist);
      stream.next(m.steer);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TimedPose_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::slam_backend::TimedPose_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::slam_backend::TimedPose_<ContainerAllocator>& v)
  {
    s << indent << "time: ";
    Printer<double>::stream(s, indent + "  ", v.time);
    s << indent << "dist: ";
    Printer<double>::stream(s, indent + "  ", v.dist);
    s << indent << "steer: ";
    Printer<double>::stream(s, indent + "  ", v.steer);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SLAM_BACKEND_MESSAGE_TIMEDPOSE_H

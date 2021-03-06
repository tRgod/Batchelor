// Generated by gencpp from file slam_backend/TimedPose2.msg
// DO NOT EDIT!


#ifndef SLAM_BACKEND_MESSAGE_TIMEDPOSE2_H
#define SLAM_BACKEND_MESSAGE_TIMEDPOSE2_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace slam_backend
{
template <class ContainerAllocator>
struct TimedPose2_
{
  typedef TimedPose2_<ContainerAllocator> Type;

  TimedPose2_()
    : header()
    , deltaDist(0.0)
    , deltaSteer(0.0)  {
    }
  TimedPose2_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , deltaDist(0.0)
    , deltaSteer(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _deltaDist_type;
  _deltaDist_type deltaDist;

   typedef double _deltaSteer_type;
  _deltaSteer_type deltaSteer;





  typedef boost::shared_ptr< ::slam_backend::TimedPose2_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::slam_backend::TimedPose2_<ContainerAllocator> const> ConstPtr;

}; // struct TimedPose2_

typedef ::slam_backend::TimedPose2_<std::allocator<void> > TimedPose2;

typedef boost::shared_ptr< ::slam_backend::TimedPose2 > TimedPose2Ptr;
typedef boost::shared_ptr< ::slam_backend::TimedPose2 const> TimedPose2ConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::slam_backend::TimedPose2_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::slam_backend::TimedPose2_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace slam_backend

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'slam_backend': ['/home/gilberg96/catkin_ws/src/slam_backend/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::slam_backend::TimedPose2_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::slam_backend::TimedPose2_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::slam_backend::TimedPose2_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::slam_backend::TimedPose2_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::slam_backend::TimedPose2_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::slam_backend::TimedPose2_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::slam_backend::TimedPose2_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0baf874fce4dad94f21c488bdbb2552f";
  }

  static const char* value(const ::slam_backend::TimedPose2_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0baf874fce4dad94ULL;
  static const uint64_t static_value2 = 0xf21c488bdbb2552fULL;
};

template<class ContainerAllocator>
struct DataType< ::slam_backend::TimedPose2_<ContainerAllocator> >
{
  static const char* value()
  {
    return "slam_backend/TimedPose2";
  }

  static const char* value(const ::slam_backend::TimedPose2_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::slam_backend::TimedPose2_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"float64 deltaDist\n"
"float64 deltaSteer\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::slam_backend::TimedPose2_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::slam_backend::TimedPose2_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.deltaDist);
      stream.next(m.deltaSteer);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TimedPose2_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::slam_backend::TimedPose2_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::slam_backend::TimedPose2_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "deltaDist: ";
    Printer<double>::stream(s, indent + "  ", v.deltaDist);
    s << indent << "deltaSteer: ";
    Printer<double>::stream(s, indent + "  ", v.deltaSteer);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SLAM_BACKEND_MESSAGE_TIMEDPOSE2_H

; Auto-generated. Do not edit!


(cl:in-package slam_backend-msg)


;//! \htmlinclude TimedPose2.msg.html

(cl:defclass <TimedPose2> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (deltaDist
    :reader deltaDist
    :initarg :deltaDist
    :type cl:float
    :initform 0.0)
   (deltaSteer
    :reader deltaSteer
    :initarg :deltaSteer
    :type cl:float
    :initform 0.0))
)

(cl:defclass TimedPose2 (<TimedPose2>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <TimedPose2>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'TimedPose2)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name slam_backend-msg:<TimedPose2> is deprecated: use slam_backend-msg:TimedPose2 instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <TimedPose2>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader slam_backend-msg:header-val is deprecated.  Use slam_backend-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'deltaDist-val :lambda-list '(m))
(cl:defmethod deltaDist-val ((m <TimedPose2>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader slam_backend-msg:deltaDist-val is deprecated.  Use slam_backend-msg:deltaDist instead.")
  (deltaDist m))

(cl:ensure-generic-function 'deltaSteer-val :lambda-list '(m))
(cl:defmethod deltaSteer-val ((m <TimedPose2>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader slam_backend-msg:deltaSteer-val is deprecated.  Use slam_backend-msg:deltaSteer instead.")
  (deltaSteer m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <TimedPose2>) ostream)
  "Serializes a message object of type '<TimedPose2>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'deltaDist))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'deltaSteer))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <TimedPose2>) istream)
  "Deserializes a message object of type '<TimedPose2>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'deltaDist) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'deltaSteer) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<TimedPose2>)))
  "Returns string type for a message object of type '<TimedPose2>"
  "slam_backend/TimedPose2")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TimedPose2)))
  "Returns string type for a message object of type 'TimedPose2"
  "slam_backend/TimedPose2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<TimedPose2>)))
  "Returns md5sum for a message object of type '<TimedPose2>"
  "0baf874fce4dad94f21c488bdbb2552f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'TimedPose2)))
  "Returns md5sum for a message object of type 'TimedPose2"
  "0baf874fce4dad94f21c488bdbb2552f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<TimedPose2>)))
  "Returns full string definition for message of type '<TimedPose2>"
  (cl:format cl:nil "Header header~%float64 deltaDist~%float64 deltaSteer~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'TimedPose2)))
  "Returns full string definition for message of type 'TimedPose2"
  (cl:format cl:nil "Header header~%float64 deltaDist~%float64 deltaSteer~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <TimedPose2>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <TimedPose2>))
  "Converts a ROS message object to a list"
  (cl:list 'TimedPose2
    (cl:cons ':header (header msg))
    (cl:cons ':deltaDist (deltaDist msg))
    (cl:cons ':deltaSteer (deltaSteer msg))
))

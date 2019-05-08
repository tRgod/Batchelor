;; Auto-generated. Do not edit!


(when (boundp 'slam_backend::TimedPose2)
  (if (not (find-package "SLAM_BACKEND"))
    (make-package "SLAM_BACKEND"))
  (shadow 'TimedPose2 (find-package "SLAM_BACKEND")))
(unless (find-package "SLAM_BACKEND::TIMEDPOSE2")
  (make-package "SLAM_BACKEND::TIMEDPOSE2"))

(in-package "ROS")
;;//! \htmlinclude TimedPose2.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass slam_backend::TimedPose2
  :super ros::object
  :slots (_header _deltaDist _deltaSteer ))

(defmethod slam_backend::TimedPose2
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:deltaDist __deltaDist) 0.0)
    ((:deltaSteer __deltaSteer) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _deltaDist (float __deltaDist))
   (setq _deltaSteer (float __deltaSteer))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:deltaDist
   (&optional __deltaDist)
   (if __deltaDist (setq _deltaDist __deltaDist)) _deltaDist)
  (:deltaSteer
   (&optional __deltaSteer)
   (if __deltaSteer (setq _deltaSteer __deltaSteer)) _deltaSteer)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64 _deltaDist
    8
    ;; float64 _deltaSteer
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64 _deltaDist
       (sys::poke _deltaDist (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _deltaSteer
       (sys::poke _deltaSteer (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64 _deltaDist
     (setq _deltaDist (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _deltaSteer
     (setq _deltaSteer (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get slam_backend::TimedPose2 :md5sum-) "0baf874fce4dad94f21c488bdbb2552f")
(setf (get slam_backend::TimedPose2 :datatype-) "slam_backend/TimedPose2")
(setf (get slam_backend::TimedPose2 :definition-)
      "Header header
float64 deltaDist
float64 deltaSteer

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

")



(provide :slam_backend/TimedPose2 "0baf874fce4dad94f21c488bdbb2552f")



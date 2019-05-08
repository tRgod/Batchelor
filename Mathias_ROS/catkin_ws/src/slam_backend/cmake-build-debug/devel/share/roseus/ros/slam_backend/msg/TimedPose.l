;; Auto-generated. Do not edit!


(when (boundp 'slam_backend::TimedPose)
  (if (not (find-package "SLAM_BACKEND"))
    (make-package "SLAM_BACKEND"))
  (shadow 'TimedPose (find-package "SLAM_BACKEND")))
(unless (find-package "SLAM_BACKEND::TIMEDPOSE")
  (make-package "SLAM_BACKEND::TIMEDPOSE"))

(in-package "ROS")
;;//! \htmlinclude TimedPose.msg.html


(defclass slam_backend::TimedPose
  :super ros::object
  :slots (_time _dist _steer ))

(defmethod slam_backend::TimedPose
  (:init
   (&key
    ((:time __time) 0.0)
    ((:dist __dist) 0.0)
    ((:steer __steer) 0.0)
    )
   (send-super :init)
   (setq _time (float __time))
   (setq _dist (float __dist))
   (setq _steer (float __steer))
   self)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:dist
   (&optional __dist)
   (if __dist (setq _dist __dist)) _dist)
  (:steer
   (&optional __steer)
   (if __steer (setq _steer __steer)) _steer)
  (:serialization-length
   ()
   (+
    ;; float64 _time
    8
    ;; float64 _dist
    8
    ;; float64 _steer
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _time
       (sys::poke _time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _dist
       (sys::poke _dist (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _steer
       (sys::poke _steer (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _time
     (setq _time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _dist
     (setq _dist (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _steer
     (setq _steer (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get slam_backend::TimedPose :md5sum-) "ff0135fc4887cc9d2384b602ae553afb")
(setf (get slam_backend::TimedPose :datatype-) "slam_backend/TimedPose")
(setf (get slam_backend::TimedPose :definition-)
      "float64 time
float64 dist
float64 steer

")



(provide :slam_backend/TimedPose "ff0135fc4887cc9d2384b602ae553afb")



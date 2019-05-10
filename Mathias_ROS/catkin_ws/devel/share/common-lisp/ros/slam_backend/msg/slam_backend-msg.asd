
(cl:in-package :asdf)

(defsystem "slam_backend-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "TimedPose" :depends-on ("_package_TimedPose"))
    (:file "_package_TimedPose" :depends-on ("_package"))
  ))
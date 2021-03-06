2015-01-03
Author: Riccardo Monica <rmonica[at]ce.unipr.it>
  RIMLab, Department of Information Engineering, University of Parma, Italy
  http://www.rimlab.ce.unipr.it/

-- INTRODUCTION --
This repository contains a KinFu Large Scale wrapper for ROS (Robot Operating System, www.ros.org).
KinFu is the KinectFusion implementation by the PCL (Point Cloud Library, www.pointclouds.org).
The original version of this wrapper was developed by Michael Korn <michael.korn(at)uni-due.de> and published at "http://fsstud.is.uni-due.de/svn/ros/is/kinfu/". That version only published the synthetic depth map and the tracked TF frame of the Kinect during KinFu execution.
Some extensions were added. These include:
- World model download as ROS message
- Known voxels download as ROS message
- Commands to start, stop, run only once, reset
- Use external tracking, from ROS messages or TF frames
- Clear part of the world model, defined by a sphere or a bounding box

In this repository, you can find four ROS packages, briefly explained in the following sections.

-- KINFU_MSGS --

Definition of the messages used by the other nodes.

-- KINFU --

The core package. This is the package that actually runs the KinFu and the extensions. Since you will have to apply patches to the PCL source code to make this work, it is required that you install the PCL from source. The procedure is detailed in kinfu/INSTALL.txt.

The kinfu node accepts two main types of message: requests and commands.

Requests are performed by sending a message of type kinfu_msgs/KinfuTsdfRequest at the "/kinfu_request_topic". Typical requests are the extraction of the world model in various formats, as defined in the header kinfu_msgs/KinfuRequestHeader. Additional options include the reset of the world representation, the subsampling or the limitation to a bounding box (useful to reduce message size).
Each request will cause the kinfu node, after processing, to send a kinfu_msgs/KinfuTsdfResponse to the topic "/kinfu_response_topic". The header field "tsdf_header" in the request is copied untouched to the response. In particular, the field tsdf_header.request_source_name can contain an arbitrary string and may be used by the subscriber to differentiate among multiple concurrent requests.

Commands are used to change the KinFu behavior at runtime and are executed by sending a kinfu_msgs/KinfuCommand message to the topic "/kinfu_command_topic". After its execution, the command will cause a std_msgs/String ack message to be sent to the "/kinfu_command_ack_topic", reporting the command_id of the command, with the added string ":OK" if succeeded or ":NO" otherwise.
Moreover, a pose hint for the KinFu tracking may be added to a command. This can be combined with some commands to guarantee that they are executed and simultaneously the KinFu tracking is set to that position. For example, sending a COMMAND_TYPE_RESUME with a forced hint allows to resume the KinFu from a specific pose.

In addition to the pose hints, it is possible to force the tracked pose to stick to a TF frame, thus disabling the internal ICP tracking. This may be done by setting the parameters "forced_tf_position" to true and "first_frame_reference_name" and "current_frame_reference_name" respectively to the reference frame and the Kinect frame. In addition, the same effect as setting "forced_tf_position" may be also achieved at runtime with COMMAND_TYPE_SET_FORCED_TF_FRAMES.

Parameters and their default values are listed in "kinfu/src/parameters.h".

-- KINFU_OUTPUT --

Due to intereferences between the modified PCL and the ROS official one, packages such as pcl_conversions couldn't be added as dependencies of the kinfu package. This means that the kinfu package will not publish the world model as a ROS-compatible sensor_msgs/PointCloud2 message. Instead, it will use custom messages as defined by the package kinfu_msgs.

The kinfu_output package is an utility that:
- receives those messages
- converts them into a ROS-compatible suitable message
- publishes them to a topic as specified by the request_source_name field in the tsdf_header.

Unfortunately, since ROS is unable to guarantee the delivery of a message sent by a just-created publisher, the message is published TWICE, with overhead since these are usually huge messages.

An alternative solution was developed using actionlib, where the request is sent to the kinfu_output node inside an action (by default, "/kinfu_output/actions/request"). The node then forwards it to the kinfu node and, when a response is available, send it as the result of the action. Multiple actions may be active at the same time. See kinfu_msgs/action/Request.action.

-- KINFU_TF_FEEDER --

The kinfu_tf_feeder node is a simple utility node that feeds the hints from TF by sending commands to the kinfu node. This allows for a greater flexibility than using the "forced_tf_position" parameter. The node may send the hint only if the TF frame is recent enough. In addition, it can use COMMAND_TYPE_TRIGGER, so a suspended kinfu node may be executed only when fresh TF data is available.

2015-01-04

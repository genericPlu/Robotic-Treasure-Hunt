
/*
Adam Pluguez
UC Merced CSE 180 Robotics
Final Project
Uses Move base to move to a group of fixed map points designed to cover the enitire map.
*/
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
//#include "geometry_msgs/Pose2D.h"
//#include <tf2/LinearMath/Quaternion.h>
//#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/Twist.h>
#include <time.h>

//void currentPoseCallBack(const geometry_msgs::PoseWithCovarianceStamped&msg);
void serviceActivated();
void serviceDone(const actionlib::SimpleClientGoalState& state,const move_base_msgs::MoveBaseResultConstPtr& result);
void serviceFeedback(const move_base_msgs::MoveBaseFeedbackConstPtr& fb);
//void scan360();
void turn(double rel_angle, double ang_speed, bool isClockwise);
void setGoal(double x, double y);


ros::Publisher vel;
geometry_msgs::Pose currentPose;
move_base_msgs::MoveBaseGoal goal;
bool STOP = true;
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;


int main(int argc, char** argv){
  ros::init(argc, argv, "gototreasure");
  ros::NodeHandle nh;
  //ros::Subscriber subCurrentpose = nh.subscribe("/amcl_pose", 10, &currentPoseCallBack);
  vel =nh.advertise<geometry_msgs::Twist>("/husky_velocity_controller/cmd_vel", 10);
  ros::Rate loop_rate(10);

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  
  //turn(13, 1, 1);

  setGoal(0,2);

  ROS_INFO("Sending goal");
  ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
   			ROS_INFO("The base moved to goal!");
			//turn(13, 1, 1);
  }
  else{
    		ROS_INFO("The base failed to move to goal for some reason.");
			//turn(13, 1, 1);
  }

  setGoal(8,2);

  ROS_INFO("Sending goal");
  ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
	ac.waitForResult();
	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
   			ROS_INFO("The base moved to goal!");
			//turn(13, 1, 1);
	}
  else{
    		ROS_INFO("The base failed to move to goal for some reason.");
			//turn(13, 1, 1);
  }
  

  setGoal(8,4);
  
  ROS_INFO("Sending goal");
  ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
	ac.waitForResult();
	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
   			ROS_INFO("The base moved to goal!");
			//turn(13, 1, 1);
	}
  else{
    		ROS_INFO("The base failed to move to goal for some reason.");
			//turn(13, 1, 1);
  }
  
  setGoal(0,4);
  
  ROS_INFO("Sending goal");
  ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
	ac.waitForResult();
	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
   			ROS_INFO("The base moved to goal!");
			//turn(13, 1, 1);
	}
  else{
    		ROS_INFO("The base failed to move to goal for some reason.");
			//turn(13, 1, 1);
  }

 
  setGoal(0,6); 

  ROS_INFO("Sending goal");
  ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
	ac.waitForResult();
	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
   			ROS_INFO("The base moved to goal!");
			//turn(13, 1, 1);
	}
  else{
    		ROS_INFO("The base failed to move to goal for some reason.");
			//turn(13, 1, 1);
  }

  
  setGoal(8,6);

  ROS_INFO("Sending goal");
  ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
	ac.waitForResult();
	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
   			ROS_INFO("The base moved to goal!");
			//turn(13, 1, 1);
	}
  else{
    		ROS_INFO("The base failed to move to goal for some reason.");
			//turn(13, 1, 1);
  }

  

  
  setGoal(8,8);

  ROS_INFO("Sending goal");
  ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
	ac.waitForResult();
	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
   			ROS_INFO("The base moved to goal!");
			//turn(13, 1, 1);
	}
  else{
    		ROS_INFO("The base failed to move to goal for some reason.");
			//turn(13, 1, 1);
  }

  
  setGoal(0,8);

  ROS_INFO("Sending goal");
  ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
	ac.waitForResult();
	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
   			ROS_INFO("The base moved to goal!");
			//turn(13, 1, 1);
	}
  else{
    		ROS_INFO("The base failed to move to goal for some reason.");
			//turn(13, 1, 1);
  }


	setGoal(-4,8);

  ROS_INFO("Sending goal");
  ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
	ac.waitForResult();
	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
   			ROS_INFO("The base moved to goal!");
			//turn(13, 1, 1);
	}
  else{
    		ROS_INFO("The base failed to move to goal for some reason.");
			//turn(13, 1, 1);
  }

 
  setGoal(-8,8);

  ROS_INFO("Sending goal");
  ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
	ac.waitForResult();
	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
   			ROS_INFO("The base moved to goal!");
			//turn(13, 1, 1);
	}
  else{
    		ROS_INFO("The base failed to move to goal for some reason.");
			//turn(13, 1, 1);
  }

  
  setGoal(-8,6);

  ROS_INFO("Sending goal");
  ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
	ac.waitForResult();
	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
   			ROS_INFO("The base moved to goal!");
			//turn(13, 1, 1);
	}
  else{
    		ROS_INFO("The base failed to move to goal for some reason.");
			//turn(13, 1, 1);
  }
   
  setGoal(0,6);

  ROS_INFO("Sending goal");
  ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
	ac.waitForResult();
	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
   			ROS_INFO("The base moved to goal!");
			//turn(13, 1, 1);
	}
  else{
    		ROS_INFO("The base failed to move to goal for some reason.");
			//turn(13, 1, 1);
  }
  
  setGoal(0,4);

  ROS_INFO("Sending goal");
  ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
	ac.waitForResult();
	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
   			ROS_INFO("The base moved to goal!");
			//turn(13, 1, 1);
	}
  else{
    		ROS_INFO("The base failed to move to goal for some reason.");
			//turn(13, 1, 1);
  }

	setGoal(-8,4);

  ROS_INFO("Sending goal");
  ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
	ac.waitForResult();
	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
   			ROS_INFO("The base moved to goal!");
			//turn(13, 1, 1);
	}
  else{
    		ROS_INFO("The base failed to move to goal for some reason.");
			//turn(13, 1, 1);
  }

  setGoal(-8,3);

  ROS_INFO("Sending goal");
  ac.sendGoal(goal,&serviceDone,&serviceActivated,&serviceFeedback);
	ac.waitForResult();
	if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
   			ROS_INFO("The base moved to goal!");
			//turn(13, 1, 1);
	}
  else{
    		ROS_INFO("The base failed to move to goal for some reason.");
			//turn(13, 1, 1);
  }
  return 0;
}


//Functions
void serviceActivated() {
    ROS_INFO_STREAM("Service received goal");
}

void serviceDone(const actionlib::SimpleClientGoalState& state,const move_base_msgs::MoveBaseResultConstPtr& result) {
    ROS_INFO_STREAM("Service completed");
    ROS_INFO_STREAM("Final state " << state.toString().c_str());
    //ros::shutdown();
}

void serviceFeedback(const move_base_msgs::MoveBaseFeedbackConstPtr& fb) {
    ROS_INFO_STREAM("Service still running");
    ROS_INFO_STREAM("Current pose (x,y) " <<
		    fb->base_position.pose.position.x << "," <<
		    fb->base_position.pose.position.y);
}

/*
void currentPoseCallBack(const geometry_msgs::PoseWithCovarianceStamped&msg){
  currentPose.position.x = msg.pose.pose.position.x;
  currentPose.position.y = msg.pose.pose.position.y;
  currentPose.position.z = msg.pose.pose.position.z;
  currentPose.orientation.x = msg.pose.pose.orientation.x;
  currentPose.orientation.y = msg.pose.pose.orientation.y;
  currentPose.orientation.z = msg.pose.pose.orientation.z;
  currentPose.orientation.w = msg.pose.pose.orientation.w;
  return;
}

void scan360(){

  ROS_INFO("Scanning goal area....");
	geometry_msgs::Twist twist;
	ros::Rate ratet(10);	
	double t0 = ros::Time::now().toSec();	
  twist.angular.z = 0.4;
	double current_angle = 0.0;

	do{
	     vel.publish(twist);
	     double t1 = ros::Time::now().toSec();
       current_angle = 0.4 * (t1-t0) * 57.29;	
	     ros::spinOnce();
       ratet.sleep();
	}while(current_angle < 360 && ros::ok());
	twist.angular.z = 0;
  vel.publish(twist);

}
*/
void turn(double rel_angle, double ang_speed, bool isClockwise){
    ROS_INFO("Scanning goal area....");
	geometry_msgs::Twist twist;

	if(isClockwise)
		twist.angular.z = -abs(ang_speed);
	else	
		twist.angular.z = abs(ang_speed);
	ros::Rate ratet(10);	
	double t0 = ros::Time::now().toSec();	
	double current_angle = 0.0;

	do{
	     vel.publish(twist);
	     double t1 = ros::Time::now().toSec();
             current_angle = ang_speed * (t1-t0);	
	     ros::spinOnce();
             ratet.sleep();
	}while(current_angle < rel_angle && ros::ok());
	twist.angular.z = 0;
        vel.publish(twist);

}

void setGoal(double x, double y){
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position.x = x;
  goal.target_pose.pose.position.y = y;
  goal.target_pose.pose.orientation.w = 1;
}

#ifndef _ROS_xbot_msgs_RobotState_h
#define _ROS_xbot_msgs_RobotState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "xbot_msgs/AbsolutePose.h"

namespace xbot_msgs
{

  class RobotState : public ros::Msg
  {
    public:
      typedef float _battery_percentage_type;
      _battery_percentage_type battery_percentage;
      typedef bool _emergency_type;
      _emergency_type emergency;
      typedef bool _is_charging_type;
      _is_charging_type is_charging;
      typedef float _gps_percentage_type;
      _gps_percentage_type gps_percentage;
      typedef float _current_action_progress_type;
      _current_action_progress_type current_action_progress;
      typedef const char* _current_state_type;
      _current_state_type current_state;
      typedef const char* _current_sub_state_type;
      _current_sub_state_type current_sub_state;
      typedef xbot_msgs::AbsolutePose _robot_pose_type;
      _robot_pose_type robot_pose;

    RobotState():
      battery_percentage(0),
      emergency(0),
      is_charging(0),
      gps_percentage(0),
      current_action_progress(0),
      current_state(""),
      current_sub_state(""),
      robot_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_battery_percentage;
      u_battery_percentage.real = this->battery_percentage;
      *(outbuffer + offset + 0) = (u_battery_percentage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_percentage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_percentage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_percentage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_percentage);
      union {
        bool real;
        uint8_t base;
      } u_emergency;
      u_emergency.real = this->emergency;
      *(outbuffer + offset + 0) = (u_emergency.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->emergency);
      union {
        bool real;
        uint8_t base;
      } u_is_charging;
      u_is_charging.real = this->is_charging;
      *(outbuffer + offset + 0) = (u_is_charging.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_charging);
      union {
        float real;
        uint32_t base;
      } u_gps_percentage;
      u_gps_percentage.real = this->gps_percentage;
      *(outbuffer + offset + 0) = (u_gps_percentage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gps_percentage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gps_percentage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gps_percentage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gps_percentage);
      union {
        float real;
        uint32_t base;
      } u_current_action_progress;
      u_current_action_progress.real = this->current_action_progress;
      *(outbuffer + offset + 0) = (u_current_action_progress.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_action_progress.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_action_progress.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_action_progress.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_action_progress);
      uint32_t length_current_state = strlen(this->current_state);
      varToArr(outbuffer + offset, length_current_state);
      offset += 4;
      memcpy(outbuffer + offset, this->current_state, length_current_state);
      offset += length_current_state;
      uint32_t length_current_sub_state = strlen(this->current_sub_state);
      varToArr(outbuffer + offset, length_current_sub_state);
      offset += 4;
      memcpy(outbuffer + offset, this->current_sub_state, length_current_sub_state);
      offset += length_current_sub_state;
      offset += this->robot_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_battery_percentage;
      u_battery_percentage.base = 0;
      u_battery_percentage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_percentage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_percentage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_percentage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_percentage = u_battery_percentage.real;
      offset += sizeof(this->battery_percentage);
      union {
        bool real;
        uint8_t base;
      } u_emergency;
      u_emergency.base = 0;
      u_emergency.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->emergency = u_emergency.real;
      offset += sizeof(this->emergency);
      union {
        bool real;
        uint8_t base;
      } u_is_charging;
      u_is_charging.base = 0;
      u_is_charging.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_charging = u_is_charging.real;
      offset += sizeof(this->is_charging);
      union {
        float real;
        uint32_t base;
      } u_gps_percentage;
      u_gps_percentage.base = 0;
      u_gps_percentage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gps_percentage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gps_percentage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gps_percentage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gps_percentage = u_gps_percentage.real;
      offset += sizeof(this->gps_percentage);
      union {
        float real;
        uint32_t base;
      } u_current_action_progress;
      u_current_action_progress.base = 0;
      u_current_action_progress.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_action_progress.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_action_progress.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_action_progress.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_action_progress = u_current_action_progress.real;
      offset += sizeof(this->current_action_progress);
      uint32_t length_current_state;
      arrToVar(length_current_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_current_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_current_state-1]=0;
      this->current_state = (char *)(inbuffer + offset-1);
      offset += length_current_state;
      uint32_t length_current_sub_state;
      arrToVar(length_current_sub_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_current_sub_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_current_sub_state-1]=0;
      this->current_sub_state = (char *)(inbuffer + offset-1);
      offset += length_current_sub_state;
      offset += this->robot_pose.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "xbot_msgs/RobotState"; };
    virtual const char * getMD5() override { return "464ee74e3497a368ce97ed6ee7a18dcb"; };

  };

}
#endif

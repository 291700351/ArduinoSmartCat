#ifndef _CAR_CONTROLLER_H
#define _CAR_CONTROLLER_H
#include <Arduino.h>

class CarMove
{
  public:
    //电机控制引脚
    CarMove(uint8_t left1, uint8_t left2, uint8_t right1, uint8_t right2);
    CarMove(uint8_t left1, uint8_t left2, uint8_t right1, uint8_t right2, uint8_t leftEN, uint8_t rightEN);

    void forward();
    void back();
    void left();
    void right();
    void stop();

  private:
    void initPins();
    uint8_t _pin_left1;
    uint8_t _pin_left2;
    uint8_t _pin_right1;
    uint8_t _pin_right2;
    uint8_t _pin_left_en;  //左电机使能
    uint8_t _pin_right_en; //右电机使能
};

#endif
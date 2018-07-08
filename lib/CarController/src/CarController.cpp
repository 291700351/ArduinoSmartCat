#include "CarController.h"

CarMove::CarMove(uint8_t left1, uint8_t left2, uint8_t right1, uint8_t right2)
{
    this->_pin_left1 = left1;
    this->_pin_left2 = left2;
    this->_pin_right1 = right1;
    this->_pin_right2 = right2;
    this->initPins();
}
CarMove::CarMove(uint8_t left1, uint8_t left2, uint8_t right1, uint8_t right2, uint8_t leftEN, uint8_t rightEN)
{
    this->_pin_left1 = left1;
    this->_pin_left2 = left2;
    this->_pin_right1 = right1;
    this->_pin_right2 = right2;
    this->_pin_left_en = leftEN;
    this->_pin_right_en = rightEN;
    this->initPins();
}

void CarMove::forward()
{
    digitalWrite(this->_pin_left1, HIGH);
    delay(1);
    digitalWrite(this->_pin_left2, LOW);
    delay(1);

    digitalWrite(this->_pin_right1, HIGH);
    delay(1);
    digitalWrite(this->_pin_right2, LOW);
    delay(1);
}

void CarMove::back()
{
    digitalWrite(this->_pin_left1, LOW);
    delay(1);
    digitalWrite(this->_pin_left2, HIGH);
    delay(1);

    digitalWrite(this->_pin_right1, LOW);
    delay(1);
    digitalWrite(this->_pin_right2, HIGH);
    delay(1);
}

void CarMove::left()
{
    digitalWrite(this->_pin_left1, LOW);
    delay(1);
    digitalWrite(this->_pin_left2, HIGH);
    delay(1);

    digitalWrite(this->_pin_right1, HIGH);
    delay(1);
    digitalWrite(this->_pin_right2, LOW);
    delay(1);
}

void CarMove::right()
{
    digitalWrite(this->_pin_left1, HIGH);
    delay(1);
    digitalWrite(this->_pin_left2, LOW);
    delay(1);

    digitalWrite(this->_pin_right1, LOW);
    delay(1);
    digitalWrite(this->_pin_right2, HIGH);
    delay(1);
}

void CarMove::stop()
{
    digitalWrite(this->_pin_left1, HIGH);
    delay(1);
    digitalWrite(this->_pin_left2, HIGH);
    delay(1);
    digitalWrite(this->_pin_left_en, LOW);
    delay(1);
    digitalWrite(this->_pin_right1, LOW);
    delay(1);
    digitalWrite(this->_pin_right2, LOW);
    delay(1);
    digitalWrite(this->_pin_right_en, LOW);
    delay(1);
}

//**********
//私有方法
//**********

void CarMove::initPins()
{
    pinMode(this->_pin_left1, OUTPUT);
    pinMode(this->_pin_left2, OUTPUT);
    pinMode(this->_pin_right1, OUTPUT);
    pinMode(this->_pin_right2, OUTPUT);
    pinMode(this->_pin_left_en, OUTPUT);
    pinMode(this->_pin_right_en, OUTPUT);
}

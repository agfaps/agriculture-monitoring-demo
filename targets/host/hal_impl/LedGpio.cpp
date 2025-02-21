#include "LedGpio.hpp"
#include <iostream>


void LedGpio::init()
{
    std::cout << "LedGpio::init" << std::endl;
}
void LedGpio::set(bool state) 
{

    std::cout << "LedGpio::set: " << (state ? "ON" : "OFF") << std::endl;
}
bool LedGpio::read() 
{
    std::cout << "LedGpio::read" << std::endl;
    return false;
}
void LedGpio::mode(HAL_GPIO_MODE mode) 
{
    std::cout << "LedGpio::mode: "<< (mode == HAL_GPIO_MODE::OUTPUT ? "OUTPUT" : "INPUT") << std::endl;
}

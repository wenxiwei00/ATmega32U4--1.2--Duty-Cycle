/* Name: main.c
 * Author: <insert your name here>
 * Copyright: <insert your copyright message here>
 * License: <insert your license reference here>
 */


#include "MEAM_general.h"  // includes the resources included in the MEAM_general.h file
#define LED_PIN PB3

uint8_t duty = 0;

int main(void)
{
    _clockdivide(0); //set the clock speed to 16Mhz

    DDRB |= (1 << LED_PIN);			// set PORTB3 as output

    //use us
    uint16_t onTime = 10*duty;
    uint16_t offTime = 1000 - onTime;

    for(;;){
        set(PORTB,LED_PIN);
        _delay_us(onTime);
        clear(PORTB,LED_PIN);
        _delay_us(offTime);
    }
    
   
}





// #include "MEAM_general.h"  // includes the resources included in the MEAM_general.h file
// int main(void) 
// { 
    
//     _clockdivide(0); //set the clock speed to 16Mhz
//     uint8_t dutyCycle = 10; //initialize duty cycle  
//     uint16_t wholeTime = 2000;   //the whole cycle is 1000 ms
//     uint16_t onTime = (dutyCycle*2000)/100; 

//     while(1){
//     set(PORTB,3);
//     _delay_ms(onTime);
//     clear(PORTB,3);
//     _delay_ms(2000-onTime);
//     }

// }


/* 
 #include "MEAM_general.h"  // includes the resources included in the MEAM_general.h file

int main(void)
{
    _clockdivide(0); // 设置时钟速度为16MHz

    uint8_t dutyCycle = 80; // 初始占空比为50%

    while (1) {
        // 根据占空比设置LED状态
        if (dutyCycle == 0) {
            clear(PORTB, 3); // 0%占空比，LED完全关闭
        } else if (dutyCycle == 100) {
            set(PORTB, 3); // 100%占空比，LED完全打开
        } else {
            // 使用占空比来决定LED状态
            uint16_t onTime = (dutyCycle * 2000) / 100; // 20ms周期下的LED打开时间
            set(PORTB, 3); // 打开LED
            _delay_ms(onTime);
            clear(PORTB, 3); // 关闭LED
            _delay_ms(2000 - onTime); // 计算关LED的时间
        }

        // 延迟1秒
        _delay_ms(1000);
    }
} */


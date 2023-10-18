/* 
 * File:   application.c
 * Author: AyaAli
 * Created on September 22, 2023, 10:24 AM
 */
#include "application.h"

led_t led_1 = {
.Port_Name = PORTC_INDEX,
.pin = PIN0,
.led_statues = LED_OFF,
};
led_t led_2 = {
.Port_Name = PORTC_INDEX,
.pin = PIN1,
.led_statues = LED_OFF,
};



button_t btn_high_1 = {
.button_pin.port = PORTD_INDEX,
.button_pin.pin = PIN0,
.button_pin.direction = Input,
.button_pin.logic = LOW,
.button_connection = BUTTON_ACTIVE_HIGH,
.button_state= BUTTON_RELEASED,
};

button_t btn_high_2 = {
.button_pin.port = PORTD_INDEX,
.button_pin.pin = PIN1,
.button_pin.direction = Input,
.button_pin.logic = LOW,
.button_connection = BUTTON_ACTIVE_HIGH,
.button_state= BUTTON_RELEASED,
};

button_state_t btn_button_high_st_1 = BUTTON_RELEASED;
button_state_t btn_button_high_st_2 = BUTTON_PRESSED;
button_state_t btn_button_high_valid_st_1 = BUTTON_RELEASED;
button_state_t btn_button_high_valid_st_2 = BUTTON_RELEASED;
uint_8 flag_1 = 0 ; 
uint_8 flag_2 = 0 ; 
uint_32 valid_button_1 = 0;
uint_32 valid_button_2 = 0;
int main() {
  while(1){
//      application_initialize();  
  Std_ReturnType ret = E_NOT_OK;

ret = led_initialize(&led_1);

ret = Button_Initialize(&btn_high_1);

ret = Button_Read_State(&btn_high_1,&btn_button_high_st_1);

ret = led_initialize(&led_2);

ret = Button_Initialize(&btn_high_2);

ret = Button_Read_State(&btn_high_2,&btn_button_high_st_2);



if( btn_button_high_st_1 ==LOW){
valid_button_1++;
if (valid_button_1 >500){
btn_button_high_valid_st_1 = BUTTON_PRESSED;
led_turn_on(&led_1);
 flag_1 = 1;
}
}
else{
valid_button_1 = 0;
led_turn_off(&led_1);
}
 if( btn_button_high_st_2 == LOW){
  valid_button_2++;
   if (valid_button_2 >500){
   btn_button_high_valid_st_2 = BUTTON_PRESSED;
   led_turn_on(&led_2);
   flag_2 = 1;
}
  
 }
else{
 valid_button_2 = 0;
led_turn_off(&led_2);
}
 
  }
  return (EXIT_SUCCESS);
}



void application_initialize(void){

  }

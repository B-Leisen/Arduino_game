//LIBRARIES
//--------------------------------------------------------------------
#include <vector>
using namespace std;
#include <LiquidCrystal.h>
#include "SR04.h"

//DEFINES AND GENERAL
//--------------------------------------------------------------------
//which peripherals are used?
bool joystick = true;
bool lcd = true;
bool matrix = true;

//set their initial values
#define lcd_length 16
#define lcd_depth 1 //0 is row one
#define matrix_module_length 8
#define matrix_module_height 8

// Arduino pin numbers for joystick
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output


// initialize the library with the numbers of the interface pins for the lcd display
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
//We define a BoolVec vector since we are gonna need this type several times
typedef vector<bool> BoolVec;

//--------------------------------------------------------------------
init_peripherals(){
    if(lcd){
    lcd.begin(lcd_length,lcd_depth);
    delay(1000);
      // Print a message to the LCD.
      lcd.print("Booting!");
  }
  if(joystick){
    //joystick
    pinMode(SW_pin, INPUT);
    digitalWrite(SW_pin, HIGH);
  
    Serial.begin(9600);//Initialization of Serial Port
     delay(1000);
  }
}
void setup() {
  init_peripherals();
  //init_menu();

}

void loop() {
  // put your main code here, to run repeatedly:
  run_menu();

}

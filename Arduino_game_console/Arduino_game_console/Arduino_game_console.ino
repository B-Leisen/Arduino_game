//LIBRARIES
//--------------------------------------------------------------------
#include <math.h>

#include <ArduinoComponents.h>
#include <LiquidCrystal.h>
#include "SR04.h"
// initialize the library with the numbers of the interface pins for the lcd display
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//We always have to include the library
#include "LedControl.h"
/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 4 is connected to the DataIn 
 pin 6 is connected to LOAD(CS)
 pin 5 is connected to the CLK 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(4,6,5,1);


//DEFINES AND GENERAL
//--------------------------------------------------------------------
int os_mode = 0; // mode of the program, initial menu state is 0, snake game is 1
//which peripherals are used?
bool joystick = true;
bool lcdscreen = true;
bool matrix = true;

//set their initial values
#define lcd_length 16
#define lcd_depth 2 //0 is row one

// Arduino pin numbers for joystick
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

/* image switching time */
unsigned long delaytime1=500;
unsigned long delaytime2=50;

String games[3]={"Snake", "Tetris", "Space"};
int menu_page = 0; // menu page displaying the games, 0 initial -> snake

//--------------------------------------------------------------------
void init_peripherals(){
    if(lcdscreen){
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
  if(matrix){
      /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}
  }

void setup() {
  init_peripherals();
  //init_menu();

}


void resultspage(){
  
}
void loop() {
 // put your main code here, to run repeatedly:
 if (os_mode==0){run_menu();}
 if (os_mode==1){startprogram();}
 if (os_mode==2){resultspage();}
}

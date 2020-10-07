//LIBRARIES
//--------------------------------------------------------------------
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

String games[2]={"Snake", "Tetris"};
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


void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte a[5]={B01111110,B10001000,B10001000,B10001000,B01111110};
  byte r[5]={B00010000,B00100000,B00100000,B00010000,B00111110};
  byte d[5]={B11111110,B00010010,B00100010,B00100010,B00011100};
  byte u[5]={B00111110,B00000100,B00000010,B00000010,B00111100};
  byte i[5]={B00000000,B00000010,B10111110,B00100010,B00000000};
  byte n[5]={B00011110,B00100000,B00100000,B00010000,B00111110};
  byte o[5]={B00011100,B00100010,B00100010,B00100010,B00011100};

  /* now display them one by one with a small delay */
  lc.setRow(0,0,a[0]);
  lc.setRow(0,1,a[1]);
  lc.setRow(0,2,a[2]);
  lc.setRow(0,3,a[3]);
  lc.setRow(0,4,a[4]);
  delay(delaytime1);
  lc.setRow(0,0,r[0]);
  lc.setRow(0,1,r[1]);
  lc.setRow(0,2,r[2]);
  lc.setRow(0,3,r[3]);
  lc.setRow(0,4,r[4]);
  delay(delaytime1);
  lc.setRow(0,0,d[0]);
  lc.setRow(0,1,d[1]);
  lc.setRow(0,2,d[2]);
  lc.setRow(0,3,d[3]);
  lc.setRow(0,4,d[4]);
  delay(delaytime1);
  lc.setRow(0,0,u[0]);
  lc.setRow(0,1,u[1]);
  lc.setRow(0,2,u[2]);
  lc.setRow(0,3,u[3]);
  lc.setRow(0,4,u[4]);
  delay(delaytime1);
  lc.setRow(0,0,i[0]);
  lc.setRow(0,1,i[1]);
  lc.setRow(0,2,i[2]);
  lc.setRow(0,3,i[3]);
  lc.setRow(0,4,i[4]);
  delay(delaytime1);
  lc.setRow(0,0,n[0]);
  lc.setRow(0,1,n[1]);
  lc.setRow(0,2,n[2]);
  lc.setRow(0,3,n[3]);
  lc.setRow(0,4,n[4]);
  delay(delaytime1);
  lc.setRow(0,0,o[0]);
  lc.setRow(0,1,o[1]);
  lc.setRow(0,2,o[2]);
  lc.setRow(0,3,o[3]);
  lc.setRow(0,4,o[4]);
  delay(delaytime1);
  lc.setRow(0,0,0);
  lc.setRow(0,1,0);
  lc.setRow(0,2,0);
  lc.setRow(0,3,0);
  lc.setRow(0,4,0);
  delay(delaytime1);
}

void resultspage(){
  
}
void loop() {
 // put your main code here, to run repeatedly:
 if (os_mode==0){run_menu();}
 if (os_mode==1){startprogram();}
 if (os_mode==2){resultspage();}
}

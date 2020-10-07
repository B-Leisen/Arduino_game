int headpos = 2; // starting at pos. 2
int actives[64];
int frame =0;
bool start = true;
void spawnfood(){
  int spawnfield = random(63);
}
double power(double base, double power)
{
    return exp(log(base)*power);
}

//the display shall be used from 0->63 as values for the different bits which we activate
void displayactives(){
  int row = 0;
  byte showbyte = B00000000;
  for(int i=0;i<64;i++){
    int j = i;
      if(i<=15 && i>7){j = j-8; row=1;}
      if(i<=23 && i>15){j= j-16;row=2;}
      if(i<=31 && i>23){ j= j-24;row=3;}
      if(i<=39 && i>31){ j= j-32;row=4;}
      if(i<=47 && i>39){ j= j-40;row=5;}
      if(i<=55 && i>47){ j= j-48;row=6;}
      if(i<=63 && i>55){ j= j-55;row=7;}

     int outputnumber= power(2.0,j);
     if(j>1){//since POW FUNCTION floating point error
      outputnumber++;
     }
     lcd.clear();
     lcd.print(j);
     lcd.print("    ");
     lcd.print(outputnumber);
    lc.setRow(0,row,outputnumber);
    delay(1500);
    lc.clearDisplay(0);
    delay(1500);

  }
}
void getframe(){
  
}
void clearactives(){
  for(int i=0; i<64;i++){
    actives[i]=i;
  }
}
void gamerunning(){
  if(start){
  clearactives();
  displayactives();
 // setstart();
  start=false;
  }
  getframe();
  //displayframe();
}
void startanimation(){
  byte bigO[2]={B11111111,B10000001};
  byte smallerO[3]={B01111110,B01000010,B00000000};
  byte tinyO[3]={B00111100,B00100100,B00000000};
  byte cube[2]={B00011000,B00000000};
  lc.setRow(0,0,bigO[0]);
  lc.setRow(0,1,bigO[1]);
  lc.setRow(0,2,bigO[1]);
  lc.setRow(0,3,bigO[1]);
  lc.setRow(0,4,bigO[1]);
  lc.setRow(0,5,bigO[1]);
  lc.setRow(0,6,bigO[1]);
  lc.setRow(0,7,bigO[0]);
  delay(500);
  lc.setRow(0,0,smallerO[2]);
  lc.setRow(0,1,smallerO[0]);
  lc.setRow(0,2,smallerO[1]);
  lc.setRow(0,3,smallerO[1]);
  lc.setRow(0,4,smallerO[1]);
  lc.setRow(0,5,smallerO[1]);
  lc.setRow(0,6,smallerO[0]);
  lc.setRow(0,7,smallerO[2]);
  delay(500);
  lc.setRow(0,0,tinyO[2]);
  lc.setRow(0,1,tinyO[2]);
  lc.setRow(0,2,tinyO[0]);
  lc.setRow(0,3,tinyO[1]);
  lc.setRow(0,4,tinyO[1]);
  lc.setRow(0,5,tinyO[0]);
  lc.setRow(0,6,tinyO[2]);
  lc.setRow(0,7,tinyO[2]);
  delay(500);
  lc.setRow(0,0,cube[1]);
  lc.setRow(0,1,cube[1]);
  lc.setRow(0,2,cube[1]);
  lc.setRow(0,3,cube[0]);
  lc.setRow(0,4,cube[0]);
  lc.setRow(0,5,cube[1]);
  lc.setRow(0,6,cube[1]);
  lc.setRow(0,7,cube[1]);
  delay(500);
}

void run_snake(){
  startanimation();
  lc.clearDisplay(0);
  gamerunning();

}

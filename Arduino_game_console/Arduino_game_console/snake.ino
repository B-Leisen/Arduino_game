int headpos = 2; // starting at pos. 2
int frame =0;
void spawnfood(){
  int spawnfield = random(63);
}
//the display shall be used from 0->63 as values for the different bits which we activate

void getframe(){
  
}
void gamerunning(){
  getframe();
  displayframe();
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

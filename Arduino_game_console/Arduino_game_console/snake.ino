int snake[64]; // starting at pos. 2
int lasthead =2;
int actives[64];
int frame =0;
int food;
int points = 0;
bool nofood = true;
String lastmove="left";
bool start = true;

double power(double base, double power)
{
    return exp(log(base)*power);
}
void setactives(){
  clearactives();
  for(int i=0; i<64; i++){
    if(snake[i]!=-1){
      actives[snake[i]]=1;
    }
  }
  if(!nofood){
  actives[food]=1;
  }
}
//the display shall be used from 0->63 as values for the different bits which we activate
void displayactives(){
  int row = 0;
  byte showbyte = B00000000;
  int rowfillers[8]={0,0,0,0,0,0,0,0};
  for(int i=0;i<64;i++){
    int j = i;
      if(i<=7){j=i; row=0;}
      if(i<=15 && i>7){j = j-8; row=1;}
      if(i<=23 && i>15){j= j-16;row=2;}
      if(i<=31 && i>23){ j= j-24;row=3;}
      if(i<=39 && i>31){ j= j-32;row=4;}
      if(i<=47 && i>39){ j= j-40;row=5;}
      if(i<=55 && i>47){ j= j-48;row=6;}
      if(i<=63 && i>55){ j= j-56;row=7;}

     int outputnumber= power(2.0,j);
     if(j>1){//since POW FUNCTION floating point error
      outputnumber++;
     }
     outputnumber = outputnumber * actives[i];
     rowfillers[row]+=outputnumber;
  }
  for(int i=0; i<8 ; i++){
    lc.setRow(0,i,rowfillers[i]);
  }
  delay(300);
  lc.clearDisplay(0);
}
bool coll(int pos){
  bool re = false;
  for(int i=1; i<64;i++){
    if(snake[i]==pos){
      re = true;
    }
  }
  if(!(pos<=63 && pos>=0)){
    re = true;
  }
  return re;
}
void pulltail(String input){
  for(int i=63; i>0;i--){
    if(snake[i]!=-1){
      snake[i]= snake[i-1];
    }
    snake[1]=lasthead;
  }
}
void movehead(String input){
  lasthead=snake[0];
  if(input=="left"){
    snake[0]++;
    lastmove="left";
    if(coll(snake[0])){
      lostgame();
    }
    if(snake[0]==0||snake[0]==8||snake[0]==16||snake[0]==24||snake[0]==32||snake[0]==40||snake[0]==48||snake[0]==56){
      lostgame();
    }
  }
  if(input=="right"){
    snake[0]--;
    lastmove="right";
    if(coll(snake[0])){
      lostgame();
    }
    if(snake[0]==7||snake[0]==15||snake[0]==23||snake[0]==31||snake[0]==39||snake[0]==47||snake[0]==55||snake[0]==63){
      lostgame();
    }
  }
  if(input=="up"){
    snake[0]-=8;
    lastmove="up";
    if(coll(snake[0])){
      lostgame();
    }
  }
  if(input=="down"){
    snake[0]+=8;
    lastmove="down";
    if(coll(snake[0])){
      lostgame();
    }
  }
  if(input=="pressed"){
    leavegame();
  }
  if(input=="neutral"){
    movehead(lastmove);
  }
}
void setsnake(){
  snake[0]=2;
  snake[1]=1;
  snake[2]=0;
  for(int i=3; i<64; i++){
    snake[i]=-1;
  }
}
bool spawnColl(int pos){
  for(int i=0; i<64;i++){
    if(snake[i]==pos){
      return true;
    }
  }
  return false;
}
void spawnfood(){
  int spawnpos = 0;
  if(nofood){
   spawnpos = random(63)+1;
   while(spawnColl(spawnpos)){
    spawnpos = random(63)+1;
   }
  food = spawnpos;
  nofood=false;
  }
}
void eat(){
  if(food==snake[0]){
    points++;
    nofood=true;
    for(int i=0; i<64; i++){
      if(i==63){
        leavegame();
      }
      if(snake[i]==-1){
        snake[i]= snake[i-1];
        break;
      }
    }
  }
}
void leavegame(){
  bool pause = true;
    lcd.clear();
    lcd.print("Game paused");
    delay(1000);
  while(pause){
    String input = getinput();
    if(input=="pressed"){
      pause=false;
      lcd.clear();
      lcd.print("resume game");
    }
  }
 delay(1000);
 lcd.clear();
      lcd.print("3");
       delay(1000);
 lcd.clear();
      lcd.print("2");
       delay(1000);
 lcd.clear();
      lcd.print("1");
             delay(1000);
}

void lostgame(){
    lcd.clear();
    lcd.print("lost the game : ");
    lcd.setCursor(0, 1);
    lcd.print(points);
    lcd.print(" points");
    os_mode=0;
    while(1){
      String input = getinput();
      if(input=="pressed"){
        break;
      }
    }

}
void getframe(){
  lc.clearDisplay(0);
  String input = getinput();
  spawnfood();
  movehead(input);
  pulltail(input);
  eat();
  setactives();
}
void clearactives(){
  for(int i=0; i<64;i++){
    actives[i]=0;
  }
}
void gamerunning(){
  if(start){
  clearactives();
  points=0;
  lastmove="left";
  setsnake();
  start=false;
  }
  while(os_mode==1){
  getframe();
  displayactives();
  }
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
  start = true;
  lc.clearDisplay(0);
  gamerunning();

}

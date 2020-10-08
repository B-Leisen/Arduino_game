int playerpos = 61;
int shots[6];
int enemy[24];
int timer=0;
int enemyspeed=8;

void activateplayer(){
  actives[playerpos]=1;
  actives[playerpos-1]=1;
  actives[playerpos+1]=1;
  actives[playerpos-8]=1;
}
void activateshot(){
  for(int i=0; i<6;i++){
    if(shots[i]!=-1){
      actives[shots[i]]=1;
    }
  }
}
void activateenemies(){
  for(int i=0; i<24;i++){
    if(enemy[i]!=-1){
      actives[enemy[i]]=1;
      actives[enemy[i]-1]=1;
    }
    }
}
void set_space_actives(){
  clearactives();
  activateplayer();
  activateenemies();
  activateshot();
}
void clear_enemies(){
  for(int i=0; i<24; i++){
    enemy[i]=-1;
  }
}
bool enemyspawncoll(int pos){
  if(pos==0){
    return true;
  }
  for(int i=0; i<24;i++){
    if(enemy[i]==pos||enemy[i]-1==pos){
      return true;
    }
   }
   return false;
}
int getspawnpos(){
  int pos = random(7);
  if(enemyspawncoll(pos)){
    return -1;
  }
  return pos;
}
void spawn_enemies(){
   for(int i=0; i<24;i++){
    if(enemy[i]==-1){
      enemy[i] = getspawnpos()+1;
      if(enemy[i]==0){
        enemy[i]=-1;
      }
      break;
    }
   }
}
void kill(int i){
  enemy[i]=-1;
}
bool shotColl(int shotpos){
  for(int i=0; i<24;i++){
    if(shotpos==enemy[i]||shotpos==enemy[i]-1){
      kill(i);
      return true;
    }
  }
  return false;
}
void move_shot(){
  for(int i=0; i<6;i++){
   if(shots[i]!=-1){
     shots[i]= shots[i]-8;
   
     if(shotColl(shots[i])){
        shots[i]=-1;
        points++;
      }
   }
   if(shots[i]<0){
    shots[i]=-1;
   }
  }
}
void spawnshot(){
  for(int i=0; i<6;i++){
    if(shots[i]==-1){
      shots[i]=playerpos-8;
      break;
    }
  }
}
void shoot(){
  spawnshot();
}

void move_enemies(){
   for(int i=0; i<24;i++){
   if(enemy[i]!=-1){
     enemy[i]= enemy[i]+8;
   }
   if(enemy[i]>64){
    lostgame();
   }
  }
}
void move_player(String input){
  if(input=="left"){
    if(playerpos<62){
    playerpos++;
    }
  }
  if(input=="right"){
    if(playerpos>57){
    playerpos--;
    }
  }
  if(input=="up"){
  lcd.clear();  
  lcd.print(points);
   shoot();
  }
  if(input=="pressed"){
    leavegame();
  }
}
void get_spaceframe(){
  lc.clearDisplay(0);
  String input = getinput();
  move_player(input);
  //if then spawn
  spawn_enemies();
  if(timer>=enemyspeed){
    timer=0;
  move_enemies();
  }
  move_shot();// detect hit
  set_space_actives();
}
void clearshots(){
  for(int i=0; i<6 ;i++){
    shots[i]=-1;
  }
}
void space_game(){
  if(start){
  clearactives();
  points=0;
  playerpos = 61;
  enemyspeed=10;
  clearshots();
  clear_enemies();
  start=false;
  }
  while(os_mode==1){
  get_spaceframe();
  displayactives();
  timer++;
  if(points==10){
    enemyspeed=8;
  }
  if(points==30){
    enemyspeed=6;
  }
  if(points==60){
    enemyspeed=4;
  }
    if(points==100){
    enemyspeed=3;
  }
      if(points==150){
    enemyspeed=2;
  }
  }
}

void run_space(){
  startanimation();
  start = true;
  lc.clearDisplay(0);
  space_game();

}

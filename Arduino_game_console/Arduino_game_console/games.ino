void rungame(String game){
  if(game=="Snake"){
    lcd.clear();
    lcd.print("running Snake");
    run_snake();
    
  }else{
    if(game=="Tetris"){
      lcd.clear();
    lcd.print("running Tetris");
    delay(1000);

  }else{
    if(game=="Space"){
      lcd.clear();
    lcd.print("running space");
    run_space();

  }else{
    lcd.clear();
    lcd.print("no such Game");
        delay(1000);
  }
  }
}
}
void run_heart(){
while(1){
  byte big[8]={B01000010,B10100101,B10011001,B10000001,B01000010,B00100100,B00011000};
  lc.setRow(0,0,big[0]);
  lc.setRow(0,1,big[1]);
  lc.setRow(0,2,big[2]);
  lc.setRow(0,3,big[3]);
  lc.setRow(0,4,big[4]);
  lc.setRow(0,5,big[5]);
  lc.setRow(0,6,big[6]);
  lc.setRow(0,7,big[7]);
  delay(500);
}
}
void startprogram(){
  rungame(games[menu_page]);
}

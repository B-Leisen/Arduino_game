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
    lcd.clear();
    lcd.print("no such Game");
        delay(1000);
  }
  }
}

void startprogram(){
  rungame(games[menu_page]);
}

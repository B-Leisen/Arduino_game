
void run_menu(){
  while(os_mode==0){
  String input = getinput();
  handleInput(input);
  if(os_mode==0){
    setdisplay();
    }
  }
}


void handleInput(String input){
  if(input=="pressed"){
    os_mode=1;
    delay(100);
  }else{
    switchpage(input);
  }
}
void switchpage(String input){
    if(input=="up"){
      menu_page++;
    }
    if(input=="down"){
      menu_page--;
    }
    menu_page = menu_page % (sizeof(games)/sizeof(*games) );
}
void setdisplay(){

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Game: ");
  lcd.print(games[menu_page]);
  delay(300);
  lcd.setCursor(0, 1);
  lcd.print(menu_page);
  delay(300);
  
}

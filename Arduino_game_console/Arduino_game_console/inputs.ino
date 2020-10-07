String getinput(){
   int pressed = digitalRead(SW_pin);
   int x = analogRead(X_pin);
   int y = analogRead(Y_pin);
   if(pressed==0){
    return "pressed";
   }
   if(x>700){
    return "left";
   }
   if(x<300){
      return "right";
    }
   
   if(y>700){
    return "up";
   }
   if(y<300){
    return "down";
   }
   return "neutral";

}

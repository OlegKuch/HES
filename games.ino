void MainMenu()
{
  if(millis() - gameTimer >= 40)
  { 
    TV.clear_screen();
    TV.select_font(font6x8);
    TV.set_cursor(2,2);
    TV.print("GreenCubic Classic");
    TV.set_cursor(2,12);
    TV.print("Pong");
    switch(gameSelect)
    {
      case 0:
        TV.draw_rect(0,0,115,10,INVERT,INVERT);
        break; 
      case 1:
        TV.draw_rect(0,10,115,10,INVERT,INVERT);
    }
    if(up && gameSelect > 0)
    {
      gameSelect--;  
    }
    if(down && gameSelect < 1)
    {
      gameSelect++;  
    }
    if(right)
    {
      game = gameSelect + 1;
      if(game == 2)
      {
        x = 64;
        y = 48;
        speedX = random(-2,2); 
        speedY = random(-2,2);
      }
    }
    gameTimer = millis();
  }
}

void GreenCubicClassic()
{
  if(millis() - gameTimer >= 40)
  { 
    if(down && y < 85)
    {
      y++;
    }
    if(up && y > 0)
    {
      y--;
    }
    if(left && x > 0)
    {
      x--;
    }
    if(right && x < 117)
    {
      x++;
    }
    TV.clear_screen();
    TV.draw_rect(x,y,10,10,WHITE,WHITE);
    gameTimer = millis();
  }
}

void Pong()
{
  if(millis() - gameTimer >= 40)
  { 
    TV.clear_screen();
    TV.draw_rect(5,myRacketY,2,15,WHITE,WHITE);
    TV.draw_rect(123,enRacketY,2,15,WHITE,WHITE);
    TV.draw_circle(x,y,2,WHITE,WHITE);
    if(down && myRacketY < 80)
    {
      myRacketY++;
    }
    if(up && myRacketY > 0)
    {
      myRacketY--;
    }
    x += speedX;
    y += speedY;
    if(y < 2 || y > 93)
    {
      speedY *= -1;  
    }
    if(x < 9 && y >= myRacketY && y <= myRacketY + 15)
    {
      speedX *= -1;
    }
    if(x > 120 && y >= enRacketY && y <= enRacketY + 15)
    {
      speedX *= -1;
    }
    if(enRacketY + 7 < y && enRacketY < 80)
    {
      enRacketY++;  
    }
    if(enRacketY + 7 > y && enRacketY > 0)
    {
      enRacketY--;  
    }
    gameTimer = millis();
    if(x < 5)
    {
      enScore++;
      x = 64;
      y = 48;
      speedX = random(-2,2); 
      speedY = random(-2,2);
    }
    if(x > 123)
    {
      myScore++;
      x = 64;
      y = 48;
      speedX = random(-2,2); 
      speedY = random(-2,2); 
    }
  }
}

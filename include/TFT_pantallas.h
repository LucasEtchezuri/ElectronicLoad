void TFT_Pantalla_SplashScreen(void)
{
  tft.fillScreen(TFT_BLACK); // a background colour defined

  tft.setTextColor(TFT_WHITE);    // Font blanco.. Sin color de fondo
  tft.setTextSize(1);             // set text size multiplier to 1
  tft.setCursor(45, 0, 4);        // Set "cursor" at top left corner of display (0,0) and select font
  tft.println("ELECTRONIC LOAD"); // Cursor will move to next line automatically during printing with 'tft.println'

  tft.setTextColor(TFT_YELLOW); // Set the font colour to be yellow with no background
  tft.setTextFont(2);           // set to font 7
  tft.setCursor(250, 220);
  tft.println("Ver: 1.0");

  delay(timeSplash);
}

void TFT_Estado(void)
{
  tft.setTextSize(1);
  tft.setTextFont(4);
  tft.setTextDatum(TR_DATUM);
  if (estado.estado == 0)
  {
    tft.fillRect(197, 0, 320, 30, TFT_RED);
    tft.setTextColor(TFT_WHITE, TFT_RED);
    tft.drawString("STOP   ", tft_pos_estado_x, tft_pos_estado_y);
  }
  else
  {
    tft.fillRect(197, 0, 320, 30, TFT_GREEN);
    tft.setTextColor(TFT_WHITE, TFT_GREEN);
    tft.drawString("RUNNING", tft_pos_estado_x, tft_pos_estado_y);
  }
}

void TFT_Modo(void)
{
  tft.setTextSize(1);
  tft.setTextFont(4);
  tft.setTextColor(TFT_BLACK, TFT_WHITE); // Font blanco.. Sin color de fondo
  tft.fillRect(85, 0, 100, 30, TFT_WHITE);
  //tft.fillRect(155, 80, 53, 40, TFT_WHITE);
  tft.setCursor(tft_pos_modo_x, tft_pos_modo_y); // Set "cursor" at top left corner of display (0,0) and select font
  tft.setTextDatum(BL_DATUM);
  if (estado.modo == 1)
  { // 1=I
    tft.print("I");
    tft.drawString("A", tft_pos_set_x + 175, tft_pos_set_y + 55);
  }
  else if (estado.modo == 2)
  { // 2=V
    tft.print("V");
    tft.drawString("V", tft_pos_set_x + 175, tft_pos_set_y + 55);
  }
  else
  {
    tft.print("W"); // 3=W
    tft.drawString("w", tft_pos_set_x + 175, tft_pos_set_y + 55);
  }
}

void TFT_Info(void)
{
  if (strcmp(estado.pantalla, "principal") == 0)
  {
    // Recuadro de Info
    tft.fillRoundRect(220, 40, 90, 130, 5, TFT_WHITE);
    tft.drawRoundRect(220, 40, 90, 130, 5, TFT_BLACK);
    tft.setTextColor(TFT_BLACK); // Font blanco.. Sin color de fondo
    tft.setTextSize(1);          // set text size multiplier to 1
    tft.setTextFont(2);
    tft.setTextDatum(TL_DATUM);
    tft.setCursor(230, 55);
    tft.println("V");
    tft.setCursor(230, 70);
    tft.println("I");
    tft.setCursor(230, 85);
    tft.println("W");
    tft.setCursor(230, 100);
    tft.println("T");
    tft.setCursor(230, 115);
    tft.println("Ah");

    tft.setTextDatum(TR_DATUM);
    tft.setCursor(250, 55);
    tft.println("=");
    tft.setCursor(250, 70);
    tft.println("=");
    tft.setCursor(250, 85);
    tft.println("=");
    tft.setCursor(250, 100);
    tft.println("=");
    tft.setCursor(250, 115);
    tft.println("=");

    tft.setTextColor(TFT_BLACK, TFT_WHITE); // Font blanco.. Sin color de fondo
    tft.setTextSize(1);                     // set text size multiplier to 1
    tft.setTextFont(2);
    tft.setTextDatum(TL_DATUM);

    tft.setCursor(260, 55);
    tft.print((float)estado.v / 1000);
    tft.setCursor(260, 70);
    tft.print(estado.i / 10000.000);
    tft.setCursor(260, 85);
    tft.print(estado.w / 10.00);
    tft.setCursor(260, 100);
    tft.print(estado.segundos);
    tft.setCursor(260, 115);
    tft.print(estado.ah);

    tft.setTextColor(TFT_BLACK, TFT_WHITE); // Font blanco.. Sin color de fondo
    tft.setTextSize(1);                     // set text size multiplier to 1
    tft.setTextFont(2);
    tft.setTextDatum(TL_DATUM);

    tft.setCursor(92, 204);
    tft.print("             ");
    tft.setCursor(92, 204);
    tft.print(estado.temperaturaDisipador);
    tft.setCursor(92, 220);
    tft.print("             ");
    tft.setCursor(92, 220);
    tft.print(estado.coolerDisipadorPotencia);
    tft.print(" %");
  }
}

void TFT_SetSeleccion(int unidad)
{

  if (unidad == 1000)
  {
    tft.fillRoundRect(17, 50, 150, 5, 2, TFT_WHITE);
    tft.fillRoundRect(17, 50, 27, 5, 2, TFT_BLACK);
  }
  else if (unidad == 100)
  {
    tft.fillRoundRect(17, 50, 150, 5, 2, TFT_WHITE);
    tft.fillRoundRect(62, 50, 27, 5, 2, TFT_BLACK);
  }
  else if (unidad == 10)
  {
    tft.fillRoundRect(17, 50, 150, 5, 2, TFT_WHITE);
    tft.fillRoundRect(93, 50, 27, 5, 2, TFT_BLACK);
  }
  else if (unidad == 1)
  {
    tft.fillRoundRect(17, 50, 150, 5, 2, TFT_WHITE);
  }
}

void TFT_Set(void)
{
  if (strcmp(estado.pantalla, "principal") == 0)
  {
    if (estado.setSeleccion == 10000)
    {
      TFT_SetSeleccion(1000);
    }
    else if (estado.setSeleccion == 1000)
    {
      TFT_SetSeleccion(100);
    }
    else if (estado.setSeleccion == 100)
    {
      TFT_SetSeleccion(10);
    }
    else if (estado.setSeleccion == 10)
    {
      TFT_SetSeleccion(1);
    }
    tft.setTextDatum(BL_DATUM);
    tft.setTextSize(1);
    tft.setTextFont(7);
    tft.setTextColor(TFT_BLACK, TFT_WHITE); // Font blanco.. Sin color de fondo
    tft.setCursor(tft_pos_set_x, tft_pos_set_y);
    tft.drawFloat(estado.set / 10000.00, 3, tft_pos_set_x, tft_pos_set_y + 50);
  }
}

void TFT_Set_Corte_V(void)
{
  if (strcmp(estado.pantalla, "setCorte_V") == 0)
  {

    spriteSetCorte.fillRect(5, 50, 270, 145, TFT_BLUE);

    if (seleccionCorte == 100)
    {
      spriteSetCorte.fillRoundRect(70, 80, 150, 5, 2, TFT_BLUE);
      spriteSetCorte.fillRoundRect(70, 80, 55, 5, 2, TFT_WHITE);
    }
    else if (seleccionCorte == 1)
    {
      spriteSetCorte.fillRoundRect(70, 80, 150, 5, 2, TFT_BLUE);
      //spriteSetCorte.fillRoundRect(128, 80, 55, 5, 2, TFT_WHITE);
    }

    spriteSetCorte.setTextDatum(TR_DATUM);
    spriteSetCorte.setTextFont(7);
    //spriteSetCorte.setCursor(200, 90);
    spriteSetCorte.setTextColor(TFT_WHITE);
    spriteSetCorte.drawFloat(estado.corteVoltajeMinimo / 100.00, 2, 200, 90);

    //spriteSetCorte.print(estado.corteVoltajeMinimo / 100.00);
    spriteSetCorte.pushSprite(20, 20);
  }
}

void TFT_Set_Corte_Tiempo(void)
{
  if (strcmp(estado.pantalla, "setCorte_Tiempo") == 0)
  {

    spriteSetCorte.fillRect(5, 50, 270, 145, TFT_BLUE);

    if (seleccionCorte == 60)
    {
      spriteSetCorte.fillRoundRect(70, 80, 150, 5, 2, TFT_BLUE);
      spriteSetCorte.fillRoundRect(73, 80, 60, 5, 2, TFT_WHITE);
    }
    else if (seleccionCorte == 1)
    {
      spriteSetCorte.fillRoundRect(70, 80, 150, 5, 2, TFT_BLUE);
      //spriteSetCorte.fillRoundRect(128, 80, 55, 5, 2, TFT_WHITE);
    }

    spriteSetCorte.setTextDatum(TR_DATUM);
    spriteSetCorte.setTextFont(7);
    //spriteSetCorte.setCursor(200, 90);
    spriteSetCorte.setTextColor(TFT_WHITE);
    spriteSetCorte.drawNumber(estado.corteTiempo / 60, 140, 90);
    spriteSetCorte.drawString(":", 150, 90);
    spriteSetCorte.drawNumber(estado.corteTiempo - (int)((estado.corteTiempo / 60) * 60), 210, 90);
    spriteSetCorte.pushSprite(20, 20);
  }
}

void TFT_Set_Corte_Temperatura(void)
{
  if (strcmp(estado.pantalla, "setCorte_Temperatura") == 0)
  {

    spriteSetCorte.fillRect(5, 50, 270, 145, TFT_BLUE);

    spriteSetCorte.fillRoundRect(70, 80, 150, 5, 2, TFT_BLUE);

    spriteSetCorte.setTextDatum(TR_DATUM);
    spriteSetCorte.setTextFont(7);
    spriteSetCorte.setTextColor(TFT_WHITE);
    spriteSetCorte.drawNumber(estado.corteTemperatura, 160, 90);
    spriteSetCorte.pushSprite(20, 20);
  }
}

void TFT_VIN(void)
{
  tft.setTextSize(1); // set text size multiplier to 1

  if (estado.setCorteVoltajeMinimo)
    tft.fillRect(5, 145, 65, 50, TFT_WHITE);
  else
    tft.fillRect(5, 145, 65, 50, TFT_GREY);

  tft.fillRect(5, 145, 65, 15, TFT_DARKGREY);
  tft.drawRect(5, 145, 65, 50, TFT_BLACK);

  tft.setTextColor(TFT_WHITE); // Font blanco.. Sin color de fondo
  tft.setTextFont(1);
  tft.setCursor(23, 150); // Set "cursor" at top left corner of display (0,0) and select font
  tft.println("V MIN");   // Cursor will move to next line automatically during printing with 'tft.println'
  tft.setTextColor(TFT_BLACK);
  tft.setTextFont(2);
  tft.setCursor(23, 168); // Set "cursor" at top left corner of display (0,0) and select font
  tft.println(estado.corteVoltajeMinimo / 100.00);
}
void TFT_Tiempo(void)
{
  tft.setTextDatum(TL_DATUM);
  tft.setTextSize(1); // set text size multiplier to 1
  if (estado.setCorteTiempo)
    tft.fillRect(75, 145, 65, 50, TFT_WHITE);
  else
    tft.fillRect(75, 145, 65, 50, TFT_GREY);
  tft.fillRect(75, 145, 65, 15, TFT_DARKGREY);
  tft.drawRect(75, 145, 65, 50, TFT_BLACK);
  tft.setTextColor(TFT_WHITE); // Font blanco.. Sin color de fondo
  tft.setTextFont(1);
  tft.setCursor(91, 150); // Set "cursor" at top left corner of display (0,0) and select font
  tft.println("TIEMPO");  // Cursor will move to next line automatically during printing with 'tft.println'
  tft.setTextColor(TFT_BLACK);
  tft.setTextFont(2);
  //tft.setCursor(92, 168); // Set "cursor" at top left corner of display (0,0) and select font
  //tft.println(estado.corteTiempo);
  tft.drawNumber(estado.corteTiempo / 60, 90, 170);
  tft.drawString(":", 110, 170);
  tft.drawNumber(estado.corteTiempo - (int)((estado.corteTiempo / 60) * 60), 120, 170);
}
void TFT_Temp(void)
{
  tft.setTextSize(1); // set text size multiplier to 1
  if (estado.setCorteTemperatura)
    tft.fillRect(145, 145, 65, 50, TFT_WHITE);
  else
    tft.fillRect(145, 145, 65, 50, TFT_GREY);

  tft.fillRect(145, 145, 65, 15, TFT_DARKGREY);
  tft.drawRect(145, 145, 65, 50, TFT_BLACK);
  tft.setTextColor(TFT_WHITE); // Font blanco.. Sin color de fondo
  tft.setTextFont(1);
  tft.setCursor(167, 150); // Set "cursor" at top left corner of display (0,0) and select font
  tft.println("TEMP");     // Cursor will move to next line automatically during printing with 'tft.println'
  tft.setTextColor(TFT_BLACK);
  tft.setTextFont(2);
  tft.setCursor(169, 168); // Set "cursor" at top left corner of display (0,0) and select font
  tft.println(estado.corteTemperatura);
}

void TFT_Pantalla_Inicial(void)
{
  tft.fillScreen(TFT_BLUE);
  tft.fillRect(0, 0, 320, 30, TFT_WHITE);
  tft.drawLine(0, 30, 320, 30, TFT_BLACK);
  tft.setTextColor(TFT_BLACK); // Font blanco.. Sin color de fondo
  tft.setTextSize(1);          // set text size multiplier to 1
  tft.setTextFont(4);
  tft.setCursor(4, 4);  // Set "cursor" at top left corner of display (0,0) and select font
  tft.println("MODO "); // Cursor will move to next line automatically during printing with 'tft.println'

  // Recuadro de SET
  tft.fillRoundRect(5, 40, 205, 100, 10, TFT_WHITE);
  tft.drawRoundRect(5, 40, 205, 100, 10, TFT_BLACK);

  // Cortes

  TFT_VIN();
  TFT_Tiempo();
  TFT_Temp();

  // Recuadro Footer
  tft.fillRect(0, 200, 320, 40, TFT_WHITE);
  tft.drawRect(0, 200, 320, 40, TFT_BLACK);

  // RPM y TEMP
  tft.setTextColor(TFT_BLACK); // Font blanco.. Sin color de fondo
  tft.setTextSize(1);          // set text size multiplier to 1
  tft.setTextFont(2);
  tft.setCursor(45, 204); // Set "cursor" at top left corner of display (0,0) and select font
  tft.println("TEMP:");   // Cursor will move to next line automatically during printing with 'tft.println'
  tft.setCursor(45, 220); // Set "cursor" at top left corner of display (0,0) and select font
  tft.println("SPEED:");  // Cursor will move to next line automatically during printing with 'tft.println'

  TFT_Modo();   // Dibujo el Modo
  TFT_Estado(); // Dibujo el Estado
}

void TFT_Creacion_Sprites(void)
{
  // Creacion de Sprite COOLER
  spriteCooler.setColorDepth(8);
  spriteCooler.createSprite(40, 40); // horizontal / Vertical
  spriteCooler.fillSprite(TFT_TRANSPARENT);

  spriteCooler.drawCircle(20, 20, 15, TFT_BLUE);
  spriteCooler.drawCircle(20, 20, 14, TFT_BLUE);
  spriteCooler.fillCircle(20, 20, 14, TFT_WHITE);

  spriteCooler.fillTriangle(20, 20, 17, 12, 23, 12, TFT_BLACK);
  spriteCooler.fillTriangle(17, 12, 23, 12, 20, 10, TFT_BLACK);

  spriteCooler.fillTriangle(20, 20, 12, 17, 12, 23, TFT_BLACK);
  spriteCooler.fillTriangle(12, 23, 12, 17, 10, 20, TFT_BLACK);

  spriteCooler.fillTriangle(20, 20, 28, 17, 28, 23, TFT_BLACK);
  spriteCooler.fillTriangle(28, 17, 28, 23, 30, 20, TFT_BLACK);

  spriteCooler.fillTriangle(20, 20, 17, 28, 23, 28, TFT_BLACK);
  spriteCooler.fillTriangle(17, 28, 23, 28, 20, 30, TFT_BLACK);
  // --------------------------------

  // creacion prohibido cambio de modo
  spriteProhibidoCambioModo.setColorDepth(8);
  spriteProhibidoCambioModo.createSprite(280, 200); // horizontal / Vertical
  spriteProhibidoCambioModo.fillSprite(TFT_BLACK);
  spriteProhibidoCambioModo.fillRect(5, 5, 270, 45, TFT_WHITE);
  spriteProhibidoCambioModo.fillRect(5, 50, 270, 145, TFT_BLUE);
  spriteProhibidoCambioModo.setTextFont(4);
  spriteProhibidoCambioModo.setTextColor(TFT_BLACK);
  spriteProhibidoCambioModo.drawString("PROHIBIDO", 75, 15);
  spriteProhibidoCambioModo.setTextFont(2);
  spriteProhibidoCambioModo.setCursor(10, 80);
  spriteProhibidoCambioModo.setTextColor(TFT_WHITE);
  spriteProhibidoCambioModo.println("Debes PARAR antes de cambiar de modo");

  // creacion pantalla Set Corte
  spriteSetCorte.setColorDepth(8);
  spriteSetCorte.createSprite(280, 200); // horizontal / Vertical
  spriteSetCorte.fillSprite(TFT_BLACK);
  spriteSetCorte.fillRect(5, 5, 270, 45, TFT_WHITE);
  spriteSetCorte.fillRect(5, 50, 270, 145, TFT_BLUE);
  spriteSetCorte.setTextFont(4);
  spriteSetCorte.setTextColor(TFT_BLACK);
  spriteSetCorte.drawString("Set Corte", 75, 15);
}

void TFT_SpriteCooler(void)
{
  velocidadCooler = estado.coolerDisipadorPotencia;

  if (strcmp(estado.pantalla, "principal") == 0)
  {
    if (velocidadCooler == 0)
    {
      dibujarCoolerAnt = millis();
      tft.setPivot(20, 220);
      rotacionCooler = 0;
      spriteCooler.pushRotated(rotacionCooler, TFT_TRANSPARENT);
    }
    else if ((dibujarCoolerAnt + (600 / velocidadCooler)) < millis())
    {
      dibujarCoolerAnt = millis();
      tft.setPivot(20, 220);
      spriteCooler.pushRotated(rotacionCooler, TFT_TRANSPARENT);
      rotacionCooler = rotacionCooler + 10;
      if (rotacionCooler > 85)
        rotacionCooler = 0;
    }
  }
}

void TFT_DibujaPantallaPrincipal(void)
{
  if ((strcmp(estado.pantalla, "prohibido") == 0) and ((millis() - timeoutMenuAnt) > timeoutMenu))
  {
    TFT_Pantalla_Inicial();
    strcpy(estado.pantalla, "principal");
  }
}

void TFT_DibujaSetSeleccion(void)
{
  if ((millis() - timeoutSetSeleccionAnt) > timeoutSetSeleccion)
  {
    estado.setSeleccion = 10;
  }
}

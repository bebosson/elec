void    main()
{


if(display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
  for(;;); // Don't proceed, loop forever
  }
}
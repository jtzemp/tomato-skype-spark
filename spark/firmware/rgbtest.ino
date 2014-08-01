struct Rgb
{
  int red;
  int green;
  int blue;
};

Rgb scanRgb(String color);
void printRgb(Rgb color);

void setup() {
    Serial.begin(9600);
    delay(8000);

    Serial.println("Hello Computer, this is the spark.io");

    printRgb(scanRgb(String("000000")));
    printRgb(scanRgb(String("000102")));
    printRgb(scanRgb(String("123456")));
    printRgb(scanRgb(String("AABBCC")));
    printRgb(scanRgb(String("FFAAFF")));
    printRgb(scanRgb(String("CCZZCC")));
    printRgb(scanRgb(String("FsF")));
}

void loop() {
}

Rgb scanRgb(String color)
{
   Serial.print("color: ");
   Serial.println(color);

   struct Rgb result = {0,0,0};
   if (color.length() == 6){
    int red   = 0;
    int green = 0;
    int blue  = 0;
    char redc[3];
    char greenc[3];
    char bluec[3];

    color.substring(0, 2).toCharArray(redc,   sizeof(redc));
    color.substring(2, 4).toCharArray(greenc, sizeof(greenc));
    color.substring(4, 6).toCharArray(bluec,  sizeof(bluec));

    sscanf(redc,   "%2X", &red);
    sscanf(greenc, "%2X", &green);
    sscanf(bluec,  "%2X", &blue);

    result.red   = red;
    result.green = green;
    result.blue  = blue;
   }
   return result;
}

void printRgb(Rgb color) {
    Serial.print("RGB HEX: ");
    Serial.print(color.red);
    Serial.print(",");
    Serial.print(color.green);
    Serial.print(",");
    Serial.print(color.blue);

    Serial.println("");
    Serial.println("");
}

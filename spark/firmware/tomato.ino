#include <stdio.h>

int setTomatoColor(String color);
int setRgbColor(String color);
int blinkRepeat(String times);

#define LED   D7
#define RED   A5
#define GREEN A6
#define BLUE  A7


void setup()
{
  //Register Spark function
  Spark.function("tomato", setTomatoColor);
  Spark.function("blinky", blinkRepeat);
  Spark.function("rgb",    setRgbColor);

  pinMode(LED,   OUTPUT);
  pinMode(RED,   OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE,  OUTPUT);
  blinkRepeat("5");

  // startup sequence
  setTomatoColor("RED");
  delay(750);
  setTomatoColor("GREEN");
  delay(750);
  setTomatoColor("BLUE");
  delay(750);
  setTomatoColor("OFF");

  delay(200);
  setTomatoColor("ALL");
  delay(200);
  setTomatoColor("OFF");
  delay(200);
  setTomatoColor("ALL");
  delay(200);
  setTomatoColor("OFF");
}

void loop()
{
  // Nothing to do here
}


/*******************************************************************************
 * Function Name  : setTomatoColor
 * Description    : Parses the incoming API commands and sets the color of the
                    tomato
 * Input          : tomato colors
                    e.g.: RED
                          GREEN
                          BLUE
                          ALL
                          OFF
 * Output         : LEDs will turn on or off
 * Return         : 1 on success and -1 on fail
 *******************************************************************************/

int setTomatoColor(String color)
{
    if(color.substring(0,3) == "RED")
    {
        analogWrite(RED,   255);
        analogWrite(GREEN, 0);
        analogWrite(BLUE,  0);
        return 1;
    }

    if(color.substring(0,4) == "BLUE")
    {
        analogWrite(RED,   0);
        analogWrite(GREEN, 0);
        analogWrite(BLUE,  255);
        return 1;
    }

    if(color.substring(0,5) == "GREEN")
    {
        analogWrite(RED,   0);
        analogWrite(GREEN, 255);
        analogWrite(BLUE,  0);
        return 1;
    }

    if(color.substring(0,3) == "ALL")
    {
        analogWrite(RED,   255);
        analogWrite(GREEN, 255);
        analogWrite(BLUE,  255);
        return 1;
    }

    if(color.substring(0,3) == "OFF")
    {
        analogWrite(RED,   0);
        analogWrite(GREEN, 0);
        analogWrite(BLUE,  0);
        return 1;
    }

    return -1;
}

/*******************************************************************************
 * Function Name  : setRgbColor
 * Description    : Parses the incoming API commands and sets the color of the
                    leds based on the RGB hex code
 * Input          : tomato colors
                    e.g.: FFFFFF
                          000000
                          CCCCCC
 * Output         : LEDs will turn on/off/PWM
 * Return         : 1 on success and -1 on fail
 *******************************************************************************/


int setRgbColor(String color)
{
    int red   = 0;
    int green = 0;
    int blue  = 0;
    int result = 1;

    if ( sscanf(color.substring(0,2).c_str(), "%X", red) &&
         sscanf(color.substring(2,2).c_str(), "%X", green) &&
         sscanf(color.substring(4,2).c_str(), "%X", blue) &&
         (red   >=0 && red   <= 255) &&
         (green >=0 && green <= 255) &&
         (blue  >=0 && blue  <= 255) )
    {
        analogWrite(RED,   red);
        analogWrite(GREEN, green);
        analogWrite(BLUE,  blue);
    }
    else
    {
        blinkRepeat("3");
        delay(1000);
        analogWrite(RED,   0);
        analogWrite(GREEN, 0);
        analogWrite(BLUE,  0);
        result = -1;
    }

    return result;
}

/*******************************************************************************
 * Function Name  : blinkRepeat
 * Description    : Parses the incoming API commands and blinks the LED
 * Input          : A String that we can turn into an integer
 * Output         : LED will turn on and off a specified # of times
 * Return         : int # of times to blink
 *******************************************************************************/


int blinkRepeat(String count)
{
    int comparison = atoi(count.c_str());
    for (int i = 0; i < comparison; i += 1)
    {
        digitalWrite(LED, HIGH);
        delay(200);
        digitalWrite(LED, LOW);
        delay(200);
    }
    return comparison;
}

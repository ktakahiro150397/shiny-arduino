#include "Mouse.h"

void setup()
{
    // put your setup code here, to run once:
    pinMode(13, OUTPUT);

    Mouse.begin();
}

void loop()
{
    // put your main code here, to run repeatedly:
    flashLED(13);

    // Mouse.move(100, 200, 0);

    delay(5 * 1000);
}

void flashLED(int port)
{
    digitalWrite(port, HIGH);
    delay(100);
    digitalWrite(port, LOW);
}

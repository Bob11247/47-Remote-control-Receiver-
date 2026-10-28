Код для приемника:
#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver(2000, 11, 8, 10, false);

void setup()
{
    driver.init();

    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen))
    {
        switch (buf[0])
        {
        case 'a':
            digitalWrite(6, HIGH);
            break;
        case 'b':
            digitalWrite(6, LOW);
            break;
        case 'c':
            digitalWrite(7, HIGH);
            break;
        case 'd':
            digitalWrite(7, LOW);
            break;
        }
    }
}

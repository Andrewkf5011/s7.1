#include <mbed.h>
#include <EthernetInterface.h>
#include <rtos.h>
#include <string>
#include <C12832.h>
#include "communications.h"

int main()
{
    C12832 lcd(D11, D13, D12, D7, D10);

    Reciever reciever;

    while(1)
    {
        string message = reciever.getMessage();

        if(!message.empty())
        {
            lcd.cls();
            lcd.locate(0,0);
            lcd.printf("\"%s\"", message.c_str());
        }
    }
}

#include "mbed.h"


DigitalOut led(LED1);

int main()
{

    while(1) {
        
        wait(1); // 1 second
        led = !led; // Toggle LED
        
    }

}

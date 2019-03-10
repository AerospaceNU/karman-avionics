#include "mbed.h"
#include "Data.h"


int main()
{
	Data data;

    while(1) {
        
        data.getData();
        data.processData();

        wait_ms(50);
        printf("%f\r\n", data.x(0));

    }

}

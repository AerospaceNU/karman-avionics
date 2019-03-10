#include "mbed.h"
#include "Data.h"

#include "PreFlight.h"
#include "PoweredAscent.h"
#include "CoastAscent.h"


int main()
{
	Data data;
	int stateNum = 0;

	PreFlight preFlight;
	PoweredAscent poweredAscent;
	CoastAscent coastAscent;

	State states[] = {preFlight, poweredAscent, coastAscent};

    while(1) {
        
        data.getData();
        data.processData();

        stateNum += states[stateNum].run(&data);

        wait_ms(50);

    }

}

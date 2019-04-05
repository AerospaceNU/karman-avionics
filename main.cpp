#include "mbed.h"
#include "Data.h"
#include "SD/SD.h"

#include "State.h"
#include "Apogee.h"
#include "PreFlight.h"
#include "Separation.h"
#include "PoweredAscent.h"
#include "CoastAscent1.h"
#include "CoastAscent2.h"
#include "CoastDescent.h"
#include "DrogueDeploy.h"
#include "DrogueDescent.h"
#include "MainDeploy.h"
#include "MainDescent.h"
#include "PostFlight.h"

#include "SDFileSystem.h"

int main()
{
	Data data;
	int stateNum = 0;

	SD sd;

	PreFlight preFlight;
	PoweredAscent poweredAscent1;
	Separation separation;
	CoastAscent1 coastAscent1;
	PoweredAscent poweredAscent2;
	CoastAscent2 coastAscent2;
	Apogee apogee;
	CoastDescent coastDescent;
	DrogueDeploy drogueDeploy;
	DrogueDescent drogueDescent;
	MainDeploy mainDeploy;
	MainDescent mainDescent;
	PostFlight postFlight;


	State states[] = {preFlight,
					  poweredAscent1,
					  separation,
					  coastAscent1,
					  poweredAscent2,
					  coastAscent2,
					  apogee,
					  coastDescent,
					  drogueDeploy,
					  drogueDescent,
					  mainDeploy,
					  mainDescent,
					  postFlight};


    while(1) {
        
        data.getData();
        data.processData();

        stateNum += states[stateNum].run(&data);

        wait_ms(50);

    }

}

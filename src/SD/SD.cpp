/*
 * SD.cpp
 *
 *  Created on: Apr 4, 2019
 *      Author: 12013
 */

#include <SD/SD.h>

bool init = false;
char* fileName;
SD::SD() {

	if (!init) {	//Initialization function, checks to find an unused file name
		printf("\rHello World!\n\r");
		  wait_ms(150);
		init = true;
		int count = 0;
		char* core = "/sd/mydir/flightdata";
		size_t len = strlen(core);
		char* newName = new char[len + 6];
		strcpy(newName, core);
		newName[len] = count;newName[len+1] = '.' ;newName[len+2] = 'c' ;newName[len+3] = 's' ;newName[len+4] = 'v' ;newName[len+5] = '\0';
		FILE *fp = fopen(newName, "r");
		while(ftell(fp) != 0){
			count++;
			strcpy(newName, core);
			newName[len] = count;newName[len+1] = '.' ;newName[len+2] = 'c' ;newName[len+3] = 's' ;newName[len+4] = 'v' ;newName[len+5] = '\0';
			fp = fopen(newName, "r");
		}
		fprintf(fp,"HEADER\n");
		fprintf(fp, "%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", "GPS Data (GPS)", "Accel X (BNO055)", "Accel Y (BNO055)",
				"Accel Z (BNO055)", "Gyro X (BNO055)", "Gyro Y (BNO055)", "Gyro Z (BNO055)" , "HG Accel X (ADXL377)",
				"HG Accel Y (ADXL377)", "HG Accel Z (ADXL377)", "Press (MS5607)", "Temp (MS5607)", "Alt (MS5607)");
		fclose(fp);
		fileName = newName;
		if(fopen(newName, "r") == NULL){	//Error report incase something gets screwed up
			fclose(fp);
			errorLog();
		}
	}
}



SD::~SD() {
	// TODO Auto-generated destructor stub
}

void SD::writeRaw(Data *data){
	/*Format: "GPS Data (GPS)", "Accel X (BNO055)", "Accel Y (BNO055)",
	"Accel Z (BNO055)", "Gyro X (BNO055)", "Gyro Y (BNO055)", "Gyro Z (BNO055)" , "HG Accel X (ADXL377)",
	"HG Accel Y (ADXL377)", "HG Accel Z (ADXL377)", "Press (MS5607)", "Temp (MS5607)", "Alt (MS5607)"*/



}

void SD::errorLog(){
	FILE *fp2 = fopen("/sd/mydir/activityLog.txt", "w");
	//TODO: Fix below to include file name in the error message
	char* message = "Could not open file "; //+ fileName + " for read\n\r";
	fprintf(fp2, message);
	fclose(fp2);
}

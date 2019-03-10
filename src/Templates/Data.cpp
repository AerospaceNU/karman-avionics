/*
 * Data.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: Adam Mirza
 */

#include "Data.h"

using namespace Eigen;

// declare objects here (sensors and filters)
BNO055 bno(PB_9, PB_8);
ADXL377 adxl377;
MS5607SPI ms5607(PA_7, PA_6, PA_5, PD_14);

Serial gps(PG_14, PG_9);
GPS gpsData;


Data::Data() {

	x.resize(6);
	z.resize(15);

	bno.setmode(OPERATION_MODE_AMG);
	bno.set_accel_units(MPERSPERS);
	bno.set_anglerate_units(RAD_PER_SEC);
	bno.setpowermode(POWER_MODE_NORMAL);

	adxl377.ADXL377_init();


}

Data::~Data() {
	// TODO Auto-generated destructor stub
}


void Data::getData() {

	// call get data functions for each sensor
	// BNO055 imu (accel and gyro)
	bno.get_accel();
	bno.get_gyro();

	// ADXL377 HighGAccel
	adxl377.getAccel();

	// ms5607 altimeter
	ms5607Data.pressure = (double) ms5607.getPressure();
	ms5607Data.temperature = (double) ms5607.getTemperature();
	ms5607Data.altitude = (double) ms5607.getAltitude((int) ms5607Data.pressure);

	// GPS
	gpsData.getGPS(&gps);

	z(0) = bno.accel.x;
	z(1) = bno.accel.y;
	z(2) = bno.accel.z;

	z(3) = bno.gyro.x;
	z(4) = bno.gyro.y;
	z(5) = bno.gyro.z;

}

void Data::processData() {

	// run filters AHRS, then UKF

	x(0) = z(0);

}

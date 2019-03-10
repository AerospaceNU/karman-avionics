/*
 * Data.h
 *
 *  Created on: Mar 6, 2019
 *      Author: Adam Mirza
 */

#ifndef TEMPLATES_DATA_H_
#define TEMPLATES_DATA_H_

#include "Dense"
#include "mbed.h"

#include "BNO055.h"
#include "ADXL377.h"
#include "MS5607SPI.h"

#include "GPS.h"

class Data {

	typedef struct ms5607_data_s{
		double pressure;
		double temperature;
		double altitude;
	}ms5607_data_t;

public:
	Data();
	virtual ~Data();

	void getData(void);
	void processData(void);

	Eigen::Quaterniond q;
	Eigen::VectorXd x;
	Eigen::VectorXd z;

	ms5607_data_t ms5607Data;

};

#endif /* TEMPLATES_DATA_H_ */

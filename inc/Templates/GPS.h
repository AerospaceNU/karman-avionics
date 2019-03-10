/*
 * GPS.h
 *
 *  Created on: Mar 3, 2019
 *      Author: Adam Mirza
 */

#ifndef GPS_GPS_H_
#define GPS_GPS_H_


#include <stdint.h>
#include <vector>
#include <string>
#include <iostream>
#include "mbed.h"

class GPS {

	//Struct for ggadata. GGA holds GPS fix data mostly (position)
	typedef struct ggaData_s{
		bool isNew;
		float time;
		float lat;
		std::string north_south;
		float longi;
		std::string east_west;
		int gps_quality;
		uint8_t num_sats[2];
		float dil_precision;
		float alt;
		std::string alt_units;
		float alt_dif;
		std::string dif_units;
		float data_age;
		uint16_t  station_id;
		std::string chksum;
		//std::uint8_t chksum[2];
	} ggaData_t;

	typedef struct rmcData_s{
		bool isNew;
		float time;
		std::string stat;
		float lat;
		std::string north_south;
		float longi;
		// east = 0, west = 1
		std::string east_west;
		float spd_knots;
		float track;
		//ddmmyy
		float date;
		float mag_var;
		std::string east_west_mag;
		std::string chksum;
		//std::uint8_t chksum;
	} rmcData_t;

	//Struct for VTG, containsdegree values, speed
	typedef struct vtgData_s{
		float degrees;
		std::string truth;
		float degrees_magnetic;
		std::string mag_truth;
		float spd_knots;
		std::string knots;
		float spd_kph;
		std::string kph;
		std::string chksum;
		//std::uint8_t chksum;
	} vtgData_t;

public:

	GPS();
	virtual ~GPS();

	void getGPS(Serial *gps);

	int listen;
	ggaData_t gga;
	rmcData_t rmc;
	vtgData_t vtg;

private:

	void parseGPS(std::string gps_input);
	int gga_parse(std::string gps_input);
	int rmc_parse(std::string gps_input);
	int vtg_parse(std::string gps_input);
	std::string data_pull(int start, int end, std::string gps_input);
	void convertGPS(void);

	char byteIn;
	char s[5][256];
	int i;



};

#endif /* GPS_GPS_H_ */

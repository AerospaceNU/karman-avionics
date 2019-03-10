/*
 * GPS.cpp
 *
 *  Created on: Mar 3, 2019
 *      Author: Adam Mirza
 */

#include "GPS.h"

GPS::GPS() {

	i = 0;
	byteIn = ' ';

	this->listen = 0;
	this->gga.alt = 0;
	this->gga.alt_dif = 0;
	this->gga.alt_units = "";
	this->gga.chksum = "";
	this->gga.data_age = 0;
	this->gga.dif_units = "";
	this->gga.dil_precision = 0;
	this->gga.east_west = "";
	this->gga.gps_quality = 0;
	this->gga.lat = 0;
	this->gga.longi = 0;
	this->gga.north_south = "";
	this->gga.num_sats[0] = 0;
	this->gga.num_sats[1] = 0;
	this->gga.station_id = 0;
	this->gga.time = 0;

	this->rmc.chksum = "";
	this->rmc.date = 0;
	this->rmc.east_west = "";
	this->rmc.east_west_mag = "";
	this->rmc.lat = 0;
	this->rmc.longi = 0;
	this->rmc.mag_var = 0;
	this->rmc.north_south = "";
	this->rmc.spd_knots = 0;
	this->rmc.stat = "";
	this->rmc.time = 0;
	this->rmc.track = 0;

	this->vtg.chksum = "";
	this->vtg.degrees = 0;
	this->vtg.degrees_magnetic = 0;
	this->vtg.knots = "";
	this->vtg.kph = "";
	this->vtg.mag_truth = "";
	this->vtg.spd_knots = 0;
	this->vtg.spd_kph = 0;
	this->vtg.truth = "";

}

GPS::~GPS() {
	// TODO Auto-generated destructor stub
}


void GPS::getGPS(Serial *gps){

	for(i = 0; i < 5; i++){

		int j = 0;
		do{
			byteIn = gps->getc();
			this->s[i][j] = byteIn;
			//pc.printf("%c",byteIn);
			j++;
		}while(byteIn != '\n');
		this->s[i][j] = '\0';

	}

	this->parseGPS(this->s[1]);
	this->parseGPS(this->s[2]);
	this->parseGPS(this->s[3]);
	this->parseGPS(this->s[4]);

	this->convertGPS();

}

void GPS::parseGPS(std::string gps_input) {

	std::string identifier = gps_input.std::string::substr(1, 2);
	bool debug = false;

	//Checks if the reciever is getting proper data (GP)
	if (identifier == "GP" && !debug) {
		this->listen = true;
		identifier = gps_input.std::string::substr(3, 3);

		//Sorts into data types
		if (identifier == "GGA") {
			this->gga_parse(gps_input);
			this->listen = 0;
			this->gga.isNew = true;


		} else if (identifier == "RMC") {
			this->rmc_parse(gps_input);
			this->listen = 1;
			this->rmc.isNew = true;


		} else if (identifier == "VTG") {
			this->vtg_parse(gps_input);
			this->listen = 2;


		} else {
			this->listen = -2;
		}

	} else {
		this->listen = -1;
	}

}


void GPS::convertGPS(){

	if(gga.isNew){
		gga.lat = floor(gga.lat/100) + (gga.lat - floor(gga.lat/100)*100)/60.0;
		gga.longi = floor(gga.longi/100) + (gga.longi - floor(gga.longi/100)*100)/60.0;
		gga.isNew = false;
	}

	if(rmc.isNew){
		rmc.lat = floor(rmc.lat/100) + (rmc.lat - floor(rmc.lat/100)*100)/60.0;
		rmc.longi = floor(rmc.longi/100) + (rmc.longi - floor(rmc.longi/100)*100)/60.0;
		rmc.isNew = false;
	}

}

int GPS::gga_parse(std::string gps_input){

    const int comma_max = 13;
    int temp_pos_arr[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    //Finds all comma positions in the string
    int pos = 6;
    int comma = 0;
    while(comma <= comma_max){
        if(pos > 90){
            break;
        }
        if (gps_input.std::string::substr(pos,1)==","){
            temp_pos_arr[comma] = pos + 1;
            comma++;
        }
        pos++;
    }
    this->gga.time = std::atof(data_pull(temp_pos_arr[0],temp_pos_arr[1],gps_input).c_str());
    this->gga.lat = std::atof(data_pull(temp_pos_arr[1],temp_pos_arr[2],gps_input).c_str());
    this->gga.north_south = (data_pull(temp_pos_arr[2],temp_pos_arr[3],gps_input));
    this->gga.longi = std::atof(data_pull(temp_pos_arr[3],temp_pos_arr[4],gps_input).c_str());
    this->gga.east_west = (data_pull(temp_pos_arr[4],temp_pos_arr[5],gps_input));
    this->gga.gps_quality = std::atoi(data_pull(temp_pos_arr[5],temp_pos_arr[6],gps_input).c_str());
    this->gga.num_sats[0] = std::atoi(gps_input.std::string::substr(temp_pos_arr[6], 1).c_str());
    this->gga.num_sats[1] = std::atoi(gps_input.std::string::substr(temp_pos_arr[6]+1, 1).c_str());
    this->gga.dil_precision = std::atof(data_pull(temp_pos_arr[7],temp_pos_arr[8],gps_input).c_str());
    this->gga.alt =  std::atof(data_pull(temp_pos_arr[8],temp_pos_arr[9],gps_input).c_str());
    this->gga.alt_units = (data_pull(temp_pos_arr[9],temp_pos_arr[10],gps_input));
    this->gga.alt_dif =  std::atof(data_pull(temp_pos_arr[10],temp_pos_arr[11],gps_input).c_str());
    this->gga.dif_units = (data_pull(temp_pos_arr[11],temp_pos_arr[12],gps_input));
    this->gga.data_age = std::atof(data_pull(temp_pos_arr[12],temp_pos_arr[13],gps_input).c_str());

    int temp_val = gps_input.std::string::length() -3;
    this->gga.chksum = (gps_input.std::string::substr(temp_val+1,2));

    return true;
}

int GPS::vtg_parse(std::string gps_input){

    const int comma_max = 8;
    int temp_pos_arr[9] = {0,0,0,0,0,0,0,0,0};

    //Finds all comma positions in the string
    int pos = 6;
    int comma = 0;
    while(comma <= comma_max){
        if(pos > 90){
            break;
        }
        if (gps_input.std::string::substr(pos,1)==","){
            temp_pos_arr[comma] = pos + 1;
            comma++;
        }
        pos++;
    }

    this->vtg.degrees =  std::atof(data_pull(temp_pos_arr[0],temp_pos_arr[1],gps_input).c_str());
    this->vtg.truth = (data_pull(temp_pos_arr[1],temp_pos_arr[2],gps_input));
    this->vtg.degrees_magnetic =  std::atof(data_pull(temp_pos_arr[2],temp_pos_arr[3],gps_input).c_str());
    this->vtg.mag_truth = (data_pull(temp_pos_arr[3],temp_pos_arr[4],gps_input));
    this->vtg.spd_knots = std::atof(data_pull(temp_pos_arr[4],temp_pos_arr[5],gps_input).c_str());
    this->vtg.knots = (data_pull(temp_pos_arr[5],temp_pos_arr[6],gps_input));
    this->vtg.spd_kph = std::atof(data_pull(temp_pos_arr[6],temp_pos_arr[7],gps_input).c_str());
    int temp_val = gps_input.std::string::length() -3;
    this->vtg.kph = (data_pull(temp_pos_arr[7],temp_pos_arr[8],gps_input));

    this->vtg.chksum = (gps_input.std::string::substr(temp_pos_arr[8],4));

    return true;
}

int GPS::rmc_parse(std::string gps_input){

    const int comma_max = 10;
    int temp_pos_arr[11] = {0,0,0,0,0,0,0,0,0,0};

    //Finds all comma positions in the string
    int pos = 6;
    int comma = 0;
    while(comma <= comma_max){
        if(pos > 90){
            break;
        }
        if (gps_input.std::string::substr(pos,1)==","){
            temp_pos_arr[comma] = pos + 1;
            comma++;
        }
        pos++;
    }

    this->rmc.time = std::atof(data_pull(temp_pos_arr[0],temp_pos_arr[1],gps_input).c_str());
    this->rmc.stat = (data_pull(temp_pos_arr[1],temp_pos_arr[2],gps_input));
    this->rmc.lat = std::atof(data_pull(temp_pos_arr[2],temp_pos_arr[3],gps_input).c_str());
    this->rmc.north_south = (data_pull(temp_pos_arr[3],temp_pos_arr[4],gps_input));
    this->rmc.longi = std::atof(data_pull(temp_pos_arr[4],temp_pos_arr[5],gps_input).c_str());
    this->rmc.east_west = (data_pull(temp_pos_arr[5],temp_pos_arr[6],gps_input));
    this->rmc.spd_knots= std::atof(data_pull(temp_pos_arr[6],temp_pos_arr[7],gps_input).c_str());
    this->rmc.track = std::atof(data_pull(temp_pos_arr[7],temp_pos_arr[8],gps_input).c_str());
    this->rmc.date = std::atof(data_pull(temp_pos_arr[8],temp_pos_arr[9],gps_input).c_str());
    this->rmc.mag_var= std::atof(data_pull(temp_pos_arr[9],temp_pos_arr[10],gps_input).c_str());
    this->rmc.east_west_mag = (data_pull(temp_pos_arr[10],temp_pos_arr[10]+2,gps_input));
    int temp_val = gps_input.std::string::length() -3;
    this->rmc.chksum = (gps_input.std::string::substr(temp_val+1,2));

    return true;
}

std::string GPS::data_pull(int start, int end, std::string gps_input){

    std::string temp = gps_input;

    if(gps_input.std::string::substr(start,(end-start)) == "," || (start == end-1)) {

        return "-0";
    }else {
        if (temp.std::string::substr(start + 1, 1) == ",") {
            return gps_input.std::string::substr(start, 1);
        }
        return gps_input.std::string::substr(start, (end - start));
    }

}

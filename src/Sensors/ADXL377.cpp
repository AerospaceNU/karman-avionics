#include "ADXL377.h"
#include "mbed.h"

// conversion factor 
float raw_to_voltage = 3300;
float conversion = 9.81*(1/6.5);
float sampleamount = 101; 

AnalogIn xaxis(PA_3);
AnalogIn yaxis(PC_0);
AnalogIn zaxis(PC_3);
AnalogIn temp(PF_3);

//constructor
ADXL377::ADXL377():HighGAccel()
{

}
    

//Initilize ADXL377
void ADXL377::ADXL377_init()
{

}

//Pull the measured values for all 3 axes of acceleration
//convert the value from output integer
void ADXL377::getAccel()
{
    //run record the raw data 100 time and find out the total and average 
    for(int x = 0; x<sampleamount; x++)
    {
    this->raw.x = xaxis.read();
    this->raw.y = yaxis.read();
    this->raw.z = zaxis.read();
    
    this->voltage.x = this->raw.x * 3300;
    this->voltage.y = this->raw.y * 3300;
    this->voltage.z = this->raw.z * 3300;
    
    this->total.x += this->voltage.x;
    this->total.y += this->voltage.y;
    this->total.z += this->voltage.z;
    }
    
    //find out average voltage for accleration conversion
    this->average.x = this->total.x/100;
    this->average.y = this->total.y/100;
    this->average.z = this->total.z/100;
    
    //convert voltage to acceleration for x,y,z axis 
    this->accel.x = conversion*(this->voltage.x - this->average.x);
    this->accel.y = conversion*(this->voltage.y - this->average.y);
    this->accel.z = conversion*(this->voltage.z - this->average.z);
    
    //print accleration for x,y,z axis 
    printf("acceleration x = %8.4f m/s^2\n", this->accel.x);
    printf("acceleration y = %8.4f m/s^2\n", this->accel.y);
    printf("acceleration z = %8.4f m/s^2\n", this->accel.z);

}

#ifndef ADXL377_H_
#define ADXL377_H_

#include "HighGAccel.h"

class ADXL377 : public HighGAccel
{
	public:
	Vectori_t raw;
	Vectord_t accel;
    Vectord_t voltage;
    Vectord_t total;
    Vectord_t average;
    
    float gvalue;
    
    
    ADXL377();
    
    void ADXL377_init(void);
    
    void getAccel(void);

};
    

#endif

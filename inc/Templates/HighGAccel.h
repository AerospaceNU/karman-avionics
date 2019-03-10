#ifndef HIGH_G_ACCEL_H_
#define HIGH_G_ACCEL_H_

#include "mbed.h"

class HighGAccel{

    public:

    typedef struct Vectord_s{
        double x;
        double y;
        double z;
    }Vectord_t;
    
    typedef struct Vectori_s{
        int x;
        int y;
        int z;
    }Vectori_t;
    
    HighGAccel();
    
    virtual void init(void);
    
    virtual void getAccel(void);   
    
};

#endif

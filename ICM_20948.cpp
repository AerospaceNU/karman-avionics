#include "mbed.h"
#include "ICM_20948.h"

PinName mosi;
PinName miso;
PinName scl;
SPI spi(mosi, miso, scl);

// Inertial Measurement Unit Class Constructor
// zero all variables and initialize pins/spi
// initialization function
ICM_20948 :: ICM_20948(PinName mosi, PinName miso, PinName scl, PinName csma): cs(csma) {
    //raw data structs
    accelRaw_t.x = 0;
    accelRaw_t.y = 0;
    accelRaw_t.z = 0;
    gyroRaw_t.x = 0;
    gyroRaw_t.y = 0;
    gyroRaw_t.z = 0;
    magRaw_t.x = 0;
    magRaw_t.y = 0;
    magRaw_t.z = 0;
    tempRaw_t.t = 0;

    //data structure
    accel_t.x = 0;
    accel_t.y = 0;
    accel_t.z = 0;
    gyro_t.x = 0;
    gyro_t.y = 0;
    gyro_t.z = 0;
    mag_t.x = 0;
    mag_t.y = 0;
    mag_t.z = 0;
    temp_t.t = 0;

}

void ICM_20948::init(void){

    //start the serial communications
    // start the spi library, hint: look in spi_Driver.h


    //give the sensor time to setup


    // write to registers to configure sensor
    // make sure power mode is enabled and all axes are enabled
    // hint: look for register definitions in LIS331.h
    writeRegister(USER_CTRL, I2C_IF_DIS);
    writeRegister(PWR_MGMT_1,DEVICE_RESET | SLEEP | CLKSEL);
    writeRegister(CNTL2,SRST);
    writeRegister(CNTL1,CONTINUOUS_MEASUREMENT_MODE_2);
    writeRegister(I2CDIS, I2CDISABLE);
    // delay 100 ms for setup
    // verify a sensor value using readRegister if you'd like
}

// accelerometer read data function
// converts and stores accelerometer reading to accel data struct in m/s^2
void ICM_20948::getAccel(void){
  //Set the values to zero
  this->accelRaw_t.x = 0;
  this->accelRaw_t.y = 0;
  this->accelRaw_t.z = 0;

  //Read the data
  this->accelRaw_t.x = readRegister(ACCEL_XOUT_L);
  this->accelRaw_t.y = readRegister(ACCEL_YOUT_L);
  this->accelRaw_t.z = readRegister(ACCEL_ZOUT_L);

  //Config the values
  this->accel_t.x = this->accelRaw_t.x / accelConversion;
  this->accel_t.y = this->accelRaw_t.y / accelConversion;
  this->accel_t.z = this->accelRaw_t.z / accelConversion;
}

// gyroscope read data function
// converts and stores gyro reading to gyro data struct in rad/sec
void ICM_20948::getGyro(void){
  //Gyro data zero
  this->gyroRaw_t.x = 0;
  this->gyroRaw_t.y = 0;
  this->gyroRaw_t.z = 0;

  // Gyro data
  this->gyroRaw_t.x = readRegister(GYRO_XOUT_L);
  this->gyroRaw_t.y = readRegister(GYRO_YOUT_L);
  this->gyroRaw_t.z = readRegister(GYRO_ZOUT_L);

  //Data
  this->gyro_t.x = this->gyroRaw_t.x / gyroConversion;
  this->gyro_t.y = this->gyroRaw_t.y / gyroConversion;
  this->gyro_t.z = this->gyroRaw_t.z / gyroConversion;
}

// magnetometer read data function
// converts and stores mag reading to mag data struct
void ICM_20948::getMag(void){
  //Gyro data zero
  this->magRaw_t.x = 0;
  this->magRaw_t.y = 0;
  this->magRaw_t.z = 0;

  // Gyro data
  this->magRaw_t.x = readRegister(HXL);
  this->magRaw_t.y = readRegister(HYL);
  this->magRaw_t.z = readRegister(HZL);

  //adjustment Values
  int adjx = spi.write(ASAX | READ);
  int adjy = spi.write(ASAY | READ);
  int adjz = spi.write(ASAZ | READ);
  //Data
  this->mag_t.x = (this->magRaw_t.x) * ((((adjx - 128) * 0.5)/(128)) + 1);
  this->mag_t.y = (this->magRaw_t.y) * ((((adjy - 128) * 0.5)/(128)) + 1);
  this->mag_t.z = (this->magRaw_t.z) * ((((adjz - 128) * 0.5)/(128)) + 1);
}

void ICM_20948::getTemp(){
    //Temp zero
    this->tempRaw_t.t = readRegister(TEMP_OUT_L);

    //Temp conversion
    this->temp_t.t = this->tempRaw_t.t / tempConversion;
  }




// conversion factor LSB/g divide raw value by this to get acceleration in g's
// hint: look under sensitivity in Mechanical Characteristics table in the data sheet
// read helper function
// should read axis and store properly into upper and lower halves of uint
// returns data as uint16
unsigned int ICM_20948::readRegister(int reg) {
  cs = 0;
  int raw = 0;
  spi.write(reg | READ);
  raw = raw << 8;
  spi.write(reg + 1 | READ);
  cs = 1;
  return raw;
}

void ICM_20948::writeRegister(int reg, int data) {
  cs = 0;
  spi.write(reg | WRITE);
  spi.write(data);
  cs = 1;
}

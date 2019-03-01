

#ifndef ICM_20948_H_

#define ICM_20948_H_

#include "mbed.h"
#include "SPI.h"

// wilson.na@husky.neu.edu

const int csICM_20948 = 22;

const double gyroConversion = 500;

const double accelConversion = 16;

const double tempConversion = 21;

#define READ 0x01
#define WRITE 0x00

//BANK 0
#define WHO_AM_I 0x00

#define USER_CTRL 0x03
#define LP_CONFIG 0x05

#define PWR_MGMT_1 0x06
#define PWR_MGMT_2 0x07

#define DELAY_TIMEH 0x28
#define DELAY_TIMEL 0x29

#define ACCEL_XOUT_H 0x2D
#define ACCEL_XOUT_L 0x2E
#define ACCEL_YOUT_H 0x2F
#define ACCEL_YOUT_L 0x30
#define ACCEL_ZOUT_H 0x31
#define ACCEL_ZOUT_L 0x32

#define GYRO_XOUT_H 0x33
#define GYRO_XOUT_L 0x34
#define GYRO_YOUT_H 0x35
#define GYRO_YOUT_L 0x36
#define GYRO_ZOUT_H 0x37
#define GYRO_ZOUT_L 0x38

#define TEMP_OUT_H 0x39
#define TEMP_OUT_L 0x3A

#define REG_BANK_SEL 0x7F

//BANK1
#define SELF_TEST_X_GYRO 0x02
#define SELF_TEST_Y_GYRO 0x03
#define SELF_TEST_Z_GYRO 0x04

#define SELF_TEST_X_ACCEL 0x0E
#define SELF_TEST_Y_ACCEL 0x0F
#define SELF_TEST_Z_ACCEL 0x10

//BANK2
#define GYRO_SMPLRT_DIV 0x00
#define GYRO_CONFIG_1 0x01
#define GYRO_CONFIG_2 0x02

#define ACCEL_SMPRLT_DIV_1 0x10
#define ACCEL_SMPRLT_DIV_2 0x11
#define ACCEL_INTEL_CTRL 0x12
#define ACCEL_WOM_THR 0x13
#define ACCEL_CONFIG 0x14
#define ACCEL_CONFIG_2 0x15

#define TEMP_CONFIG 0x53

//MANETOMETER REGISTERS

#define WIA 0x00
#define INFO 0x01
#define ST1 0x02

#define HXL 0x03
#define HXH 0x04
#define HYL 0x05
#define HYH 0x06
#define HZL 0x07
#define HZH 0x08

#define ST2 0x09
#define CNTL1 0x0A
#define CNTL2 0x0B
#define ASTC 0x0C
#define TS1 0x0D
#define TS2 0x0E

#define I2CDIS 0x0F
#define ASAX 0x10
#define ASAY 0x11
#define ASAZ 0x12
#define RSV 0x13

//USER_CTRL register
#define I2C_IF_DIS (1 << 4)

//PWR_MGMT_1 register values
#define DEVICE_RESET (1 << 7)
#define SLEEP (0 << 6)
#define CLKSEL (1 << 0)

//PWR_MGMT_2 register
#define DISABLE_ACCEL (0 << 3)
#define DISABLE_GYRO (0 << 0)

//REG_BANK_SEL
#define BANK1 (0 << 4)
#define BANK2 (1 << 4)
#define BANK3 (2 << 4)
#define BANK4 (3 << 4)

//GYRO_CONFIG
#define GYRO_FCHOICE (1 << 0)
#define GYRO_FS_SEL (1 << 1)
#define GYRO_DLPFCG (2 << 3)

//GYRO_CONFIG_2

//ACCEL_CONFIG
#define ACCEL_FCHOICE (1 << 0)
#define ACCEL_FS_SEL (3 << 1)
#define ACCEL_DLPFCFG (2 << 3)

//TEMP_CONFIG
#define TEMP_DLPFCFG (2 << 0)


//GYRO Registers
#define WIA 0x00
#define INFO 0x01
#define STI 0x02
#define HXL 0x03
#define HXH 0x04
#define HYL 0x05
#define HYH 0x06
#define HZL 0x07
#define HZH 0x08
#define ST2 0x09
#define CNTL1 0x0A
#define CNTL2 0x0B
#define ASTC 0x0C
#define TS1 0x0D
#define TS2 0x0E
#define I2CDIS 0x0F
#define ASAX 0x10
#define ASAY 0x11
#define ASAZ 0x12
#define RSV 0x13

//CNTL1
#define CONTINUOUS_MEASUREMENT_MODE_2 (3 << 1)
//CNTL2
#define SRST (1 << 0)
//I2CDIS
#define I2CDISABLE (00011011)

class ICM_20948{

  public:

  // raw accel data struct
  typedef struct{
    int x;
    int y;
    int z;
  }accelRaw;

  // raw gyro data struct
  typedef struct{
    int x;
    int y;
    int z;
  }gyroRaw;

  // raw magnetometer data struct
  typedef struct{
    int x;
    int y;
    int z;
  }magRaw;

  //raw temperature data
  typedef struct{
    int t;
  }tempRaw;

  // calibrated accel data struct
  typedef struct {
    float x;
    float y;
    float z;
    float temp;
  }accel;

  // calibrated gyro data struct
  typedef struct {
    float x;
    float y;
    float z;
  }gyro;

  // calibrated mag data struct
  typedef struct {
     float x;
     float y;
     float z;
  }mag;

  //calibrated temp data struct
  typedef struct {
     float t;
  }temp;

  //raw data structs
  accelRaw accelRaw_t;
  gyroRaw gyroRaw_t;
  magRaw magRaw_t;
  tempRaw tempRaw_t;

  //data structure
  accel accel_t;
  gyro gyro_t;
  mag mag_t;
  temp temp_t;

  PinName spi_mosi;
  PinName spi_miso;
  PinName spi_scl;
  PinName spi_csma;


  DigitalOut cs;

  // the function prototypes are to keep you on the right track

  ICM_20948(PinName mosi, PinName miso, PinName scl, PinName csma);
  ~ICM_20948();
  // sensor initialization function
  void init();

  // get data function, returns outputs to global variable
  void getAccel();
  void getGyro();
  void getMag();
  void getTemp();
  unsigned int readRegister(int reg);
  void writeRegister(int reg, int data);
};

#endif


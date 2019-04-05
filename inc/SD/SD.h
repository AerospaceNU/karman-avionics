/*
 * SD.h
 *
 *  Created on: Apr 4, 2019
 *      Author: 12013
 */
#include "mbed.h"
#include "SDFileSystem.h"
#include "Data.h"


#ifndef SD_SD_H_
#define SD_SD_H_

class SD {
public:

	SD();
	virtual ~SD();
	void writeRaw(Data *data);
	void errorLog(void);
};

#endif /* SD_SD_H_ */

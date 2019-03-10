/*
 * CoastAscent1.h
 *
 *  Created on: Mar 9, 2019
 *      Author: Adam Mirza
 */

#ifndef STATES_COASTASCENT1_H_
#define STATES_COASTASCENT1_H_

#include "State.h"

class CoastAscent1 : public State {
public:
	CoastAscent1();
	virtual ~CoastAscent1();

	int run(Data *data);
};

#endif /* STATES_COASTASCENT1_H_ */

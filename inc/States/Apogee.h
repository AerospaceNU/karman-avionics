/*
 * Apogee.h
 *
 *  Created on: Mar 9, 2019
 *      Author: Adam Mirza
 */

#ifndef STATES_APOGEE_H_
#define STATES_APOGEE_H_

#include "State.h"

class Apogee : public State {
public:
	Apogee();
	virtual ~Apogee();

	int run(Data *data);

};

#endif /* STATES_APOGEE_H_ */

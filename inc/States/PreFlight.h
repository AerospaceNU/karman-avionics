/*
 * PreFlight.h
 *
 *  Created on: Mar 9, 2019
 *      Author: Adam Mirza
 */

#ifndef STATES_PREFLIGHT_H_
#define STATES_PREFLIGHT_H_

#include "State.h"

class PreFlight : public State {
public:
	PreFlight();
	virtual ~PreFlight();

	int run(Data *data);

};

#endif /* STATES_PREFLIGHT_H_ */

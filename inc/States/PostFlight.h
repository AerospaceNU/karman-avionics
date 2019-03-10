/*
 * PostFlight.h
 *
 *  Created on: Mar 9, 2019
 *      Author: Adam Mirza
 */

#ifndef STATES_POSTFLIGHT_H_
#define STATES_POSTFLIGHT_H_

#include "State.h"

class PostFlight : public State {
public:
	PostFlight();
	virtual ~PostFlight();

	int run(Data *data);

};

#endif /* STATES_POSTFLIGHT_H_ */

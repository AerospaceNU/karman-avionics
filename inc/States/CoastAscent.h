/*
 * CoastAscent.h
 *
 *  Created on: Mar 9, 2019
 *      Author: Adam Mirza
 */

#ifndef STATES_COASTASCENT_H_
#define STATES_COASTASCENT_H_

#include "State.h"

class CoastAscent : public State{
public:
	CoastAscent();
	virtual ~CoastAscent();

	int run(Data *data);
};

#endif /* STATES_COASTASCENT_H_ */

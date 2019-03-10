/*
 * CoastAscent2.h
 *
 *  Created on: Mar 9, 2019
 *      Author: Adam Mirza
 */

#ifndef STATES_COASTASCENT2_H_
#define STATES_COASTASCENT2_H_

#include "State.h"

class CoastAscent2 : public State {
public:
	CoastAscent2();
	virtual ~CoastAscent2();

	int run(Data *data);

};

#endif /* STATES_COASTASCENT2_H_ */

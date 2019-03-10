/*
 * CoastDescent.h
 *
 *  Created on: Mar 9, 2019
 *      Author: Adam Mirza
 */

#ifndef STATES_COASTDESCENT_H_
#define STATES_COASTDESCENT_H_

#include "State.h"

class CoastDescent : public State {
public:
	CoastDescent();
	virtual ~CoastDescent();

	int run(Data *data);

};

#endif /* STATES_COASTDESCENT_H_ */

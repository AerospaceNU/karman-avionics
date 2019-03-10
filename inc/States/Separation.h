/*
 * Separation.h
 *
 *  Created on: Mar 9, 2019
 *      Author: Adam Mirza
 */

#ifndef STATES_SEPARATION_H_
#define STATES_SEPARATION_H_

#include "State.h"

class Separation : public State {
public:
	Separation();
	virtual ~Separation();

	int run(Data *data);

};

#endif /* STATES_SEPARATION_H_ */

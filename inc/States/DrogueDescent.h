/*
 * DrogueDescent.h
 *
 *  Created on: Mar 9, 2019
 *      Author: Adam Mirza
 */

#ifndef STATES_DROGUEDESCENT_H_
#define STATES_DROGUEDESCENT_H_

#include "State.h"

class DrogueDescent : public State {
public:
	DrogueDescent();
	virtual ~DrogueDescent();

	int run(Data *data);

};

#endif /* STATES_DROGUEDESCENT_H_ */

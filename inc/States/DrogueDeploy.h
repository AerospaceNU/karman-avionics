/*
 * DrogueDeploy.h
 *
 *  Created on: Mar 9, 2019
 *      Author: Adam Mirza
 */

#ifndef STATES_DROGUEDEPLOY_H_
#define STATES_DROGUEDEPLOY_H_

#include "State.h"

class DrogueDeploy : public State {
public:
	DrogueDeploy();
	virtual ~DrogueDeploy();

	int run(Data *data);

};

#endif /* STATES_DROGUEDEPLOY_H_ */

/*
 * MainDeploy.h
 *
 *  Created on: Mar 9, 2019
 *      Author: Adam Mirza
 */

#ifndef STATES_MAINDEPLOY_H_
#define STATES_MAINDEPLOY_H_

#include "State.h"

class MainDeploy : public State {
public:
	MainDeploy();
	virtual ~MainDeploy();

	int run(Data *data);

};

#endif /* STATES_MAINDEPLOY_H_ */

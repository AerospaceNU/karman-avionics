/*
 * MainDescent.h
 *
 *  Created on: Mar 9, 2019
 *      Author: Adam Mirza
 */

#ifndef STATES_MAINDESCENT_H_
#define STATES_MAINDESCENT_H_

#include "State.h"

class MainDescent : public State {
public:
	MainDescent();
	virtual ~MainDescent();

	int run(Data *data);

};

#endif /* STATES_MAINDESCENT_H_ */

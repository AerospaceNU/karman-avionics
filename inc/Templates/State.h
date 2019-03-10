/*
 * State.h
 *
 *  Created on: Mar 9, 2019
 *      Author: Adam Mirza
 */

#ifndef TEMPLATES_STATE_H_
#define TEMPLATES_STATE_H_

#include "Data.h"

class State {

public:
	State();
	virtual ~State();

	virtual int run(Data *data);

};

#endif /* TEMPLATES_STATE_H_ */

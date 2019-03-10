/*
 * PoweredAscent.h
 *
 *  Created on: Mar 9, 2019
 *      Author: Adam Mirza
 */

#ifndef STATES_POWEREDASCENT_H_
#define STATES_POWEREDASCENT_H_

#include "State.h"

class PoweredAscent : public State {
public:
	PoweredAscent();
	virtual ~PoweredAscent();

	int run(Data *data);

};

#endif /* STATES_POWEREDASCENT_H_ */

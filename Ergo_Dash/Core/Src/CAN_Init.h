/*
 * CAN_Init.h
 *
 *  Created on: Feb 21, 2024
 *      Author: imjus
 */

/* The purpose of this class is to initialize CAN's low level and high
 * level resources. The constructor will initialize the entirety of CAN,
 * and the deinit function will be used for deinitialization.
 * This class should not be considered an object, but rather a set of
 * functions for the intialization process.*/

#ifndef SRC_CAN_INIT_H_
#define SRC_CAN_INIT_H_


/*This includes all stm32f5xx.h files, even the intermediary ones.
 * The files that this class will utilize the most the ones concerning CAN.*/
#include <stm32f4xx.h>
#include "Filter_Config.h"

class CAN_Init {
public:
	CAN_HandleTypeDef *hCAN;

	//Default Constructor (Does nothing)
	CAN_Init();
	// Initializes CAN.
	CAN_HandleTypeDef * CAN_Initialize(CAN_HandleTypeDef *hCAN, Filter_Config *fConfig);
	// Not so sure what to do with the destructor yet.
	virtual ~CAN_Init();
	// Deinitializes CAN.
	void CAN_deInit();
	// Create a function to configure the filter set up. Returns a pointer.
	// This pointer will be passed in Initialize for filter configuration.
};

#endif /* SRC_CAN_INIT_H_ */

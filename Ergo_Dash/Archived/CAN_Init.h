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

#ifndef INC_CAN_INIT_H_
#define INC_CAN_INIT_H_


/*This includes all stm32f5xx.h files, even the intermediary ones.
 * The files that this class will utilize the most the ones concerning CAN.*/
#include <stm32f4xx.h>
#include "Filter_Config.h"

class CAN_Init {
public:
	CAN_HandleTypeDef *hCAN;
	//Default Constructor (Does nothing)
	CAN_Init();
	// Initializes CAN, to be more robust and user friendly than the generated constructor in main.c.
	CAN_HandleTypeDef * CAN_Initialize(CAN_HandleTypeDef *phCAN, string instance, uint_32 prescaler, string mode,  Filter_Config *fConfig);
	// Deinitializes CAN, probably in case the CAN need to be switched from master to slave.
	void CAN_DeInit(CAN_HandleTypeDef *phCAN);
	// Default destructor.
	~CAN_Init();

	// Create a function to configure the filter set up. Returns a pointer.
	// This pointer will be passed in Initialize for filter configuration.
};

#endif /* SRC_CAN_INIT_H_ */

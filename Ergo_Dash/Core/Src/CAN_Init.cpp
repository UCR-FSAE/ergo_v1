/*
 * CAN_Init.cpp
 *
 *  Created on: Feb 21, 2024
 *      Author: imjus
 */

#include "CAN_Init.h"

	//Default Constructor (Does nothing)
CAN_Init::CAN_Init() {}

CAN_HandleTypeDef * CAN_Init::CAN_Initialize(CAN_HandleTypeDef *phCAN, Filter_Config *fConfig) {
	//1. Initialize CAN Low Level resources by implementing HAL_CAN_MSPInit()
		// MSPInit() is normally unused, but can be implemented in the user file.
	//2. Initialize CAN Peripheral with HAL_CAN_Init()
	HAL_CAN_Init(phCAN);
	//3. Configure the reception filters with HAL_CAN_ConfigFilter()
	const CAN_FilterTypeDef constConfig = fConfig->FilterConfig;
	HAL_CAN_ConfigFilter(phCAN, &constConfig);

	return phCAN;
}

CAN_Init::~CAN_Init() {
	// TODO Auto-generated destructor stub
}

// Deinitializes CAN.
void CAN_Init::CAN_deInit() {

}

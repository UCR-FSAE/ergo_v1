/*
 * CAN_Init.cpp
 *
 *  Created on: Feb 21, 2024
 *      Author: imjus
 */

#include "CAN_Init.h"

//Default Constructor (Does nothing)
CAN_Init::CAN_Init() {}

// User friendly version of the generated initlization in the main.c.
CAN_HandleTypeDef *CAN_Init::CAN_Initialize(CAN_HandleTypeDef *phCAN, Filter_Config *fConfig) {
	//1. Initialize CAN Low Level resources by implementing HAL_CAN_MSPInit()
		// MSPInit() is normally unused, but can be implemented in the user file.
	phCAN->Instance = CAN2;
	phCAN->Init.Prescaler = 16;
	phCAN->Init.Mode = CAN_MODE_NORMAL;
	phCAN->Init.SyncJumpWidth = CAN_SJW_1TQ;
	phCAN->Init.TimeSeg1 = CAN_BS1_1TQ;
	phCAN->Init.TimeSeg2 = CAN_BS2_1TQ;
	phCAN->Init.TimeTriggeredMode = DISABLE;
	phCAN->Init.AutoBusOff = DISABLE;
	phCAN->Init.AutoWakeUp = DISABLE;
	phCAN->Init.AutoRetransmission = DISABLE;
	phCAN->Init.ReceiveFifoLocked = DISABLE;
	phCAN->Init.TransmitFifoPriority = DISABLE;
	//2. Initialize CAN Peripheral with HAL_CAN_Init()
	HAL_CAN_Init(phCAN);

	//3. Configure the reception filters with HAL_CAN_ConfigFilter()
	const CAN_FilterTypeDef constConfig = fConfig->FilterConfig;
	HAL_CAN_ConfigFilter(phCAN, &constConfig);

	//4. Returns the pointer to the passed in handle.
	return phCAN;
}

// FIXME: Create a deInitializer.
void CAN_Init::CAN_DeInit(CAN_HandleTypeDef *phCAN) {
	HAL_CAN_DeInit(phCAN);
}

// CAN Default Constructor.
CAN_Init::~CAN_Init() {

}

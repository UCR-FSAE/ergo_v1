/*
 * CAN_Receive.h
 *
 *  Created on: Apr 8, 2024
 *      Author: imjus
 */

#ifndef INC_CAN_RECEIVE_H_
#define INC_CAN_RECEIVE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f4xx.h>

class CAN_Receive {
	private:
		// These are all private variables that the receive class will use.
		// Instance of CAN that will be manipulated.
		CAN_HandleTypeDef* hCAN;
		// RxHeader that will store the message header.
		CAN_RxHeaderTypeDef* RxHeader = new CAN_RxHeaderTypeDef;
		// RxData array will store the data of the message.
		uint8_t RxData[8];
	public:
		// Activation function. Should only need to be called once. Activates notifications for pending messages.
		// Default Constructor.
		CAN_Receive();
		// Parameterized constructor.
		CAN_Receive(CAN_HandleTypeDef* CAN, CAN_RxHeaderTypeDef*RxHeader) : hCAN(CAN), RxHeader(RxHeader) {}
		// Parameterized constructor that takes in only the CAN value and configures the RxHeader.
		CAN_Receive(CAN_HandleTypeDef* CAN, uint32_t Identifier) : hCAN(CAN){
			RxHeader->IDE = Identifier;
		}

		// Activation function. Should only need to be called once. Activates notifications for pending messages.
		bool ActivateNotifications();
		// Function to actually grab messages. Checks the mailbox fill level first, and takes no action if the mailbox is empty.
		bool GetMessages();
};


#ifdef __cplusplus
}
#endif

#endif /* INC_CAN_RECEIVE_H_ */

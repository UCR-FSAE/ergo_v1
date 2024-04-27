/*
 * CAN_Receive.cpp
 *
 *  Created on: Apr 8, 2024
 *      Author: imjus
 */

#include "CAN_Receive.h"

// Activates notifications for pending messages. Returns true if successful, otherwise returns false.
bool CAN_Receive::ActivateNotifications() {
	return HAL_OK == HAL_CAN_ActivateNotification(hCAN, CAN_IT_RX_FIFO0_MSG_PENDING);
}

// Gets a message from the mailbox, and stores it into RxData. By Default, the mailbox is always 0. Takes no
// action if the mailbox is empty.
bool CAN_Receive::GetMessages() {
	if (HAL_CAN_GetRxFifoFillLevel(hCAN, 0) == 0) {
		return true;
	}
	return HAL_OK == HAL_CAN_GetRxMessage(hCAN, 0, RxHeader ,RxData);
}

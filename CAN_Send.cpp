/*
 * CAN_Send.cpp
 *
 *  Created on: Jan 18, 2024
 *      Author: imjus
 */

#include "CAN_Send.h"

// Default Constructor.
CAN_Send::CAN_Send(){};

// FIXME Implement a parameterized constructor.

/*Sets IDE to either standard or extended.
 * If the number passed in is true, then the message is standard.
 * If the number passed in is false, then the message is extended.*/
void CAN_Send::setIDType(const bool input) {
	if (input == true) {
		TxHeader.IDE = CAN_ID_STD;
	}
	else {
		TxHeader.IDE = CAN_ID_EXT;
	}
}

/*Returns a bool of the ID type of the TxHeader.
 * If the number passed in is true, then the message is standard.
 * If the number passed in is false, then the message is extended.*/
const bool CAN_Send::getIDType() {
	return TxHeader.IDE == CAN_ID_STD;
}


/*Sets RTR to either remote frame or data frame.
 * If the value passed in is true, then the message is a Data Frame.
 * If the value passed in is false, then the message is a Remote Frame*/
void CAN_Send::setRTRType(const bool input) {
	if (input == true) {
		TxHeader.RTR = CAN_RTR_DATA;
	}
	else {
		TxHeader.RTR = CAN_RTR_REMOTE;
	}
}

/*Returns a bool of the RTR of the TxHeader.
 * If the value passed in is true, then the message is a Data Frame.
 * If the value passed in is false, then the message is a Remote Frame.*/
const bool CAN_Send::getRTRType() {
	return TxHeader.RTR == CAN_RTR_DATA;
}

/*Sets the length of the data being transmitted.
 * The should only be between 0 and 8.*/
// FIXME: implement an interrupt in case the input goes out of bounds.
void CAN_Send::setLength(int length) {
	if (length >= 0 && length < 8) {
		TxHeader.DLC = length;
	}
}

/*Returns the length of the data being transmitted*/
const int CAN_Send::getLength() {
	return TxHeader.DLC;
}

/*Sets the TxData payload array to whatever data is passed in.
 * FIXME: consider implementing an is in bounds function, in case the data is too large.
 * FIXME: consider implementing a message class, so that we can generate new classes while
 * using the same CAN_Send object.
 * FIXME: Is there a faster way to do this than a for loop?*/
// also lmfao lowkey why does this also work
void CAN_Send::setTxData(uint8_t data[]) {
	for (unsigned i = 0; i < TxHeader.DLC; i++) {
		TxData[i] = data[i];
	}
}

/*Returns the TxData array by reference.*/
// lmfao lowkey why does this work
uint8_t & CAN_Send::getData() {
	return *(TxData);
}

// MEATY FUNCTION
/*Function to send data to a mailbox.
 * Should:
 * Check first for free mailbox.
 * Return false if there is no free mailbox.
 * If there are free mailboxes, through the message into the first available mailbox.
 * Watch for interrupts from the mailbox in case something goes wrong.
 * Return true if the message was successfully sent.*/

//FIXME: This function does not work. TxHeader is supposed to be const. How to make it const but still modifiable?
bool CAN_Send::send() {
	if (HAL_CAN_GetTxMailboxesFreeLevel(hCAN) > 0) {
		const CAN_TxHeaderTypeDef *pTxHeader = &TxHeader;
		HAL_StatusTypeDef retVal = HAL_CAN_AddTxMessage(hCAN, pTxHeader, TxData, Mailbox);
		if (retVal != HAL_OK) {
			return false;
		}
	}
	return true;
}

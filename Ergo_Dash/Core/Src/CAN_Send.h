/*
 * CANSend.h
 *
 *  Created on: Jan 18, 2024
 *      Author: imjus
 */

#ifndef SRC_CAN_Send_H_
#define SRC_CAN_Send_H_

#ifdef __cplusplus
extern "C" {
#endif

// NOTE: this class is concerned with sending messages/transmitting messages.
// FIXME: Consider which functions should be const and which functions should have a const and non const version.

/*This includes all stm32f5xx.h files, even the intermediary ones.
 * The files that this class will utilize the most the ones concerning CAN.*/
#include <stm32f4xx.h>

class CAN_Send {
	private:
		//FIXME: FIGURE OUT WHICH MEMBERS ARE NEEDED FOR CAN
		// Classwide CanHandle, needed for messaging.
		CAN_HandleTypeDef *hCAN;

		// When a CAN_Send object is created, TX will be automatically generated.
		// Classwide TXHeader object. Will be configured using setters and getters.
		CAN_TxHeaderTypeDef TxHeader;
		// Data Array that stores the data to be sent. Will be configured using setters and getters.
		uint8_t TxData[8];
		// Mailbox. Need to explore the possibility of using multiple mailboxes and cycling through them.
		uint32_t *Mailbox;


	public:
		// Constructor, needs parameters that can be turned into a CANHandle.
		// The constructor would be a CAN_Send Object, which would be a representative of a transmit message.
		// The private data members will behave a bit like a config file, here it would be used in send to
		// sent out a complete transmit message.
		CAN_Send();

		// FIXME: Implement a parameterized constructor.
		CAN_Send(bool, bool, int, uint8_t *);


		// Destructor
		~CAN_Send();

		//A series of setters and getters for the TX Header.
		/*Sets IDE to either standard or extended.
		 * If the value passed in is true, then the message is standard.
		 * If the value passed in is false, then the message is extended.*/
		void setIDType(const bool);

		/*Returns a bool of the ID type of the TxHeader.
		 * If the value passed in is true, then the message is standard.
		 * If the value passed in is false, then the message is extended.*/
		const bool getIDType();

		/*Sets RTR to either remote frame or data frame.
		 * If the value passed in is true, then the message is a Data Frame.
		 * If the value passed in is false, then the message is a Remote Frame*/
		void setRTRType(const bool);

		/*Returns a bool of the RTR of the TxHeader.
		 * If the value passed in is true, then the message is a Data Frame.
		 * If the value passed in is false, then the message is a Remote Frame.*/
		const bool getRTRType();

		/*Sets the length of the data being transmitted.
		 * The should only be between 0 and 8.*/
		// FIXME: implement an interrupt in case the input goes out of bounds.
		void setLength(int);

		/*Returns the length of the data being transmitted*/
		const int getLength();

		/*Sets the TxData payload array to whatever data is passed in.
		 * FIXME: consider implementing an is in bounds function, in case the data is too large.
		 * FIXME: consider implementing a message class, so that we can generate new classes while
		 * using the same CAN_Send object. */
		void setTxData(uint8_t *);

		/*Returns the TxData array by reference.*/
		uint8_t & getData();

		/*Function to send data to a mailbox.
		 * Should:
		 * Check first for free mailbox.
		 * Return false if there is no free mailbox.
		 * If there are free mailboxes, through the message into the first available mailbox.
		 * Watch for interrupts from the mailbox in case something goes wrong.
		 * Return true if the message was successfully sent.*/
		bool send();
	};


#ifdef __cplusplus
}
#endif

#endif /* SRC_CANINTERFACE_H_ */

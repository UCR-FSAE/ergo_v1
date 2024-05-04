/*
 * Filter_Config.h
 *
 *  Created on: Feb 21, 2024
 *      Author: imjus
 */

#ifndef INC_FILTER_CONFIG_H_
#define INC_FILTER_CONFIG_H_

/* This includes all stm32f5xx.h files, even the intermediary ones.
 * The files that this class will utilize the most the ones concerning CAN.*/
#include <stm32f4xx.h>

/* This class is designed to represent the the HAL_CAN Filter configuration.
 * Once initialized, there will exist a Filter_Config object. The Filter_Config's FilterConfig parameter
 * will be passed into functions requiring a filter configuration. This entire class exists solely for the
 * CAN_Init class.
 * This class is comprised mainly of setters and getters that will configure the filter prior to it being
 * passed in to the CAN_Init class. The entire configuration process should occur before the completion
 * of the CAN_Init process.*/

class Filter_Config {
// FIXME: IMPLEMENT ERROR CHECKING FOR ALL OF THE SETTERS AND GETTERS

public:
	// This is the FilterConfig member variable that will be passed into CAN_Init.
	CAN_FilterTypeDef FilterConfig;

	// Default Constructor. Does nothing at the moment, but may change depending on defined default macros (future iterations).
	Filter_Config();

	// Parameterized Constructor. Uses the setter functions to configure the filter all at once.
	Filter_Config(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, bool, uint32_t, bool, uint32_t);

	/* Specifies the filter identification number (MSBs for a 32-bit
	 * configuration, first one for a 16-bit configuration).
	 * This parameter must be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF. */
	void setIDHigh(uint32_t);

	/* Returns the filter identification number (MSBs for a 32-bit configuration, first
	 * for a 16-bit configuration). */
	uint32_t getIDHigh();

	/* Specifies the filter identification number (LSBs for a 32-bit
	 * configuration, second one for a 16-bit configuration).
	 * This parameter must be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF. */
	void setIDLow(uint32_t);

	/* Returns the filter identification number (LSBs for a 32-bit configuration, second
	 * for a 16-bit configuration). */
	uint32_t getIDLow();

	/* Specifies the filter mask number or identification number, depending on the mode (MSBs for a 32-bit
	 * configuration, first one for a 16-bit configuration).
	 * This parameter must be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF. */
	void setMaskIDHigh(uint32_t);

	/* Returns the filter mask number/identification number (MSBs for a 32-bit
	 * configuration, first one for a 16-bit configuration). */
	uint32_t getMaskIDHigh();

	/* Specifies the filter mask number or identification number, depending on the mode (LSBs for a 32-bit
	 * configuration, second for a 16-bit configuration).
	 * This parameter must be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF. */
	void setMaskIDLow(uint32_t);

	/* Returns the filter mask number/identification number (LSBs for a 32-bit
	 * configuration, second for a 16-bit configuration). */
	uint32_t getMaskIDLow();

	/* Sets the FIFO number that a particular CAN will be using. The parameter will
	 * be 0 (for FIFO0) or 1 (for FIFO1)*/
	void setFIFO(uint32_t);

	/* Returns the FIFO number for a particular CAN instance.*/
	uint32_t getFIFO();

	/* Specifies the filter bank that will be initialized for a CAN instance. For a single CAN instance,
	 * the parameter must be between 0 and 13. If it is a double CAN instance, the parameter can be between
	 * 0 and 14. */
	void setBank(uint32_t);

	/* Returns the filter bank that is used for a particular CAN instance. */
	uint32_t getBank();

	/* Sets the mode of a CAN instance. If true is passed in, the mode will be Mask mode. Otherwise,
	 * the mode will be list mode. */
	void setMode(bool);

	/* Returns the mode of a CAN instance. If true is returned, then the mode is Mask. Otherwise, the mode
	 * is list mode. */
	bool getMode();

	/* Sets the scale of the filters to either one 32-bit filter bank or two 16-bit filter banks.
	 * This function only accepts inputs of 16 or 32, representing the size of a filter.
	 * i.e. If 16 is input, then there are two 16 bit filter banks.*/
	void setScale(uint32_t);

	/* Returns the scale of the filters.
	 * Returns either 16 or 32, representing the size of a filter.*/
	uint32_t getScale();

	/* Sets the CAN activation status. If true is passed in, then the activation status is on. Otherwise,
	 * the activation status will be toggled off. */
	void setActivation(bool);

	/* Returns the activation status of a CAN instance. If the true is returned, the CAN is active. Otherwise,
	 * the CAN is inactive. */
	bool getActivation();

	/* Sets the beginning filter for the slave instance of CAN. The parameter must be a number between 0 and 27.
	 * This function and the slaveFilter in general is meaningless in a single CAN setup. */
	void setSlaveFilters(uint32_t);

	/* Returns the beginning of the slave filters for a dual CAN instance. */
	uint32_t getSlaveFilters();

	/* Implements this filter configuration into a particular CAN instance. */
	bool implementFilter(CAN_HandleTypeDef *phCAN);

	virtual ~Filter_Config();
};

#endif /* SRC_FILTER_CONFIG_H_ */

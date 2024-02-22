/*
 * Filter_Config.h
 *
 *  Created on: Feb 21, 2024
 *      Author: imjus
 */

#ifndef SRC_FILTER_CONFIG_H_
#define SRC_FILTER_CONFIG_H_

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
	 * for a 16-bit configuration).*/
	uint32_t getIDHigh();

	void setIDLow(uint32_t);

	uint32_t getIDLow();

	void setMaskIDHigh(uint32_t);
	uint32_t getMaskIDHigh();
	void setMaskIDLow(uint32_t);
	uint32_t getMaskIDLow();
	void setFIFO(uint32_t);
	uint32_t getFIFO();
	void setBank(uint32_t);
	uint32_t getBank();

	void setMode(bool);
	bool getMode();
	/* Sets the scale of the filters to either one 32 bit filterbank or 2 16 bit filterbanks.
	 * This function only accepts inputs of 16 or 32, representing the size of a filter.
	 * i.e. If 16 is input, then there are two 16 bit filterbanks.*/
	void setScale(uint32_t);
	/* Returns the scale of the filters.
	 * Returns either 16 or 32, representing the size of a filter.*/
	uint32_t getScale();
	void setActivation(bool);
	bool getActivation();
	void setSlaveFilters(uint32_t);
	uint32_t getSlaveFilters();

	virtual ~Filter_Config();
};

#endif /* SRC_FILTER_CONFIG_H_ */

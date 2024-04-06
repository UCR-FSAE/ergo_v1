/*
 * Filter_Config.cpp
 *
 *  Created on: Feb 21, 2024
 *      Author: imjus
 */

#include "Filter_Config.h"

// Default constructor. Does nothing at the moment.
Filter_Config::Filter_Config() {}

// Parameterized constructor. Uses the defined setters to configure the FilterTypeDef.
Filter_Config::Filter_Config(uint32_t highID, uint32_t lowID, uint32_t highMaskID, uint32_t lowMaskID,
		uint32_t FIFONumber, uint32_t bankNumber, bool isMaskMode, uint32_t filterScale,
		bool isActive, uint32_t slaveFilterStart) {
	setIDHigh(highID);
	setIDLow(lowID);
	setMaskIDHigh(highMaskID);
	setMaskIDLow(lowMaskID);
	setFIFO(FIFONumber);
	setBank(bankNumber);
	setMode(isMaskMode);
	setScale(filterScale);
	setActivation(isActive);
	setSlaveFilters(slaveFilterStart);
}

// Default Destructor. Does nothing at the moment.
Filter_Config::~Filter_Config() {
	// TODO Auto-generated destructor stub
}

/* Specifies the filter identification number (MSBs for a 32-bit
 * configuration, first one for a 16-bit configuration).
 * This parameter must be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF. */
void Filter_Config::setIDHigh(uint32_t highID) {
	if (highID > 0x0000 && highID < 0xFFFF) {
		FilterConfig.FilterIdHigh = highID;
	}
}

/* Returns the filter identification number (MSBs for a 32-bit configuration, first
 * for a 16-bit configuration). */
uint32_t Filter_Config::getIDHigh() {
	return FilterConfig.FilterIdHigh;
}

/* Specifies the filter identification number (LSBs for a 32-bit
 * configuration, the second for a 16-bit configuration).
 * This parameter must be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF. */
void Filter_Config::setIDLow(uint32_t lowID) {
	if (lowID > 0x0000 && lowID < 0xFFFF) {
		FilterConfig.FilterIdLow = lowID;
	}
}
/* Returns the filter identification number (LSBs for a 32-bit configuration, second
 * for a 16-bit configuration). */
uint32_t Filter_Config::getIDLow() {
	return FilterConfig.FilterIdLow;
}

/* Specifies the filter mask number or identification number, depending on the mode (MSBs for a 32-bit
 * configuration, first one for a 16-bit configuration).
 * This parameter must be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF. */
void Filter_Config::setMaskIDHigh(uint32_t maskHighID) {
	if (maskHighID > 0x0000 && maskHighID < 0xFFFF) {
		FilterConfig.FilterMaskIdHigh = maskHighID;
	}
}
/* Returns the filter mask number/identification number (MSBs for a 32-bit
 * configuration, first one for a 16-bit configuration). */
uint32_t Filter_Config::getMaskIDHigh() {
	return FilterConfig.FilterMaskIdHigh;

}

/* Specifies the filter mask number or identification number, depending on the mode (LSBs for a 32-bit
 * configuration, second for a 16-bit configuration).
 * This parameter must be a number between Min_Data = 0x0000 and Max_Data = 0xFFFF. */
void Filter_Config::setMaskIDLow(uint32_t maskLowID) {
	if (maskLowID > 0x0000 && maskLowID < 0xFFFF) {
		FilterConfig.FilterMaskIdLow = maskLowID;
	}
}

/* Returns the filter mask number/identification number (LSBs for a 32-bit
 * configuration, second for a 16-bit configuration). */
uint32_t Filter_Config::getMaskIDLow() {
	return FilterConfig.FilterMaskIdLow;
}

/* Sets the FIFO number that a particular CAN will be using. The parameter will
 * be 0 (for FIFO0) or 1 (for FIFO1)*/
void Filter_Config::setFIFO(uint32_t fifoNumber) {
	if (fifoNumber == 0) {
		FilterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	}
	else if (fifoNumber == 1) {
		FilterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO1;
	}
	else {
		return;
	}
}

/* Returns the FIFO number for a particular CAN instance.*/
uint32_t Filter_Config::getFIFO() {
	return FilterConfig.FilterFIFOAssignment;
}

/* Specifies the filter bank that will be initialized for a CAN instance. For a single CAN instance,
 * the parameter must be between 0 and 13. If it is a double CAN instance, the parameter can be between
 * 0 and 14. */
// FIXME: Determine how change the bounds of the bankNumber depending on if the set up is single or dual.
void Filter_Config::setBank(uint32_t bankNumber) {
	if (bankNumber > 0 && bankNumber < 27) {
		FilterConfig.FilterBank = bankNumber;
	}
}

/* Returns the filter bank that is used for a particular CAN instance. */
uint32_t Filter_Config::getBank() {
	return FilterConfig.FilterBank;
}

/* Sets the beginning filter for the slave instance of CAN. The parameter must be a number between 0 and 27.
 * This function and the slaveFilter in general is meaningless in a single CAN setup. */
void Filter_Config::setSlaveFilters(uint32_t slaveFilterStart) {
	if (slaveFilterStart > 0 && slaveFilterStart < 27) {
		FilterConfig.SlaveStartFilterBank = slaveFilterStart;
	}
}

/* Returns the beginning of the slave filters for a dual CAN instance. */
uint32_t Filter_Config::getSlaveFilters() {
	return FilterConfig.SlaveStartFilterBank;
}

/* Sets the mode of a CAN instance. If true is passed in, the mode will be Mask mode. Otherwise,
 * the mode will be list mode. */
void Filter_Config::setMode(bool isMaskMode) {
	if (isMaskMode) {
		FilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	}
	else {
		FilterConfig.FilterMode = CAN_FILTERMODE_IDLIST;
	}
}

/* Returns the mode of a CAN instance. If true is returned, then the mode is Mask. Otherwise, the mode
 * is list mode. */
bool Filter_Config::getMode() {
	return FilterConfig.FilterMode == CAN_FILTERMODE_IDMASK;
}

/* Sets the scale of the filters to either one 32 bit filterbank or 2 16 bit filterbanks.
 * This function only accepts inputs of 16 or 32, representing the size of a filter.
 * i.e. If 16 is input, then there are two 16 bit filterbanks.*/
void Filter_Config::setScale(uint32_t filterScale) {
	if (filterScale == 16) {
		FilterConfig.FilterScale = CAN_FILTERSCALE_16BIT;
	}
	else if (filterScale == 32) {
		FilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	}
	else {
		return;
	}
}

/* Returns the scale of the filters.
 * Returns either 16 or 32, representing the size of a filter.*/
uint32_t Filter_Config::getScale() {
	if (FilterConfig.FilterScale == CAN_FILTERSCALE_16BIT) {
		return 16;
	}
	else {
		return 32;
	}
}

/* Sets the activation status of the filter. If the state is true, the FilterActivation number is
 * changed to one and the filter is active. Otherwise, the number is changed to 0 and the filter is inactive. */
void Filter_Config::setActivation(bool state) {
	if (state == true) {
		FilterConfig.FilterActivation = CAN_FILTER_ENABLE ;
	}
	else {
		FilterConfig.FilterActivation = CAN_FILTER_DISABLE;
	}
}

/* Returns the activation status of the filter. */
bool Filter_Config::getActivation() {
	return FilterConfig.FilterActivation == 1;
}

/* Implements the current filter configuration into an instance of CAN. */
bool Filter_Config::implementFilter(CAN_HandleTypeDef *phCAN) {
	const CAN_FilterTypeDef constConfig = this->FilterConfig;
	HAL_StatusTypeDef ok = HAL_CAN_ConfigFilter(phCAN, &constConfig);
	return ok == HAL_OK;
}

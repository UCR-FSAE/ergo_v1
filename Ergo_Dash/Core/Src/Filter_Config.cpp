/*
 * Filter_Config.cpp
 *
 *  Created on: Feb 21, 2024
 *      Author: imjus
 */

#include "Filter_Config.h"

Filter_Config::Filter_Config() {}

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

void Filter_Config::setMaskIDHigh(uint32_t maskHighID) {
	if (maskHighID > 0x0000 && maskHighID < 0xFFFF) {
		FilterConfig.FilterMaskIdHigh = maskHighID;
	}
}
uint32_t Filter_Config::getMaskIDHigh() {
	return FilterConfig.FilterMaskIdHigh;

}
void Filter_Config::setMaskIDLow(uint32_t maskLowID) {
	if (maskLowID > 0x0000 && maskLowID < 0xFFFF) {
		FilterConfig.FilterMaskIdLow = maskLowID;
	}
}
uint32_t Filter_Config::getMaskIDLow() {
	return FilterConfig.FilterMaskIdLow;
}

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
uint32_t Filter_Config::getFIFO() {
	return FilterConfig.FilterFIFOAssignment;
}

// FIXME: Use a parent class. to determine whether or not the max will be 13 or 27.
void Filter_Config::setBank(uint32_t bankNumber) {
	if (bankNumber > 0 && bankNumber < 27) {
		FilterConfig.FilterBank = bankNumber;
	}
}
uint32_t Filter_Config::getBank() {
	return FilterConfig.FilterBank;
}

void Filter_Config::setSlaveFilters(uint32_t slaveFilterStart) {
	if (slaveFilterStart > 0 && slaveFilterStart < 27) {
		FilterConfig.SlaveStartFilterBank = slaveFilterStart;
	}
}
uint32_t Filter_Config::getSlaveFilters() {
	return FilterConfig.SlaveStartFilterBank;
}

/* Sets the filter mode to Mask mode or to list mode. If true is passed in, the mode will be set to mask.
 * Otherwise, the mode will be set to list. */
void Filter_Config::setMode(bool isMaskMode) {
	if (isMaskMode) {
		FilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	}
	else {
		FilterConfig.FilterMode = CAN_FILTERMODE_IDLIST;
	}
}

/* Returns the filter mode of the filter. If true is returned, the filter is in mask mode. Otherwise, the mode is
 * in list. */
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

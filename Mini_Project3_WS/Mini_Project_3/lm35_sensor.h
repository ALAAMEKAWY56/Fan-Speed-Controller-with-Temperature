/**********************************************************************************************************
 * [FILE NAME]		:	lm35_sensor.h											                                  *
 * [DESCRIPTION]	:	Header file for LM35 Temperature Sensor driver								      *
 * [DATE CREATED]	: 	OCT 9, 2023																          *
 * [AURTHOR]		: 	Alaa Mekawi															              *
 *********************************************************************************************************/

#ifndef LM35_H_
#define LM35_H_
/************************************Header Files used*********************************************/
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define SENSOR_CHANNEL_ID       2
#define SENSOR_MAX_VOLT_VALUE   1.5
#define SENSOR_MAX_TEMPERATURE  150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*[FUNCTION NAME]	: LM35_getTemperature
 *[DESCRIPTION]		: Function responsible for calculate the temperature from the ADC digital value
 *[ARGUMENTS]		: void
 *[RETURNS]			: uint8
 */
uint8 LM35_getTemperature(void);


#endif /* LM35_H_ */

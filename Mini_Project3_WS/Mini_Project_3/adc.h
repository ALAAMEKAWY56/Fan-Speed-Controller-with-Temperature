/**********************************************************************************************************
 * [FILE NAME]		:			adc.h											                          *
 * [DESCRIPTION]	:			Header file for the AVR ADC_driver										  *
 * [DATE CREATED]	: 			Sep 9, 2023																  *
 * [AURTHOR]		: 			Alaa Mekawi															      *
 *********************************************************************************************************/
#ifndef ADC_H_
#define ADC_H_

/************************************Header Files used*********************************************/
#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define  ADC_MAX_VALUE       1023
#define  ADC_REF_VOLT_VALUE  2.56

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum{
	AREF,AVCC,RESERVED,INTERNAL
	/*0 ,  1  ,   2    ,   3  */
}ADC_ReferenceVolatge;

typedef enum{
	F_CPU_2_FIRST, F_CPU_2_SECOND, F_CPU_4 , F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
	/*    0       ,      1       ,   2    ,   3  ,    4   ,   5     ,   6    ,   7   */
}ADC_Prescaler;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*[FUNCTION NAME]	: ADC_init
 *[DESCRIPTION]		: Function responsible for initialize the ADC driver.
 *[ARGUMENTS]		: pointer to function of type ADC_ConfigType
 *[RETURNS]			: void
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*[FUNCTION NAME]	: ADC_readChannel
 *[DESCRIPTION]		: Function responsible for read analog data from a certain ADC channel
 *                    and convert it to digital using the ADC driver.
 *[ARGUMENTS]		: uint8 ch_num
 *[RETURNS]			: uint16
 */
uint16 ADC_readChannel(uint8 ch_num);


#endif /* ADC_H_ */

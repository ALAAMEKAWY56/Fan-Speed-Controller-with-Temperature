/**********************************************************************************************************
 * [FILE NAME]		:			adc.c											                          *
 * [DESCRIPTION]	:			source file for the AVR ADC_driver										  *
 * [DATE CREATED]	: 			Sep 9, 2023																  *
 * [AURTHOR]		: 			Alaa Mekawi															      *
 *********************************************************************************************************/
#include "adc.h"
#include"common_macros.h"
#include "avr/io.h" /* To use the ADC Registers */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*[FUNCTION NAME]	: ADC_init
 *[DESCRIPTION]		: Function responsible for initialize the ADC driver.
 *[ARGUMENTS]		: pointer to function of type ADC_ConfigType
 *[RETURNS]			: void
 */
void ADC_init(const ADC_ConfigType * Config_Ptr){
	/* choose refernace value according to value in struct
	 * channel 0 --- 0000 (MUX4) "intial value"
	 * ADLAR = 0 */
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt)<<6);

	/* ADC Enbale bit*/
	ADCSRA = (1<<ADEN) ;
	/*choose ADC Prescaler Select Bits*/
	ADCSRA = (ADCSRA & 0xF8 ) | (Config_Ptr->prescaler);
}

/*[FUNCTION NAME]	: ADC_readChannel
 *[DESCRIPTION]		: Function responsible for read analog data from a certain ADC channel
 *                    and convert it to digital using the ADC driver.
 *[ARGUMENTS]		: uint8 ch_num
 *[RETURNS]			: uint16
 */
uint16 ADC_readChannel(uint8 ch_num){

	ADMUX = (ADMUX & 0xE0) | (ch_num & 0X07);
	/*SET BIT to set this bit only and don't change other values*/
	SET_BIT(ADCSRA,ADSC);

	/*polling unitl flag = 1*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF));

	/*write logical one to set flag*/
	SET_BIT(ADMUX,ADIF);
	return ADC;

}

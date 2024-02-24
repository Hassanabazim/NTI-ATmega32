
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATE.h"
#include "MGIE_int.h"
#include "MADC_int.h"
#include "MADC_config.h"
#include "MADC_priv.h"

static void(*ADC_callback)(void) = {NULL};

ErrorState_t MADC_enInit(prescaler_t copy_u8presclaer, vref_t copy_vref)
{	
	/* Enable ADC */
	SET_BIT (ADCSRA_REG,ADEN);
	
	/* Clear the PRESCALER BITS by Masking it */
	ADCSRA_REG &= PRESCALER_MASK;
	/* Set the value of the Prescaler */
	ADCSRA_REG |= copy_u8presclaer;
	
	/* clear the VREF_BITS by Masking it */
	ADMUX_REG &= VREF_MASK;
	/* Set the Value of the Vref */
	ADMUX_REG |= copy_vref;
	
	

	return SUCCESS;	
}

ErrorState_t MADC_enReadChannel(channel_t copy_u8Channel, u16 *ptrValue )
{
	/* Clear the channel BITS by Masking it */
	ADMUX_REG &= CHANNEL_MASK;
	/* Set the value of the Channel */
	ADMUX_REG |= copy_u8Channel;
	
	/* start conversion */
	SET_BIT(ADCSRA_REG,ADSC);
	
	while (!(GET_BIT(ADCSRA_REG,ADIF)));
	SET_BIT(ADCSRA_REG, ADIF);
	
	*ptrValue =  ADC_REG;

	return SUCCESS;
}

ErrorState_t MADC_enCallback(void(*ptr)(void))
{
	ErrorState_t local_state = SUCCESS;
	if (ptr != NULL)
	{
		ADC_callback = ptr   ;
	}
	else
	{
		local_state = NULL_PTR_ERR;
	}
	return local_state;
}

ISR(ADC_INT)
{
	if (ADC_callback != NULL)
	{
		ADC_callback();
	}
}

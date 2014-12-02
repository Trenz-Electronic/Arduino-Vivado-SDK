/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "Arduino.h"
#include "wiring_int.h"

#include "xparameters.h"

#ifdef __cplusplus
 extern "C" {
#endif

void pinMode(uint32_t pin, uint32_t mode)
{
//	uint32_t bit = 1 << (pin & 0x1F);
//	XGpioPs_SetDirectionPin(&Gpio, ledpin, 1);
//	XGpioPs_SetOutputEnablePin(&Gpio, ledpin, 1);

	if (mode==INPUT) {
		XGpioPs_SetDirectionPin(&Gpio, pin, 0);
		XGpioPs_SetDirectionPin(&Gpio, pin, 0);
	} else {
		XGpioPs_SetDirectionPin(&Gpio, pin, 1);
		XGpioPs_SetDirectionPin(&Gpio, pin, 1);
	}


//	if      (pin < 32)  { if (mode==INPUT) { GPO_3_shadow |= bit; } else { GPO_3_shadow &= ~bit; } GPO_3 = GPO_3_shadow; } // 0..31 support real Tristate 
//        else if (pin < 64)  { if (mode==INPUT) { GPO_4_shadow |= bit; } else { GPO_4_shadow &= ~bit; } GPO_4 = GPO_4_shadow; } // 32..63 support real Tristate 
//        else if (pin < 96)  { if (mode==INPUT) { GPO_3_shadow |= bit; } else { GPO_3_shadow &= ~bit; } GPO_3 = GPO_3_shadow; } // 64..95  output only or open-collector
//        else if (pin < 128) { if (mode==INPUT) { GPO_4_shadow |= bit; } else { GPO_4_shadow &= ~bit; } GPO_4 = GPO_4_shadow; } // 96..127 

	return;
}

void digitalWrite(uint32_t pin, uint32_t val)
{
#ifdef XPAR_XGPIOPS_NUM_INSTANCES
	XGpioPs_WritePin(&Gpio, pin, val & 1);
#endif

	return;
}

int digitalRead(uint32_t pin)
{


//	if      (pin < 32)  { if ((GPI_1) & bit) return HIGH; return LOW; }
//	else if (pin < 64)  { if ((GPI_2) & bit) return HIGH; return LOW; }
//	else if (pin < 96)  { if ((GPI_3) & bit) return HIGH; return LOW; }
//	else if (pin < 128) { if ((GPI_4) & bit) return HIGH; return LOW;
//	} else return LOW;
#ifdef XPAR_XGPIOPS_NUM_INSTANCES
	return XGpioPs_ReadPin(&Gpio, pin);	
#endif

//	return LOW;
  	
}


#ifdef __cplusplus
}
#endif


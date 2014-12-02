/*
  Copyright (c) 2012 Arduino.  All right reserved.

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

#ifndef Arduino_h
#define Arduino_h

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "binary.h"

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

#define _BV(a)          1<<a

#include "registers.h"
#include "wiring_constants.h"

#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a) ( ((a) * 1000L) / (F_CPU / 1000L) )
#define microsecondsToClockCycles(a) ( (a) * (F_CPU / 1000000L) )

#include "wiring.h"
#include "wiring_digital.h"
#include "wiring_analog.h"
#include "wiring_shift.h"

/* sketch */
extern void setup( void ) ;
extern void loop( void ) ;

#ifdef __cplusplus
} // extern "C"

///#include "WCharacter.h"
///#include "WString.h"
//#include "Tone.h"
///#include "WMath.h"
///#include "HardwareSerial.h"
///#include "HardwareSPI.h"
///#include "wiring_pulse.h"

#endif // __cplusplus

#include "pins_arduino.h"

#endif

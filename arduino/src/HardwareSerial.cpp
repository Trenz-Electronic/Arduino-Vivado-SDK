/*
  HardwareSerial.cpp - Hardware serial library for Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  
  Modified 23 November 2006 by David A. Mellis
  Modified 28 September 2010 by Mark Sproul
  Modified 14 August 2012 by Alarus
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "Arduino.h"

// this next line disables the entire HardwareSerial.cpp, 
// this is so I can support Attiny series and any other chip without a uart
#if defined(UART0_UBRR) || defined(UART1_UBRR) || defined(UART2_UBRR) || defined(UART3_UBRR)

#include "HardwareSerial.h"


#if defined(UART0_UBRR)
  void serialEvent() __attribute__((weak));
  void serialEvent() {}
  #define serialEvent_implemented
#endif

#if defined(UART1_UBRR)
  void serialEvent1() __attribute__((weak));
  void serialEvent1() {}
  #define serialEvent1_implemented
#endif

#if defined(UART2_UBRR)
  void serialEvent2() __attribute__((weak));
  void serialEvent2() {}
  #define serialEvent2_implemented
#endif

#if defined(UART3_UBRR)
  void serialEvent3() __attribute__((weak));
  void serialEvent3() {}
  #define serialEvent3_implemented
#endif


void serialEventRun(void)
{
#ifdef serialEvent_implemented
  if (Serial.available()) serialEvent();
#endif
#ifdef serialEvent1_implemented
  if (Serial1.available()) serialEvent1();
#endif
#ifdef serialEvent2_implemented
  if (Serial2.available()) serialEvent2();
#endif
#ifdef serialEvent3_implemented
  if (Serial3.available()) serialEvent3();
#endif
}


// Constructors ////////////////////////////////////////////////////////////////

HardwareSerial::HardwareSerial(volatile uint16_t *ubrr,
  volatile uint16_t *ucr, volatile uint8_t *udr)
{
//  _ubrr = ubrr;
//  _ucr = ucr;
//  _udr = udr;
}

// Public Methods //////////////////////////////////////////////////////////////

void HardwareSerial::begin(unsigned long baud)
{
  // assign the baud_setting, a.k.a. ubbr (UART Baud Rate Register)
//  *_ubrr = (F_CPU/8/baud + 1)/2 - 1;
//  *_ucr = 0x80;
  transmitting = false;
}

void HardwareSerial::begin(unsigned long baud, byte config)
{
  // config not yet supported
//  *_ubrr = (F_CPU/8/baud + 1)/2 - 1;
//  *_ucr = 0x80;
  transmitting = false;
}

void HardwareSerial::end()
{
  // wait for transmission of outgoing data
//  while (*_ucr & 0x04)
//    ;
//  *_ucr = 0;
}

int HardwareSerial::available(void)
{
//  uint16_t status = *_ucr;
//  if (status & 0x08)
//    return 16;
//  if (status & 0x10)
//    return  1;

  return 0;
}

int HardwareSerial::peek(void)
{
//  uint16_t status = *_ucr;
//  if (status & 0x10) {
//    return (status>>8);
//  } else {
//    return -1;
//  }
}

int HardwareSerial::read(void)
{
//  uint16_t status = *_ucr;
//  if (status & 0x10) {
//    unsigned char c = *_udr;
//    return c;
//  } else {
//    return -1;
//  }
}

void HardwareSerial::flush()
{
//  while (transmitting && ! (*_ucr & 0x04));
  transmitting = false;
}

size_t HardwareSerial::write(uint8_t c)
{	
  // If the output buffer is full, there's nothing for it other than to 
  // wait for the interrupt handler to empty it a bit
//  while ((*_ucr & 0x02))
//    ;
//
//  *_udr = c;

  transmitting = true;
  return 1;
}

HardwareSerial::operator bool() {
	return true;
}

// Preinstantiate Objects //////////////////////////////////////////////////////

#if defined(UART0_UBRR)
  HardwareSerial Serial(&UART0_UBRR, &UART0_UCR, &UART0_UDR);
#endif
#if defined(UART1_UBRR)
  HardwareSerial Serial1(&UART1_UBRR, &UART1_UCR, &UART1_UDR);
#endif
#if defined(UART2_UBRR)
  HardwareSerial Serial2(&UART2_UBRR, &UART2_UCR, &UART2_UDR);
#endif
#if defined(UART3_UBRR)
  HardwareSerial Serial3(&UART3_UBRR, &UART3_UCR, &UART3_UDR);
#endif


#endif // whole file


/*
  HardwareSPI.cpp - Hardware SPI library for Wiring
  Copyright (c) 2013 Magnus Karlsson.  All right reserved.

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
*/

#include "Arduino.h"
#include "HardwareSPI.h"

// Constructors ////////////////////////////////////////////////////////////////

HardwareSPI::HardwareSPI(volatile uint8_t *spcr,
  volatile uint8_t *spsr, volatile uint8_t *spdr)
{
//  _spcr = spcr;
//  _spsr = spsr;
//  _spdr = spdr;
}

// Public Methods //////////////////////////////////////////////////////////////

void HardwareSPI::begin(void)
{
//  *_spcr |= _BV(MSTR);
//  *_spcr |= _BV(SPE);
}

void HardwareSPI::end()
{
//  *_spcr &= ~_BV(SPE);
}

void HardwareSPI::setBitOrder(uint8_t bitOrder)
{
//  if(bitOrder == LSBFIRST) {
//    *_spcr |= _BV(DORD);
//  } else {
//    *_spcr &= ~(_BV(DORD));
//  }
}

void HardwareSPI::setDataMode(uint8_t mode)
{
//  *_spcr = (*_spcr & ~SPI_MODE_MASK) | mode;
}

void HardwareSPI::setClockDivider(uint8_t rate)
{
//  *_spcr = (*_spcr & ~SPI_CLOCK_MASK) | (rate & SPI_CLOCK_MASK);
//  *_spsr = (*_spsr & ~SPI_2XCLOCK_MASK) | ((rate >> 2) & SPI_2XCLOCK_MASK);
}


// Preinstantiate Objects //////////////////////////////////////////////////////

#if defined(SPI0_SPCR)
  HardwareSPI SPI0(&SPI0_SPCR, &SPI0_SPSR, &SPI0_SPDR);
#endif
#if defined(SPI1_SPCR)
  HardwareSPI SPI1(&SPI1_SPCR, &SPI1_SPSR, &SPI1_SPDR);
#endif
#if defined(SPI2_SPCR)
  HardwareSPI SPI2(&SPI2_SPCR, &SPI2_SPSR, &SPI2_SPDR);
#endif




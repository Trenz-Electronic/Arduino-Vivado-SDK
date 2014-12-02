/*
  HardwareSPI.h - Hardware SPI library for Wiring
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

#ifndef HardwareSPI_h
#define HardwareSPI_h

#include <inttypes.h>

#define SPI_CLOCK_DIV4 0x00
#define SPI_CLOCK_DIV16 0x01
#define SPI_CLOCK_DIV64 0x02
#define SPI_CLOCK_DIV128 0x03
#define SPI_CLOCK_DIV2 0x04
#define SPI_CLOCK_DIV8 0x05
#define SPI_CLOCK_DIV32 0x06

#define SPI_MODE0 0x00
#define SPI_MODE1 0x04
#define SPI_MODE2 0x08
#define SPI_MODE3 0x0C

#define SPI_MODE_MASK 0x0C  // CPOL = bit 3, CPHA = bit 2 on SPCR
#define SPI_CLOCK_MASK 0x03  // SPR1 = bit 1, SPR0 = bit 0 on SPCR
#define SPI_2XCLOCK_MASK 0x01  // SPI2X = bit 0 on SPSR

class HardwareSPI {
  private:
  //  volatile uint8_t *_spcr;
  //  volatile uint8_t *_spsr;
  //  volatile uint8_t *_spdr;
  public:
    HardwareSPI(volatile uint8_t *spcr, volatile uint8_t *spsr, volatile uint8_t *spdr);
    inline uint8_t transfer(uint8_t _data);
    
    inline void attachInterrupt();
    inline void detachInterrupt();
    
    void begin();
    void end();

    void setBitOrder(uint8_t);
    void setDataMode(uint8_t);
    void setClockDivider(uint8_t);
};

#if defined(SPI0_SPCR)
  extern HardwareSPI SPI0;
#endif
#if defined(SPI1_SPCR)
  extern HardwareSPI SPI1;
#endif
#if defined(SPI2_SPCR)
  extern HardwareSPI SPI2;
#endif

uint8_t HardwareSPI::transfer(uint8_t _data) {
//  *_spdr = _data;
//  while (!(*_spsr & _BV(SPIF)))
//    ;
//  return *_spdr;
}

void HardwareSPI::attachInterrupt() {
//  *_spcr |= _BV(SPIE);
}

void HardwareSPI::detachInterrupt() {
//  *_spcr &= ~_BV(SPIE);
}

#endif

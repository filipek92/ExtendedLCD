/*
  ExtendedLCD.h - Library for handling LCD
  Created by Filip Richter, 30.07.2016.
*/

#ifndef EXTENDED_LCD
#define EXTENDED_LCD

#include "Arduino.h"
#include "stdint.h"

#include <LiquidCrystal.h>

class ExtendedLCD: public LiquidCrystal
{
  public:
		ExtendedLCD(uint8_t rs, uint8_t enable,
			uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
			uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
		ExtendedLCD(uint8_t rs, uint8_t rw, uint8_t enable,
			uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
			uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
		ExtendedLCD(uint8_t rs, uint8_t rw, uint8_t enable,
			uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
		ExtendedLCD(uint8_t rs, uint8_t enable,
			uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);

		void initText(const char line1[], const char line2[]);
		void doWork();
		void revert();
		void linePrint(const char line1[], const char line2[]);
		void linePrint(const char* value, uint8_t line);
		void linePrint(const char* l);
		void splash(const char line1[], const char* line2, unsigned long time);
		void splash(const char value[], uint8_t line, unsigned long time);
		void setDisplay(const char line1[], const char line2[]);
		void setDisplay(const char value[], uint8_t line);
	private:

		unsigned long revert_time=0;
		char _line[2][17];
};

#endif

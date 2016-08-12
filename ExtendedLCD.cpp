/*
  ExtendedLCD.cpp - Library for handling LCD
  Created by Filip Richter, 30.07.2016.
*/

#include "ExtendedLCD.h"

ExtendedLCD::ExtendedLCD(uint8_t rs, uint8_t rw, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
			     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
:LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7)
{
}

ExtendedLCD::ExtendedLCD(uint8_t rs, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
			     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
:LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7)
{
}

ExtendedLCD::ExtendedLCD(uint8_t rs, uint8_t rw, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
:LiquidCrystal(rs, rw, enable, d0, d1, d2, d3)
{
}

ExtendedLCD::ExtendedLCD(uint8_t rs,  uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
:LiquidCrystal(rs, enable, d0, d1, d2, d3)
{
}

void ExtendedLCD::revert(){
  clear();
  print(_line[0]);
  setCursor(0,1);
  print(_line[1]);
  revert_time=0;
}

void ExtendedLCD::doWork(){
  static long memTime=0;
  if(revert_time && millis()>revert_time){
    revert();
  }
}


void ExtendedLCD::linePrint(const char line1[], const char line2[]){
  strcpy(_line[0],line1);
  strcpy(_line[1],line2);
  clear();
  print(line1);
  setCursor(0,1);
  print(line2);
}

void ExtendedLCD::linePrint_P(const char line1[], const char line2[]){
  strcpy_P(_line[0],line1);
  strcpy_P(_line[1],line2);
  clear();
  print(line1);
  setCursor(0,1);
  print(line2);
}

void ExtendedLCD::linePrint(const char value[], uint8_t line){
  strcpy(_line[line-1],value);
  setCursor(0,line-1);
  print(_line[line-1]);
}

void ExtendedLCD::linePrint_P(const char value[], uint8_t line){
  strcpy_P(_line[line-1],value);
  setCursor(0,line-1);
  print(_line[line-1]);
}

void ExtendedLCD::linePrint(const char value[]){
  linePrint(value, 1);
}

void ExtendedLCD::linePrint_P(const char value[]){
  linePrint_P(value, 1);
}

void ExtendedLCD::splash(const char line1[], const char line2[], unsigned long time){
  clear();
  print(line1);
  setCursor(0,1);
  print(line2);
  revert_time=millis()+time;
}

void ExtendedLCD::splash_P(const char line1[], const char line2[], unsigned long time){
  char buffer[2][17];
  strcpy_P(buffer[0], line1);
  strcpy_P(buffer[1], line2);
  clear();
  print(buffer[0]);
  setCursor(0,1);
  print(buffer[1]);
  revert_time=millis()+time;
}

void ExtendedLCD::splash(const char value[], uint8_t line, unsigned long time){
  setCursor(0, line-1);
  print(value);
  revert_time=millis()+time;
}

void ExtendedLCD::splash_P(const char value[], uint8_t line, unsigned long time){
  char buffer[17];
  strcpy_P(buffer, value);
  setCursor(0, line-1);
  print(buffer);
  revert_time=millis()+time;
}

void ExtendedLCD::setDisplay(const char line1[], const char line2[]){
  strcpy(_line[0],line1);
  strcpy(_line[1],line2);
  if(!revert_time) revert();
}

void ExtendedLCD::setDisplay_P(const char line1[], const char line2[]){
  strcpy_P(_line[0],line1);
  strcpy_P(_line[1],line2);
  if(!revert_time) revert();
}

void ExtendedLCD::setDisplay(const char value[], uint8_t line){
  strcpy(_line[line-1], value);
  if(!revert_time) revert();
}

void ExtendedLCD::setDisplay_P(const char value[], uint8_t line){
  strcpy_P(_line[line-1], value);
  if(!revert_time) revert();
}

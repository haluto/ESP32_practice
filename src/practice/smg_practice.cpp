#include <Arduino.h>
#include "../driver/tm1637/SevenSegmentTM1637.h"

// Module connection pins (Digital Pins)
#define CLK 16
#define DIO 17

SevenSegmentTM1637    display(CLK, DIO);

#define CHAR_COUNT (4) // total 4 chars.
#define SEG_X (B10000000)
static uint8_t segError[] = {TM1637_CHAR_E, TM1637_CHAR_r, TM1637_CHAR_r};

static void displayNumberString(const char str[], SevenSegmentTM1637* display) {
  int len = strlen(str);
  int data_len = 0;
  uint8_t data[CHAR_COUNT];
  bool err = false;

  display->clear();

  for(int i=0; i<len; i++) {
    if(i == 0 && str[i] == '.') {
      err = true;
      break;
    }

    if(str[i] == '0') {data[data_len] = TM1637_CHAR_0;data_len++;}
    else if(str[i] == '1') {data[data_len] = TM1637_CHAR_1;data_len++;}
    else if(str[i] == '2') {data[data_len] = TM1637_CHAR_2;data_len++;}
    else if(str[i] == '3') {data[data_len] = TM1637_CHAR_3;data_len++;}
    else if(str[i] == '4') {data[data_len] = TM1637_CHAR_4;data_len++;}
    else if(str[i] == '5') {data[data_len] = TM1637_CHAR_5;data_len++;}
    else if(str[i] == '6') {data[data_len] = TM1637_CHAR_6;data_len++;}
    else if(str[i] == '7') {data[data_len] = TM1637_CHAR_7;data_len++;}
    else if(str[i] == '8') {data[data_len] = TM1637_CHAR_8;data_len++;}
    else if(str[i] == '9') {data[data_len] = TM1637_CHAR_9;data_len++;}
    else if(str[i] == '.') {data[data_len-1] = data[data_len-1] | SEG_X;} //(i == 0 && '.') has been treated above.
    else {
      err = true;
      break;
    }

    if(data_len == CHAR_COUNT) {
      break;
    }
  }

  if(err) {
    display->printRaw(segError);
  } else {
    display->printRaw(data);
  }
}


void smg_practice_setup() {
  display.begin();
  display.setBacklight(100);
  display.clear();
  display.print("INIT");
  delay(1000);
}

void smg_practice_loop() {
  //display.print("LOOP");
  //delay(1000);
  //display.print("COUNTTING SOME DIGITS");
  //display.clear();
  /*
  for (uint16_t i=0; i<1001; i++) {
    display.print(i);
    delay(100);
  }
  */
  //display.clear();
  //display.print(3456);
  //delay(2000);

  displayNumberString("12w", &display);
  delay(2000);
  displayNumberString("1235", &display);
  delay(2000);
  displayNumberString("12.34", &display);
  delay(2000);
  displayNumberString("3.14", &display);
  delay(2000);
  displayNumberString("8.8.9.0", &display);
  delay(2000);
  displayNumberString(".345", &display);
  delay(2000);

  //display.clear();
  //display.print("SUCC");
  //display.blink(500, 10, 100, 10); //not work.
  //delay(1000);
}


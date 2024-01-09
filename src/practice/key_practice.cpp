#include <key_practice.h>
#include <Arduino.h>

//key connected pins.
#define key1_pin  14 
#define key2_pin  27
#define key3_pin  26
#define key4_pin  25
//led connected pins.
#define led1_pin  15
#define led2_pin  2
#define led3_pin  0
#define led4_pin  4

#define KEY_UNPRESS 0 
#define KEY1_PRESS  1
#define KEY2_PRESS  2
#define KEY3_PRESS  3
#define KEY4_PRESS  4
#define KEY1_RELEASE 5
#define KEY2_RELEASE 6
#define KEY3_RELEASE 7
#define KEY4_RELEASE 8
static bool bKey1Pressed = false;
static bool bKey2Pressed = false;
static bool bKey3Pressed = false;
static bool bKey4Pressed = false;

static unsigned char key_scan_by_pin(unsigned char key_pin)
{
  switch(key_pin) {
  case key1_pin:
    if(!bKey1Pressed && digitalRead(key1_pin)==0) {
      bKey1Pressed = true;
      return KEY1_PRESS;
    }
    if(bKey1Pressed && digitalRead(key1_pin) == 1) {
      bKey1Pressed = false;
      return KEY1_RELEASE;
    }
    break;

  case key2_pin:
    if(!bKey2Pressed && digitalRead(key2_pin)==0) {
      bKey2Pressed = true;
      return KEY2_PRESS;
    }
    if(bKey2Pressed && digitalRead(key2_pin) == 1) {
      bKey2Pressed = false;
      return KEY2_RELEASE;
    }
    break;

  case key3_pin:
    if(!bKey3Pressed && digitalRead(key3_pin)==0) {
      bKey3Pressed = true;
      return KEY3_PRESS;
    }
    if(bKey3Pressed && digitalRead(key3_pin) == 1) {
      bKey3Pressed = false;
      return KEY3_RELEASE;
    }
    break;

  case key4_pin:
    if(!bKey4Pressed && digitalRead(key4_pin)==0) {
      bKey4Pressed = true;
      return KEY4_PRESS;
    }
    if(bKey4Pressed && digitalRead(key4_pin) == 1) {
      bKey4Pressed = false;
      return KEY4_RELEASE;
    }
    break;
  }

  return KEY_UNPRESS;
}

void key_practice_setup(void) {
  pinMode(key1_pin, INPUT_PULLUP);
  pinMode(key2_pin, INPUT_PULLUP);
  pinMode(key3_pin, INPUT_PULLUP);
  pinMode(key4_pin, INPUT_PULLUP);

  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  pinMode(led3_pin, OUTPUT);
  pinMode(led4_pin, OUTPUT);

  digitalWrite(led1_pin,0);
  digitalWrite(led2_pin,0);
  digitalWrite(led3_pin,0);
  digitalWrite(led4_pin,0);
}

void key_practice_loop(void) {
  unsigned char key1_status = key_scan_by_pin(key1_pin);
  if(key1_status == KEY1_PRESS) {
    printf("key1 pressed.\n");
    digitalWrite(led1_pin,1);
  } else if(key1_status == KEY1_RELEASE) {
    printf("key1 released.\n");
    digitalWrite(led1_pin,0);
  }
  unsigned char key2_status = key_scan_by_pin(key2_pin);
  if(key2_status == KEY2_PRESS) {
    printf("key2 pressed.\n");
    digitalWrite(led2_pin,1);
  } else if(key2_status == KEY2_RELEASE) {
    printf("key2 released.\n");
    digitalWrite(led2_pin,0);
  }
  unsigned char key3_status = key_scan_by_pin(key3_pin);
  if(key3_status == KEY3_PRESS) {
    printf("key3 pressed.\n");
    digitalWrite(led3_pin,1);
  } else if(key3_status == KEY3_RELEASE) {
    printf("key3 released.\n");
    digitalWrite(led3_pin,0);
  }
  unsigned char key4_status = key_scan_by_pin(key4_pin);
  if(key4_status == KEY4_PRESS) {
    printf("key4 pressed.\n");
    digitalWrite(led4_pin,1);
  } else if(key4_status == KEY4_RELEASE) {
    printf("key4 released.\n");
    digitalWrite(led4_pin,0);
  }
}
# PRNG_xorshift
Implementing pseudo random number generators for AVR's

## Hardware
* Atmega32U4

## GOALS
* DONE To generate 15 packages with 12 numbers
* DONE Cannot use bigger type than uint32_t
* DONE Final type of result have to be uint8_t
* Range: < 0x04 , 0x27 > u < 0x2D , 0x38 >
* Need at least:
  *  One number from < 0x04 , 0x1D >
  *  One number from < 0x1E , 0x27 >
  *  One number from < 0x2D , 0x38 >
* To create PRNG with variable seed using own xorshift implementation

## TO DO
* Learn how to take seed via ADC pins
* Learn if it's possible to take seed from internal clock

https://en.wikipedia.org/wiki/Xorshift
http://www.retroprogramming.com/2017/07/xorshift-pseudorandom-numbers-in-z80.html
https://github.com/edrosten/8bit_rng

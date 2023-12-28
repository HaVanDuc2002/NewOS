#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>
#include <stdbool.h>

#define low_16(address) (uint16_t)((address) & 0xFFFF)
#define high_16(address) (uint16_t)(((address) >> 16) & 0xFFFF)


void memory_copy(char *source, char *dest, int nbytes);
int string_length(char s[]);
void reverse(char s[]);
void int_to_string(int n, char str[]);
void append(char s[], char n);
bool backspace(char s[]);

#endif

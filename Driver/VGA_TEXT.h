#ifndef VGA_TEXT_H
#define VGA_TEXT_H

#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80

#define VGA_CTRL_REGISTER   0x3D4
#define VGA_DATA_REGISTER   0x3D5
#define VGA_OFFSET_LOW      0x0F
#define VGA_OFFSET_HIGH     0x0E

void print_string(char* string,unsigned char color);
void print_nl();
void clear_screen(unsigned char color);
int scroll_ln(int offset);
void print_backspace(void);

#endif

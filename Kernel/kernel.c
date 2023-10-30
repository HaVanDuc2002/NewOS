#include "../Driver/VGA_TEXT.h"
#include "util.h"
#include "../Driver/color.h"

void start_kernel(){
    clear_screen(BAR_COLOR);
    print_string("\nHello World!\n",BAR_COLOR);
}
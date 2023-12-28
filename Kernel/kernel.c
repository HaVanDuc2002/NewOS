#include "../Driver/VGA_TEXT.h"
#include "util.h"
#include "../Driver/color.h"
#include "../CPU/idt.h"
#include "../CPU/isr.h"
#include "../Driver/keyboard.h"

void start_kernel(){
    clear_screen(BAR_COLOR);
    print_string("Installing interrupt service routines (ISRs).\n",BAR_COLOR);
    isr_install();

    print_string("Enabling external interrupts.\n",BAR_COLOR);
    asm volatile("sti");

    print_string("Initializing keyboard (IRQ 1).\n",BAR_COLOR);
    init_keyboard();
}

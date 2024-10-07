// Code from Kavi for printf to actually work

// Necessary includes for printf to work
#include "print_f.h"


// Function used by printf to send characters to the laptop
int _write(int file, char ptr, int len) {
  int i = 0;
  for (i = 0; i < len; i++) {
    ITM_SendChar((ptr++));
  }
  return len;
}


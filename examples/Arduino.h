#ifndef ARDUINO_DEFINES
#define ARDUINO_DEFINES

#ifdef __cplusplus
#include <cstdint>
#include <cstddef>
#else
#include <stdint.h>
#include <string.h>
#include <stddef.h>
#endif

#define PROGMEM
#define pgm_read_byte(address) (*(address))

#endif

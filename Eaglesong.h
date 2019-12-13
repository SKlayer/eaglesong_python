#ifndef EAGLESONG_H
#define EAGLESONG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void EaglesongHash(uint8_t *output, uint8_t *input, int input_length);

#ifdef __cplusplus
}
#endif

#endif

#ifndef OSAL_H
#define OSAL_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void osal_delay_ms(uint32_t ms);    

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // OSAL_H
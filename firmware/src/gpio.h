#ifndef _GPIO_H_
#define _GPIO_H_

#include <stdbool.h>
#include "fsl_gpio.h"

void gpio_setMilliAmpEn(bool val);
void gpio_setMicroAmpEn(bool val);
void gpio_setNanoAmpEn(bool val);

#endif // _GPIO_H_
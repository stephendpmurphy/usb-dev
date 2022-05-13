#ifndef _GPIO_H_
#define _GPIO_H_

#include <stdbool.h>
#include "fsl_gpio.h"

void gpio_setStat0(bool val);
void gpio_setStat1(bool val);

#endif // _GPIO_H_
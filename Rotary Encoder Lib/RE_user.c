/*
  RE_user.c -
    Copyright (C) 2022 Paulus Kivelä

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef SRC_RE_USER_H
#define SRC_RE_USER_H

#include <stdint.h>

#include "main.h"

volatile int8_t _RE_Ticks;
GPIO_TypeDef *_PB_Port;
uint16_t _PB_Pin;

void RE_user_init(GPIO_TypeDef *PB_Port, uint16_t PB_Pin) {
  _RE_Ticks = 0;
  _PB_Port = PB_Port;
  _PB_Pin = PB_Pin;
}

void RE_user_int_handler(void) {
  if (HAL_GPIO_ReadPin(_PB_Port, _PB_Pin) == GPIO_PIN_SET) {
    _RE_Ticks++;
  } else {
    _RE_Ticks--;
  }
}

int8_t RE_user_getticks(void) {
  const int8_t temp = _RE_Ticks;
  _RE_Ticks = 0;
  return temp;
}

#endif /* SRC_RE_USER_H */

/*
  RE_user.h -
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

#ifndef SRC_RE_USER_H_
#define SRC_RE_USER_H_

//#include "main.h"

// Init function, records port and pin of Encoder pin B
void RE_user_init(GPIO_TypeDef, uint16_t);

// Place into interrupt handler for pin A of Encoder
void RE_user_int_handler(void);

// Get Tick count since last poll (Positive = CW, Negative = CCW)
int8_t RE_user_getticks(void);

#endif /* SRC_RE_USER_H_ */

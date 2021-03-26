/*
 * Submit no.27666091
 * 
 * Copyright (C) 2021. Hyun-Ku Lee
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#define KAGA 5

int main(void)
{
    int loar = 0;
    for(int i = 0; i < KAGA; i++)
    {
        int tmp;
        scanf("%d", &tmp); //input five number with ONE line, but it'll be ok
        loar += tmp * tmp;
    }
    printf("%d", loar % 10);
    return 0;
}
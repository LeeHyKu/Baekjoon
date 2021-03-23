/*
 * Submit no.27578303
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

int csln(int num)
{
    int sum = num;
    
    while(num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main(void)
{
    int nar[10035] = {0, };
    for(int i = 1; i <= 10000; i++)
    {
        nar[csln(i)] = 1;
        if(!nar[i])
            printf("%d\n", i);
    }
    return 0;
}
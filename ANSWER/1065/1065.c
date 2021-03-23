/*
 * Submit no.27578366
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

int min(int ein, int zwi)
{
    return ein < zwi ? ein : zwi;
}

int arit(int n)
{
    int c = min(n, 99);
    for(int i = 100; i <= n; i++)
    {
        int ein =  i / 100,
            zwi = (i % 100) / 10,
            tri =  i % 10;
        if((tri - zwi) == (zwi - ein))
            c++;
    }
    return c;
}

int main(void)
{
    int zie;
    scanf("%d", &zie);
    printf("%d", arit(zie));
    return 0;
}
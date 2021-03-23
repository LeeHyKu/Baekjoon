/*
 * Submit no.27581765
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

int cftl(int von)
{
    if(!von) return 1;
    
    int erg = von;
    for(int i = von - 1; i > 1; i--)
        erg *= i;
    return erg;
}

int main(void)
{
    int na;
    scanf("%d", &na);
    printf("%d", cftl(na));
    return 0;
}
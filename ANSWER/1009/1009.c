/*
 * Submit no.27413492
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

int last(int lain, int laou)
{
    lain = lain % 10;
    laou = laou % 4;
    if(laou == 0) laou = 4;
    
    int resu = lain;
    for(int i = 1; i < laou; i++)
        resu *= lain;
    resu = resu % 10;
    if(resu == 0) resu = 10;
    return resu;
}

int main(void)
{
    int lao;
    scanf("%d", &lao);
    
    for(int _i = 0; _i < lao; _i++)
    {
        int lain, laou;
        scanf("%d %d", &lain, &laou);
        printf("%d\n", last(lain, laou));
    }
    return 0;
}
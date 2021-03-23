/*
 * Submit no.27543038
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

int ater(int pnz, int eke)
{
    return 2 - (pnz - eke);
}

int main(void)
{
    int tca;
    scanf("%d", &tca);
    for(int _i = 0; _i < tca; _i++)
    {
        int pnz, eke;
        scanf("%d %d", &pnz, &eke);
        printf("%d\n", ater(pnz, eke));
    }
    return 0;
}
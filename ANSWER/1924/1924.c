/*
 * Submit no.27581659
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

const int MNT = 30;
const int KLI[12] = {
    1, -2, 1,
    0, 1, 0,
    1, 1, 0,
    1, 0, 1
};
const char TAG[7][4] = {
    "MON", "TUE", "WED",
    "THU", "FRI", "SAT",
    "SUN"
};

int clmd(int mna)
{
    mna--;
    int erg = 0;
    for(int i = 0; i < mna; i++)
        erg += MNT + KLI[i];
    return erg;
}

int main(void)
{
    int mna, tag;
    scanf("%d %d", &mna, &tag);
    printf(TAG[(clmd(mna) + tag - 1) % 7]);
    return 0;
}
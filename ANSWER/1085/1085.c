/*
 * Submit no.27447158
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

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int diffrance(int a, int b)
{
    return max(a, b) - min(a, b);
}

int main(void)
{
    int x, y, tx, ty;
    scanf("%d %d %d %d", &x, &y, &tx, &ty);
    int r = min(
        min(x, diffrance(x, tx)),
        min(y, diffrance(y, ty))
    );
    printf("%d", r);
    return 0;
}
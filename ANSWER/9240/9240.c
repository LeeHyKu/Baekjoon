/*
 * Submit no.27876928
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
#include <math.h>

/* ==========[Dienstprogramm]========== */
int qdrt(int ein)
{
    return ein * ein;
}

int entf(int ex, int ey, int zx, int zy)
{
    return qdrt(zx - ex) + qdrt(zy - ey);
}

/* ==========[Programmläufer]========== */
int main(void)
{
    int grs;
    scanf("%d", &grs);
    char xv[2002] = { 0, };
    int  xa[2002],
         xi[2002];
    
    for(int i = 0; i < grs; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        x += 1000;
        if(!xv[x])
        {
            xa[x] = xi[x] = y;
            xv[x] = 1;
        }
        else
        {
            if(xa[x] < y)
                xa[x] = y;
            else if(xi[x] > y)
                xi[x] = y;
        }
    }

    int erg = 0;
    for(int i = 0; i < 2002; i++)
    {
        if(!xv[i])
            continue;
        for(int j = i; j < 2002; j++)
        {
            if(!xv[j])
                continue;
            int ein = entf(i, xa[i], j, xi[j]),
                zwi = entf(i, xi[i], j, xa[j]);
            if(ein > erg)
                erg = ein;
            if(zwi > erg)
                erg = zwi;
        }
    }

    printf("%.9lf", sqrt(erg));
    return 0;
}
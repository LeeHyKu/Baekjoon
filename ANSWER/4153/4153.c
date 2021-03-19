/*
 * Submit no.27447672
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
#include <stdlib.h>
#include <math.h>

typedef struct trident
{
    int x;
    int y;
    int r;
} Trident;

int mxnu(int a, int b)
{
    return a > b ? a : b;
}

int maxi(Trident *tri)
{
    return mxnu(mxnu(tri->x, tri->y), tri->r);
}

Trident* alin(Trident *tri)
{
	int x = tri->x;
	int y = tri->y;
	int r = tri->r;
	
    int mx = maxi(tri);
    int a = x != mx ? x :
			y != mx ? y :
					  r;
	int b = x != mx && x != a ? x :
			y != mx && y != a ? y :
								r;
	
	Trident *rs = (Trident*)malloc(sizeof(Trident));
	rs->x = a;
	rs->y = b;
	rs->r = mx;
	return rs;
}

int ckan(Trident *tri)
{
	Trident *al = alin(tri);
	int rs = (
		((al->x * al->x) + (al->y * al->y)) ==
			(al->r * al->r)
	);
	free(al);
	return rs;
}

int main()
{
    while(1)
    {
        Trident *loar = (Trident*)malloc(sizeof(Trident));
        scanf("%d %d %d", &loar->x, &loar->y, &loar->r);
        if(loar->x != 0 && loar->y != 0 && loar->r != 0)
        {
            printf(ckan(loar) ? "right\n" : "wrong\n");
            free(loar);
        }
        else
        {
            free(loar);
            break;
        }
    }
    return 0;
}
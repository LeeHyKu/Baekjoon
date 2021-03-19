/*
 * Submit no.27454038
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
#define AZR 3

typedef struct
{
    int x;
    int y;
} Vector;

Vector* love()
{
    return (Vector*)malloc(sizeof(Vector));
}

Vector** lova(int lt)
{
    Vector** rs = (Vector**)malloc(sizeof(Vector) * lt);
    for(int i = 0; i < lt; i++)
        rs[i] = (Vector*)malloc(sizeof(Vector));
    return rs;
}

void frva(Vector ***va, int lt)
{
    for(int i = 0; i < lt; i++)
        free((*va)[i]);
    free(*va);
    return;
}

int ccw(Vector *von, Vector *mid, Vector *zu)
{
    int tmp = (von->x * mid->y) + (mid->x * zu->y) + (zu->x * von->y);
    tmp -= (von->y * mid->x) + (mid->y * zu->x) + (zu->y * von->x);
    if(tmp > 0) return 1;
    else if(tmp < 0) return -1;
    else return 0;
}

int main(void)
{
    Vector **ip = lova(AZR);
    for(int i = 0; i < AZR; i++)
        scanf("%d %d", &ip[i]->x, &ip[i]->y);
    printf("%d", ccw(ip[0], ip[1], ip[2]));
    frva(&ip, AZR);
    return 0;
}
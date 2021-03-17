/*
 * Submit no.27391636
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

typedef struct location
{
    int x;
    int y;
    int r;
} Location;

int dif(int a, int b)
{
    return fmax(a, b) - fmin(a, b);
}

double dist(Location *alfa, Location *beta)
{
    int x = dif(alfa->x, beta->x);
    int y = dif(alfa->y, beta->y);
    return sqrt((x * x) + (y * y));
}

int over(Location *alfa, Location *beta)
{
    double dst = dist(alfa, beta);
    int pr = alfa->r + beta->r;
    int nx = abs(alfa->r - beta->r);
    if(dst == 0 && alfa->r == beta->r) return -1;
    else if((alfa->r + dst) < beta->r || (beta->r + dst) < alfa->r) return 0;
    else if(pr == dst || nx == dst) return 1;
    else if(pr > dst && nx < dst) return 2;
    else if(pr < dst && nx > dst) return 0;
    else return 0;
}

int main(void)
{
    int lo;
    scanf("%d", &lo);

    for(int i = 0; i < lo; i++){
        Location
            *alfa = (Location*)malloc(sizeof(Location)),
            *beta = (Location*)malloc(sizeof(Location));
        scanf("%d %d %d %d %d %d",
                &alfa->x, &alfa->y, &alfa->r,
                &beta->x, &beta->y, &beta->r
        );
        printf("%d\n", over(alfa, beta));
        free(alfa);
        free(beta);
    }
}
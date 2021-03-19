/*
 * Submit no.27412431
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

typedef struct vector
{
    int x;
    int y;
} Vector;

typedef struct circle
{
    int x;
    int y;
    int r;
} Circle;

int isin(Vector *als, Circle *auf)
{
    return (
        pow(auf->x - als->x, 2) + pow(auf->y  - als->y, 2) 
            <
        pow(auf->r, 2)
    );
}

int idex(Vector *von, Vector *zu, int loin, Circle ** loar)
{
    int rtn = 0;

    for(int _i = 0; _i < loin; _i++)
    {
        Circle *losi = loar[_i];
        if(isin(von, losi) ^ isin(zu, losi))
            rtn++;
    }

    return rtn;
}

int main(void)
{
    int la;
    scanf("%d", &la);
    for(int _i = 0; _i < la; _i++)
    {
        Vector
            *von = (Vector*)malloc(sizeof(Vector)),
            *zu  = (Vector*)malloc(sizeof(Vector));
        
        scanf("%d %d %d %d",
                &von->x, &von->y,
                &zu->x,  &zu->y
        );

        int loin;
        scanf("%d", &loin);

        Circle**
            loar = (Circle**)malloc(loin * sizeof(Circle));
        
        for(int _j = 0; _j < loin; _j++)
        {
            loar[_j] = (Circle*)malloc(sizeof(Circle));
            scanf("%d %d %d",
                    &loar[_j]->x,
                    &loar[_j]->y,
                    &loar[_j]->r
            );
        }

        printf("%d\n", idex(von, zu, loin, loar));

        free(von);
        free(zu);
        for(int _k = 0; _k < loin; _k++)
            free(loar[_k]);
        free(loar);
    }
    return 0;
}
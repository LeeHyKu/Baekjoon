/*
 * Submit no.27449387
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

typedef struct
{
    int x;
    int y;
} Vector;

int mxnu(int a, int b)
{
    return a > b ? a : b;
}

int minu(int a, int b)
{
    return a < b ? a : b;
}

int eqal(Vector *a, Vector *b)
{
    return (a->x == b->x) && (a->y == b->y);
}

Vector* cvtr(int x, int y)
{
    Vector* rs = (Vector*)malloc(sizeof(Vector));
    rs->x = x;
    rs->y = y;
    return rs;
}

void vsfr(Vector **v)
{
    free(*v);
}

void rtfr(Vector ***a)
{
    for(int _i = 0; _i < 4; _i++)
        vsfr(&(*a)[_i]);
    free(*a);
}

Vector** rect(Vector *a, Vector *b, Vector *c)
{
    int xx = mxnu(mxnu(a->x, b->x), c->x);
    int xy = mxnu(mxnu(a->y, b->y), c->y);
    int ix = minu(minu(a->x, b->x), c->x);
    int iy = minu(minu(a->y, b->y), c->y);

    Vector** rsar = (Vector**)malloc(sizeof(Vector) * 4);
    rsar[0] = cvtr(ix, xy);
    rsar[1] = cvtr(xx, xy);
    rsar[2] = cvtr(ix, iy);
    rsar[3] = cvtr(xx, iy);
    return rsar;
}

Vector* rmin(Vector *a, Vector *b, Vector *c)
{
    Vector** al = rect(a, b, c);
    Vector* rs;
    for(int _i = 0; _i < 4; _i++)
    {
        Vector* _c = al[_i];
        if(!eqal(_c, a) && !eqal(_c, b) && !eqal(_c, c))
        {
            rs = cvtr(_c->x, _c->y);
            break;
        }
    }

    rtfr(&al);
    return rs;
}

int main(void)
{
    Vector *a = (Vector*)malloc(sizeof(Vector)),
           *b = (Vector*)malloc(sizeof(Vector)),
           *c = (Vector*)malloc(sizeof(Vector));
    scanf("%d %d", &a->x, &a->y);
    scanf("%d %d", &b->x, &b->y);
    scanf("%d %d", &c->x, &c->y);

    Vector *rs = rmin(a, b, c);
    printf("%d %d", rs->x, rs->y);

    vsfr(&a);
    vsfr(&b);
    vsfr(&c);
    vsfr(&rs);
    return 0;
}
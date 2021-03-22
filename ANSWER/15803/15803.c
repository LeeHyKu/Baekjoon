/*
 * Submit no.27542212
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

typedef struct
{
    int x;
    int y;
} Vektor;

Vektor* lvec()
{
    return (Vektor*)malloc(sizeof(Vektor));
}

Vektor** avec(int meg)
{
    Vektor **erg = (Vektor**)malloc(sizeof(Vektor) * meg);
    for(int i = 0; i < meg; i++)
        erg[i] = lvec();
    return erg;
}

Vektor* grsr(Vektor* ein, Vektor* zwi, Vektor* tri)
{
    if((ein->x > zwi->x) ^ (ein->x > tri->x)) return ein;
    else if((zwi->x > ein->x) ^ (zwi->x > tri->x)) return zwi;
    else return tri;
}

Vektor* grsy(Vektor* ein, Vektor* zwi, Vektor* tri)
{
    if((ein->y > zwi->y) ^ (ein->y > tri->y)) return ein;
    else if((zwi->y > ein->y) ^ (zwi->y > tri->y)) return zwi;
    else return tri;
}

int glei(Vektor* ein, Vektor* zwi, Vektor* tri)
{
    return ein->x == zwi->x && zwi->x == tri->x;
}

Vektor** ordn(Vektor* ein, Vektor* zwi, Vektor* tri)
{
    Vektor **erg = avec(3);
    
    erg[1] = glei(ein, zwi, tri) ? grsy(ein, zwi, tri) : grsr(ein, zwi, tri);
    erg[0] = ein != erg[1] ? ein : zwi != erg[1] ? zwi : tri;
    erg[2] = zwi != erg[1] && zwi != erg[0] ? zwi : tri;
    return erg;
}

double neig(Vektor* von, Vektor* zu)
{
    return ((zu->y - von->y) * 1.0) / ((zu->x - von->x) * 1.0);
}

int main(void)
{
    Vektor *ein = lvec(),
           *zwi = lvec(),
           *tri = lvec();
    
    scanf("%d %d", &ein->x, &ein->y);
    scanf("%d %d", &zwi->x, &zwi->y);
    scanf("%d %d", &tri->x, &tri->y);

    Vektor **odn = ordn(ein, zwi, tri);

    double esl = neig(odn[0], odn[1]),
           zsl = neig(odn[1], odn[2]);
    
    printf(esl == zsl ? "WHERE IS MY CHICKEN?" : "WINNER WINNER CHICKEN DINNER!");
    free(odn);
    free(ein);
    free(zwi);
    free(tri);
    return 0;
}
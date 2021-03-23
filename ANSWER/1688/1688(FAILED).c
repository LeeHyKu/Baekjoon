//FAILED
//좌표가 특정하게(자세히는 모름) 정렬되어 있어야 합니다.
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Vektor;

typedef struct
{
    int wan;
    Vektor **ves;
} Polygon;

Vektor* lvec()
{
    return (Vektor*)malloc(sizeof(Vektor));
}

Vektor** avec(int wan)
{
    Vektor** erg = (Vektor**)malloc(sizeof(Vektor*) * wan);
    for(int i = 0; i < wan; i++)
        erg[i] = lvec();
    return erg;
}

Polygon* lpol(int wan)
{
    Polygon* erg = (Polygon*)malloc(sizeof(Polygon));
    erg->wan = wan;
    erg->ves = avec(wan);
    return erg;
}

void favc(Vektor*** vc, int wan)
{
    for(int i = 0; i < wan; i++)
        free((*vc)[i]);
    free(*vc);
}

void fpol(Polygon** pol)
{
    favc(&(*pol)->ves, (*pol)->wan);
    free(*pol);
}

int innr(Polygon* pol, Vektor* vec)
{
    int sit = 0;
    for(int i = 0; i < pol->wan; i++)
    {
        int j = (i + 1) % pol->wan;
        Vektor *v = pol->ves[i],
               *w = pol->ves[j];
        if((v->y > vec->y) ^ (w->y > vec->y))
        {
            double jax = (w->x - v->x) * (vec->y - v->y) / (w->y - v->y) + v->x;
            if(vec->x < jax)
                sit++;
        }
    }
    return sit % 2 > 0;
}

int main(void)
{
    int wan;
    scanf("%d", &wan);

    Polygon* pol = lpol(wan);

    for(int i = 0; i < wan; i++)
        scanf("%d %d", &pol->ves[i]->x, &pol->ves[i]->y);
    
    for(int i = 0; i < 3; i++)
    {
        Vektor* vec = lvec();
        scanf("%d %d", &vec->x, &vec->y);
        printf(innr(pol, vec) ? "1\n" : "0\n");
        free(vec);
    }

    fpol(&pol);
    return 0;
}
*/
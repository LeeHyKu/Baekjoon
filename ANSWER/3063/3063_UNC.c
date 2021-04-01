/*
 * UNCOMPLATE SOLUTION
 * 
 * Copyright (C) 2021. Hyun-Ku Lee
 * 
 *  Dieses Programm ist freie Software. Sie können es unter den Bedingungen
 *  der GNU General Public License, wie von der Free Software Foundation
 *  veröffentlicht, weitergeben und/oder modifizieren, entweder gemäß Version 3
 *  der Lizenz oder (nach Ihrer Option) jeder späteren Version.
 * 
 *  Die Veröffentlichung dieses Programms erfolgt in der Hoffnung, daß es Ihnen
 *  von Nutzen sein wird, aber OHNE IRGENDEINE GARANTIE, sogar ohne die implizite
 *  Garantie der MARKTREIFE oder der VERWENDBARKEIT FÜR EINEN BESTIMMTEN ZWECK.
 *  Details finden Sie in der GNU General Public License.
 *
 *  Sie sollten ein Exemplar der GNU General Public License zusammen mit diesem
 *  Programm erhalten haben. Falls nicht, siehe http://www.gnu.org/licenses/.
 */
#include <stdio.h>
#include <stdlib.h>

/* ==========[Dienstprogramm]========== */
int abslt(int zhl)
{
    return zhl > 0 ? zhl : -zhl;
}

int maxzl(int ein, int zwi)
{
    return ein > zwi ? ein : zwi;
}

int minzl(int ein, int zwi)
{
    return ein < zwi ? ein : zwi;
}

/* ==========[Vektor Objekt]========== */
typedef struct
{
    int x;
    int y;
} Vektor;

Vektor* vkloc()
{
    return (Vektor*)malloc(sizeof(Vektor));
}

int vkgrs(Vektor* von, Vektor* zu)
{
    return abslt(von->x - zu->x) * abslt(von->y - zu->y);
}

int konflt(Vektor* evon, Vektor* ezu, Vektor* zvon, Vektor* zzu)
{
//EIN
    int evx = maxzl(evon->x, ezu->x),
        evy = maxzl(evon->y, ezu->y),
        ezx = minzl(evon->x, ezu->x),
        ezy = minzl(evon->y, ezu->y),
//ZWEI
        zvx = maxzl(zvon->x, zzu->x),
        zvy = maxzl(zvon->y, zzu->y),
        zzx = minzl(zvon->x, zzu->x),
        zzy = minzl(zvon->y, zzu->y);
    
    if(
        ezx < zvx ||
        evx > zzx ||
        ezy < zvy ||
        evy > zzy
    )    return 0;
    else return abslt((minzl(ezx, zzx) - maxzl(evx, zvx)) * (minzl(ezy, zzy) - maxzl(evy, zvy)));
}

/* ==========[Programmläufer]========== */
int main(void)
{
    int slf;
    scanf("%d", &slf);
    for(int _i = 0; _i < slf; _i++)
    {
        Vektor *evon = vkloc(),
               *ezu  = vkloc(),
               *zvon = vkloc(),
               *zzu  = vkloc();
        scanf("%d %d %d %d %d %d %d %d",
                &evon->x, &evon->y, &ezu->x, &ezu->y,
                &zvon->x, &zvon->y, &zzu->x, &zzu->y
        );
        printf("%d\n", maxzl(vkgrs(evon, ezu) - konflt(evon, ezu, zvon, zzu), 0));
        free(evon);
        free(ezu);
        free(zvon);
        free(zzu);
    }
    return 0;
}
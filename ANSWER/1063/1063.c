/*
 * Einreich 27798507
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
#define KAGA 8

const char STL[KAGA] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' //if change KAGA, adjust this too
};

int fndt(char t)
{
    for(int i = 0; i < KAGA; i++)
    {
        if(t == STL[i])
            return i;
    }
    return -1;
}

typedef struct
{
    int x;
    int y;
} Vektor;

Vektor* vklc()
{
    return (Vektor*)malloc(sizeof(Vektor));
}

Vektor* vkcr(char x, int y)
{
    Vektor *erg = vklc();
    erg->x = fndt(x);
    erg->y = KAGA - y;
    return erg;
}

Vektor* vkci(int x, int y)
{
    Vektor *erg = vklc();
    erg->x = x;
    erg->y = y;
    return erg;
}

Vektor* vkmv(char *c)
{
    switch(c[0])
    {
        case 0x52:                  //R GRUPPEN
            if(c[1] == 0x54)            //RT
                return vkci(1, -1);
            else if(c[1] == 0x42)       //RB
                return vkci( 1,  1);
            else                        //R
                return vkci( 1,  0);
        case 0x4C:                  //L GRUPPEN
            if(c[1] == 0x54)            //LT
                return vkci(-1, -1);
            else if(c[1] == 0x42)       //LB
                return vkci(-1,  1);
            else                        //L
                return vkci(-1,  0);
        case 0x54:                  //T
                return vkci( 0, -1);
        case 0x42:                  //B
                return vkci( 0,  1);
    }
}

int vkab(Vektor *vkt, Vektor *cpr)
{
    int x = vkt->x + cpr->x,
        y = vkt->y + cpr->y;
    return x >= 0 && x < KAGA && y >= 0 && y < KAGA;
}

int vkcl(Vektor *ksr, Vektor *dol, Vektor *cpr)
{
    int x = ksr->x + cpr->x,
        y = ksr->y + cpr->y;
    return (x == dol->x) && (y == dol->y);
}

void vkcp(Vektor *vkt, Vektor *cpr)
{
    vkt->x += cpr->x;
    vkt->y += cpr->y;
}

void vkdm(Vektor *ksr, Vektor *dol, Vektor *cpr)
{
    int cl = vkcl(ksr, dol, cpr);
    if(vkab(ksr, cpr) && (!cl || vkab(dol, cpr)))
    {
        if(cl) vkcp(dol, cpr);
        vkcp(ksr, cpr);
    }
}

void vkpr(Vektor *vkt)
{
    printf("%c%d\n", STL[vkt->x], KAGA - vkt->y);
}

int main(void)
{
    char kx, dx;
    int  ky, dy, mv;
    scanf("%c%d %c%d %d", &kx, &ky, &dx, &dy, &mv);
    
    Vektor *ksr = vkcr(kx, ky),
           *dol = vkcr(dx, dy);
    for(int _i = 0; _i < mv; _i++)
    {
        char mvd[3];
        scanf("%s", &mvd);
        Vektor *cpr = vkmv(mvd);
        vkdm(ksr, dol, cpr);
        free(cpr);
    }

    vkpr(ksr);
    vkpr(dol);
    free(ksr);
    free(dol);

    return 0;
}
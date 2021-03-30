/*
 * Einreich 27834027
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
#include <math.h>

/*==========[Zusammenbau]==========*/
typedef enum
{
    SPK,
    LTK,
    SWN,
    NIN,
    ABN,
    ERH,
    SPR,
    HLT
} Befehl;

Befehl calbef(unsigned char m)
{
    return m / 0b100000;
}

char calzah(unsigned char m)
{
    return m % 0b100000;
}

const char bist[16][5] = {
    "0000", "0001", "0010", "0011",
    "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011",
    "1100", "1101", "1110", "1111"
};

void pribin(unsigned char m)
{
    printf("%s%s\n", bist[m / 0x10], bist[m % 0x10]);
}

/*==========[Von Neumann Architektur]==========*/
typedef struct
{
    unsigned char ged[32];
    unsigned char zgr;
    unsigned char akm;
    char ede;
} Vonneum;

Vonneum* vloc()
{
    Vonneum *erg = malloc(sizeof(Vonneum));
    erg->zgr = 0;
    erg->akm = 0;
    erg->ede = 0;
    return erg;
}

void vmlc(Vonneum *von, int ind, char *c)
{
    unsigned char erg = 0;
    for(int i = 0; i < 8; i++)
    {
        int a = c[i] - 0x30;
        if(a)
            erg += pow(2, 7 - i);
    }
    von->ged[ind] = erg;
}

void vrun(Vonneum *von)
{
    if(von->ede) return;
    while(1)
    {
        char bef = calbef(von->ged[von->zgr]),
             zah = calzah(von->ged[von->zgr]);
        von->zgr = (von->zgr + 1) & 0x1F;
        switch(bef)
        {
            case SPK:
                von->ged[zah] = von->akm;
                break;
            case LTK:
                von->akm = von->ged[zah];
                break;
            case ABN:
                von->akm--;
                break;
            case ERH:
                von->akm++;
                break;
            case SWN:
                if(von->akm) break;
            case SPR:
                von->zgr = zah;
                break;
            case HLT:
                goto EXT;
        }
    }
EXT:
    von->ede = 1;
    return;
}

/*==========[Programmläufer]==========*/
int main(void)
{
    char flg = 1;
    while(flg)
    {
        Vonneum *von = vloc();
        for(int i = 0; i < 32; i++)
        {
            char egb[9];
            if(scanf("%s", &egb) < 1)
            {
                flg = 0;
                goto LST;
            }
            else vmlc(von, i, egb);
        }
        vrun(von);
        pribin(von->akm);
    LST:
        free(von);
    }
    return 0;
}
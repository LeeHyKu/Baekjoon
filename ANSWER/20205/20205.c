/*
 * Einreich 27911923
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
int** ewitrn(int *ckr, int urs, int gzu)
{
    int **erg = (int**)malloc(sizeof(int*) * gzu);
    for(int i = 0; i < gzu; i++)
        erg[i] = (int*)malloc(sizeof(int) * gzu * urs);
    for(int i = 0; i < urs; i++)
    {
        int zil = ckr[i];
        for(int j = 0; j < gzu; j++)
            for(int k = 0; k < gzu; k++)
                erg[j][i * gzu + k] = zil;
    }
    return erg;
}

void druckn(int **ckr, int lin, int urs)
{
    int zil = lin * urs;
    for(int i = 0; i < lin; i++)
    {
        for(int j = 0; j < zil; j++)
            printf("%d ", ckr[i][j]);
        printf("\n");
    }
    return;
}

/* ==========[Programmläufer]========== */
int main(void)
{
    int urs, gzu;
    scanf("%d %d", &urs, &gzu);
    for(int _i = 0; _i < urs; _i++)
    {
        int* uck = (int*)malloc(sizeof(int) * urs);
        for(int j = 0; j < urs; j++)
            scanf("%d", &uck[j]);
        druckn(ewitrn(uck, urs, gzu), gzu, urs);
        free(uck);
    }
    return 0;
}
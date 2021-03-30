/*
 * Einreich 27832605
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
#include <math.h>

typedef enum
{
    STA,
    LDA,
    BEQ,
    NOP,
    DEC,
    INC,
    JMP,
    HLT
}   Befehl;

char srtobi(char *s)
{
    return (
        (s[0] == 0x31 ? 128 : 0) +
        (s[1] == 0x31 ?  64 : 0) +
        (s[2] == 0x31 ?  32 : 0) +
        (s[3] == 0x31 ?  16 : 0) +
        (s[4] == 0x31 ?   8 : 0) +
        (s[5] == 0x31 ?   4 : 0) +
        (s[6] == 0x31 ?   2 : 0) +
        (s[7] == 0x31 ?   1 : 0)
    );
}

Befehl calbef(unsigned char m)
{
    return m / 0b100000;
}

char calzah(unsigned char m)
{
    return m % 0b100000;
}

void pribin(unsigned char m)
{
    const char *bit_rep[16] = {
        [ 0] = "0000", [ 1] = "0001", [ 2] = "0010", [ 3] = "0011",
        [ 4] = "0100", [ 5] = "0101", [ 6] = "0110", [ 7] = "0111",
        [ 8] = "1000", [ 9] = "1001", [10] = "1010", [11] = "1011",
        [12] = "1100", [13] = "1101", [14] = "1110", [15] = "1111",
    };
    
    printf("%s%s\n", bit_rep[m / 0x10], bit_rep[m % 0x10]);
}

int main(void)
{
    while(1)
    {
        unsigned char mem[32];

        for(int i = 0; i < 32; i++)
        {
            char egb[9];
            if(scanf("%s", &egb) < 1) goto END;
            mem[i] = srtobi(egb);
        }

        unsigned char 
            ptr = 0,
            rgt = 0;
        while(1)
        {
            char
                bef = calbef(mem[ptr]),
                zah = calzah(mem[ptr]);
            ptr++;
            ptr &= 0x1F;
            switch(bef)
            {
                case STA:
                    mem[zah] = rgt;
                    break;
                case LDA:
                    rgt = mem[zah];
                    break;
                case BEQ:
                    if(!rgt) ptr = zah;
                    break;
                case DEC:
                    rgt--;
                    break;
                case INC:
                    rgt++;
                    break;
                case JMP:
                    ptr = zah;
                    break;
                case HLT:
                    goto EXT;
            }
            
        }
    EXT:
        pribin(rgt);
    }
END:
    return 0;
}
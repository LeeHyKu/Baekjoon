/*
 * Submit no.27547563
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
#define AKAGI 1000001

int main(void)
{
    int tcs,
        gst = AKAGI,
        kst = AKAGI;
    scanf("%d", &tcs);
    for(int _i = 0; _i < tcs; _i++)
    {
        int kas;
        scanf("%d", &kas);
        if(gst < kas || gst == AKAGI) gst = kas;
        if(kst > kas || kst == AKAGI) kst = kas;
    }
    printf("%d %d", kst, gst);
    return 0;
}
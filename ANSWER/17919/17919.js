/*
 * Submit no.27583348
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
var sch = require('fs').readFileSync('/dev/stdin').toString().split(' ');
var ges = 0, zah = 0;
for(var s of sch){
    ges++;
    if(s.includes('ae'))
        zah++;
}
console.log((zah / ges) >= 0.4 ? 
            'dae ae ju traeligt va' : 
            'haer talar vi rikssvenska'
);
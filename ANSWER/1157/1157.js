/*
 * Submit no.27579366
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
var fs = require('fs');
var input = fs.readFileSync('/dev/stdin').toString().toUpperCase();
var alp = 'qwertyuiopasdfghjklzxcvbnm'.toUpperCase().split('');
var rs = [];
for(var a of alp){
    var mat = input.match(RegExp(a, 'g'))
    if(mat) rs.push({ l: a, m: mat?.length });
}
    
rs = rs.sort((n, p) => p?.m - n?.m);
if(rs[0]?.m == rs[1]?.m) console.log('?');
else console.log(rs[0]?.l);
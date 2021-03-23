/*
 * Submit no.27549329
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
var input = fs.readFileSync('/dev/stdin').toString().split('\n')[1].split(' ')
var max = 0;
for(var i of input){
    if(+i > max) max = i;
}
for(var i = 0; i < input.length; i++){
    input[i] = input[i] / max * 100;
}

var t = 0;
for(var i of input)
    t += i
console.log((t / input.length).toFixed(5))
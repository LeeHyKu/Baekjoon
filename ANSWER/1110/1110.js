/*
 * Submit no.27374387
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
var input = (+fs.readFileSync('/dev/stdin').toString()).toString();
if(+input < 10) input = `0${input}`;
var cp = input;

var result = 0;
while(true){
    result++;
    var ca = ((parseInt(cp[0])) + (parseInt(cp[1]))).toString();
    cp = `${cp[1]}${ca[ca.length - 1]}`;
    if(cp == input) break;
}
console.log(result);
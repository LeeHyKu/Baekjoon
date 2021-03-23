/*
 * Submit no.27549621
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
var input = fs.readFileSync('/dev/stdin').toString().split('\n');

const O = 'O';

var loop = +input.splice(0, 1)[0];
for(var i = 0; i < loop; i++){
    var str = input[i].split('');
    var sco = 0;
    var com = 0;
    for(var j of str){
        if(j == O) sco += ++com;
        else com = 0;
    }
    console.log(sco)
}
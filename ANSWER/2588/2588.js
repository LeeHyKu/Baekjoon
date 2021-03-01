/*
 * Submit no.26850946
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

var a = input[0];
var b = [
	input[1][0],
	input[1][1],
	input[1][2]
];
var c = input[1];

console.log(a * b[2]);
console.log(a * b[1]);
console.log(a * b[0]);
console.log(a * c);
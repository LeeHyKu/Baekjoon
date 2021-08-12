/*
 * Standard Input and Output in Javascript(Node.js)
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
//INPUT ROUTINE
	var input = require('fs').readFileSync('/dev/stdin').toString(); //nein! Diese Routine verursacht wahrscheinlich Fehler!!!

	var inp = [];
	require('readline').createInterface({
		input: process.stdin,
  		output: process.stdout,
	}).on('line', l=>inp.push(l))
	  .on('close', ()=>{
		  //tun!!
	  });

//OUTPUT ROUTINE
	console.log(input);
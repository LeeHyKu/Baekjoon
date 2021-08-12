/*
 * Einreich 32125840
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
const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

var v = [];

rl.on('line', (l) => v.push(l)).on('close', ()=>
	console.log(v.slice(1).map(e => ({
		o: e,
		s: e.toLowerCase().replace(/ng/g, 'z')
			.replace(/k/g, 'c')
			.replace(/g/g, 'f')
			.replace(/h/g, 'g')
			.replace(/i/g, 'h')
			.replace(/l/g, 'i')
			.replace(/m/g, 'j')
			.replace(/n/g, 'k')
			.replace(/z/g, 'l')
			.replace(/o/g, 'm')
			.replace(/p/g, 'n')
			.replace(/r/g, 'o')
			.replace(/s/g, 'p')
			.replace(/t/g, 'q')
			.replace(/u/g, 'r')
			.replace(/w/g, 's')
			.replace(/y/g, 't')
	})).sort((a,b)=>{ return a.s > b.s ? 1 : a.s == b.s ? 0 : -1; }).map(e => e.o).join('\n'))
);
/*
 * Einreich 33807837
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
var inp = '',
    pre = {
        A: 2, B: 2, C: 2,
        D: 3, E: 3, F: 3,
        G: 4, H: 4, I: 4,
        J: 5, K: 5, L: 5,
        M: 6, N: 6, O: 6,
        P: 7, Q: 7, R: 7, S: 7,
        T: 8, U: 8, V: 8,
        W: 9, X: 9, Y: 9, Z: 9
    };
require('readline').createInterface({input: process.stdin, output: process.stdout}).on('line', l=>inp += l).on('close', ()=>console.log(inp.split('').map(e => pre[e] + 1).reduce((a, b) => (a ?? 0) + b)));
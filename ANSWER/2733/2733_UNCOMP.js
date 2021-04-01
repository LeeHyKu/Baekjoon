/*
 * UNCOMPLATE SOURCE
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
var ns = require('fs').readFileSync('/dev/stdin').toString()
            .split('\n').slice(1).map(e => e.includes('%') ? e.slice(0, e.indexOf('%')) : e)
            .join('').split('end');

ns.splice(ns.length - 1, 1);

var i = 1;
for(var n of ns) {
    var che = [],
        cha = 0,
        paa = 0,
        buf = [],
        mem = [],
        ptr = 0,
        pas = false;
    n = n.split('');
    for(var id = 0; id < n.length; id++){
        if(pas && n[id] != ']' && n[id] != '[') continue;
        var c = n[id];
        switch(c){
            case '+':
                mem[ptr] = ((mem[ptr] ?? 0) + 1) % 32768;
                break;
            case '-':
                var a = (mem[ptr] ?? 0) - 1;
                mem[ptr] = a < 0 ? 32767 : a;
                break;
            case '>':
                ptr = (ptr + 1) % 256;
                break;
            case '<':
                var p = ptr - 1;
                ptr = p < 0 ? 255 : p;
                break;
            case '.':
                buf.push(mem[ptr] ?? 0);
                break;
            case '[':
                if(pas) { paa++; cha++; }
                else if(mem[ptr] ?? 0) { che.push(id); cha++; }
                else {pas = true; paa++; cha++; }
                break;
            case ']':
                if(pas) cha--;
                if(pas && !--paa) pas = false;
                else{
                    if((mem[ptr] ?? 0) && (cha > 0)) id = che[che.length - 1];
                    else { che.pop(); cha--; }
                }
                break;
        }
    }
    console.log(`PROGRAM #${i++}:`);
    console.log(cha ? 'COMPILE ERROR' : buf.map(e => String.fromCharCode(e)).join(''));
}
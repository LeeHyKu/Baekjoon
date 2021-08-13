/*
 * Einreich 32162843
 *  Platin vier!!
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
const v = ()=>console.log("valid"),
      i = ()=>console.log("invalid"),
      xmltag = /\<(?:\/)?[0-9a-z]+\>/g,
      xmlcls = /\<\/[0-9a-z]+\>/,
      xmltin = /\<(?:\/)?([0-9a-z]+)\>/,
      xmlesc = /\&(?:lt|gt|amp|x(?:[0-9a-fA-F][0-9a-fA-F])+);/,
      xmlsin = /\<[0-9a-z]+\/\>/,
      xmlvld = /\<|\>|\&/;

require('readline').createInterface({
	input: process.stdin,
	output: process.stdout,
}).on('line', l=>{
    if(!l) return v();
    var lp = l.matchAll(xmltag),
        st = [];
    for(var _v of lp){
        if(xmlcls.test(_v[0])){
            if(!st.length || xmltin.exec(_v[0])?.[1] != st.pop())
                return i();
        }
        else
            st.push(xmltin.exec(_v[0])?.[1]);
    }
    if(!!st.length) return i();
    var r = l.replace(xmltag, '').replace(RegExp(xmlesc, 'g'), '').replace(RegExp(xmlsin, 'g'), '');
    return xmlvld.test(r) ? i() : v();
})
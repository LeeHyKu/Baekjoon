"""
 Einreich 32122808
 
 Copyright (C) 2021. Hyun-Ku Lee
 
  Dieses Programm ist freie Software. Sie können es unter den Bedingungen
  der GNU General Public License, wie von der Free Software Foundation
  veröffentlicht, weitergeben und/oder modifizieren, entweder gemäß Version 3
  der Lizenz oder (nach Ihrer Option) jeder späteren Version.
 
  Die Veröffentlichung dieses Programms erfolgt in der Hoffnung, daß es Ihnen
  von Nutzen sein wird, aber OHNE IRGENDEINE GARANTIE, sogar ohne die implizite
  Garantie der MARKTREIFE oder der VERWENDBARKEIT FÜR EINEN BESTIMMTEN ZWECK.
  Details finden Sie in der GNU General Public License.
 
  Sie sollten ein Exemplar der GNU General Public License zusammen mit diesem
  Programm erhalten haben. Falls nicht, siehe http://www.gnu.org/licenses/.
"""
v=input()
t=[]
if '::' in v:
	a=v.split('::')
	b=a[0].split(':') if a[0] != '' else []
	c=a[1].split(':') if a[1] != '' else []
	t += b
	for _i in range(8 - len(b) - len(c)):
		t.append('0000')
	t += c
else:
	t=v.split(':')

for f in range(len(t)):
	t[f] = ('0' * (4 - len(t[f]))) + t[f]

print(':'.join(t))
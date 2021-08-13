"""
 Einreich 32170308
 
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
import re

pr=re.compile('^([a-zA-Z0-9]*)\:\/\/')
hs=re.compile('^(?:[a-zA-Z0-9]*)\:\/\/([a-zA-Z0-9.\-]*)')
po=re.compile('^(?:[a-zA-Z0-9]+)\:\/\/(?:[a-zA-Z0-9.\-]+)(?:\:([0-9]+))?')
pt=re.compile('^(?:[a-zA-Z0-9]+)\:\/\/(?:[a-zA-Z0-9.\-]+)(?:\:[0-9]+)?(?:\/(.*))?$')

tc=int(input())
for _i in range(tc):
    v=input()
    p=pr.search(v)
    h=hs.search(v)
    o=po.search(v)
    t=pt.search(v)
    print(f"URL #{_i + 1}")
    print(f"Protocol = {p.group(1)}")
    print(f"Host     = {h.group(1)}")
    print(f"Port     = {'<default>' if o.group(1) is None else o.group(1)}")
    print(f"Path     = {'<default>' if t.group(1) is None else t.group(1)}")
    print()

"""
 Einreich 31957819
 Gebrauchte Kombinationsformel
 
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
from math import comb

tc=int(input())

for _i in range(tc):
    linie=input().split()
    print(comb(int(linie[1]), int(linie[0])))
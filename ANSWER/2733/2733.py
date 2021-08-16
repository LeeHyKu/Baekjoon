"""
 Einreich 32257441
 
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
def compile(cp):
    st=''
    if cp == '':
        while True:
            _i=input()
            if _i == 'end':
                break
            else:
                st += _i.split('%')[0]
        st=list(st)
    else:
        st=cp
    sa=0
    for _s in st:
        if _s == '[':
            sa += 1
        elif _s == ']':
            sa -= 1
    if cp == '' and sa != 0:
        return 0, 0
    rs=[]
    i=0
    while i < len(st):
        s = st[i]
        if s == '+':
            rs.append(1)
        elif s == '-':
            rs.append(2)
        elif s == '>':
            rs.append(3)
        elif s == '<':
            rs.append(4)
        elif s == '.':
            rs.append(5)
        elif s == '[':
            [c, le] = compile(st[i+1:])
            if c == 0:
                return 0, 0
            i += le + 1
            rs.append(c)
        elif s == ']':
            break
        i += 1
    return rs, i


vl=[0] * 32768
pt=0
ca=[]

def run(jit):
    global pt
    global vl
    global ca
    for r in jit:
        if r == 1:
            vl[pt] = (vl[pt] + 1) % 256
        elif r == 2:
            if vl[pt] == 0:
                vl[pt] = 255
            else:
                vl[pt] -= 1
        elif r == 3:
            pt = (pt + 1) % 32768
        elif r == 4:
            if pt == 0:
                pt = 32767
            else:
                pt -= 1
        elif r == 5:
            ca.append(vl[pt])
        elif vl[pt] != 0:
            while vl[pt] != 0:
                run(r)

tc=int(input())
for _i in range(tc):
    vl=[0] * 32768
    pt=0
    ca=[]
    [c, _r]=compile('')
    print(f"PROGRAM #{_i + 1}:")
    if c == 0:
        print("COMPILE ERROR")
    else:
        run(c)
        print(''.join(list(map(chr, ca))))

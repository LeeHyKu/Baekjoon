# Submit no.27582831
# 
# Copyright (C) 2021. Hyun-Ku Lee
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <https://www.gnu.org/licenses/>.
STR = '*'
BAK = ' '
mes = int(input())

for i in range(mes - 1):
    print(f"{BAK * i}{STR * ((mes - i) * 2 - 1)}")

for i in range(mes):
    print(f"{BAK * (mes - i - 1)}{STR * ((i + 1) * 2 - 1)}")
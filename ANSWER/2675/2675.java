/*
 * Submit no.27579176
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
import java.io.*;
import java.util.*;

public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int tcl = sc.nextInt();
        for(int _i = 0; _i < tcl; _i++){
            int rpt = sc.nextInt();
            String str = sc.nextLine();
            String[] chr = str.replace(" ", "").split("");
            String erg = "";
            for(String c : chr)
                erg += c.repeat(rpt);
            System.out.println(erg);
        }
    }
}
/*
 * Submit no.27373555
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
import java.util.*;
import java.io.*;

public class Main{
	public static void main(String args[]){
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		    int c = Integer.parseInt(br.readLine());
            for(int i = 0; i < c; i++){
                String l[] = br.readLine().split(" ");
                bw.write((Integer.parseInt(l[0]) + Integer.parseInt(l[1])) + (i < (c - 1) ? "\n" : ""));
            }
            bw.close();
	    	br.close();
        }
        catch(Exception e){}
    }
}
/*
 * Submit no.27578191
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
		int loi = sc.nextInt();
        for(int _i = 0; _i < loi; _i++){
            int am = sc.nextInt();
            List<Integer> il = new ArrayList<>();
            for(int _j = 0; _j < am; _j++) il.add(sc.nextInt());
            double t = 0.0d;
            for(int a : il)
                t += a;
            t = t / il.size();
            double up = 0;
            for(int a : il){
                if(a > t)
                    up++;
            }
            System.out.printf("%.3f%%\n", (up / (il.size()*1d)) * 100d);
        }
    }
}
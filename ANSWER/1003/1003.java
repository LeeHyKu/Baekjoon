/*
 * Submit no.26849331
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
			int loop = Integer.parseInt(br.readLine());
			for(int i = 0; i < loop; i++){
				Fibonacci fib = new Fibonacci(Integer.parseInt(br.readLine()));
				bw.write(fib.getZero() + " " + fib.getOne() + '\n');
			}
			br.close();
			bw.close();
		}
		catch(Exception e){}
	}
	private static class Fibonacci{
		private int zro = 0;
		private int one = 0;
		public int getZero(){ return zro; }
		public int getOne(){ return one; }
		
		public Fibonacci(int _calc){ run(_calc); }
		
		private void run(int n){
			switch(n){
				case 0:
					zro++;
					return;
				case 1:
					one++;
					return;
				default:
					Integer[] on = new Integer[41];
					on[0] = 0;
					on[1] = 1;
					on[2] = 1;
					
					for(int i = 3; i <= n; i++) on[i] = on[i - 1] + on[i - 2];
					zro = on[n - 1];
					one = on[n];
					return;
			}
		}
	}
}
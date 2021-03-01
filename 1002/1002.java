/*
 * Submit no.26847445
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

public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int loop = sc.nextInt();
		for(int i = 0; i < loop; i++){
			Location alfa = new Location(sc);
			Location beta = new Location(sc);
			System.out.println(alfa.getOverlap(beta));
		}
	}
	private static class Location{
		public final int x;
		public final int y;
		public final int r;
		
		public Location(Scanner s){
			x = s.nextInt();
			y = s.nextInt();
			r = s.nextInt();
		}
		
		public int getOverlap(Location loc){
			double dist = getDistance(loc);
            if(dist == 0 && r == loc.r) return -1;
			else if((r + dist) < loc.r || (loc.r + dist) < r) return 0;
			else if((r + loc.r) == dist || Math.abs(r - loc.r) == dist) return 1;
            else if((r + loc.r) > dist && Math.abs(r - loc.r) < dist) return 2;
			else if((r + loc.r) < dist && Math.abs(r - loc.r) > dist) return 0;
            else return 0;
		}
		
		public double getDistance(Location loc){
			int _x = getDiffrence(x, loc.x);
			int _y = getDiffrence(y, loc.y);
			return Math.sqrt((_x * _x) + (_y * _y));
		}
		
		private int getDiffrence(int a, int b){ return Math.max(a, b) - Math.min(a, b); }
	}
}
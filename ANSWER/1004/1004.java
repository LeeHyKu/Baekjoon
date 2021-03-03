/*
 * Submit no.26909691
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
		Scanner s = new Scanner(System.in);
		int loop = s.nextInt();
		for(int i = 0; i < loop; i++){
			Prince p = new Prince(s);
			System.out.println(p.getIndex());
		}
	}

	private static class Prince {
		private final Vector von;
		private final Vector zu;
		private final List<Vector> vecs;

		public Prince(Scanner s){
			von = new Vector(s.nextInt(), s.nextInt());
			zu = new Vector(s.nextInt(), s.nextInt());

			int loop = s.nextInt();
			List<Vector> _vecs = new ArrayList();
			for(int i = 0; i < loop; i++)
				_vecs.add(new Vector(s.nextInt(), s.nextInt(), s.nextInt()));
			vecs = _vecs;
		}

		public int getIndex(){
			int res = 0;

			for(Vector vec : vecs){
				if(vec.isInside(von) ^ vec.isInside(zu))
					res++;
			}

			return res;
		}
	}
	private static class Vector {
		public final int x;
		public final int y;
		public final int r;
		private final double powed;

		public Vector(int _x, int _y){ this(_x, _y, 0); }
		public Vector(int _x, int _y, int _r){
			x = _x;
			y = _y;
			r = _r;
			powed = _r == 0 ? 0 : Math.pow(r, 2);
		}

		public boolean isInside(Vector vec){
			return (Math.pow(x - vec.x, 2) + Math.pow(y - vec.y, 2)) < powed;
		}
	}
}

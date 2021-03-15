/*
 * Submit no.27302540
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
		new Time(sc.nextInt(), sc.nextInt()).back(45).print();
    }
    
    public static class Time{
        public final int hur;
        public final int mni;
        
        public Time(int _hur, int _mni){
            if(_mni < 0){
                _hur--;
                _mni += 60;
            }
            if(_hur < 0) _hur += 24;
            
            hur = _hur;
            mni = _mni;
        }
        
        public void print(){
            System.out.println(hur + " " + mni);
        }
        
        public Time back(int amnt){
            return new Time(hur, mni - amnt);
        }
    }
}
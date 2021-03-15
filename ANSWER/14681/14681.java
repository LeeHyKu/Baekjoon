/*
 * Submit no.27302306
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
		boolean x = checkPostive(sc.nextInt());
        boolean y = checkPostive(sc.nextInt());
        
        System.out.println(
            x && y    ? 1 :
            !x && y   ? 2 :
            !x && !y  ? 3 :
                        4
        );
    }
    
    private static boolean checkPostive(int i){
        return i > 0; //0이 입력되는 경우는 없음
    }
}
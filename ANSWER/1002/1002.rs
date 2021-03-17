/*
 * Rust Programming Language Transition Code #1
 * Submit no.27395929
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
use std::io;
use std::cmp;

#[derive(Copy, Clone)]
struct Location {
    x: i64,
    y: i64,
    r: i64,
}

fn dif(a: i64, b: i64) -> i64 {
    cmp::max(a, b) - cmp::min(a, b)
}

fn dst(a: Location, b: Location) -> f64 {
    let x = dif(a.x, b.x) as f64;
    let y = dif(a.y, b.y) as f64;
    ((x * x) + (y * y)).sqrt()
}

fn ovr(a: Location, b: Location) -> i64 {
    let dis = dst(a, b);
    let pre = (a.r + b.r) as f64;
    let nex = (a.r - b.r).abs() as f64;
    if dis == 0.0 && a.r == b.r {
        return -1;
    } else if (a.r as f64 + dis) < b.r as f64 || (b.r as f64 + dis) < a.r as f64 {
        return 0;
    } else if pre == dis || nex == dis {
        return 1;
    } else if pre > dis && nex < dis {
        return 2;
    } else if pre < dis && nex > dis {
        return 0;
    } else {
        return 0;
    }
}

fn main() {
    let si = io::stdin();
    let mut lain = String::new();
    si
        .read_line(&mut lain)
        .expect("LAIN IS NIL");
    let la = lain.trim().parse::<i64>().unwrap();
    for _num in 0..la {
        let mut loin = String::new();
        si
            .read_line(&mut loin)
            .expect("LOIN IS NIL");
        let loar = loin
            .split_whitespace()
            .map(|x| x.parse::<i64>())
            .collect::<Result<Vec<i64>, _>>()
            .unwrap();

        let alfa = Location {
            x: loar[0],
            y: loar[1],
            r: loar[2],
        };
        let beta = Location {
            x: loar[3],
            y: loar[4],
            r: loar[5],
        };

        println!("{}", ovr(alfa, beta));
    }
}
package main

import "fmt"

//import "math"

// sqt*sqt <= x < (sqt+1)*(sqt+1)
func mySqrt(x int) int {
	if x == 0 {
		return 0
	}

	//small, big := 1, math.MaxInt32
	small, big := 1, x
	var ret int
	for true {
		mid := small + (big-small)/2
		if mid*mid > x {
			big = mid - 1
		} else {
			if (mid+1)*(mid+1) > x {
				ret = mid
				break
			}
			small = mid + 1
		}
		//fmt.Printf("current (%v,%v,%v)\n", small, mid, big)
	}
	return ret
}

// Newton's method
func mySqrt1(x int) int {
	y := x
	// Newton's method
	for y*y > x {
		y = (y + x/y) / 2
	}

	return y
}

func main() {
	var x int
	x = 4
	fmt.Printf("origin: %v, result: %v\n", x, mySqrt(x))

	x = 8
	fmt.Printf("origin: %v, result: %v\n", x, mySqrt(x))

	x = 1
	fmt.Printf("origin: %v, result: %v\n", x, mySqrt(x))

	x = 0
	fmt.Printf("origin: %v, result: %v\n", x, mySqrt(x))

	x = 1 / 2
	fmt.Printf("origin: %v, result: %v\n", x, mySqrt(x))

	x = 1 / 4
	fmt.Printf("origin: %v, result: %v\n", x, mySqrt(x))
}

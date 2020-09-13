package main

import "fmt"
import "math"

// 存在性能问题
func myPow1(x float64, n int) float64 {
	sign := 1
	if n < 0 {
		sign = -1
		n = int(math.Abs(float64(n)))
	} else if n == 0 {
		return 1.0
	}

	if math.Abs(x) == 1.0 {
		if n%2 == 0 {
			return math.Abs(x)
		} else {
			return x
		}
	}

	var ret float64 = 1.0
	for i := 0; i < n; i++ {
		ret *= x
	}

	if sign == -1 {
		ret = 1 / ret
	}
	return ret
}

func myPowWithRecursive(x float64, n int) float64 {
	if n == 0 {
		return 1
	} else if n < 0 {
		x, n = 1/x, -n
	}

	if n%2 == 0 {
		return myPowWithRecursive(x*x, n/2)
	} else {
		return x * myPowWithRecursive(x*x, n/2)
	}
}

/*
	N = 9 = 2^3 + 2^0 = 1001 in binary. Then:
	x^9 = x^(2^3) * x^(2^0)
*/
func myPowWithoutRecursive(x float64, n int) float64 {
	if n == 0 {
		return 1
	} else if n < 0 {
		x, n = 1/x, -n
	}

	var ret float64 = 1.0
	for n != 0 {
		if n&1 == 1 {
			ret *= x
		}
		x *= x
		n >>= 1
	}
	return ret
}

func main() {
	var x float64
	var n int

	x, n = 2.00000, 10
	fmt.Printf("origin(%v, %v) result:%v\n", x, n, myPowWithoutRecursive(x, n))

	x, n = 2.10000, 3
	fmt.Printf("origin(%v, %v) result:%v\n", x, n, myPowWithoutRecursive(x, n))

	x, n = 2.00000, -2
	fmt.Printf("origin(%v, %v) result:%v\n", x, n, myPowWithoutRecursive(x, n))

	x, n = 1.00000, -2147483648
	fmt.Printf("origin(%v, %v) result:%v\n", x, n, myPowWithoutRecursive(x, n))
}

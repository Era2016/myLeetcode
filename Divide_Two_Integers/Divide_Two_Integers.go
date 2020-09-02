package main

import "fmt"
import "math"

func divide(dividend int, divisor int) int {
	if dividend == math.MinInt32 && divisor == -1 {
		return math.MaxInt32
	}

	sign := 1
	if (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) {
		sign = -1
	}

	dnd := math.Abs(float64(dividend))
	dvr := math.Abs(float64(divisor))
	minus, count := dnd-dvr, 0

	for minus > 0 {
		count++
		//dnd, minus = minus, dnd-dvr
		dnd, minus = minus, minus-dvr
	}

	count *= sign
	return int(count)
}

func main() {
	var dividend, divisor int
	dividend, divisor = 10, 3
	fmt.Printf("origin[%d, %d] result:%v\n", dividend, divisor, divide(dividend, divisor))

	dividend, divisor = -7, 3
	fmt.Printf("origin[%d, %d] result:%v\n", dividend, divisor, divide(dividend, divisor))
}

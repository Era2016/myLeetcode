package main

import "fmt"
import "math"
import "time"

func divide(dividend int, divisor int) int {
	if dividend == math.MinInt32 && divisor == -1 {
		return math.MaxInt32
	}

	sign := 1
	if (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) {
		sign = -1
	}

	dnd := int64(math.Abs(float64(dividend))) // uint32 会有溢出问题
	dvr := int64(math.Abs(float64(divisor)))
	count := 0

	for dnd >= dvr {
		shift, tmp := 1, dvr
		for dnd >= tmp<<1 {
			tmp <<= 1
			shift <<= 1
		}
		count += shift
		dnd -= tmp
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

	dividend, divisor = 2, 3
	fmt.Printf("origin[%d, %d] result:%v\n", dividend, divisor, divide(dividend, divisor))

	var t1 time.Time
	var t2 time.Duration

	t1 = time.Now()
	dividend, divisor = 2147483647, 2
	fmt.Printf("origin[%d, %d] result:%v\n", dividend, divisor, divide(dividend, divisor))
	t2 = time.Now().Sub(t1)
	fmt.Printf("consume: %s\n", t2)

	t1 = time.Now()
	dividend, divisor = -2147483648, 1
	fmt.Printf("origin[%d, %d] result:%v\n", dividend, divisor, divide(dividend, divisor))
	t2 = time.Now().Sub(t1)
	fmt.Printf("consume: %s\n", t2)
}

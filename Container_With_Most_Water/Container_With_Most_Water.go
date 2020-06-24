package main

import "fmt"

func maxArea(height []int) int {
	var (
		max        int
		length     int
		start, end int
	)

	length = len(height)
	for start, end = 0, length-1; start < end; {
		tmp := (end - start) * min(height[start], height[end])
		if tmp > max {
			max = tmp
		}

		if height[start] < height[end] {
			start++
		} else {
			end--
		}
	}
	return max
}

func min(a, b int) int {
	if a <= b {
		return a
	} else {
		return b
	}
}

func main() {
	arr := []int{1,8,6,2,5,4,8,3,7}
	ret := maxArea(arr)
	fmt.Println(ret)
}

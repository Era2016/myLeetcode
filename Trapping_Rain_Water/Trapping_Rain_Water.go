package main

import "fmt"

func trap(height []int) int {

	left, right := 0, len(height)-1
	maxLeft, maxRight := 0, 0
	res := 0

	for left <= right {
		if height[left] <= height[right] {
			if height[left] >= maxLeft {
				maxLeft = height[left]
			} else {
				res += maxLeft - height[left]
			}
			left++
		} else {
			if height[right] >= maxRight {
				maxRight = height[right]
			} else {
				res += maxRight - height[right]
			}
			right--
		}
	}

	return res
}

func main() {
	height := []int{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}
	fmt.Printf("origin: %v, target: %d\n", height, trap(height))
}

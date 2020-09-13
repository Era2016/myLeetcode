package main

import "fmt"

func findPeakElement(nums []int) int {
	l, r := 0, len(nums)-1
	for l < r {
		mid := l + (r-l)/2
		if nums[mid] > nums[mid+1] {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}

func main() {
	var nums []int
	nums = []int{1, 2, 3, 1}
	fmt.Printf("origin: %v, result: %v\n", nums, findPeakElement(nums))

	nums = []int{1, 2, 1, 3, 5, 6, 4}
	fmt.Printf("origin: %v, result: %v\n", nums, findPeakElement(nums))
}

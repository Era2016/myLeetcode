package main

import "fmt"

func searchRange(nums []int, target int) []int {
	left := leftBound(nums, target)
	right := rightBound(nums, target)
	return []int{left, right}
}

func leftBound(nums []int, target int) int {
	low, high := 0, len(nums)-1
	for low <= high {
		mid := (high-low)/2 + low
		if nums[mid] < target {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
	if low >= len(nums) || nums[low] != target {
		//fmt.Printf("cur low: %d, cur val: %d, total cnt: %d\n", low, nums[low], len(nums))
		return -1
	}
	return low
}

func rightBound(nums []int, target int) int {
	low, high := 0, len(nums)-1
	for low <= high {
		mid := (high-low)/2 + low
		if nums[mid] <= target {
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
	if high < 0 || nums[high] != target {
		return -1
	}
	return high
}

func main() {
	var nums, res []int
	var target int

	nums = []int{5, 7, 7, 8, 8, 10}
	target = 8
	res = searchRange(nums, target)
	fmt.Println(res)

	target = 6
	res = searchRange(nums, target)
	fmt.Println(res)

	nums = []int{}
	target = 0
	res = searchRange(nums, target)
	fmt.Println(res)
}

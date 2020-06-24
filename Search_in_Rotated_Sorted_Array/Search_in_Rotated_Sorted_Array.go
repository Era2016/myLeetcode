package main

import "fmt"

func search(nums []int, target int) int {
	var ret int
	length := len(nums)
	rotate := findRotateIndex(nums, length)
	if length == 0 {
		return -1
	}

	if target < nums[0] || rotate == 0 {
		ret = binarySort(nums, rotate, length-1, target)
	} else {
		ret = binarySort(nums, 0, rotate-1, target)
	}
	return ret
}

func binarySort(nums []int, start, end, target int) int {
	for i, j := start, end; i <= j; {
		mid := i + (j-i)/2
		if target > nums[mid] {
			i = mid + 1
		} else if target < nums[mid] {
			j = mid - 1
		} else {
			return mid
		}
	}

	return -1
}

func findRotateIndex(nums []int, length int) int {
	var start, end int

	for start, end = 0, length-1; start <= end; {
		mid := start + (end-start)/2
		if nums[mid] < nums[start] {
			end = mid
		} else if nums[mid] > nums[end] {
			start = mid + 1
		} else { // nums[mid] >= start && nums[mid] <= end
			break
		}
	}
	return start
}

func main() {
	//arr := []int{4, 5, 6, 7, 0, 1, 2}
	arr := []int{0, 1, 2, 4, 5, 6, 7}
	//arr := []int{2, 4, 5, 6, 7, 0, 1}

	rotate := findRotateIndex(arr, len(arr))
	fmt.Printf("length: %d, rotate: %d\n", len(arr), rotate)
	//return
	ret := search(arr, 2)
	fmt.Printf("index: %d", ret)
}

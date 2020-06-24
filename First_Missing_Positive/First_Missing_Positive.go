package main

import "fmt"

func firstMissingPositive(nums []int) int {

	length := len(nums)
	for i := 0; i < length; i++ {
		for nums[i] > 0 && nums[i] <= length && nums[nums[i]-1] != nums[i] {
			nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]
		}
	}

	for i := 0; i < length; i++ {
		if nums[i] != i+1 {
			return i + 1
		}
	}

	return length + 1
}

func main() {
	mm := make(map[int][]int)
	mm[3] = []int{1, 2, 0}
	mm[2] = []int{3, 4, -1, 1}
	mm[1] = []int{7, 8, 9, 10, 11}
	mm[4] = []int{1, 1, 2, 3, 0}
	mm[5] = []int{0, -1, -2, -3, 4}
	mm[6] = []int{}

	for k, v := range mm {
		fmt.Printf("origin array: %v, target: %v, act: %v\n", v, k, firstMissingPositive(v))
	}
}

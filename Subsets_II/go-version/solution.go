package main

import (
	"fmt"
	"sort"
)

func subsetsWithDup(nums []int) [][]int {
	result := make([][]int, 0)
	tmp := make([]int, 0)

	sort.Ints(nums)
	var backtrack func(idx int)
	backtrack = func(idx int) {
		result = append(result, append([]int(nil), tmp...))
		for i := idx; i < len(nums); i++ {
			if i > idx && nums[i] == nums[i-1] {
				continue
			}

			tmp = append(tmp, nums[i])
			backtrack(i + 1)
			tmp = tmp[:len(tmp)-1]
		}
	}

	backtrack(0)
	return result
}

func main() {
	var nums []int

	nums = []int{1, 2, 2}
	fmt.Println(subsetsWithDup(nums))

	nums = []int{0}
	fmt.Println(subsetsWithDup(nums))

	nums = []int{4, 4, 4, 1, 4}
	fmt.Println(subsetsWithDup(nums))
}

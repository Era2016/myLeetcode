package main

import "fmt"

func subsets(nums []int) [][]int {
	result := make([][]int, 0)
	tmp := make([]int, 0)
	var backtrack func(idx int)

	backtrack = func(idx int) {
		result = append(result, append([]int(nil), tmp...))
		for i := idx; i < len(nums); i++ {
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

	nums = []int{1, 2, 3}
	fmt.Println(subsets(nums))

	nums = []int{0}
	fmt.Println(subsets(nums))
}

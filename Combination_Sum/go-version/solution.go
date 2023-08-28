package main

import "fmt"

func combinationSum(candidates []int, target int) [][]int {
	result := make([][]int, 0)
	tmp := make([]int, 0)
	var backtrack func(idx, target int)
	backtrack = func(idx int, target int) {
		if target == 0 {
			result = append(result, append([]int(nil), tmp...))
			return
		} else if target < 0 {
			return
		} else {
			for i := idx; i < len(candidates); i++ {
				tmp = append(tmp, candidates[i])
				backtrack(i, target-candidates[i])
				tmp = tmp[:len(tmp)-1]
			}
		}
	}

	backtrack(0, target)
	return result
}

func main() {
	var nums []int

	nums = []int{2, 3, 6, 7}
	fmt.Println(combinationSum(nums, 7))

	nums = []int{2, 3, 5}
	fmt.Println(combinationSum(nums, 8))

	nums = []int{2}
	fmt.Println(combinationSum(nums, 1))
}

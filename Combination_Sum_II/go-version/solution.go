package main

import (
	"fmt"
	"sort"
)

func combinationSum2(candidates []int, target int) [][]int {
	result := make([][]int, 0)
	tmp := make([]int, 0)
	sort.Ints(candidates)

	var backtrack func(idx, target int)
	backtrack = func(idx, target int) {
		if target < 0 {
			return
		} else if target == 0 {
			result = append(result, append([]int(nil), tmp...))
			return
		} else {
			for i := idx; i < len(candidates); i++ {
				if i > idx && candidates[i] == candidates[i-1] {
					continue
				}
				tmp = append(tmp, candidates[i])
				backtrack(i+1, target-candidates[i])
				tmp = tmp[:len(tmp)-1]
			}
		}
	}

	backtrack(0, target)
	return result
}

func main() {
	var nums []int

	nums = []int{10, 1, 2, 7, 6, 1, 5}
	fmt.Println(combinationSum2(nums, 8))

	nums = []int{2, 5, 2, 1, 2}
	fmt.Println(combinationSum2(nums, 5))
}

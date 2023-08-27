package main

import (
	"fmt"
	"sort"
)

func permuteUnique(nums []int) [][]int {
	sort.Ints(nums)
	result := make([][]int, 0)
	visit := make([]bool, len(nums))
	permute := make([]int, 0, len(nums))
	var backtrack func()
	backtrack = func() {
		if len(permute) == len(nums) {
			result = append(result, append([]int(nil), permute...))

			// 相同的slice，导致最终结果都是相同元素
			//result = append(result, permute)
			//for i := 0; i < len(result); i++ {
			//	fmt.Printf("permute: %p, result[%d]: %p\n", permute, i, result[i])
			//}

			return
		}

		for i := 0; i < len(nums); i++ {
			if visit[i] || i > 0 && nums[i] == nums[i-1] && !visit[i-1] {
				continue
			}

			visit[i] = true
			permute = append(permute, nums[i])
			backtrack()
			visit[i] = false
			permute = permute[:len(permute)-1]
		}
	}
	backtrack()
	return result
}

func main() {
	var nums []int

	nums = []int{1, 3, 2}
	fmt.Println(permuteUnique(nums))

	nums = []int{1, 1, 2}
	fmt.Println(permuteUnique(nums))
}

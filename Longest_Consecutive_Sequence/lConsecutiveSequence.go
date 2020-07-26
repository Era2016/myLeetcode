package main

import "fmt"

func longestConsecutive(nums []int) int {
	m := make(map[int]bool)
	for i := 0; i < len(nums); i++ {
		m[nums[i]] = true
	}

	maxLength := 0
	for i := 0; i < len(nums); i++ {
		if _, ok := m[nums[i]-1]; !ok {
			curNum := nums[i]
			curLength := 1
			for {
				if _, ok := m[curNum+1]; ok {
					curLength++
					curNum++
				} else {
					break
				}
			}

			maxLength = max(maxLength, curLength)
		}
	}
	return maxLength
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func main() {
	nums := [][]int{
		{10, 4, 20, 1, 3, 2},
		{1},
		{0},
		{},
		{-1, 0},
		{-1, -4, -2, -3, 0, 1, 3},
		{9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6},
		{1, 2, 0, 1},
	}
	for i := 0; i < len(nums); i++ {
		fmt.Printf("=======start======\n")
		fmt.Println(nums[i])
		fmt.Println(longestConsecutive(nums[i]))
		fmt.Printf("=======end========\n")
	}
}

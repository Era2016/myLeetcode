package main

import (
	"fmt"
)

func twoSum(nums []int, target int) []int {
	var (
		ret        []int
		index, end = 0, len(nums) - 1
	)

	for index < end {
		for j := index + 1; j <= end; j++ {
			if nums[index]+nums[j] == target {
				ret = append(ret, index, j)
				goto SUCC
			}
		}
		index++
	}

SUCC:
	return ret
}

func twoSum2(nums []int, target int) []int {
	var ret []int
	mm := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		mm[nums[i]] = i
	}

	for k, v := range nums {
		half := target - v
		if _, ok := mm[half]; ok {
			ret = append(ret, k, mm[half])
			break
		}
	}
	return ret
}

func twoSum3(nums []int, target int) []int {
	var ret []int
	mm := make(map[int]int)

	for k, v := range nums {
		half := target - v
		if _, ok := mm[half]; ok {
			ret = append(ret, k, mm[half])
			break
		} else {
			mm[v] = k
		}
	}
	return ret
}

func main() {
	ss := []int{1, 9, 3, 7, 5}
	ret := twoSum(ss, 8)
	fmt.Println(ret)

	ret = twoSum2(ss, 8)
	fmt.Println(ret)

	ret = twoSum3(ss, 8)
	fmt.Println(ret)
}

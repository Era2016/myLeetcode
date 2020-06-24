package main

import "fmt"
import "sort"

func threeSum(nums []int) [][]int {
	var targetSet [][]int
	len := len(nums)
	sort.Ints(nums)
	var sum int

	for i := 0; i < len-2; i++ {
		sum = nums[i]
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		var j, p int
		for j, p = i+1, len-1; j < p; {
			if nums[j]+nums[p] == -sum {
				tmpSet := []int{nums[i], nums[j], nums[p]}
				targetSet = append(targetSet, tmpSet)

				for j < p && nums[j] == nums[j+1] {
					j++
				}
				j++
				for p > j && nums[p] == nums[p-1] {
					p--
				}
				p--
			} else if nums[j]+nums[p] > -sum {
				for p > j && nums[p] == nums[p-1] {
					p--
				}
				p--
			} else {
				for j < p && nums[j] == nums[j+1] {
					j++
				}
				j++
			}
		}
	}

	return targetSet
}

func main() {
	nums := []int{-1, 0, 1, 2, -1, -4}
	//nums := []int{0, 0, 0, 0}
	//nums := []int{1, 2, -1, -2}
	ret := threeSum(nums)
	fmt.Println(ret)
}

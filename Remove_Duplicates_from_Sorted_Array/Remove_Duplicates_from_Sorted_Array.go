package main

import "fmt"
import "sort"

func removeDuplicates(nums []int) int {
	length := len(nums)
	if length == 0 {
		return 0
	}

	index, counter := 0, 0
	sort.Ints(nums)
	for ; index < length; index++ {
		for index < length-1 && nums[index] == nums[index+1] {
			index++
		}
		nums[counter] = nums[index]
		counter++
	}
	return counter
}

func main() {
	num1 := []int{1, 1, 2, 2, 3, 3}
	num2 := []int{1, 1, 2, 2, 3}
	num3 := []int{1, 2, 3}
	num4 := []int{1, 2, 2, 2, 3}
	num5 := []int{1, 1}
	num6 := []int{}
	numSlice := [][]int{
		num1,
		num2,
		num3,
		num4,
		num5,
		num6,
	}

	for _, nums := range numSlice {
		ret := removeDuplicates(nums)
		fmt.Println(ret)
	}

}

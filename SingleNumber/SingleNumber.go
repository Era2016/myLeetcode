package main

import "fmt"

func singleNumber(nums []int) int {
	flag := 1
	for i := 0; i < len(nums); i++ {
		flag ^= nums[i]
	}

	flag ^= 1
	return flag
}

func main() {
	//nums := []int{2, 2, 1}
	nums := []int{4, 1, 2, 1, 2}
	fmt.Println(singleNumber(nums))
}

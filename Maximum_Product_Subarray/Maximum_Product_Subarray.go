package main

import "fmt"

// maxdp[i]:前i个值中的最大值；mindp[i]:前i个值中的最小值
// maxdp[i] = max(nums[i]*maxdp[i-1], nums[i]*mindp[i-1], nums[i])
// mindp[i] = min(nums[i]*maxdp[i-1], nums[i]*mindp[i-1], nums[i])
func maxProduct(nums []int) int {
	length := len(nums)
	if length == 0 {
		return 0
	}

	maxdp := make([]int, length)
	mindp := make([]int, length)
	maxdp[0], mindp[0] = nums[0], nums[0]
	maxVal, minVal := nums[0], nums[0]
	for i := 1; i < length; i++ {
		maxdp[i] = max(nums[i]*maxdp[i-1], nums[i]*mindp[i-1], nums[i])
		mindp[i] = min(nums[i]*maxdp[i-1], nums[i]*mindp[i-1], nums[i])

		maxVal = max(maxVal, maxdp[i])
		minVal = min(minVal, mindp[i])
	}

	//fmt.Println(maxdp)
	//fmt.Println(mindp)
	return max(maxVal, minVal)
}

func max(arr ...int) int {
	max := arr[0]
	for i := 1; i < len(arr); i++ {
		if arr[i] > max {
			max = arr[i]
		}
	}

	return max
}

func min(arr ...int) int {
	min := arr[0]
	for i := 1; i < len(arr); i++ {
		if arr[i] < min {
			min = arr[i]
		}
	}

	return min
}

func main() {
	vv := [][]int{
		{2, 3, -2, 4},
		{-2, 0, -1},
	}

	for i := 0; i < len(vv); i++ {
		fmt.Printf("arr: %v\t, result: %v\n", vv[i], maxProduct(vv[i]))
	}
}

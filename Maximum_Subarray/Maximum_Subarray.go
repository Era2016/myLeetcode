package main

import "fmt"

/**
* maxSubArray(A, i) = maxSubArray(A, i - 1) > 0 ? maxSubArray(A, i - 1) : 0 + A[i];
 */

func maxSubArray(nums []int) int {

	if len(nums) == 0 {
		return 0
	}

	sum := make([]int, len(nums))
	sum[0] = nums[0]
	max := sum[0]

	for i := 1; i < len(nums); i++ {
		if sum[i-1] > 0 {
			sum[i] = sum[i-1] + nums[i]
		} else {
			sum[i] = nums[i]
		}

		if sum[i] > max {
			max = sum[i]
		}
	}

	return max
}

func main() {
	mm := map[int][]int{
		6:  []int{-2, 1, -3, 4, -1, 2, 1, -5, 4},
		-1: []int{-2, -1, -3, -4, -5},
	}

	for k, v := range mm {
		fmt.Printf("origin: %v, target: %v, act: %v\n", v, k, maxSubArray(v))
	}
}

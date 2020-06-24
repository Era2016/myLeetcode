package main

import "fmt"

func searchRange(nums []int, target int) []int {
	start, end := 0, len(nums)-1
	index := -1
	for start <= end {
		mid := start + (end-start)/2
		if nums[mid] < target {
			start = mid + 1
		} else if nums[mid] > target {
			end = mid - 1
		} else {
			index = mid
			break
		}
	}

	if index == -1 {
		return []int{-1, -1}
	}

	for start = index; start >= 0 && nums[start] == nums[index]; start-- {
		// do nothing
	}
	start++

	for end = index; end < len(nums) && nums[end] == nums[index]; end++ {
		// do nothing
	}
	end--

	return []int{start, end}
}

func searchRange2(nums []int, target int) []int {
	start, end := 0, len(nums)-1
	ret := []int{-1, -1}

	if end < 0 {
		return ret
	}

	// Search for the left one
	for start < end {
		mid := start + (end-start)/2
		if nums[mid] < target {
			start = mid + 1
		} else {
			end = mid
		}
	}

	if nums[start] != target {
		return []int{-1, -1}
	} else {
		ret[0] = start
	}

	// Search for the right one
	// We don't have to set i to 0 the second time.
	end = len(nums) - 1
	for start < end {
		mid := start + (end-start)/2 + 1 // Make mid biased to the right
		if nums[mid] > target {
			end = mid - 1
		} else {
			start = mid
		}
	}
	ret[1] = end
	return ret
}

func main() {
	// target -> nums
	mm := make(map[int][]int)
	mm[8] = []int{5, 7, 7, 8, 8, 10}
	mm[6] = []int{5, 7, 7, 8, 8, 10}
	mm[1] = []int{}
	mm[2] = []int{2}
	mm[3] = []int{3, 3, 3, 3, 3, 3}
	mm[5] = []int{4, 4}

	// for k, v := range mm {
	// 	ret := searchRange(v, k)
	// 	fmt.Printf("cur nums: %v, target: %d, ret: %v\n", v, k, ret)
	// }

	for k, v := range mm {
		ret := searchRange2(v, k)
		fmt.Printf("cur nums: %v, target: %d, ret: %v\n", v, k, ret)
	}

	//nums = []int{5, 7, 7, 8, 8, 10}
	//ret := searchRange(nums, 6)
	//fmt.Println(ret)
}

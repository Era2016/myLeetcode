package main

import "fmt"

/**
从前往后遍历，
1.遇到0继续循环;
2.遇到1与从后面遍历的遇到第一个0交换;
3.遇到2与从后面遍历的遇到非2值【0/1】交换;

待交换值的索引i，j，如果j <= i 退出循环
*/
func sortColors(nums []int) {

	var index, end int
	index, end = 0, len(nums)-1
	endNot2, end0 := end, end

	for index <= end {
		if nums[index] == 0 {
			index++
		} else if nums[index] == 1 {
			for end0 >= 0 && nums[end0] != 0 {
				end0--
			}
			if end0 <= index {
				index++
			} else {
				nums[index], nums[end0] = nums[end0], nums[index]
			}

		} else {
			for endNot2 >= 0 && nums[endNot2] == 2 {
				endNot2--
				//fmt.Printf("index: %v, end0: %v, endNot2: %v, nums: %v\n", index, end0, endNot2, nums)
			}
			if endNot2 <= index {
				break
			} else {
				nums[index], nums[endNot2] = nums[endNot2], nums[index]
			}
		}
		//fmt.Printf("index: %v, end0: %v, endNot2: %v, nums: %v\n", index, end0, endNot2, nums)
	}
}

func sortColors2(nums []int) {
	start0, start1 := 0, 0
	end2 := len(nums) - 1

	for start1 <= end2 {
		if nums[start1] == 0 {
			nums[start1], nums[start0] = nums[start0], nums[start1]
			start0++
			start1++
		} else if nums[start1] == 1 {
			start1++
		} else {
			nums[start1], nums[end2] = nums[end2], nums[start1]
			end2--
		}
	}
}

func main() {
	origin := []int{2, 0, 2, 1, 1, 0}
	fmt.Printf("before: %v\n", origin)
	sortColors2(origin)
	fmt.Printf("after: %v\n", origin)
}

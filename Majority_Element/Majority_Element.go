package main

import "fmt"

func majorityElement(nums []int) int {
	var val int

	//quickSort(nums, 0, len(nums)-1)
	//fmt.Printf("sorted: %v\nlen: %v, index: %v\n", nums, len(nums), len(nums)/2)
	//val = nums[len(nums)/2]

	//val = countSort(nums)

	val = mooreVoting(nums)
	return val
}

func mooreVoting(nums []int) int {
	count, candidate := 0, 0
	for _, v := range nums {
		//fmt.Printf("current num: %v\n", v)
		if count == 0 {
			candidate = v
		}

		if candidate == v {
			count++
		} else {
			count--
		}
		//fmt.Printf("current round: %d, candidate: %v, count: %v\n", k, candidate, count)
	}
	// 因为多数一定存在，否则需要二次遍历确认candidate的正确性
	// 多数->大于一半的数，不包含等于，否则该算法有问题
	// {1, 4, 5, 4, 2, 2, 4, 4}
	return candidate
}

func countSort(nums []int) int {
	mm := make(map[int]int)
	for _, v := range nums {
		if _, ok := mm[v]; ok {
			mm[v]++
		} else {
			mm[v] = 1
		}
	}

	for k, v := range mm {
		if v > len(nums)/2 {
			return k
		}
	}

	return 0
}

func quickSort(nums []int, start, end int) {
	if start < end {
		index := partation(nums, start, end)
		quickSort(nums, start, index-1)
		quickSort(nums, index+1, end)
	}
}

func partation(nums []int, start, end int) int {
	index := start - 1
	for i := start; i < end; i++ {
		if nums[i] < nums[end] {
			index++
			if index != i {
				nums[index], nums[i] = nums[i], nums[index]
			}
		}
	}
	index++
	nums[index], nums[end] = nums[end], nums[index]
	return index
}

func main() {
	nums := []int{1, 4, 5, 4, 2, 2, 4, 4, 4}
	fmt.Printf("origin: %v\n", nums)
	//quickSort(nums, 0, len(nums)-1)
	//fmt.Printf("result: %v\n", nums)

	val := majorityElement(nums)
	fmt.Printf("result: %v\n", val)
}

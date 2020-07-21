package main

import "fmt"

func merge(nums1 []int, m int, nums2 []int, n int) {

	i, j := m-1, n-1
	index := m + n - 1
	for i >= 0 && j >= 0 {
		if nums1[i] >= nums2[j] {
			nums1[index] = nums1[i]
			index, i = index-1, i-1
		} else {
			nums1[index] = nums2[j]
			index, j = index-1, j-1
		}
	}

	for i >= 0 {
		nums1[index] = nums1[i]
		index, i = index-1, i-1
	}

	for j >= 0 {
		nums1[index] = nums2[j]
		index, j = index-1, j-1
	}
}

func main() {
	nums1 := []int{1, 2, 3, 0, 0, 0}
	nums2 := []int{2, 5, 6}

	fmt.Printf("before: %v\n", nums1)
	merge(nums1, 3, nums2, 3)
	fmt.Printf("after: %v\n", nums1)
}

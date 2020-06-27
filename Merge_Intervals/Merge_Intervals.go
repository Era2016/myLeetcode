package main

import "fmt"
import "sort"

/**
*	先构造interval的左右边界，通过每次遍历来修改右边界的值
*   在无法合并右边界的时候放入最终merged的集合中，最终合并
*   一次：有修改，但未合并就退出循环的情况
*/
func merge(intervals [][]int) [][]int {

	if len(intervals) == 0 {
		return [][]int{}
	}

	// 根据start value对intervals[i]排序
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	//fmt.Printf("sorted slice: %v\n", intervals)

	// 从小到大对intervals合并
	var ret [][]int
	r := []int{intervals[0][0], intervals[0][1]}
	//fmt.Printf("init intervals: %v\n", r)

	for i := 1; i < len(intervals); i++ {

		if intervals[i][0] > r[1] {
			ret = append(ret, r)
			//fmt.Printf("current ret: %v\n", ret)
			r = []int{intervals[i][0], intervals[i][1]}
		} else {
			r[1] = max(r[1], intervals[i][1])
			//fmt.Printf("index: %d, merged: %v\n", i, r[1])
		}
	}
	ret = append(ret, r)

	return ret
}


/**
*	先将interval放入最终merged集合中，然后每次遍历来修改interval的右边界
*/
func merge2(intervals [][]int) [][]int {

	if len(intervals) <= 1 {
		return intervals
	}

	// 根据start value对intervals[i]排序
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	var ret [][]int
	r := intervals[0]
	ret = append(ret, r)

	for _, v := range intervals {
		if v[0] > r[1] {
			r = v
			ret = append(ret, r)
		} else {
			r[1] = max(r[1], v[1])
		}
	}

	return ret
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {

	var intervals [][]int

	intervals = [][]int{
		{3, 9}, {1, 4}, {5, 8}, {2, 6}, {7, 9},
	}

	fmt.Printf("origin: %v\n", intervals)
	fmt.Printf("after func: %v\n", merge(intervals))
	fmt.Println()

	intervals = [][]int{
		{1, 3}, {2, 6}, {8, 10}, {15, 18}, {15, 18},
	}

	fmt.Printf("origin: %v\n", intervals)
	fmt.Printf("after func: %v\n", merge(intervals))
	fmt.Println()

	intervals = [][]int{
		{1, 4}, {4, 5},
	}

	fmt.Printf("origin: %v\n", intervals)
	fmt.Printf("after func: %v\n", merge2(intervals))
	fmt.Println()

	intervals = [][]int{
		{2, 3}, {2, 2}, {3, 3}, {1, 3}, {5, 7}, {2, 2}, {4, 6},
	}
	fmt.Printf("origin: %v\n", intervals)
	fmt.Printf("after func: %v\n", merge2(intervals))
	fmt.Println()
}

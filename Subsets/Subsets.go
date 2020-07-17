package main

//
//import "fmt"
//
///**
//slice 底层实现，导致递归失败 ！！！
//不可用, 需要修改
//*/
//
//func subsets(nums []int) [][]int {
//	var (
//		ret    [][]int
//		tmpRet []int
//	)
//
//	getSubsets(&ret, &tmpRet, nums, 0)
//	return ret
//}
//
//func getSubsets(retList *[][]int, tmpList *[]int, nums []int, start int) {
//	*retList = append(*retList, *tmpList)
//	for i := start; i < len(nums); i++ {
//		*tmpList = append(*tmpList, nums[i])
//		getSubsets(retList, tmpList, nums, i+1)
//		tailRemove(tmpList)
//	}
//}
//
//func tailRemove(p *[]int) {
//	s := *p
//	s = s[:len(s)-1]
//	*p = s
//}
//
func main() {
	//	nums := []int{1, 2, 3}
	//	fmt.Printf("before: %v\n", nums)
	//	ret := subsets(nums)
	//	fmt.Printf("after: %v\n", ret)
}

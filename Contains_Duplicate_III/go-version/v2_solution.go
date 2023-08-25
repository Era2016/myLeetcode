package main

// 超时
import (
	"fmt"
	"sort"
)

type imap struct {
	key int
	val int64
}

type ordered_map []imap

func (m ordered_map) Len() int {
	return len(m)
}

func (m ordered_map) Less(i, j int) bool {
	return m[i].val < m[j].val
}

func (m ordered_map) Swap(i, j int) {
	m[i], m[j] = m[j], m[i]
}

func (m ordered_map) LowerBound(val int64) (int64, bool) {
	for i := 0; i < len(m); i++ {
		if m[i].val >= val {
			return m[i].val, true
		}
	}
	return -1, false
}

func (m *ordered_map) Append(key int, val int64) {
	if _val, ok := m.LowerBound(val); ok && _val == val {
		return
	}

	_imap := imap{
		key: key,
		val: val,
	}
	*m = append(*m, _imap)
	sort.Sort(*m)
}

func (m *ordered_map) Remove(val int64) {
	for k, v := range *m {
		if v.val == val {
			newM := make(ordered_map, 0, len(*m)-1)
			newM = append(newM, (*m)[:k]...)
			newM = append(newM, (*m)[k+1:]...)
			*m = newM
			break
		}
	}
}

func containsNearbyAlmostDuplicate(nums []int, indexDiff int, valueDiff int) bool {
	index := 0
	window := make(ordered_map, 0, indexDiff)
	for index < len(nums) {
		if val, ok := window.LowerBound(int64(nums[index]) - int64(valueDiff)); ok {
			if val <= int64(nums[index])+int64(valueDiff) {
				return true
			}
		}

		window.Append(index, int64(nums[index]))

		if index-indexDiff >= 0 {
			window.Remove(int64(nums[index-indexDiff]))
		}
		index++
	}

	return false
}

func main() {
	var nums []int

	nums = []int{1, 2, 3, 1}
	fmt.Println(containsNearbyAlmostDuplicate(nums, 3, 0))

	nums = []int{1, 5, 9, 1, 5, 9}
	fmt.Println(containsNearbyAlmostDuplicate(nums, 2, 3))

}

func main() {
	var nums []int

	nums = []int{1, 2, 3, 1}
	fmt.Println(containsNearbyAlmostDuplicate(nums, 3, 0))

	nums = []int{1, 5, 9, 1, 5, 9}
	fmt.Println(containsNearbyAlmostDuplicate(nums, 2, 3))

}

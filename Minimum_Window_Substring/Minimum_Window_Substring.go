package main

import "fmt"

func minWindow(s string, t string) string {
	targetData, byteLength := []byte(t), len(t)
	if byteLength == 0 {
		return "" // 防止匹配第一个字符，直接退出
	}

	targetMap := make(map[byte]int)
	for i := 0; i < byteLength; i++ {
		if _, ok := targetMap[targetData[i]]; ok {
			targetMap[targetData[i]]++
		} else {
			targetMap[targetData[i]] = 1
		}
	}

	targetLength := len(targetMap)

	originData := []byte(s)
	originMap := make(map[byte]int)
	matchFlag := 0         // 不同字符的匹配个数，用来判断当前滑动窗口是否完全包含目标字符串
	left, right := 0, 0    // 滑动窗口的左右两边
	res := []int{-1, 0, 0} // 包含t的最小窗口长度、起始索引、终止索引

	for right < len(originData) {
		if _, ok := originMap[originData[right]]; ok {
			originMap[originData[right]]++
		} else {
			originMap[originData[right]] = 1
		}

		if count, ok := targetMap[originData[right]]; ok && count == originMap[originData[right]] {
			matchFlag++
		}

		for left <= right && matchFlag == targetLength {
			curLength := right - left + 1

			if left == 0 || curLength < res[0] {
				res[0] = curLength
				res[1], res[2] = left, right
			}

			originMap[originData[left]]--
			if count, ok := targetMap[originData[left]]; ok && originMap[originData[left]] < count {
				matchFlag--
			}
			left++
		}

		right++
	}

	if res[0] == -1 {
		return "" // 防止没匹配上，取默认值0
	}
	return s[res[1] : res[2]+1]
}

func main() {
	//s, t := "ADOBECODEBANC", "ABC"
	//s, t := "a", "aa"
	fmt.Printf("res: %v\n", minWindow("aa", ""))
	fmt.Printf("res: %v\n", minWindow("", "aa"))
	fmt.Printf("res: %v\n", minWindow("a", "aa"))
	fmt.Printf("res: %v\n", minWindow("aa", "aa"))
	fmt.Printf("res: %v\n", minWindow("ADOBECODEBANC", "ABC"))
}

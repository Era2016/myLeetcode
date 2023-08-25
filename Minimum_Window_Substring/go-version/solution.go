package main

import "fmt"

func minWindow(s string, t string) string {
	left, right := 0, 0
	window := make(map[byte]int, len(t))
	for _, v := range t {
		window[byte(v)]++
	}

	valid := 0
	start, length := -1, len(s)+1
	slide := make(map[byte]int)
	for right < len(s) {
		chr := byte(s[right])
		right++

		if _, ok := window[chr]; ok {
			slide[chr]++
			if slide[chr] == window[chr] {
				valid++
			}
		}

		for left <= right && valid == len(window) {
			if right-left < length {
				start, length = left, right-left
			}
			chr = byte(s[left])
			left++
			if _, ok := window[chr]; ok {
				if slide[chr] == window[chr] {
					valid--
				}
				slide[chr]--
			}
		}
	}

	if start == -1 {
		return ""
	} else {
		return s[start : start+length]
	}
}

func main() {
	fmt.Println(minWindow("ADOBECODEBANC", "ABC"))
	fmt.Println(minWindow("a", "a"))
	fmt.Println(minWindow("a", "aa"))
}

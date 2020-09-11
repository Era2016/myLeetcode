package main

import "fmt"
import "strings"

func isPalindrome(s string) bool {
	for i, j := 0, len(s)-1; i <= j; {
		sI := strings.ToUpper(string(s[i]))
		sJ := strings.ToUpper(string(s[j]))

		byteI, byteJ := sI[0], sJ[0]
		if !((byteI >= '0' && byteI <= '9') || (byteI >= 'A' && byteI <= 'Z')) {
			i++
			continue
		}
		if !((byteJ >= '0' && byteJ <= '9') || (byteJ >= 'A' && byteJ <= 'Z')) {
			j--
			continue
		}

		if byteI != byteJ {
			return false
		}
		i, j = i+1, j-1
	}

	return true
}

func main() {
	var s string

	s = "A,b  ,,a"
	fmt.Printf("origin:%v, result:%v\n", s, isPalindrome(s))

	s = " ab b,a"
	fmt.Printf("origin:%v, result:%v\n", s, isPalindrome(s))

	s = "cabbeac"
	fmt.Printf("origin:%v, result:%v\n", s, isPalindrome(s))

	s = "  ,  ,  ,  "
	fmt.Printf("origin:%v, result:%v\n", s, isPalindrome(s))

	s = "A man, a plan, a canal: Panama"
	fmt.Printf("origin:%v, result:%v\n", s, isPalindrome(s))

	s = ",,,,,,,,,,,,acva"
	fmt.Printf("origin:%v, result:%v\n", s, isPalindrome(s))
}

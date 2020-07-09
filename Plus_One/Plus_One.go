package main

import "fmt"

func plusOne(digits []int) []int {

	added := 0
	length := len(digits)
	newDigits := make([]int, length)

	for i := length - 1; i >= 0; i-- {
		var cur int
		if i == length-1 {
			cur = digits[i] + 1
		} else {
			cur = digits[i]
		}

		newDigits[i] = (cur + added) % 10
		added = (cur + added) / 10
	}

	if added != 0 {
		newDigits = append([]int{1}, newDigits...)
	}

	return newDigits
}

func main() {
	digits := []int{1, 2, 9}
	fmt.Printf("before: %v, after: %v\n", digits, plusOne(digits))

	digits = []int{1, 2, 3}
	fmt.Printf("before: %v, after: %v\n", digits, plusOne(digits))

	digits = []int{9, 9, 9}
	fmt.Printf("before: %v, after: %v\n", digits, plusOne(digits))

	digits = []int{0}
	fmt.Printf("before: %v, after: %v\n", digits, plusOne(digits))

	digits = []int{1,2,3,4,5,6,7,8,9,9,8,7,6,5,4,3,2,1}
	fmt.Printf("before: %v, after: %v\n", digits, plusOne(digits))
}

package main

import "fmt"

func Add2Slice(s []int, t int) {
	s[0]++
	s = append(s, t)
	s[0]++
}

func Add2Slice2(s *[]int, t int) {
	//*s[0]++  /* 报错！ */
	*s = append(*s, t)
	//s[0]++
}
func main() {
	a := []int{0, 1, 2, 3}
	Add2Slice(a, 4)
	fmt.Println(a) // output: [1 1 2 3]

	b := []int{0, 1, 2, 3}
	Add2Slice2(&b, 4)
	fmt.Println(b) // output: [0 1 2 3 4]
}

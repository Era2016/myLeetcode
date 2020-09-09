package main

import "fmt"

func main() {
	var i uint32 = 1
	var j int32 = 1
	for p := 0; p < 35; p++ {
		i <<= 1
		j <<= 1
		fmt.Printf("i: %v, j: %v\n", i, j)
	}
	fmt.Println("vim-go")
}

package main

import "fmt"

func setZeroes(matrix [][]int) {
	
	var rows = make(map[int]bool)
	var cols = make(map[int]bool)

	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[0]); j++ {
			if matrix[i][j] == 0 {
				rows[i] = true
				cols[j] = true
			}
		}
	}

	for i := 0; i < len(matrix); i++ {
		if _, ok := rows[i]; ok {
			for j := 0; j < len(matrix[0]); j++ {
				matrix[i][j] = 0
			}
		}
	}

	for j := 0; j < len(matrix[0]); j++ {
		if _, ok := cols[j]; ok {
			for i := 0; i < len(matrix); i++ {
				matrix[i][j] = 0
			}
		}
	}
}

func main() {
	origin := [][]int{
		{1, 1, 1},
		{1, 0, 1},
		{1, 1, 1},
	}

	fmt.Printf("before: %v\n", origin)
	setZeroes(origin)
	fmt.Printf("after: %v\n", origin)

	origin = [][]int{
		{0, 1, 2, 0},
		{3, 4, 5, 2},
		{1, 3, 1, 5},
	}

	fmt.Printf("before: %v\n", origin)
	setZeroes(origin)
	fmt.Printf("after: %v\n", origin)
}

package main

import "fmt"

/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3

 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7

 * 1 2 3 10 12
 * 4 5 6 11 13
 * 7 8 9 21 14
 * 1 2 3 4  23
 * 6 7 8 10 11
 */

func rotate(matrix [][]int) {

	division := len(matrix)
	for i := 0; i < division/2; i++ {
		for j := 0; j < division; j++ {
			matrix[i][j], matrix[division-i-1][j] = matrix[division-i-1][j], matrix[i][j]
		}
	}

	for i := 0; i < division; i++ {
		for j := i + 1; j < division; j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}
}

func main() {
	/*matrix := [][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}*/

	matrix := [][]int{
		{5, 1, 9, 11},
		{2, 4, 8, 10},
		{13, 3, 6, 7},
		{15, 14, 12, 16},
	}

	print(matrix)
	rotate(matrix)
	print(matrix)
}

func print(matrix [][]int) {
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[i]); j++ {
			fmt.Printf("%d ", matrix[i][j])
		}
		fmt.Println()
	}

	fmt.Println()
}

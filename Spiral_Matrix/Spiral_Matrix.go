package main

import "fmt"

func spiralOrder(matrix [][]int) []int {

	if len(matrix) == 0 {
		return []int{}
	}

	rowEnd, colEnd := len(matrix)-1, len(matrix[0])-1

	rowBegin, colBegin := 0, 0
	ret := make([]int, 0, (rowEnd+1)*(colEnd+1))

	for rowBegin <= rowEnd && colBegin <= colEnd {
		// Traverse Right
		for j := colBegin; j <= colEnd; j++ {
			ret = append(ret, matrix[rowBegin][j])
		}
		rowBegin++

		// Traverse Down
		for i := rowBegin; i <= rowEnd; i++ {
			ret = append(ret, matrix[i][colEnd])
		}
		colEnd--

		// Traverse Left
		if rowBegin <= rowEnd {
			for j := colEnd; j >= colBegin; j-- {
				ret = append(ret, matrix[rowEnd][j])
			}
		}
		rowEnd--

		// Traver Up
		if colBegin <= colEnd {
			for i := rowEnd; i >= rowBegin; i-- {
				ret = append(ret, matrix[i][colBegin])
			}
		}
		colBegin++
	}

	return ret
}

func main() {
	//matrix := [][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
	matrix := [][]int{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}
	fmt.Println(spiralOrder(matrix))
}

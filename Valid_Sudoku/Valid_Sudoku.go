package main

import "fmt"
/*
k = i / 3 * 3 + j / 3

0  0  0 | 1  1  1 | 2  2  2
0  0  0 | 1  1  1 | 2  2  2
0  0  0 | 1  1  1 | 2  2  2
--------+---------+---------
3  3  3 | 4  4  4 | 5  5  5
3  3  3 | 4  4  4 | 5  5  5
3  3  3 | 4  4  4 | 5  5  5
--------+----------+--------
6  6  6 | 7  7  7 | 8  8  8
6  6  6 | 7  7  7 | 8  8  8
6  6  6 | 7  7  7 | 8  8  8

*/

func isValidSudoku(board [][]byte) bool {
	s1 := [9][9]int{}
	s2 := [9][9]int{}
	s3 := [9][9]int{}

	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			if board[i][j] != '.' {
				num := board[i][j] - '0' - 1
				k := i/3*3 + j/3
				if s1[i][num] == 1 || s2[j][num] == 1 || s3[k][num] == 1 {
					return false
				} else {
					s1[i][num], s2[j][num], s3[k][num] = 1, 1, 1
				}
			}
		}
	}
	return true
}

func isValidSudoku2(board [][]byte) bool {
	for i := 0; i < len(board); i++ {
		m1 := make(map[byte]bool)
		m2 := make(map[byte]bool)
		for j := 0; j < len(board[0]); j++ {
			if board[i][j] != '.' {
				if _, ok := m1[board[i][j]]; ok {
					return false
				} else {
					m1[board[i][j]] = true
				}
			}

			if board[j][i] != '.' {
				if _, ok := m2[board[j][i]]; ok {
					return false
				} else {
					m2[board[j][i]] = true
				}
			}
		}
	}

	for i := 0; i <= len(board)-3; i += 3 {
		for j := 0; j <= len(board[0])-3; j += 3 {
			if ret := isValid(board, i, i+2, j, j+2); !ret {
				return false
			}
		}
	}
	return true
}

func isValid(board [][]byte, istart, iend, jstart, jend int) bool {
	mm := make(map[byte]bool)
	for i := istart; i <= iend; i++ {
		for j := jstart; j <= jend; j++ {
			if board[i][j] != '.' {
				if _, ok := mm[board[i][j]]; ok {
					return false
				} else {
					mm[board[i][j]] = true
				}
			}
		}
	}
	return true
}

func main() {
	board := [][]byte{
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
	}

	board2 := [][]byte{
		{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
	}

	board3 := [][]byte{
		{'.', '.', '.', '.', '5', '.', '.', '1', '.'},
		{'.', '4', '.', '3', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '3', '.', '.', '1'},
		{'8', '.', '.', '.', '.', '.', '.', '2', '.'},
		{'.', '.', '2', '.', '7', '.', '.', '.', '.'},
		{'.', '1', '5', '.', '.', '.', '.', '.', '.'},
		{'.', '.', '.', '.', '.', '2', '.', '.', '.'},
		{'.', '2', '.', '9', '.', '.', '.', '.', '.'},
		{'.', '.', '4', '.', '.', '.', '.', '.', '.'},
	}
	fmt.Println(isValidSudoku(board))
	fmt.Println(isValidSudoku(board2))
	fmt.Println(isValidSudoku(board3))
}

package main

import "fmt"

func isValidSudoku(board [][]byte) bool {
	for i := 0; i < len(board); i++ {
		mm := make(map[byte]bool)
		for j := 0; j < len(board[0]); j++ {
			if board[i][j] != '.' {
				if _, ok := mm[board[i][j]]; ok {
					return false
				} else {
					mm[board[i][j]] = true
				}
			}
		}
	}

	for i := 0; i < len(board[0]); i++ {
		mm := make(map[byte]bool)
		for j := 0; j < len(board); j++ {
			if board[j][i] != '.' {
				if _, ok := mm[board[j][i]]; ok {
					return false
				} else {
					mm[board[j][i]] = true
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

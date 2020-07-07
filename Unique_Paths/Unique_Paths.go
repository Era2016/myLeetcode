package main

import "fmt"

/**
If we use dp[i][j] for the number of unique paths to arrive at the point (i, j)
then the state equation is dp[i][j] = dp[i][j - 1] + dp[i - 1][j]

dp 数组初始化
dp[0][j] = dp[i][0] = 1 for all valid i and j
其余数组值可以是任何值，后面的计算会覆盖掉
for i := 0; i < m; i++ {
	for j := 0; j < n; j++ {
		if i == 0 || j == 0 {
			dp[i][j] = 1
		} else {
			dp[i][j] = 2
		}
	}
}

*/

func uniquePaths(m int, n int) int {
	dp := make([][]int, m)
	for i := 0; i < m; i++ {
		dp[i] = make([]int, n)
	}

	// dp 数组初始化
	// dp[0][j] = dp[i][0] = 1 for all valid i and j
	// 其余数组值可以是任何值，后面的计算会覆盖掉

	for j := 0; j < n; j++ {
		dp[0][j] = 1
	}

	for i := 0; i < m; i++ {
		dp[i][0] = 1
	}

	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			dp[i][j] = dp[i][j-1] + dp[i-1][j]
		}
	}
	return dp[m-1][n-1]
}

func main() {
	m, n := 3, 2
	fmt.Printf("m: %d, n: %d, result: %v\n", m, n, uniquePaths(m, n)) // 3

	m, n = 7, 3
	fmt.Printf("m: %d, n: %d, result: %v\n", m, n, uniquePaths(m, n)) // 28

	m, n = 1, 1
	fmt.Printf("m: %d, n: %d, result: %v\n", m, n, uniquePaths(m, n)) // 1
}

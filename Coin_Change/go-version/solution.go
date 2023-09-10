package main

import (
	"fmt"
	"math"
)

func coinChange(coins []int, amount int) int {
	memo := make([]int, amount+1)

	var dp func(amount int) int
	dp = func(amount int) int {
		if amount == 0 {
			return 0
		} else if amount < 0 {
			return -1
		}

		if memo[amount] != 0 {
			return memo[amount]
		}

		res := math.MaxInt32
		var sub int
		for _, v := range coins {
			if sub = dp(amount - v); sub == -1 {
				continue
			}

			res = int(math.Min(float64(res), float64(sub)+1))
		}

		if res == math.MaxInt32 {
			memo[amount] = -1
		} else {
			memo[amount] = res
		}
		return memo[amount]
	}

	return dp(amount)
}

func main() {
	fmt.Println(coinChange([]int{1, 2, 5}, 11))
	fmt.Println(coinChange([]int{2}, 3))
	fmt.Println(coinChange([]int{1}, 0))
}

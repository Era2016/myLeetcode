package main

import "fmt"

/**
这里可以用动态规划 Dynamic Programming 来解，维护一个一维数组 dp，
其中 dp[i] 表示达到i位置时剩余的跳力，若到达某个位置时跳力为负了，说明无法到达该位置。

推导状态转移方程，到达当前位置的剩余跳力跟什么有关，
其实是跟上一个位置的剩余跳力（dp 值）和上一个位置新的跳力（nums 数组中的值）有关，
这里新的跳力就是原数组中每个位置的数字，因为其代表了以当前位置为起点能到达的最远位置。
所以当前位置的剩余跳力（dp 值）和当前位置新的跳力中的较大那个数决定了当前能到的最远距离，
而下一个位置的剩余跳力（dp 值）就等于当前的这个较大值减去1，因为需要花一个跳力到达下一个位置，
所以就有状态转移方程了：dp[i] = max(dp[i - 1], nums[i - 1]) - 1，
如果当某一个时刻 dp 数组的值为负了，说明无法抵达当前位置，则直接返回 false，
最后循环结束后直接返回 true  即可，
参见代码如下：
*/
func canJump(nums []int) bool {

	dp := make([]int, len(nums))
	for i := 1; i < len(nums); i++ {
		dp[i] = max(dp[i-1], nums[i-1]) - 1

		if dp[i] < 0 {
			return false
		}
	}

	return true
}

/**
贪婪算法 Greedy Algorithm
因为这里并不是很关心每一个位置上的剩余步数，而只希望知道能否到达末尾，
也就是说我们只对最远能到达的位置感兴趣，所以维护一个变量 reach，表示最远能到达的位置，初始化为0。

遍历数组中每一个数字，如果当前坐标大于 reach 或者 reach 已经抵达最后一个位置则跳出循环，
否则就更新 reach 的值为其和 i + nums[i] 中的较大值，
其中 i + nums[i] 表示当前位置能到达的最大位置，
参见代码如下：
*/
func canJump2(nums []int) bool {
	
	reach, length := 0, len(nums)
	for i := 0; i < length; i++ {
		if i > reach || reach >= length-1 {
			break
		}

		reach = max(reach, i+nums[i])
	}
	return reach >= length-1
}

func max(a, b int) int {
	if a >= b {
		return a
	} else {
		return b
	}
}

func main() {
	nums := [][]int{
		{2, 3, 1, 1, 4},
		{3, 2, 1, 0, 4},
	}
	for _, v := range nums {
		fmt.Printf("current arr: %v, result: %v\n", v, canJump(v))
		fmt.Printf("current arr: %v, result: %v\n", v, canJump2(v))
	}
}

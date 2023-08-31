package main

import (
	"fmt"
	"strconv"
	"strings"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	queue := make([]*TreeNode, 0)
	queue = append(queue, root)
	depth := 1
	for len(queue) > 0 {
		length := len(queue)
		for i := 0; i < length; i++ {
			node := queue[0]
			queue = queue[1:]
			if (*node).Left == nil && (*node).Right == nil {
				return depth
			}
			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}

		}
		depth = depth + 1
	}

	return depth
}

func buildBinaryTree(nums []string) *TreeNode {

	if len(nums) == 0 || strings.Compare(nums[0], "null") == 0 {
		return nil
	}

	val, _ := strconv.Atoi(nums[0])
	root := &TreeNode{Val: val}
	nums = nums[:1]
	queue := make([]*TreeNode, 0, 1)
	queue = append(queue, root)
	index := 0
	for len(queue) > 0 && index < len(nums) {
		node := queue[0]
		queue = queue[1:]
		if node.Left == nil {
			if strings.Compare(nums[index], "null") != 0 {
				val, _ := strconv.Atoi(nums[index])
				t_node := &TreeNode{Val: val}
				node.Left = t_node

				queue = append(queue, t_node)
			}
			index++
		}
		if node.Right == nil && index < len(nums) {
			if strings.Compare(nums[index], "null") != 0 {
				val, _ := strconv.Atoi(nums[index])
				t_node := &TreeNode{Val: val}
				node.Right = t_node

				queue = append(queue, t_node)
			}
			index++
		}
	}

	return root
}

func main() {
	//node1 := &TreeNode{Val: 3}
	//node2 := &TreeNode{Val: 9}
	//node3 := &TreeNode{Val: 20}
	//node4 := &TreeNode{Val: 15}
	//node5 := &TreeNode{Val: 7}
	//node1.Left = node2
	//node1.Right = node3
	//node3.Left = node4
	//node3.Right = node5

	node1 := buildBinaryTree([]string{"3", "9", "20", "null", "null", "15", "7"})
	fmt.Println(minDepth(node1))
}

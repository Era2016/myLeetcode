package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 中序遍历，有顺序
func kthSmallest(root *TreeNode, k int) int {
	/*
		sli := make([]int, 0, 1)
		//inOrder(root, &sli)
		inOrderWithoutRecursive(root, &sli)
		fmt.Println(sli)
		return sli[k-1]
	*/
	return inOrderWithoutRecursive2(root, k)
}

func inOrder(root *TreeNode, s *[]int) {
	if root != nil {
		inOrder(root.Left, s)
		*s = append(*s, root.Val)
		inOrder(root.Right, s)
	}
}

func inOrderWithoutRecursive(root *TreeNode, s *[]int) {
	stack := make([]*TreeNode, 0, 1)
	for root != nil || len(stack) != 0 {
		for root != nil {
			stack = append(stack, root)
			root = root.Left
		}
		node := stack[len(stack)-1]
		*s = append(*s, node.Val)
		stack = stack[:len(stack)-1]
		root = node.Right
	}
}

func inOrderWithoutRecursive2(root *TreeNode, k int) int {
	stack, count := make([]*TreeNode, 0, 1), 0
	for root != nil || len(stack) != 0 {
		for root != nil {
			stack = append(stack, root)
			root = root.Left
		}
		node := stack[len(stack)-1]
		count++
		if count == k {
			return node.Val
		}
		stack = stack[:len(stack)-1]
		root = node.Right
	}
	return -1
}

func main() {
	node := &TreeNode{Val: 3}
	node1 := &TreeNode{Val: 1}
	node2 := &TreeNode{Val: 4}
	node3 := &TreeNode{Val: 2}
	node.Left = node1
	node.Right = node2
	node1.Right = node3

	fmt.Println(kthSmallest(node, 3))
}

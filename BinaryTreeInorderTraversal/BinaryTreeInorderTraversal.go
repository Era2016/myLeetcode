package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// TODO 有问题，后面两个打印会报空指针错误，去掉注释，但运行结果不对
// 结构体指针相关确认下
func inorderTraversal(root *TreeNode) []int {
	stack, ret := make([]*TreeNode, 0), make([]int, 0)
	for root != nil || len(stack) != 0 {
		for root != nil {
			stack = append(stack, root)
			root = root.Left
		}

		size := len(stack)
		root := stack[size-1]
		ret = append(ret, root.Val)
		stack = stack[:size-1]
		root = root.Right
		//fmt.Printf("curr root: %v\n", root.Val)
		//fmt.Printf("curr root: %v\n", root != nil)
	}

	return ret
}

func inorderTraversal2(root *TreeNode) []int {
	valueList := make([]int, 0)
	stack := make([]*TreeNode, 0)

	curNode := root
	for curNode != nil || len(stack) > 0 {
		for curNode != nil {
			stack = append(stack, curNode)
			curNode = curNode.Left
		}

		top := stack[len(stack)-1]
		stack = stack[0 : len(stack)-1]
		valueList = append(valueList, top.Val)
		curNode = top.Right
	}

	return valueList
}

func main() {
	node := new(TreeNode)
	node.Val = 1
	node.Right = new(TreeNode)
	node.Right.Val = 2
	node.Right.Left = new(TreeNode)
	node.Right.Left.Val = 3
	fmt.Println(inorderTraversal(node))
}

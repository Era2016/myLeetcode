package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{}
	var iter *ListNode = head

	for l1 != nil && l2 != nil {
		if l1.Val <= l2.Val {
			iter.Next = l1
			iter = iter.Next

			l1 = l1.Next
		} else {
			iter.Next = l2
			iter = iter.Next

			l2 = l2.Next
		}
	}

	if l1 != nil {
		iter.Next = l1
	} else {
		iter.Next = l2
	}

	return head.Next
}

func mergeTwoListsWithRecursion(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}

	if l1.Val < l2.Val {
		l1.Next = mergeTwoListsWithRecursion(l1.Next, l2)
		return l1
	} else {
		l2.Next = mergeTwoListsWithRecursion(l1, l2.Next)
		return l2
	}
}

func print(node *ListNode) {
	for node != nil {
		fmt.Println(node.Val)
		node = node.Next
	}
}

func main() {
	node1 := &ListNode{Val: 1}
	node2 := &ListNode{Val: 2}
	node3 := &ListNode{Val: 4}
	node4 := &ListNode{Val: 1}
	node5 := &ListNode{Val: 3}
	node6 := &ListNode{Val: 4}
	//node7 := &ListNode{}
	var node8 *ListNode
	node1.Next = node2
	node2.Next = node3
	node4.Next = node5
	node5.Next = node6

	//print(node1)
	//print(node4)
	//newNode := mergeTwoListsWithRecursion(node1, node7)
	newNode := mergeTwoListsWithRecursion(node1, node8)
	print(newNode)
}

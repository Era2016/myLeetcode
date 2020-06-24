package main

import "fmt"

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	rr := calculate(l1, l2)
	//printList(rr)

	m := resetNumber(rr)
	//printList(m)
	return m
}

func calculate(l1 *ListNode, l2 *ListNode) *ListNode {
	var pHead, lHead *ListNode
	p1, p2 := l1, l2

	for p1 != nil && p2 != nil {
		node := &ListNode{}
		node.Val = p1.Val + p2.Val
		node.Next = nil
		if pHead == nil {
			pHead = node
			lHead = pHead
		} else {
			pHead.Next = node
			pHead = node
		}

		p1 = p1.Next
		p2 = p2.Next
	}

	for p1 != nil {
		node := &ListNode{}
		node.Val = p1.Val
		node.Next = nil
		if pHead == nil {
			pHead = node
			lHead = pHead
		} else {
			pHead.Next = node
			pHead = node
		}

		p1 = p1.Next
	}
	for p2 != nil {
		node := &ListNode{}
		node.Val = p2.Val
		node.Next = nil
		if pHead == nil {
			pHead = node
			lHead = pHead
		} else {
			pHead.Next = node
			pHead = node
		}

		p2 = p2.Next
	}
	return lHead
}

func resetNumber(l *ListNode) *ListNode {
	if l == nil {
		return nil
	}

	pHead := l
	added := l.Val / 10
	l.Val = l.Val % 10

	for l.Next != nil {
		if added > 0 {
			l.Next.Val += added
			added = 0
		}

		if l.Next.Val >= 10 {
			l.Next.Val -= 10
			added += 1
		}

		l = l.Next
	}

	if added != 0 {
		node := &ListNode{}
		node.Val = 1
		node.Next = nil

		l.Next = node
	}

	return pHead
}

/****high star****/
func addTwoNumbers2(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{}
	dummy := head
	for carry := 0; l1 != nil || l2 != nil || carry > 0; carry /= 10 {
		if l1 != nil {
			carry += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			carry += l2.Val
			l2 = l2.Next
		}
		dummy.Next = &ListNode{
			Val: carry % 10,
		}
		dummy = dummy.Next
	}
	return head.Next
}

func main() {
	lm := make(map[*ListNode]*ListNode)

	/* test 1*/
	lm[initList(2, 4, 3)] = initList(5, 6, 4)

	/* test 2*/
	lm[initList(1, 8)] = initList(0)

	/* test 3*/
	lm[initList(0)] = initList(0)

	/* test 4*/
	lm[initList(5)] = initList(5)

	for k, v := range lm {
		rr := calculate(k, v)
		m := resetNumber(rr)
		printList(m)
	}

	// ret := addTwoNumbers(L1, L2)
	// printList(ret)
}

func initList(ss ...int) *ListNode {
	var tmpHead, pHead *ListNode

	for i := 0; i < len(ss); i++ {
		node := &ListNode{}
		node.Val = ss[i]
		node.Next = nil
		if i == 0 {
			pHead = node
			tmpHead = node
		} else {
			tmpHead.Next = node
			tmpHead = node
		}
	}
	return pHead
}

func printList(l *ListNode) {
	p := l
	for p != nil {
		//fmt.Printf("node: %v\n", p.Val)
		fmt.Printf("%v\t", p.Val)
		p = p.Next
	}
	fmt.Println("")
}

func reverse(l *ListNode) *ListNode {
	if l == nil {
		return nil
	}

	var tmpNode, pNode *ListNode
	pHead := l
	pNode = pHead.Next

	for pNode != nil {
		tmpNode = pNode.Next

		pNode.Next = pHead
		if pHead == l {
			pHead.Next = nil
		}

		pHead = pNode
		pNode = tmpNode
	}

	return pHead
}

func output(l *ListNode) *ListNode {
	return reverse(resetNumber(l))
}

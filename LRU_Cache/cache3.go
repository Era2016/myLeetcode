package main

/*
去除读写锁，不支持并发读写；leetcode提交代码
*/

import "fmt"

// doublely link list
type linkList struct {
	key, val   int
	prev, next *linkList
}

func nodeRemove(node *linkList) {
	node.prev.next = node.next
	node.next.prev = node.prev
	node.next, node.prev = nil, nil
}

func nodeInsert(head, node *linkList) {
	node.prev = head
	node.next = head.next

	head.next.prev = node
	head.next = node
}

type LRUCache struct {
	count, capacity int
	hmap            map[int]*linkList
	head, tail      *linkList
}

func Constructor(capacity int) LRUCache {
	cache := LRUCache{
		hmap:     make(map[int]*linkList),
		capacity: capacity,
		head:     &linkList{},
		tail:     &linkList{},
	}
	cache.head.next = cache.tail
	cache.tail.prev = cache.head
	return cache
}

func (this *LRUCache) Get(key int) int {
	var val int
	var node *linkList

	if _, ok := this.hmap[key]; ok {
		node = this.hmap[key]
		val = node.val
	} else {
		val = -1
		goto FIN
	}

	if node == this.head {
		goto FIN
	} else {
		nodeRemove(node)
		nodeInsert(this.head, node)
	}

FIN:
	return val
}

func (this *LRUCache) Put(key, value int) {
	var isUpdate bool
	var node *linkList
	if v, ok := this.hmap[key]; ok {
		isUpdate = true
		node = v
	} else {
		node = &linkList{key: key, val: value}
	}

	if isUpdate {
		nodeRemove(node)
		// update (key value) pair
		node.val = value
	}

	// insert node
	nodeInsert(this.head, node)
	// update hash map
	this.hmap[key] = node

	// capacity check
	if !isUpdate {
		this.count++
		if this.count > this.capacity {
			node := this.tail.prev
			delete(this.hmap, node.key)
			nodeRemove(node)
			this.count--
		}
	}

	return
}

func (cache *LRUCache) print() {
	fmt.Printf("count: %d\n", cache.count)
	for k, v := range cache.hmap {
		fmt.Printf("key: %d, value: %d\n", k, v.val)
	}
	fmt.Println()
}

func (cache *LRUCache) printSequential() {
	fmt.Printf("count: %d\n", cache.count)
	for p := cache.head.next; p != cache.tail; p = p.next {
		fmt.Printf("key: %d, value: %d\n", p.key, p.val)
	}
	fmt.Println()
}

func main() {

	var cache LRUCache = Constructor(int(10))
	for i := 1; i <= 20; i++ {
		cache.Put(int(i), int(i+100))
	}
	cache.printSequential()
	cache.print()

	cache.Put(int(8), int(88888))
	cache.printSequential()
	//cache.print()

	cache.Get(int(1))
	cache.Get(int(12))
	cache.printSequential()

	fmt.Println("hello world")
}

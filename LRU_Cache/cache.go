package main

import "fmt"
import "sync"

// doublely link list
type linkList struct {
	key, val   int64
	prev, next *linkList
}

type LRUCache struct {
	capacity, count int64
	hmap            map[int64]*linkList
	head, tail      *linkList
	sync.RWMutex
}

func cacheInit(capacity int64) *LRUCache {
	cache := &LRUCache{
		hmap:     make(map[int64]*linkList),
		capacity: capacity,
	}
	return cache
}

func (cache *LRUCache) get(key int64) (val int64) {
	// O(1) get value
	var node *linkList
	cache.RLock()
	if _, ok := cache.hmap[key]; ok {
		node = cache.hmap[key]
		val = node.val
		cache.RUnlock()
	} else {
		val = -1
		cache.RUnlock()
		return
	}

	// sort link list
	cache.Lock()
	if node == cache.head {
		goto FIN
	} else {
		// delete node
		if node.next == nil { // tail node
			node.prev.next = nil
			cache.tail = node.prev
			node.prev = nil
		} else { // normal node
			node.prev.next = node.next
			node.next.prev = node.prev
			node.next, node.prev = nil, nil
		}

		// insert node
		node.next = cache.head
		cache.head.prev = node
		cache.head = node
	}

FIN:
	cache.Unlock()

	return
}

func (cache *LRUCache) put(key, value int64) {
	var isUpdate bool
	var node *linkList
	cache.RLock()
	if v, ok := cache.hmap[key]; ok {
		isUpdate = true
		node = v
	} else {
		node = &linkList{key: key, val: value}
	}
	cache.RUnlock()

	cache.Lock()
	if isUpdate {
		// delete node
		if node.next == nil { // tail node
			node.prev.next = nil
			cache.tail = node.prev
			node.prev = nil
		} else { // normal node
			node.prev.next = node.next
			node.next.prev = node.prev
			node.next, node.prev = nil, nil
		}
		// update (key value) pair
		node.val = value
	}

	// insert node
	if cache.head == nil {
		cache.head = node
		cache.tail = node
	} else {
		node.next = cache.head
		cache.head.prev = node
		cache.head = node
	}

	// update hash map
	cache.hmap[key] = node

	// capacity check
	if !isUpdate {
		cache.count++
		if cache.count > cache.capacity {
			cache.tail.prev.next = nil
			tmp := cache.tail
			cache.tail = cache.tail.prev
			tmp.prev = nil

			delete(cache.hmap, tmp.key)
			cache.count--
		}
	}

	cache.Unlock()
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
	for p := cache.head; p != nil; p = p.next {
		fmt.Printf("key: %d, value: %d\n", p.key, p.val)
	}
	fmt.Println()
}

func main() {

	var cache *LRUCache = cacheInit(int64(10))
	for i := 1; i <= 20; i++ {
		cache.put(int64(i), int64(i+100))
	}
	cache.printSequential()
	//cache.print()

	cache.put(int64(8), int64(88888))
	cache.printSequential()
	//cache.print()

	cache.get(int64(1))
	cache.get(int64(12))
	cache.printSequential()

	fmt.Println("hello world")
}

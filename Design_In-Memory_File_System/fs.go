package main

import "fmt"
import "strings"
import "sort"

type node struct {
	is_dir bool             // flag, judge whether dir
	name   string           // file or dir name
	data   string           // content if file, consider transform to []byte
	next   map[string]*node // path name -> tree node
}

type FileSystem struct {
	root *node // root of tree
}

func (this *node) isDir() bool          { return this.is_dir }
func (this *node) getName() string      { return this.name }
func (this *node) write(content string) { this.data += content }
func (this *node) read() string         { return this.data }

func (this *node) ls() []string {
	//if this.is_dir == false || this.getName() == "/" {
	if this.is_dir == false {
		return []string{this.getName()}
	}

	dirs := []string{}
	for k, _ := range this.next {
		dirs = append(dirs, k)
	}
	sort.Strings(dirs)
	return dirs
}

func NewFileSystem() *FileSystem {
	// 虚拟头结点，不存储路径信息
	pNode := node{
		is_dir: true,
		name:   "",
	}
	fs := FileSystem{root: &pNode}
	return &fs
}

func (fs *FileSystem) ls(path string) []string {
	var ok bool
	dirs, cur := fs.tokenize(path), fs.root

	for _, v := range dirs {
		if cur, ok = cur.next[v]; !ok {
			return []string{}
		}
	}
	return cur.ls()
}

func (fs *FileSystem) mkdir(path string) {
	dirs, cur := fs.tokenize(path), fs.root

	for _, v := range dirs {
		if cur.next == nil {
			cur.next = make(map[string]*node)
		}

		if _, ok := cur.next[v]; !ok {
			cur.next[v] = &node{is_dir: true, name: v}
		}
		cur = cur.next[v]
	}
}

func (fs *FileSystem) addContentToFile(path, content string) {
	var ok bool
	dirs, cur := fs.tokenize(path), fs.root

	for i := 0; i < len(dirs)-1; i++ {
		if cur, ok = cur.next[dirs[i]]; !ok {
			return
		}
	}

	fileName := dirs[len(dirs)-1]
	cur.next[fileName] = &node{is_dir: false, name: fileName}
	cur.write(content)

	return
}

func (fs *FileSystem) readContentFromFile(path string) string {
	var ok bool
	dirs, cur := fs.tokenize(path), fs.root

	for i := 0; i < len(dirs)-1; i++ {
		if cur, ok = cur.next[dirs[i]]; !ok {
			return ""
		}
	}

	return cur.read()
}

func (this *FileSystem) tokenize(path string) []string {
	dirs := []string{"/"} // 特殊头结点 / ,所有目录以/ 起始
	// 去除目录末尾/ 标识，便于统一处理节点信息
	dirs = append(dirs, strings.Split(strings.TrimRight(path, "/"), "/")...)
	return dirs
}

func main() {
	fs := NewFileSystem()
	var ret []string
	ret = fs.ls("/")
	fmt.Printf("ls /, ret: %v\n", ret)

	fs.mkdir("/a/b/c/d")
	ret = fs.ls("/a/b/")
	fmt.Printf("ls /a/b/, ret: %v\n", ret)

	fs.mkdir("/a/b/d")
	ret = fs.ls("/a/b")
	fmt.Printf("ls /a/b, ret: %v\n", ret)
	ret = fs.ls("/a")
	fmt.Printf("ls /a, ret: %v\n", ret)
	ret = fs.ls("/")
	fmt.Printf("ls /, ret: %v\n", ret)

	fs.mkdir("/a")
	ret = fs.ls("/a")
	fmt.Printf("ls /a, ret: %v\n", ret)

	fs.addContentToFile("/a/b/file.txt", "hello world")
	fmt.Println(fs.readContentFromFile("/a/b/file.txt"))

	ret = fs.ls("/a/b")
	fmt.Printf("ls /a/b, ret: %v\n", ret)

}

package main

import "fmt"
import "strings"

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
	if this.is_dir == false || this.getName() == "/" {
		return []string{this.getName()}
	}

	dirs := []string{}
	for k, _ := range this.next {
		dirs = append(dirs, k)
	}
	return dirs
}

func NewFileSystem() *FileSystem {
	pNode := node{
		is_dir: true,
		name:   "/",
	}
	fs := FileSystem{root: &pNode}
	return &fs
}

func (fs *FileSystem) ls(path string) []string {
	var ok bool
	dirs := fs.tokenize(path)
	cur := fs.root

	//for i := 0; i < len(dirs); i++ {
	//	if dirs[i] == "/" {
	//		goto END
	//	} else if cur, ok = cur.next[dirs[i]]; !ok {
	//		return []string{}
	//	}
	//}

	for _, v := range dirs {
		if v == "/" {
			goto END
		} else if cur, ok = cur.next[v]; !ok {
			return []string{}
		}
	}
END:
	return cur.ls()
}

func (fs *FileSystem) mkdir(path string) {
	dirs := fs.tokenize(path)
	cur := fs.root
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
	dirs := fs.tokenize(path)
	cur := fs.root
	for i := 0; i < len(dirs); i++ {
		cur = cur.next[dirs[i]]
	}

	cur.write(content)
	return
}

func (fs *FileSystem) readContentFromFile(path string) string {
	dirs := fs.tokenize(path)
	cur := fs.root
	for i := 0; i < len(dirs); i++ {
		cur = cur.next[dirs[i]]
	}

	return cur.read()
}

func (this *FileSystem) tokenize(path string) []string {
	if path != "/" {
		return strings.Split(strings.TrimRight(path, "/"), "/")
	}
	return []string{"/"}
}

func main() {
	fs := NewFileSystem()
	var ret []string

	fs.mkdir("/a/b/c/d")
	ret = fs.ls("/a/b/")
	fmt.Println(ret)

	fs.mkdir("/a/b/d")
	ret = fs.ls("/a/b")
	fmt.Println(ret)
	ret = fs.ls("/a")
	fmt.Println(ret)
	ret = fs.ls("/")
	fmt.Println(ret)

	fs.mkdir("/a")
	ret = fs.ls("/a")
	fmt.Println(ret)

}

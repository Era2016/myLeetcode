package main

import "fmt"

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
func (this *node) getName()             { return this.name }
func (this *node) write(content string) { this.data = append(this.data, content) }
func (this *node) read() string         { return this.data }

func FileSystem() *FileSystem                                   { return &FileSystem{} }
func (this *FileSystem) ls(path string) []string                {}
func (this *FileSystem) mkdir(path string)                      {}
func (this *FileSystem) addContentToFile(path, content string)  {}
func (this *FileSystem) readContentFromFile(path string) string {}

func main() {}

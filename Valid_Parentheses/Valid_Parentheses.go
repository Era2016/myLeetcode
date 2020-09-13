package main

import "fmt"

func isValid(s string) bool {
	stack, top := make([]byte, len(s)), -1
	for i := 0; i < len(s); i++ {
		if s[i] == '(' || s[i] == '[' || s[i] == '{' {
			stack[top+1] = s[i]
			top++
		} else {
			if top == -1 {
				return false
			}
			if stack[top] == '(' && s[i] == ')' || stack[top] == '[' && s[i] == ']' || stack[top] == '{' && s[i] == '}' {
				top--
			} else {
				return false
			}
		}
	}
	if top == -1 {
		return true
	}
	return false
}

func main() {
	var s string

	s = "()[]{}"
	fmt.Printf("origin: %s, result: %v\n", s, isValid(s))

	s = "([{}])"
	fmt.Printf("origin: %s, result: %v\n", s, isValid(s))

	s = "())[]{}"
	fmt.Printf("origin: %s, result: %v\n", s, isValid(s))

	s = ""
	fmt.Printf("origin: %s, result: %v\n", s, isValid(s))

}

package main

import "fmt"

func countAndSay(n int) string {
	var str string = "1"
	for i := 1; i < n; i++ {
		//fmt.Printf("index: %v,before result: %v\n", i, string(str))
		str = countString(str)
		//fmt.Printf("index: %v,after result: %v\n", i, string(str))
	}
	return str
}

func countString(s string) string {
	//fmt.Printf("before countString: %s\n", string(s))
	if len(s) == 0 {
		return ""
	}

	count := 1
	str := make([]byte, 0, len(s))
	for i := 1; i < len(s); i++ {
		if s[i] == s[i-1] {
			count++
		} else {
			tmp := fmt.Sprintf("%d%s", count, string(s[i-1]))
			str = append(str, []byte(tmp)...)
			count = 1
		}
	}

	tmp := fmt.Sprintf("%d%s", count, string(s[len(s)-1]))
	str = append(str, []byte(tmp)...)
	//fmt.Printf("after countString: %s\n", string(str))
	return string(str)
}

func main() {
	//tmp := countString("11")
	//fmt.Println(tmp)

	var n int
	n = 4
	tmp := countAndSay(n)
	fmt.Println(tmp)
}

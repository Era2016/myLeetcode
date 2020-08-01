package main

import "fmt"

//import "sort"

func groupAnagrams(strs []string) [][]string {
	m := make(map[string][]string)

	for i := 0; i < len(strs); i++ {
		str := sortStringWithCounting(strs[i])
		if _, ok := m[str]; ok {
			var s []string = m[str]
			s = append(s, strs[i])
			m[str] = s
		} else {
			m[str] = []string{strs[i]}
		}
	}

	ss, i := make([][]string, len(m)), 0

	for _, v := range m {
		ss[i] = v
		i++
	}
	return ss
}

func sortStringWithInsert(s string) string {
	data := []byte(s)

	for i := 1; i < len(data); i++ {
		j := i - 1
		for j >= 0 && data[j] > data[j+1] {
			data[j], data[j+1] = data[j+1], data[j]
			j--
		}
	}

	return string(data)
}

func sortStringWithCounting(s string)  string{
	data := []byte(s)
	cArr := make([]int, 26)
	for i := 0; i < len(data); i ++ {
		cArr[data[i] - 'a'] ++
	}

	k := 0
	for i := 0; i < 26; i ++ {
		for j := 0; j < cArr[i]; j ++ {
			data[k] = byte(i) + 'a'
			k ++
		}
	}
	return string(data)
}

func main() {
	strs := []string{"eat", "tea", "tan", "ate", "nat", "bat"}
	/*for _, v := range strs {
		fmt.Println(sortStringWithCounting(v))
	}*/
	fmt.Println(groupAnagrams(strs))
}

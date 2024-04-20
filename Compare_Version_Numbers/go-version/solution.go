package main

import (
	"fmt"
	"strconv"
	"strings"
)

func compareVersion(version1, version2 string) int {
	s1 := strings.Split(version1, ".")
	s2 := strings.Split(version2, ".")

	for i1, i2 := 0, 0; i1 < len(s1) || i2 < len(s2); i1, i2 = i1+1, i2+1 {
		num1, num2 := int64(0), int64(0)
		if i1 < len(s1) {
			num1, _ = strconv.ParseInt(s1[i1], 10, 64)
		}
		if i2 < len(s2) {
			num2, _ = strconv.ParseInt(s2[i2], 10, 64)
		}

		if num1 < num2 {
			return -1
		} else if num1 > num2 {
			return 1
		}
	}
	return 0
}

func main() {
	fmt.Println(compareVersion("1.01", "1.001"))
	fmt.Println(compareVersion("1.0", "1.0.0"))
	fmt.Println(compareVersion("0.1", "1.1"))
	fmt.Println(compareVersion("7.5.2.4", "7.5.3"))
}

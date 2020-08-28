package main

import "fmt"

func romanToInt(s string) int {
	romanMap := map[byte]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}
	num := 0
	s += "0"

	for i := 0; i < len(s)-1; i++ {
		if (s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')) ||
			(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) ||
			(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')) {
			num += romanMap[s[i+1]] - romanMap[s[i]]
			i++
			continue
		}
		num += romanMap[s[i]]
	}
	return num
}

func romanToInt2(s string) int {
	var roman = map[string]int{
		"I": 1,
		"V": 5,
		"X": 10,
		"L": 50,
		"C": 100,
		"D": 500,
		"M": 1000,
	}
	res := 0
	for i := 0; i < (len(s) - 1); i++ {
		add := roman[string(s[i])]
		if add < roman[string(s[i+1])] {
			add = -add
		}
		res = res + add
	}
	res = res + roman[string(s[len(s)-1])]
	return res
}

func main() {
	//origin := "III"
	//fmt.Println(romanToInt(origin))

	mm := map[string]int{
		"III":     3,
		"IV":      4,
		"IX":      9,
		"LVIII":   58,
		"MCMXCIV": 1994,
	}
	for k, v := range mm {
		fmt.Printf("origin: %s, result: %d, in act: %d\n", k, v, romanToInt(k))
	}
}

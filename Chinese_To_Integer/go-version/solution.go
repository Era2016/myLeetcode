package main

import (
	"fmt"
)

func convert(str []rune) int64 {
	mapping_1 := map[rune]int64{
		'一': 1, '二': 2, '三': 3, '四': 4, '五': 5,
		'六': 6, '七': 7, '八': 8, '九': 9}
	mapping_2 := map[rune]int64{'十': 10, '百': 100, '千': 1000, '万': 10000, '亿': 100000000}
	result := int64(0)

	isBillion, isTenThousand := false, false
	i := 0
	for i < len(str)-1 {
		s1, s2 := str[i], str[i+1]
		fmt.Println(string(s1), string(s2))
		if v, ok := mapping_1[s1]; ok {
			if s2 == '亿' {
				isBillion = true
				result = (result + v) * mapping_2[s2]
			} else if s2 == '万' {
				isTenThousand = true
				result = (result + v) * mapping_2[s2]
			} else {
				result = result + v*mapping_2[s2]
			}
			i += 2
		} else if v2, ok := mapping_2[s1]; ok {
			if s1 == '亿' {
				isBillion = true
			} else if s1 == '万' {
				isTenThousand = true
			}

			remain := result
			if isBillion {
				remain %= 100000000
				result -= remain
			}
			if isTenThousand {
				tmp_remain := remain % 10000
				if tmp_remain != remain {
					result -= tmp_remain
					remain = tmp_remain
				}
			}
			if isBillion || isTenThousand {
				result = result + v2*remain
			} else {
				result = v2 * remain
			}

			i += 1
		} else {
			i += 1
		}
	}

	s := str[len(str)-1]
	if v, ok := mapping_1[s]; ok {
		result += v
	} else {
		result *= v
	}

	return result
}

func main() {
	fmt.Println("hello world")
	//三千五百四十二万五千三百六十八亿七千九百六十万零五千二百三十八 --> 3542536879605238
	fmt.Println(convert([]rune{'三', '千', '五', '百', '四', '十', '二', '万', '五', '千', '三', '百', '六', '十', '八', '亿', '七', '千', '九', '百', '六', '十', '万', '零', '五', '千', '二', '百', '三', '十', '八'}))

	//三十亿零五千万零三 --> 3050000003
	fmt.Println(convert([]rune{'三', '十', '亿', '零', '五', '千', '万', '零', '三'}))
}

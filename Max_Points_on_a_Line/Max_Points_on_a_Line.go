package main

import "fmt"
import "strings"
import "strconv"

/**
* 重复点当做1
* y = kx + b
  k 有精度问题
 */
func maxPointsWithoutRepeated(points [][]int) int {

	if len(points) == 0 {
		return 0
	}

	m := make(map[string]map[int]bool)
	max := 1

	for i := 0; i < len(points)-1; i++ {
		for j := i + 1; j < len(points); j++ {
			minus, k := points[j][0]-points[i][0], 0
			var key string
			if minus == 0 {
				key = fmt.Sprintf("#%d", points[i][1])
			} else {
				k = (points[j][1] - points[i][1]) / minus
				b := points[j][1] - k*points[j][0]
				key = fmt.Sprintf("%d#%d", k, b)
			}

			if _, ok := m[key]; !ok {
				m[key] = map[int]bool{
					i: true,
					j: true,
				}
			} else {
				//fmt.Printf("current (%v,%v)\n", i, j)
				m[key][i] = true
				m[key][j] = true
			}
		}
	}

	for _, v := range m {
		if max < len(v) {
			max = len(v)
		}
	}
	return max
}

// 有精度问题
func maxPoints(points [][]int) int {

	if len(points) <= 1 {
		return len(points)
	}

	m := make(map[string]bool)

	for i := 0; i < len(points)-1; i++ {
		for j := i + 1; j < len(points); j++ {
			minus, k := points[j][0]-points[i][0], 0
			var key string
			if minus == 0 {
				key = fmt.Sprintf("#%d", points[i][1])
			} else {
				k = (points[j][1] - points[i][1]) / minus
				b := points[j][1] - k*points[j][0]
				key = fmt.Sprintf("%d#%d", k, b)
			}

			if _, ok := m[key]; !ok {
				m[key] = true
			}
		}
	}

	fmt.Println(m)
	var x, k, b int64
	var max int
	for v, _ := range m {
		ret := strings.Split(v, "#")
		tmpMax := 0
		for i := 0; i < len(points); i++ {
			if ret[0] == "" {
				x, _ = strconv.ParseInt(ret[1], 10, 64)
				if points[i][0] == int(x) {
					tmpMax++
				}
			} else {
				k, _ = strconv.ParseInt(ret[0], 10, 64)
				b, _ = strconv.ParseInt(ret[1], 10, 64)
				if points[i][1] == int(k)*points[i][0]+int(b) {
					tmpMax++
				}
			}

			if max < tmpMax {
				max = tmpMax
			}

		}
	}
	return max
}

func main() {
	points1 := [][]int{{1, 1}, {2, 2}, {3, 3}}
	points2 := [][]int{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}}
	points3 := [][]int{{0, 0}}
	points4 := [][]int{}
	points5 := [][]int{{3, 10}, {0, 2}, {0, 2}, {3, 10}}
	fmt.Println(maxPoints(points1))
	fmt.Println(maxPoints(points2))
	fmt.Println(maxPoints(points3))
	fmt.Println(maxPoints(points4))
	fmt.Println(maxPoints(points5))
}

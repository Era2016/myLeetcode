package main

import "fmt"
import "strings"
import "strconv"
import "math"

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
			minus, k := points[j][0]-points[i][0], float64(0)
			var key string
			if minus == 0 {
				key = fmt.Sprintf("#%f", float64(points[i][0]))
			} else {
				k = float64((points[j][1] - points[i][1])) / float64(minus)
				b := float64(points[j][1]) - k*float64(points[j][0])
				key = fmt.Sprintf("%f#%f", k, b)
			}

			if _, ok := m[key]; !ok {
				m[key] = true
			}
		}
	}

	fmt.Println(m)
	var x, k, b float64
	var max int
	for v, _ := range m {
		ret := strings.Split(v, "#")
		tmpMax := 0
		for i := 0; i < len(points); i++ {
			if ret[0] == "" {
				x, _ = strconv.ParseFloat(ret[1], 64)
				//if float64(points[i][0]) == float64(x) {
				if equal(float64(points[i][0]), float64(x)) == true {
					tmpMax++
				}
			} else {
				k, _ = strconv.ParseFloat(ret[0], 64)
				b, _ = strconv.ParseFloat(ret[1], 64)
				//fmt.Printf("index: %v, ret: %v, calu: %v\n", i, points[i][1], float64(k)*float64(points[i][0])+float64(b))
				//if float64(points[i][1]) == float64(k)*float64(points[i][0])+float64(b) {
				if equal(float64(points[i][1]), float64(k)*float64(points[i][0])+float64(b)) == true {
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

func equal(a, b float64) (ret bool) {
	// defer func() {
	// 	fmt.Printf("[%v, %v, %v] \n", a, b, ret)
	// }()

	ret = math.Abs(a-b) <= 0.00001
	return
}

func main() {
	//fmt.Println(equal(float64(10), float64(10.000001)))

	// points1 := [][]int{{1, 1}, {2, 2}, {3, 3}}
	// points2 := [][]int{{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}}
	// points3 := [][]int{{0, 0}}
	// points4 := [][]int{}
	// points5 := [][]int{{3, 10}, {0, 2}, {0, 2}, {3, 10}}
	// points6 := [][]int{{0, 0}, {94911151, 94911150}, {94911152, 94911151}} // -> 2
	points7 := [][]int{{4, 0}, {4, -1}, {4, 5}}
	// fmt.Println(maxPoints(points1))
	// fmt.Println(maxPoints(points2))
	// fmt.Println(maxPoints(points3))
	// fmt.Println(maxPoints(points4))
	// fmt.Println(maxPoints(points5))
	// fmt.Println(maxPoints(points6))
	fmt.Println(maxPoints(points7))
}

#include <iostream>
using namespace std;

int maxArea(int* height, int heightSize);
int main()
{
    int* height = new int[10];
    /*for (int i = 0; i < 10; i ++) {
        height[i] = i + 1;
    }*/
    height[0] = 1;
    height[1] = 2;
    height[2] = 4;
    height[3] = 3;
    int result = maxArea(height, 4);
    cout << result << endl;
    return 0;
}

int maxArea(int* height, int heightSize)
{
    int start = 0;
    int end = heightSize - 1;
    int area = 0;
    int tar1 = -1, tar2 = -1;

    while (start < end) {
        //area = height[start]*(end - start);
        if (height[start] < height[end]) {
            int temp = height[start] * (end - start);
            if (temp > area) {
                area = temp;
                tar1 = start;
                tar2 = end;
            }
            start ++;
        } else {
            int temp = height[end] * (end - start);
            if (temp > area) {
                area = temp;
                tar1 = start;
                tar2 = end;
            }
            end --;
        }
    }
    
    cout << tar1 << endl << tar2 << endl;
    return area;
}

#include <iostream>
using namespace std;

int Partition1(int a[], int p, int r) {                    //进行快速排序
    int x = a[r];
    int i = p - 1;
    for (int j = p; j < r; j ++)
    {
        if (a[j] <= x) {
            i ++;
            swap(a[i], a[j]);                        //交换
        }
    }
    swap(a[i+1], a[r]);
    return i + 1;
}

void quicksort1(int a[],int p,int r) {              //递归调用
    if (p < r)
    {
        int q = Partition1(a, p, r);
        quicksort1(a, p, q - 1);
        quicksort1(a, q + 1 , r);
    }
}

int main()
{
    int a[8] = { 1,3,2,4,5,8,6,9 };
    quicksort1(a,0,7);
    for (int n = 0; n < 8; n++)
    {
        cout << a[n] << endl;
    }
    cout << endl;
}

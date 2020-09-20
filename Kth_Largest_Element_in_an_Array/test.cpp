#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    public:
        void testQueue(vector<int> v) {
            // min-heap
            priority_queue<int, vector<int>, greater<int> > pq;
            for (int i = 0; i < (int)v.size(); i ++) {
                pq.push(v[i]);
            }

            while (!pq.empty()) {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        
        void testNthElement(vector<int> v, int k) {
            nth_element(v.begin(), v.begin()+k-1, v.end(), greater<int>()); 
            cout << v[k-1] << endl;
        }

        int partation(vector<int>& v, int start, int end) {
            int index = start - 1;
            for (int i = start; i < end; i ++) {
                if (v[i] < v[end]) {
                    if (i != index) {
                        index ++;
                        swap(v[i], v[index]);
                    }
                }
            }
            index ++;
            swap(v[index], v[end]);
            return index;
        }

        void quickSort(vector<int>& v, int start, int end) {
            if (start < end) {
                int index = partation(v, start, end);
                quickSort(v, start, index-1);
                quickSort(v, index+1, end);
            }
        }
};

int main() {
    Solution* so = new Solution();
    vector<int> v = {1,5,3,4,2};
    //so->testQueue(v);
    //so->testNthElement(v, 1);
    so->quickSort(v, 0, v.size()-1);
    for (int i = 0; i < (int)v.size(); i ++) {
        cout << v[i] << endl;
    }
}

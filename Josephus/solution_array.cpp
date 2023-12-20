#include <iostream>
#include <vector>

using std::vector;
class Solution {
public:
    int Josephus(int n, int m) {
        vector<int> people(n, 1);
        int left = n;
        int index = 0;
        while (left > 1) {
            int cnt = 1;
            while (cnt < m) {
                if (people[index] == 0) {
                    index = (index+1)%n;
                    continue;
                }
                index = (index+1)%n;
                cnt ++;
            }
            people[index] = 0;
            left --;
        }
        
        for (int i = 0; i < n; i ++) {
            if (people[i] == 1) {
                return i;
            }
        }
        return -1;
    }

    int Josephus_v2(vector<int> arr, int k) {
        //unordered_map<int, int> um;
        //for (int i = 0; i < arr.size(); i ++) {
        //    um[arr[i]] = i;
        //}

        int index = 0, i = 0;
        while (true) {
            index ++;
            if (index == k) {
                index = 1;
                std::cout << "remove: " << arr[i] << std::endl;
                arr.erase(arr.begin()+i);
                if (arr.size() == 1) {
                    //return um[arr[0]];
                    return arr[0];
                }
            }

            i ++;
            if (i >= arr.size()) {
                i = 0;
            }
        }
        return -1;
    }
    
};

int main() {
    Solution *so = new Solution();

    std::cout << so->Josephus(5, 2) << std::endl; //2
    std::cout << so->Josephus(5, 3) << std::endl; //1
}
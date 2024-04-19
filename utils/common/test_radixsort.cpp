#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

using std::vector;
class Solution {
public:
    // 基数排序
    void radixSort(vector<int>& nums) {
        int maxVal = *std::max_element(nums.begin(), nums.end());
        int maxDigits = 0;
        for (int i = maxVal; i != 0; i /= 10) {
            maxDigits ++;
        }

        auto getDigit=[](int num, int iDigit) {
            //for (int cnt = 0; num != 0; num /= 10, cnt ++) {
            //    int d = num%10;
            //    if (cnt == iDigit) {
            //        return d;
            //    }
            //}
            //return 0;
            while (iDigit > 0) {
                num /= 10;
                iDigit --;
            }
            return num%10;
        };
        
        // radix sort
        vector<vector<int>> buckets(10);
        for (int i = 0; i < maxDigits; i ++) {
            
            for (auto num: nums) {
                int d = getDigit(num, i); 
                buckets[d].push_back(num);
            }

            int index = 0;
            for (auto& bucket: buckets) {
                for (auto num: bucket) {
                    nums[index ++] = num;
                }

                bucket.clear();
            }
        }
    }
};

int main() {
    Solution *so = new Solution();
    vector<int> nums;
    auto print=[&]() {
        for (auto num: nums) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    };

    // 创建随机数引擎
    std::random_device rd;
    std::mt19937 gen(rd()); // 使用 Mersenne Twister 算法
    // 创建均匀分布器，指定随机数范围为 [1, 100]
    std::uniform_int_distribution<int> dis(1, 1000);
    // 生成随机数
    //int randomNum = dis(gen);
    for (int cnt = 10; cnt > 0; cnt --) {
        for (int i = 0; i < 15; i ++) {
            nums.push_back(dis(gen));
        }
        so->radixSort(nums);
        print();
        nums.clear();
    }
}

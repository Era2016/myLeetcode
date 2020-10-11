#include <iostream>
#include <vector>
#include <chrono> // Measure execution time of a function in C++ 

using namespace std;
using namespace std::chrono;

class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) {
            return 0;
        }
        // dp[i] = the least number of perfect square numbers 
        // which sum to i. Note that dp[0] is 0.
 		vector<int> dp(n+1, INT_MAX); 
        dp[0] = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j*j <= i; j ++) {
                dp[i] = min(dp[i], dp[i-j*j] + 1);
            }
        }

        return dp[n];
    }

	int numSquares2(int n) 
    {
        if (n <= 0) {
            return 0;
        }
        
        // cntPerfectSquares[i] = the least number of perfect square numbers 
        // which sum to i. Since cntPerfectSquares is a static vector, if 
        // cntPerfectSquares.size() > n, we have already calculated the result 
        // during previous function calls and we can just return the result now.
        static vector<int> cntPerfectSquares({0});
        
        // While cntPerfectSquares.size() <= n, we need to incrementally 
        // calculate the next result until we get the result for n.
        while ((int)cntPerfectSquares.size() <= n) {
            int m = cntPerfectSquares.size();
            int cntSquares = INT_MAX;
            for (int i = 1; i*i <= m; i++) {
                cntSquares = min(cntSquares, cntPerfectSquares[m - i*i] + 1);
            }
            
            cntPerfectSquares.push_back(cntSquares);
        }
        
        return cntPerfectSquares[n];
    }
};

int main() {
    Solution* so = new Solution();
    cout << "first =====" << endl;
    for (int i = 0; i < 10; i ++) {
        auto start = high_resolution_clock::now();
        int val = so->numSquares(123456 + i);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << val << " consuming:" << duration.count() << endl; 
    }

    cout << "second=====" << endl;
    for (int i = 0; i < 10; i ++) {
        auto start2 = high_resolution_clock::now();
        int val2 = so->numSquares2(123456 + i);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        cout << val2 << " consuming:" << duration2.count() << endl; 
    }

    //val = so->numSquares(13);
    //val2 = so->numSquares2(12);
    //cout << val << "\t"<< val2 << endl;
}

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <deque>

using namespace std;

class Solution {
    public:
        vector<deque<int>> generate(int n) {
            
        }

        void inoutstack(int in, int out, deque<int>& q, stack<int>& s, deque<int> seq, vector<deque<int>>& result) {
            if (!in && !out) {
                result.push_back(q);
            } 
            
            if (in > 0) {
                s.push(seq.front());
                seq.pop_front();
                inoutstack(in - 1, out, q, s, seq, result);
                seq.push_front(s.top());
                s.pop();
            }

            if (out > 0 && in < out) {
                q.push_back(s.top());
                s.pop();
                inoutstack(in, out - 1, q, s, seq, result);
                s.push(q.back());
                q.pop_back();
            }
        } 
        
;

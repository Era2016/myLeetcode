// timeout for `aaaaaaaa....aaaa`

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) {
            return {};
        }
        unordered_map<string, int> um;
        unordered_map<string, int> window;
        for (const auto& k: words) {
            um[k] ++;
        }

        int wordLen = words[0].length();
        int size = um.size();
        int totalLen = words.size() * wordLen;
        vector<int> result;
        int left = 0, right = 0;
        int cnt = 0;
        while (right <= s.length()) {
            while (right - left >= totalLen) {
                for (int i = left; i <= s.length()-wordLen; i += wordLen) {
                    string subString = s.substr(i, wordLen);
                    if (um.find(subString) != um.end()) {
                        window[subString] ++;
                        if (window[subString] == um[subString]) {
                            cnt ++;
                        } else if (window[subString] > um[subString]) {
                            break;
                        }
                    } else {
                        break;
                    }
                }
                
                if (cnt == size) {
                    result.push_back(left);
                    cout << "result: " << left << endl;
                }
                left ++;
            }
            right ++;
            window.clear();
            cnt = 0;
        }

        return result;
    }
};

int main() {
    Solution *so = new Solution();
    vector<string> words;
    vector<int> result;
    string s;
    auto print=[](vector<int>& nums) {
        for (const auto& n: nums) {
            cout << n << "\t";
        }
        cout << endl << endl;
    };

    words = {"foo","bar"};
    s = "barfoothefoobarman";
    result = so->findSubstring(s, words);
    print(result);
    
    words = {"word","good","best","word"};
    s = "wordgoodgoodgoodbestword";
    result = so->findSubstring(s, words);
    print(result);

    words = {"bar","foo","the"};
    s = "barfoofoobarthefoobarman";
    result = so->findSubstring(s, words);
    print(result);

    words = {"word","good","best","good"};
    s = "wordgoodgoodgoodbestword";
    result = so->findSubstring(s, words);
    print(result);
}

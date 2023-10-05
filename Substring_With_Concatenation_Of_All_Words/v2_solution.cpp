// slideing window

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) return {};
        int wordLength = words[0].length();
        int wordSize = words.size();
        int totalLength = wordLength*wordSize;
        int stringLength = s.length();
        
        unordered_map<string, int> window;
        vector<int> result;
        for (int i = 0; i < wordLength && i+totalLength<=stringLength; i ++) {
            //cout << "index: " <<i << endl;
            window.clear();
            for (int j = 0; j < wordSize; j += 1) {
                window[s.substr(i+j*wordLength, wordLength)] ++;
            }
            for (const auto& word: words) {
                window[word] --;
                if (window[word] == 0) {
                    window.erase(word);
                }
            }

            for (int j = i; j <= stringLength-totalLength; j += wordLength) {
                if (j != i) {
                    string nextSub = s.substr(j+totalLength-wordLength, wordLength);
                    window[nextSub] ++;
                    if (window[nextSub] == 0) {
                        window.erase(nextSub);
                    }

                    string prevSub = s.substr(j-wordLength, wordLength);
                    window[prevSub] --;
                    if (window[prevSub] == 0) {
                        window.erase(prevSub);
                    }
                }
                if (window.empty()) {
                    result.push_back(j);
                    //cout << "succ: " <<j << endl;
                }
            }
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

    // words = {"foo","bar"};
    // s = "barfoothefoobarman";
    // result = so->findSubstring(s, words);
    // print(result);
    
    // words = {"word","good","best","word"};
    // s = "wordgoodgoodgoodbestword";
    // result = so->findSubstring(s, words);
    // print(result);

    // words = {"bar","foo","the"};
    // s = "barfoofoobarthefoobarman";
    // result = so->findSubstring(s, words);
    // print(result);

    // words = {"word","good","best","good"};
    // s = "wordgoodgoodgoodbestword";
    // result = so->findSubstring(s, words);
    // print(result);

    words = {"fooo","barr","wing","ding","wing"};
    s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    result = so->findSubstring(s, words);
    print(result);
}
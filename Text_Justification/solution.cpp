#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Solution {
    string blank(int n) {
        return string(n, ' ');
    }

    string join(vector<string> &words, int left, int right, string sep) {
        string s = words[left];
        for (int i = left + 1; i < right; i ++) {
            s.append(sep).append(words[i]);
        }
        return s;
    }
public:
    const string splitC = "#";
    vector<string> fullJustify(vector<string>& words, int width) {
        vector<string> ans;
        int left, right = 0;
        int n = words.size();
        while (true) {
            int sumLen = 0;
            left = right;
            while (right < n && sumLen+words[right].length()+right-left <= width) {
                sumLen += words[right ++].length();
            }

            if (right == n) {
                string str = join(words, left, n, splitC);
                ans.push_back(str + blank(width-str.length()));
                return ans;
            }

            int numWords = right - left;
            int numSpaces = width - sumLen;
            if (numWords == 1) {
                ans.push_back(words[left] + blank(numSpaces));
                continue;
            }

            int avgSpaces = numSpaces / (numWords - 1);
            int extraSpaces = numSpaces % (numWords - 1);
            string s1 = join(words, left, left+extraSpaces+1, blank(avgSpaces+1));
            string s2 = join(words, left+extraSpaces+1, right, blank(avgSpaces));
            ans.push_back(s1+blank(avgSpaces)+s2);
        }
    }
    /*vector<string> fullJustify(vector<string>& words, int width) {
        vector<string> result;
        int sumLength = 0;
        int index = 0, end = 0;
        while (index < words.size()) {
            string str;
            for (int cnt = 0; end < words.size() && sumLength+words[end].length()+cnt < width; end ++, cnt ++) {
                sumLength += words[end].length();
            }

            if (end == words.size()) {
                for (int i = index; i < end; i ++) {
                    str.append(words[i]).append(string(1, splitC));
                }
                str.append(string(width-str.length(), splitC));
                result.push_back(str);
                return result;
            }

            int numWords = end-index;
            int numSpaces = width-sumLength;

            if (numWords == 1) {
                str = words[end].append(numSpaces, splitC);
                result.push_back(str);
                std::cout << "input vector: " << str << std::endl;
                index = end;
                std::cout << "index: " << end << std::endl;
                continue;
            }

            int avgSpaces = (numSpaces)/(numWords-1);
            int preSpace = (numSpaces)%(numWords-1);
            for (int i = index; i < end-1; i ++) {
                int b = preSpace > 0;
                str.append(words[i]).append(string(avgSpaces+b, splitC));
                preSpace --;
            }
            result.push_back(str);
            std::cout <<"input vector: " << str << std::endl;
            index = end;
            std::cout << "index: " << end << std::endl;
        }
        return result;
    }*/
};

int main() {
    Solution *so = new Solution();
    vector<string> v, result;

    auto print=[](vector<string>& arr) {
        for (const auto& k: arr) {
            std::cout << k << std::endl;
        }
        std::cout << std::endl;
    };
    v = {"This", "is", "an", "example", "of", "text", "justification."};
    result = so->fullJustify(v, 16);
    print(result);

    v = {"What","must","be","acknowledgment","shall","be"};
    result = so->fullJustify(v, 16);
    print(result);

    v = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    result = so->fullJustify(v, 20);
    print(result);
}

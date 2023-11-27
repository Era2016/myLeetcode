#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> splitString(std::string input, char delimiter) {
    std::vector<std::string> tokens;
    auto start = input.begin();
    auto end = std::find(start, input.end(), delimiter);
    while (end != input.end()) {
        tokens.emplace_back(start, end);
        //tokens.push_back(std::string(start, end));
        start = std::next(end);
        end = std::find(start, input.end(), delimiter);
    }
    tokens.emplace_back(start, end);
    //tokens.push_back(std::string(start, end));
    return tokens;
}

std::vector<std::string> splitString_v2(std::string input, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream tokenStream(input);
    std::string token;
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    std::string str = "a/b/c/d/e";
    std::vector<std::string> v;
    auto print=[](std::vector<std::string>& arr) {
        std::cout << ">>>>>";
        for (const auto& i: arr) {
            std::cout << i << " ";
        }
        std::cout << "<<<<<" << std::endl;
    };

    std::cout << str << std::endl;
    v = splitString(str, '/');
    print(v);

    v = splitString_v2(str, '/');
    print(v);
}

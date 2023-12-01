#include <iostream>
#include <string>

int main() {
    std::u32string chineseStr = U"你好世界我爱你们";
    std::cout << "string size: " << chineseStr.length() << std::endl;
    std::cout << "char32_t size: " << sizeof(char32_t) << std::endl;
    std::cout << "u32string size: " << sizeof(std::u32string) << std::endl;
    for (char32_t ch: chineseStr) {
        std::cout << "Character: " << static_cast<char>(ch) << std::endl;  // 转换为 char 输出
        if (ch == U'好') {
            std::cout << "Found character: " << static_cast<char>(ch) << std::endl;
            std::cout << "Found character: " << ch << std::endl;
        }
    }
}

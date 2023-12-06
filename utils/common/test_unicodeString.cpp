#include <iostream>
#include <string>

void func1() {
    std::string text = "今天周五123";
    for(size_t i = 0; i < text.length();)
    {
        int cplen = 1;
        if((text[i] & 0xf8) == 0xf0) cplen = 4; 	 // 占用4个字节，前5位为11110
        else if((text[i] & 0xf0) == 0xe0) cplen = 3; // 占用3个字节，前4位为1110
        else if((text[i] & 0xe0) == 0xc0) cplen = 2; // 占用2个字节，前3位为110
        // 个人感觉这行代码好像没什么用，如果三种情况都不符合，那么cplen就为初始化的0，是符合utf-8编码定义的
        if((i + cplen) > text.length()) cplen = 1;
        std::cout << text.substr(i, cplen) << std::endl;
        i += cplen;
    }
}

void func2() {
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

int main() {
    func1();
    func2();
}

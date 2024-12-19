#include <iostream>
#include <string>

// Hàm thay thế tất cả các lần xuất hiện của P1 trong T bằng P2
std::string replaceAll(const std::string &text, const std::string &from, const std::string &to)
{
    if (from.empty())
        return text; // Kiểm tra nếu từ thay thế rỗng

    std::string result = text;
    size_t pos = 0;

    // Lặp để thay thế tất cả các lần xuất hiện của P1 trong T
    while ((pos = result.find(from, pos)) != std::string::npos)
    {
        result.replace(pos, from.length(), to);
        pos += to.length(); // Di chuyển con trỏ để tiếp tục tìm kiếm
    }
    return result;
}

int main()
{
    std::string P1, P2, T;

    // Đọc dữ liệu từ đầu vào
    std::getline(std::cin, P1); // Xâu P1
    std::getline(std::cin, P2); // Xâu P2
    std::getline(std::cin, T);  // Văn bản T

    // Thay thế các xâu P1 bằng P2
    std::string result = replaceAll(T, P1, P2);

    // Xuất kết quả
    std::cout << result << std::endl;

    return 0;
}

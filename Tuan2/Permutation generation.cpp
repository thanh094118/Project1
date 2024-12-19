#include <iostream>
#include <vector>
#include <algorithm>

// Hàm để in một hoán vị
void printPermutation(const std::vector<int> &perm)
{
    for (size_t i = 0; i < perm.size(); ++i)
    {
        if (i > 0)
            std::cout << " ";
        std::cout << perm[i];
    }
    std::cout << std::endl;
}

int main()
{
    int n;

    // Nhập n
    std::cin >> n;

    // Tạo vector chứa các số từ 1 đến n
    std::vector<int> permutation;
    for (int i = 1; i <= n; ++i)
    {
        permutation.push_back(i);
    }

    // Sắp xếp và in tất cả các hoán vị theo thứ tự từ điển
    do
    {
        printPermutation(permutation);
    } while (std::next_permutation(permutation.begin(), permutation.end()));

    return 0;
}
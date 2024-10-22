
#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cout << "input vector size\n";
    std::cin >> n;
    std::vector<int> vec(n);
    std::cout << "input vector\n";
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }
    int x;
    std::cout << "input number to delete\n";
    std::cin >> x;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == x) {
            for (int j = i; j < vec.size() - 1; j++) {
                vec[j] = vec[j + 1];
            }
            vec.pop_back();
            --i;
        }
    }
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
}

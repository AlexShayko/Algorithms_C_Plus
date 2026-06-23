#include <vector>
#include <iostream>
#include <set>


int main() {
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int>> gr(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int num = 0;
            std::cin >> num;
            if (num != 0) {
                gr[i].push_back(j);
            }
        }
    }
    std::vector<int> colors(n);
    for (auto& el : colors) {
        std::cin >> el;
    }
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        for (const auto& el : gr[i]) {
            if (colors[i] != colors[el]) {
                counter += 1;
            }
        }
    }

    std::cout << counter / 2;
    return 0;
}

#include <vector>
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int>> gr(n, std::vector<int> (n));
    std::vector<int> min_v(2, 0);
    std::vector<int> bin(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> gr[i][j];
        }
    }
    int min = 10000;
    for (int i = 0; i < n; ++i) {
        std::cin >> bin[i];
    }
    for (int i = 0; i < n; ++i) {
        if (bin[i] == 0) {
            for (int j = 0; j < n; ++j) {
                if (bin[j] == 1) {
                    if (gr[i][j] < min) {
                        min = gr[i][j];
                        min_v[0] = i;
                        min_v[1] = j;
                    }
                }
            }
        }
    }

    std::cout << min_v[0] + 1 << ' ' << min_v[1] + 1;
    return 0;
}

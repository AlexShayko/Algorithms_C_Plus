#include <vector>
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        int num = 0;
        std::cin >> num;
        A[i] = num;
    }
    int q = 0, w = 0;
    std::cin >> q >> w;
    --q;
    --w;
    int el = A[q];
    int change = A[w];
    for (int i = 0; i < n; ++i) {
        if (A[i] == el) {
            A[i] = change;
        }
    }
    for (auto el : A) {
        std::cout << el << ' ';
    }
    return 0;
}

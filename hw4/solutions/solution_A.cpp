#include <vector>
#include <iostream>

std::vector<int> sizes;
std::vector<int> parent;

int find(int v) {
    if (parent[v] == v) {
        return v;
    }
    parent[v] = find(parent[v]);
    return parent[v];
}

bool unite(int a, int b) {
    int p_a = find(a);
    int p_b = find(b);
    if (p_a == p_b) {
        return false;
    }
    if (sizes[p_a] < sizes[p_b]) {
        std::swap(p_a, p_b);
    }
    parent[p_b] = p_a;
    sizes[p_a] += sizes[p_b];
    return true;
}

int main() {
    int n = 0, m = 0;
    std::cin >> n >> m;
    int counter = 0;
    int counter_br = 0;
    parent.resize(n + 1);
    sizes.assign(n + 1, 1);

    for (int i = 1; i < n + 1; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int from = 0, to = 0;
        std::cin >> from >> to;
        if (unite(from, to)) {
            counter += 1;
            if (counter == n - 1) {
                counter_br = i + 1;
                break;
            }
        }
    }

    std::cout << counter_br;

}

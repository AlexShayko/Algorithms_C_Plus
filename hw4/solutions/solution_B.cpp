#include <vector>
#include <iostream>

std::vector<int> sizes;
std::vector<int> parent;
std::vector<long long> sum;

int find(int v) {
    if (parent[v] == v) {
        return v;
    }
    parent[v] = find(parent[v]);
    return parent[v];
}

void unite(int a, int b, int value) {
    int p_a = find(a);
    int p_b = find(b);
    if (p_a == p_b) {
        sum[p_a] += value;
        return;
    }
    if (sizes[p_a] < sizes[p_b]) {
        std::swap(p_a, p_b);
    }
    parent[p_b] = p_a;
    sum[p_a] += sum[p_b] + value;
    sizes[p_a] += sizes[p_b];
}

int main() {
    int n = 0, m = 0;
    std::cin >> n >> m;
    parent.resize(n + 1);
    sizes.assign(n + 1, 1);
    sum.resize(n + 1);

    for (int i = 1; i < n + 1; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int num = 0;
        std::cin >> num;
        if (num == 2) {
            int v = 0;
            std::cin >> v;
            std::cout << sum[find(v)] << '\n';
        } else {
            int from = 0, to = 0, value = 0;
            std::cin >> from >> to >> value;
            unite(from, to, value);
        }
    }
}

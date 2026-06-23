#include <vector>
#include <iostream>
#include <algorithm>

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
    parent.resize(n + 1);
    sizes.assign(n + 1, 1);

    for (int i = 1; i < n; ++i) {
        parent[i] = i;
    }

    std::vector<std::pair<int, std::pair<int, int>>> edges;

    for (int i = 0; i < m; ++i) {
        int a = 0, b = 0, c = 0;
        std::cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }

    std::sort(edges.begin(), edges.end());
    int counter = 0;
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        int cost = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if (unite(a, b)) {
            counter += 1;
            sum += cost;
        }
        if (counter == n - 1) {
            break;
        }
    }

    std::cout << sum;

    return 0;


}

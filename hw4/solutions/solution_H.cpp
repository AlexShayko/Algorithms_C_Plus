#include <vector>
#include <iostream>
#include <string>

struct Q {
    std::string type;
    int u = 0;
    int v = 0;
};

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
    int n = 0, m = 0, k = 0;
    std::cin >> n >> m >> k;

    parent.resize(n + 1);
    sizes.assign(n + 1, 1);

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int a = 0, b = 0;
        std::cin >> a >> b;
    }

    std::vector<Q> queries;

    for (int i = 0; i < k; ++i) {
        std::string q;
        int v1 = 0, v2 = 0;
        std::cin >> q >> v1 >> v2;
        queries.push_back({q, v1, v2});
    }

    std::vector<std::string> ans;

    for (int i = k - 1; i >= 0; --i) {
        Q el = queries[i];

        if (el.type == "ask") {
            if (find(el.u) == find(el.v)) {
                ans.push_back("YES");
            } else {
                ans.push_back("NO");
            }
        } else {
            unite(el.u, el.v);
        }
    }

    for (int i = ans.size() - 1; i >= 0; --i) {
        std::cout << ans[i] << '\n';
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <cstdint>

int64_t k = 0;

class SegmentTree {

    struct Node {
        int begin = 0;
        int end = 0;

        int64_t max = 0;
        int64_t lazy = 0;
        bool haz_lazy = false;


        Node* left = nullptr;
        Node* right = nullptr;


        Node(int begin, int end) : begin(begin), end(end) {
            if (begin + 1 != end) {
                int mid = (begin + end) / 2;
                left = new Node(begin, mid);
                right = new Node(mid, end);
            }
        }

        void push() {
            if (begin + 1 != end) {
                if (haz_lazy) {
                    left->lazy += lazy;
                    left->max += lazy;

                    right->lazy += lazy;
                    right->max += lazy;

                    left->haz_lazy = true;
                    right->haz_lazy = true;
                }
            }
            lazy = 0;
            haz_lazy = false;
        }

        void add(int q_begin, int q_end, int64_t value) {
            if (q_begin <= begin && end <= q_end) {
                max += value;
                lazy += value;
                haz_lazy = true;
                return;
            }
            if (q_begin >= end || q_end <= begin) {
                return;
            }
            push();
            left->add(q_begin, q_end, value);
            right->add(q_begin, q_end, value);
            max = std::max(left->max, right->max);
        }

        int64_t get(int q_begin, int q_end) {
            if (q_begin <= begin && end <= q_end) {
                return max;
            }
            if (q_begin >= end || q_end <= begin) {
                return 0;
            }
            push();
            return std::max(left->get(q_begin, q_end), right->get(q_begin, q_end));
        }

        ~Node() {
            delete left;
            delete right;
        }
    };

    Node* root = nullptr;

public:

    SegmentTree(int begin, int end) {
        root = new Node(begin, end);
    }

    void add(int q_begin, int q_end, int64_t value) {
        root->add(q_begin, q_end, value);
    }

    int64_t get(int q_begin, int q_end) {
        return root->get(q_begin, q_end);
    }

    ~SegmentTree() {
        delete root;
    }
};

int main() {
    int n = 0;
    std::cin >> n;
    SegmentTree st(1, n + 1);
    for (int i = 1; i <= n; ++i) {
        int value = 0;
        std::cin >> value;
        st.add(i, i + 1, value);
    }
    int m = 0;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        char c = 0;
        std::cin >> c;
        if (c == 'm') {
            int q_begin = 0, q_end = 0;
            std::cin >> q_begin >> q_end;
            std::cout << st.get(q_begin, q_end + 1) << ' ';
        } else {
            int q_begin = 0, q_end = 0, value = 0;
            std::cin >> q_begin >> q_end >> value;
            st.add(q_begin, q_end + 1, value);
        }
    }
        return 0;
    }

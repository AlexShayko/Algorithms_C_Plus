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
            if (this->left) {
                left->lazy +=lazy;
                right->lazy += lazy;
                left->max += lazy;
                right->max += lazy;

                lazy = 0;
            }
        }

        void add (int q_begin, int q_end) {
            if (q_begin <= begin && end <= q_end) {
                max += 1;
                lazy += 1;
                return;
            }
            if (q_begin >= end || q_end <= begin) {
                return;
            }
            push();
            if (this->left) {
                left->add(q_begin, q_end);
                right->add(q_begin, q_end);
                max = std::max(left->max, right->max);
            }
        }

        int64_t get_max(int q_begin, int q_end) {
            if (q_begin <= begin && end <= q_end) {
                return max;
            }

            if (q_begin >= end || q_end <= begin) {
                return 0;
            }
            push();
            if (this->left) {
                return std::max(left->get_max(q_begin, q_end), right->get_max(q_begin, q_end));
            }
            return 0;
        }

        int get(int q_begin, int q_end) {
            if (get_max(q_begin, q_end) >= k) {
            return 0;
            } else {
                add(q_begin, q_end);
                return 1;
            }
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

    void add(int q_begin, int q_end) {
        root->add(q_begin, q_end);
    }

    int64_t get_max(int q_begin, int q_end) {
        return root->get_max(q_begin, q_end);
    }

    int get(int q_begin, int q_end) {
        return root->get(q_begin, q_end);
    }

    ~SegmentTree() {
        delete root;
    }
};

int main() {
    int n = 0, m = 0;
    std::cin >> n >> k >> m;
    SegmentTree st(0, n);
    for (int i = 0; i < m; ++i) {
        int x = 0, y = 0;
        std::cin >> x >> y;
        std::cout << st.get(x, y) << '\n';
    }

    return 0;
}

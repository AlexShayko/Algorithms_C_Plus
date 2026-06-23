#include <iostream>
#include <vector>
#include <cstdint>

int64_t inf = 1e18;

class SegmentTree {

    struct Node {
        int begin = 0;
        int end = 0;

        std::pair<int, int64_t> max = {-1, -inf};

        Node* left = nullptr;
        Node* right = nullptr;


        Node(int begin, int end) : begin(begin), end(end) {}

        void push() {
            if (begin + 1 != end && left == nullptr) {
                int mid = (begin + end) / 2;
                left = new Node(begin, mid);
                right = new Node(mid, end);
            }
        }

        void set(int index, int64_t value) {
            push();
            if (begin + 1 == end) {
                max = {begin, value};
            } else if (index < (begin + end) / 2) {
                left->set(index, value);
                if (left->max.second > right-> max.second) {
                    max = left->max;
                } else {
                    max = right->max;
                }
            } else {
                right->set(index, value);
                if (left->max.second > right-> max.second) {
                    max = left->max;
                } else {
                    max = right->max;
                }
            }
        }

        std::pair<int, int64_t> get(int q_begin, int q_end) {
            if (q_begin <= begin && end <= q_end) {
                return max;
            }
            if (q_begin >= end || q_end <= begin) {
                return {-1, -inf};
            }
            push();
            std::pair<int, int64_t> max_l = left->get(q_begin, q_end);
            std::pair<int, int64_t> max_r = right->get(q_begin, q_end);
            if (max_l.second > max_r.second) {
                return max_l;
            } else {
                return max_r;
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

    void set(int index, int64_t value) {
        root->set(index, value);
    }

    std::pair<int, int64_t> get(int q_begin, int q_end) {
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
    for (int i = 1; i <=n; ++i) {
        int value = 0;
        std::cin >> value;
        st.set(i, value);
    }

    int k = 0;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        int q_begin = 0, q_end = 0;
        std::cin >> q_begin >> q_end;
        std::pair<int, int64_t> max = st.get(q_begin, q_end + 1);
        std::cout << max.second << ' ' << max.first << '\n';
    }

    return 0;
}

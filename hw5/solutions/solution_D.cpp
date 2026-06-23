#include <iostream>
#include <vector>
#include <cstdint>

int64_t gcd(int64_t a, int64_t b) {
    a = std::abs(a);
    b = std::abs(b);

    while (b!= 0) {
        int64_t r = a % b;
        a = b;
        b = r;
    }

    return a;
}

class SegmentTree {

    struct Node {
        int begin = 0;
        int end = 0;

        int64_t nod = 0;

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
                nod = value;
            } else if (index < (begin + end) / 2) {
                left->set(index, value);
                this->nod = gcd(left->nod, right->nod);
            } else {
                right->set(index, value);
                this->nod = gcd(left->nod, right->nod);
            }
        }

        int64_t get(int q_begin, int q_end) {
            if (q_begin <= begin && end <= q_end) {
                return nod;
            }
            if (q_begin >= end || q_end <= begin) {
                return 0;
            }
            return gcd(left->get(q_begin, q_end), right->get(q_begin, q_end));
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
        st.set(i, value);
    }
    int m = 0;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        char c = 0;
        std::cin >> c;
        if (c == 's') {
            int q_begin = 0, q_end = 0;
            std::cin >> q_begin >> q_end;
            std::cout << st.get(q_begin, q_end + 1) << ' ';
        }
        else {
            int index = 0, value = 0;
            std::cin >> index >> value;
            st.set(index, value);
        }
    }

    return 0;
}

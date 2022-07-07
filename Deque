#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <fstream>
#include <queue>
#include <set>
#include <string>

using namespace std;

template<typename T>
class Deque {
private:
    struct Node {
        Node *next;
        Node *prev;
        T val;

        Node(T _val) : next(nullptr), prev(nullptr), val(_val) {}

        Node(Node *_next, Node *_prev, int _val) : next(_next), prev(_prev), val(_val) {}
    };

    Node *start = nullptr;
    Node *last = nullptr;
    int sz = 0;
    
public:
    void push_front(T val) {
        Node *node = new Node(val);
        if (start == nullptr) {
            start = node;
            last = node;
        } else {
            node->next = start;
            start->prev = node;
            start = node;
        }
        sz++;
        cout << "ok\n";
    }

    void push_back(T val) {
        Node *node = new Node(val);
        if (last == nullptr) {
            start = node;
            last = node;
        } else {
            node->prev = last;
            last->next = node;
            last = node;
        }
        sz++;
        cout << "ok\n";
    }

    void pop_front() {
        if (sz == 0) {
            throw std::logic_error("error");
        }
        Node *node = start->next;
        if (node != nullptr) {
            node->prev = nullptr;
        }
        delete (start);
        start = node;
        sz--;
        if (sz == 0) {
            last = nullptr;
        }
    }

    void pop_back() {
        if (sz == 0) {
            throw std::logic_error("error");
        }
        Node *node = last->prev;
        if (node != nullptr) {
            node->next = nullptr;
        }
        delete (last);
        last = node;
        sz--;
        if (sz == 0) {
            start = nullptr;
        }
    }

    T front() {
        if (sz == 0) {
            throw std::logic_error("error");
        }
        return start->val;
    }

    T back() {
        if (sz == 0) {
            throw std::logic_error("error");
        }
        return last->val;
    }

    int size() {
        return sz;
    }

    void clear() {
        while (sz != 0) {
            pop_back();
        }
        cout << "ok\n";
    }
};

signed main() {
    Deque<int> d;
    int a;
    string s;
    cin >> s;
    while (s != "exit") {
        if (s == "push_front") {
            cin >> a;
            d.push_front(a);
        } else if (s == "push_back") {
            cin >> a;
            d.push_back(a);
        } else if (s == "pop_front") {
            try {
                cout << d.front() << "\n";
                d.pop_front();
            }
            catch (std::exception &e) {
                cout << e.what() << "\n";
            }
        } else if (s == "pop_back") {
            try {
                cout << d.back() << "\n";
                d.pop_back();
            }
            catch (std::exception &e) {
                cout << e.what() << "\n";
            }
        } else if (s == "front") {
            try {
                cout << d.front() << "\n";
            }
            catch (std::exception &e) {
                cout << e.what() << "\n";
            }
        } else if (s == "back") {
            try {
                cout << d.back() << "\n";
            }
            catch (std::exception &e) {
                cout << e.what() << "\n";
            }
        } else if (s == "size") {
            cout << d.size() << "\n";
        } else if (s == "clear") {
            d.clear();
        }
        cin >> s;
    }
    cout << "bye\n";
}


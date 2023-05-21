#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    Node* alpha[26] = {0};
    bool end = false;

    bool containsKey(char ch) {
        return alpha[ch - 'a'] != NULL;
    }

    void setNode(char ch, Node* node) {
        alpha[ch - 'a'] = node;
    }

    Node* getNode(char ch) {
        return alpha[ch - 'a'];
    }

    void setEnd() {
        end = true;
    }

    bool isEnd() {
        return end;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insertWord(string s) {
        Node* n1 = root;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (!(n1->containsKey(s[i]))) {
                n1->setNode(s[i], new Node());
            }
            n1 = n1->getNode(s[i]);
        }
        n1->setEnd();
    }

    bool searchWord(string s) {
        int n = s.size();
        Node* n1 = root;

        for (int i = 0; i < n; i++) {
            if (!(n1->containsKey(s[i]))) {
                return false;
            }
            n1 = n1->getNode(s[i]);
        }
        return n1->isEnd();
    }
};

int main() {
    Trie t1;

    t1.insertWord("Hello");
    t1.insertWord("Hell");
    t1.insertWord("Heed");
    t1.insertWord("Heap");
    t1.insertWord("Help");
    t1.insertWord("Helo");

    cout << t1.searchWord("Hello") << "\n";
    cout << t1.searchWord("Hell");

    return 0;
}


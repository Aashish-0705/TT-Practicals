#include <iostream>
#include <unordered_map>

class TrieNode {
public:
    bool isWord;
    std::unordered_map<char, TrieNode*> children;

    TrieNode() {
        isWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* curr = root;

        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }

        curr->isWord = true;
    }

    bool search(const std::string& word) {
        TrieNode* curr = root;

        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                return false;
            }
            curr = curr->children[ch];
        }

        return curr->isWord;
    }
};

int main() {
    Trie trie;

    // Insert some example words into the trie
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("cherry");
    trie.insert("dog");
    trie.insert("elephant");

    // Search for words in the trie
    std::cout << trie.search("apple") << std::endl;       // Output: 1 (true)
    std::cout << trie.search("banana") << std::endl;      // Output: 1 (true)
    std::cout << trie.search("cherry") << std::endl;      // Output: 1 (true)
    std::cout << trie.search("dog") << std::endl;         // Output: 1 (true)
    std::cout << trie.search("elephant") << std::endl;    // Output: 1 (true)
    std::cout << trie.search("cat") << std::endl;         // Output: 0 (false)

    return 0;
}


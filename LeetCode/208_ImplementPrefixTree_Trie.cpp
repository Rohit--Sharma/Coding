#include <iostream>
#include <string>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = newNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = newNode();
            pCrawl = pCrawl->children[index];
        }
        pCrawl->endOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (!pCrawl->children[index])
                return false;
            pCrawl = pCrawl->children[index];
        }
        return pCrawl != NULL && pCrawl->endOfWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *pCrawl = root;
        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (!pCrawl->children[index])
                return false;
            pCrawl = pCrawl->children[index];
        }
        return true;
    }

private:
    struct TrieNode {
        TrieNode *children[26];
        bool endOfWord;
    };

    TrieNode *newNode() {
        TrieNode *pNode = new TrieNode;
        pNode->endOfWord = false;
        for (int i = 0; i < 26; i++)
            pNode->children[i] = NULL;
        return pNode;
    }

    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
int main()
{
    Trie obj = Trie();
    obj.insert("apple");
    cout << obj.search("apple") << endl;
    cout << obj.search("app") << endl;
    cout << obj.startsWith("app") << endl;
    obj.insert("app");
    cout << obj.search("app") << endl;
    return 0;
}
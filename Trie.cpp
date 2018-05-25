#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() {
        cout << "Initializing a default Trie Node" << endl;
        for (int i = 0; i < ALPHABET_SIZE; i++)
            children[i] = NULL;
        isEndOfWord = false;
    } 
};

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(TrieNode *root, string key)
{
    TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (pCrawl->children[index] == NULL) {
            TrieNode *temp = new TrieNode();
            pCrawl->children[index] = temp;
        }
 
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool search(TrieNode *root, string key)
{
    TrieNode *pCrawl = root;
    cout << "Searching: " << key << endl;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        cout << "Node: " << key[i] << endl;
        if (pCrawl->children[index] == NULL)
            return false;
 
        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = { "the", "a", "there", "answer", "any", "by", "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);

    TrieNode *root = new TrieNode();
 
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
 
    // Search for different keys
    search(root, "the") ? cout << "Yes\n" : cout << "No\n";
    search(root, "these") ? cout << "Yes\n" : cout << "No\n";
    search(root, "their") ? cout << "Yes\n" : cout << "No\n";
    search(root, "thaw") ? cout << "Yes\n" : cout << "No\n";

    return 0;
}
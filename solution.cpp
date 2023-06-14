class TrieNode {
    public:
    char val;
    unordered_map<char, TrieNode*> mp;
    bool isTerminal;

    TrieNode(char ch) {
        this->val = ch;
        isTerminal = false;
    }
};

class Trie {
    public:
    TrieNode* root;

    Trie() {
        root = new TrieNode(NULL);
    }

    void insert(string word) {
        int n = word.size();
        TrieNode* temp = root;

        for(int i = 0; i < n; i++) {
            char ch = word[i];
            if(temp->mp.find(ch) == temp->mp.end()) {
                temp->mp[ch] = new TrieNode(ch);
            }
            temp = temp->mp[ch];
        }
        temp->isTerminal = true;
    }

    bool search(string word) {
        int n = word.size();
        TrieNode* temp = root;

        for(int i = 0; i < n; i++) {
            char ch = word[i];
            if(temp->mp.find(ch) == temp->mp.end()) {
                return false;
            }
            temp = temp->mp[ch];
        }

        if(temp->isTerminal) {
            return true;
        }

        return false;
    }
};

vector<int> Solution::solve(vector<string> &A, vector<string> &B) {
    int n = A.size();
    int m = B.size();
    vector<int> res(m, 0);

    Trie *trie = new Trie();

    for(int i = 0; i < n; i++) {
        trie->insert(A[i]);
    }

    for(int i = 0; i < m; i++) {
        if(trie->search(B[i])) {
            res[i] = 1;
        }
    }

    return res;
}

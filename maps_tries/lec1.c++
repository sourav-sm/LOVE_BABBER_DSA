// 49. Group Anagrams
//Given an array of strings strs, group the anagrams together. You can return the answer in any order.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        for(int i=0;i<strs.size();i++){
            string str=strs[i];
            string temp=str;
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(str);
        }

        vector<vector<string>>ans;
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};

// 208. Implement Trie (Prefix Tree)
// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

// Implement the Trie class:
// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

class TrieNode{
  public:
      char data;
      unordered_map<char,TrieNode*>child;
      bool isTerminal;

      TrieNode(char val){
        data=val;
        isTerminal=false;
      }
};

void insertInTrie(TrieNode* root,string word){
    //base case
    if(word.lenght()==0){
        root->isTerminal=true;
        return;
    }


   char ch=word[0];
   TrieNode* child;
   if(root->child.find(ch)!=root->child.end()){
     //present
        child=root->child[ch];
   }else{
    //not present
    //create a new 
    child=new TrieNode(ch);
    //link
    root->child[ch]=child;
   }
   //baki recursion samal legs
   insertInTrie(root,word.susbstr(1));
}

class Trie {
public:
    Trie() {
        TrieNode* root=new TrieNode("-");
    }

    
    void insert(string word) {
        insertInTrie(root,word);
    }
    
    bool search(string word) {
        
    }
    
    bool startsWith(string prefix) {
        
    }
};
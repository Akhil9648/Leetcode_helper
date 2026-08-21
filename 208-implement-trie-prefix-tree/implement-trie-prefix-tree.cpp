struct Node{
    Node *links[26];
    bool flag=false;
    bool contains(char c){
        return (links[c-'a']!=NULL);
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
            flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(!node->contains(word[i])) node->put(word[i],new Node()); 
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        int n=word.size();
        Node* node=root;
        for(int i=0;i<n;i++){
            if(!node->contains(word[i])) return false;
            node=node->get(word[i]);
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
         int n=prefix.size();
        for(int i=0;i<n;i++){
            if(!node->contains(prefix[i])) return false;
            node=node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
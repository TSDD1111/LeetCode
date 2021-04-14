class Trie {

    //建立树的数据结构
    private class TrieNode {
        private boolean isEnd;     //表示到这里是否是一个字符串结束了
        private TrieNode[] next;   //每个节点可以存放26个字母对应的节点,如果有值说明该字母被用过了

        //构造函数
        public TrieNode(){
            isEnd = false;
            next = new TrieNode[26];   
        }
    }

    //root节点
    private TrieNode root;

    /** Initialize your data structure here. */
    public Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        TrieNode q = root;
        //分割字符串，依次遍历，一个一个字符寻找是否存入树中
        for(int i = 0, len = word.length(), ch; i < len; i++){
            ch = word.charAt(i) - 'a';     //计算该字母的序号，a为0
            if(q.next[ch] == null){
                q.next[ch] = new TrieNode();
            }
            q = q.next[ch];
        }
        q.isEnd = true; //表示该字符串在这里结束了，是一个单词
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        TrieNode q = root;
        for(int i = 0, len = word.length(), ch; i < len; i++){
            ch = word.charAt(i) - 'a';
            if(q.next[ch] == null){   //遍历到树的末尾仍有字母剩余，说明不匹配
                return false;
            }
            q = q.next[ch];
        }
        return q.isEnd;   //根据isEnd判断是否是一个单词
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        TrieNode q = root;
        for(int i = 0, len = prefix.length(), ch; i < len; i++){
            ch = prefix.charAt(i) - 'a';
            if(q.next[ch] == null){      //遍历到树的末尾仍有字母剩余，说明没有该前缀
                return false;
            }
            q = q.next[ch];
        }
        return true;    //无需判断是否是一个完整的单词
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */

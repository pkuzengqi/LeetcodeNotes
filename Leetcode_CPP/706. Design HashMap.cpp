class MyHashMap {
public:
  
    int N=200011; //设置为2w会溢出
    vector<list<pair<int,int>>> hash;
  
  
    /** Initialize your data structure here. */
    MyHashMap() {
      hash = vector<list<pair<int,int>>>(N);
    }
  
    list<pair<int,int>>::iterator find(int key){
      int t = key % N;
      auto it=hash[t].begin();
      for(;it!=hash[t].end();++it)
        if(it->first==key) break;
      return it;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
      int t = key % N;
      auto it = find(t);
      if(it==hash[t].end())
        hash[t].push_back(make_pair(key,value));
      else
        it->second=value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
      int t=key%N;
      auto it = find(t);
      if(it==hash[t].end())
        return -1;
      else
        return it->second;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
      int t = key % N;
      auto it=find(t);
      if(it!=hash[key % N].end())
        hash[t].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
      unordered_map<string,int> hash;
      for(auto &w:words) hash[w]++;
      
      typedef pair<int,string> PIS;
      priority_queue<PIS> heap;
      
      for(auto &item:hash){
        PIS t(-item.second, item.first);
        if(heap.size()==k && t<heap.top()) heap.pop();
        if(heap.size()<k) heap.push(t);
        
      }
      
      vector<string> res(k);
      for(int i=k-1;i>=0;--i){
        res[i] = heap.top().second;
        heap.pop();
      }
      return res;
    }
};
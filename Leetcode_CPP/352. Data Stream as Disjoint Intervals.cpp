class SummaryRanges {
public:
    // https://www.acwing.com/solution/LeetCode/content/373/
  
    /** Initialize your data structure here. */
    map<int,int> L2R, R2L;
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
      // check if val exists in any interval
      // ite=m.lower_bound(x);//返回比第一个大于或等于x的值的位置 ，当m为空时，返回m.end()
      // ite=m.upper_bound(x);//返回比最后一个大于或等于x的值的位置，当m为空时，返回m.begin()
      if(R2L.size()){
        map<int,int>::iterator it=R2L.lower_bound(val); //it是第一个>=val的右端点
        if(it!=R2L.end() && it->second<=val) return;
      }
      
      // 判断val-1和val+1是否存在
      int left=R2L.count(val-1), right=L2R.count(val+1);
      if(left && right){
        L2R[R2L[val-1]] = L2R[val+1];
        R2L[L2R[val+1]] = R2L[val-1];
        R2L.erase(val-1);
        L2R.erase(val+1);
      }
      else if(right){
        // 放进右区间 val+1 ----- L2R[val+1]
        R2L[L2R[val+1]] = val;
        L2R[val] = L2R[val+1];
        L2R.erase(val+1);
        
      }
      else if(left){
        // 放进左区间 R2L[val-1] ----- val-1
        L2R[R2L[val-1]] = val;
        R2L[val] = R2L[val-1];
        R2L.erase(val-1);
      }
      else{
        L2R[val] = val;
        R2L[val] = val;
      }
    }
    
    vector<vector<int>> getIntervals() {
      vector<vector<int>> res;
      for(auto &p:L2R) res.push_back({p.first, p.second});
      return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */



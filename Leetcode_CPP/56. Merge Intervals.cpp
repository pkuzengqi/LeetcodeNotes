/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(const Interval& x, const Interval& y){
      if(x.start != y.start) return x.start < y.start;
      return x.end < y.end;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.empty()) return res;
        sort(intervals.begin(),intervals.end(),cmp);
        
        Interval cur=intervals[0];
        for(int i=1;i<intervals.size();++i){
          if(cur.end < intervals[i].start){
            res.push_back(cur);
            cur = intervals[i];
          }
          else if(cur.end < intervals[i].end)
            cur.end = intervals[i].end;
        }
        res.push_back(cur);
        return res;
        
    }
};
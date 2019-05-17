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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
      bool put=false; //has newInterval been put into res
      vector<Interval> res;
      
      for(auto interval:intervals){ 
        if(interval.end < newInterval.start){ //not cross: interval is on the left
          res.push_back(interval);
        }
        else if(interval.start > newInterval.end){ //not cross: interval is on the right
          if(!put){
            res.push_back(newInterval);
            put=true;
          }
          res.push_back(interval);
        }
        else{ //cross:update newInterval
          newInterval.start = min(newInterval.start,interval.start);
          newInterval.end = max(newInterval.end,interval.end);
        }
      }
      
      if(!put) res.push_back(newInterval);
      return res;
    }
};
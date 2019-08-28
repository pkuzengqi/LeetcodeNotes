// https://www.acwing.com/solution/LeetCode/content/303/
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> s;
    priority_queue<int,vector<int>,greater<int>> l;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
      if(s.empty()||num<=s.top())
        s.push(num);
      else
        l.push(num);
      
      if(s.size()==l.size()+2){
        int t=s.top();
        s.pop();
        l.push(t);
      }
      else if(s.size()+1==l.size()){
        int t=l.top();
        l.pop();
        s.push(t);
      }
    }
    
    double findMedian() {
      if(s.size()==l.size()) return (s.top()+l.top())/2.0;
      return s.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
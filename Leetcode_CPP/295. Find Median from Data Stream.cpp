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


// (双堆) O(nlogn)O(nlog⁡n)
// 建立一个大根堆，一个小根堆。大根堆存储小于当前中位数，小根堆存储大于等于当前中位数。且小根堆的大小永远都比大根堆大1或相等。
// 根据上述定义，我们每次可以通过小根堆的堆顶或者两个堆的堆顶元素的平均数求出中位数。
// 维护时，如果新加入的元素大于等于当前的中位数，则加入小根堆；否则加入大根堆。然后如果发现两个堆的大小关系不满足上述要求，则可以通过弹出一个堆的元素放到另一个堆中。
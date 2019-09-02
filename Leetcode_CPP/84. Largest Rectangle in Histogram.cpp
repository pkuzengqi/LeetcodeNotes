class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      int res=0;
      stack<int> st;
      heights.push_back(-1); //使得所有元素都可以pop
      // 本质是找到每个柱形条cur两边最近的比自己低的矩形条i和j, 那么[i,j]中间都是高度大于等于cur的，就可以放心以cur的高度来作为矩阵高度
      for(int i=0;i<heights.size();++i){
        while(!st.empty() && heights[i]<heights[st.top()]){
          int cur=st.top(); st.pop();
          if(st.empty()) res=max(res, heights[cur]*i);
          else res=max(res,heights[cur]*(i-st.top()-1));
        }
        st.push(i);
      }
      return res;
    }
};
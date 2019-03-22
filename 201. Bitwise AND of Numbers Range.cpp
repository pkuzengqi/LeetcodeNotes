class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
      int i=30;
      for(;i>=0;--i)
        if((m>>i&1)^(n>>i&1))
          break;
      ++i;
      return (m>>i)<<i;
      
    }
};
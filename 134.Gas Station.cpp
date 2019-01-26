class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n= gas.size();
        vector<int> sum=vector<int>(n*2,0);
        for(int i=0;i<n*2;++i) sum[i]=gas[i%n]-cost[i%n];
        
        int start=0,end=0,tot=0;
        while(start==end && sum[start]<0){
          ++start;
          ++end;
        }
        while(start<n && end<2*n){
          tot+=sum[end];
          while(tot<0){
            tot-=sum[start];
            ++start;
          }
          ++end;
          if(end-start==n) return start;
        }
        return -1;
    }
};
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double, int>> workers;
        int n = quality.size();
        for (int i = 0; i < n; i ++ ) workers.push_back({wage[i] * 1.0 / quality[i], quality[i]});
        sort(workers.begin(), workers.end());
        
        priority_queue<int> heap;
        int s = 0;
        double res = 1e9;
        for (int i = 0; i < n; i ++ ) {
            int q = workers[i].second;
            s += q;
            heap.push(q);
            if (heap.size() > K) { //让heap保持k个
                s -= heap.top();
                heap.pop();
            }
            if (heap.size() >= K) //如果还没到k个就跳过
                res = min(res, s * workers[i].first); //s是quality的和，workers[i].first是quality的单价，现在走到i是按照i的单价计算的
        }
        return res;

  }
};
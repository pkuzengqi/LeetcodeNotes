// 暴力枚举 O(N^2)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i=0;i<nums.size();++i){
        	for(int j=0;j<nums.size();++j){
        		if(nums[i]+nums[j]==target){
        			res = vector<int>({i,j});
        			break;
        		}
        	}
        	if(res.size()>0) break;
        }
    }
};

// hash 复杂度O(n)  unordered_map<int, int> hash
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> res;
        unordered_map<int, int> hash；
        for(int i=0;i<nums.size();++i){
        	int another = target-nums[i];
        	if(hash.count(another)){
        		res=vector<int>({i,hash[another]});//hash[value]=pos
        		break;
        	}
        	hash[nums[i]]=i
        }
        return res;
    }
};


// 20190824 update
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();++i){
          if(hash.count(target-nums[i])){
            return vector<int>({hash[target-nums[i]],i});
          }
          hash[nums[i]]=i;
        }
        return vector<int>();
    }
};

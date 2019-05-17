class Solution {
public:
    int add(int num1, int num2){
        // leetcode 371
        if(num2==0) return num1;
        int sum=num1^num2, carry=(num1&num2)<<1;
        return add(sum,carry);
    }
};
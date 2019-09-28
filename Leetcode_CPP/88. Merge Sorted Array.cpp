// ### 题目描述
// 给定两个有序的整数数组nums1和nums2，要求将nums2合并进nums1中，并使nums1有序。


//(线性合并) 时间复杂度 $O(m+n)$,  空间复杂度$O(1)$
// 1. 设置`cur`指针指向合并后的`nums1`数组(大小为m+n)的最后一个元素，
// `p`指向合并前的`nums1`数组(大小为m)的最后一个元素，
// `q`指向`nums2`数组(大小为n)的最后一个元素。
// 2. 比较`p`指向的值和`q`指向的值，将大的值挪进`nums1[cur]`。
// 3. `cur`指针往前挪，`p`或者`q`指针也相应往前挪。
// 4. 循环以上步骤直到p=0或q=0


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m - 1 , q = n - 1 , cur = m + n - 1 ;
        while(p>= 0 && q >= 0){
            nums1[cur--] = ( nums1[p] >= nums2[q] ? nums1[p--] : nums2[q--]);
        }
        while(q >= 0){
            nums1[cur--] = nums2[q--];
        }
    }
};

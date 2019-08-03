class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1=0, p2=0, n1=version1.length(), n2=version2.length();
        while(p1<n1 || p2<n2){
            int num1=0, num2=0;
            while(p1<n1 && version1[p1]!='.')
                num1 = num1*10 + (version1[p1++] - '0');
            while(p2<n2 && version2[p2]!='.')
                num2 = num2*10 + (version2[p2++] - '0');
            
            if(num1<num2) return -1;
            if(num1>num2) return 1;
            ++p1, ++p2;
        }
        return 0; //equal
    }
};
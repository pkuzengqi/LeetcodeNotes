class Solution {
public:
    int strToInt(string str) {
        long long num=0;
        int k=0, n=str.size();
        bool is_minus=false;
        
        while(k<n && str[k]==' ') ++k;
        
        if(str[k]=='+') ++k;
        else if(str[k]=='-') is_minus=true,++k;
        
        while(k<n && str[k]>='0' && str[k]<='9')
            num = num*10 + str[k++] - '0';
        
        if(is_minus) num*=-1;
        if(num>INT_MAX) return INT_MAX;
        if(num<INT_MIN) return INT_MIN;
        
        return (int)num;
    }
};
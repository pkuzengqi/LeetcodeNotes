class Solution {
public:
    
    unordered_map<int, string> dict;
    int h = 100, t = 1000, m = 1000000, b = 1000000000;
    
    string numberToWords(int num) {
        
        // preprocess numbers 
        
        vector<string> tmp = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"};
        for(int i=0;i<tmp.size();++i) dict[i]=tmp[i];
        dict[30]="Thirty", dict[40]="Forty", dict[50]="Fifty",dict[60]="Sixty", dict[70]="Seventy", dict[80]="Eighty", dict[90]="Ninety";
        dict[h]="Hundred", dict[t]="Thousand",dict[m]="Million",dict[b]="Billion";
        
        
        // process every four digits
        string res;
        for (int k = 1000000000; k >= 100; k /= 1000)
        {
            if (num >= k)
            {
                res += ' ' + get3(num / k) + ' ' + dict[k];
                num %= k;
            }
        }
        
        if (num) res += ' ' + get3(num); // last four digits
        if (res.empty()) res = ' ' + dict[0]; // num=0
        return res.substr(1); // delete first blank
   
    }
    
    string get3(int x){
        // input x will not be zero
        string res;
        if(x>=h){
            res += ' '+dict[x/h]+' '+dict[h];
            x%=h;
        }
        if(x){
            if(x<20 || x%10==0) res += ' '+dict[x];
            else res += ' '+dict[x/10*10]+' '+dict[x%10];
        }
        return res.substr(1);
    }
};
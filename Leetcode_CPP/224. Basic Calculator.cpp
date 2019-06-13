class Solution {
public:
    stack<char> op;
    stack<int> num;
    
    void calc(){
      int y=num.top();
      num.pop();
      int x=num.top();
      num.pop();
      char p=op.top();
      op.pop();
      if(p=='+') num.push(x+y);
      else num.push(x-y);
    }
  
    int calculate(string s) {
        for(int i=0; i<s.size(); ++i){
          char c=s[i];
          if(c==' ') continue;
          if(c=='+' ||c=='-'||c=='(') op.push(c);
          else if(c==')'){
            op.pop(); 
            if(op.size()&&op.top()!='(') calc();
          }
          else{ //number
            int j=i; //找数字末尾
            while(j<s.size() && isdigit(s[j])) ++j;
            num.push(atoi(s.substr(i, j - i).c_str()));
            if(op.size()&&op.top()!='(') calc();
            i=j-1;
          }
        }
        return num.top();
    }
};
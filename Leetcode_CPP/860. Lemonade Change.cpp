class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
      int five=0,ten=0;
      for(auto &x:bills){
        if(x==5) ++five;
        else if(x==10){
          if(five){--five;++ten;}
          else{return false;}
        }
        else{ //x=15
          if(five&&ten){--ten;--five;}
          else if(five>=3){five-=3;}
          else{return false;}
        }
      }
      return true;
    }
};
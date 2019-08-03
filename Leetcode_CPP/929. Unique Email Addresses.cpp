class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> h;
        for(auto &email:emails){
            string user, domain;
            int i = 0, j = 0;
            while(email[i]!='@') ++i;
            domain = email.substr(i+1);
            while(j<i && email[j]!='+'){
                if(email[j]!='.')user+=email[j];
                ++j;
            }
            h.insert(user+'@'+domain);
        }
        return h.size();
    }
};
class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;
        int num=0;
        string curr="";
        for(char c:s){
            if(isdigit(c)){
                num=num*10+(c-'0');
            }
            else if(c=='['){
                nums.push(num);
                strs.push(curr);
                num=0;
                curr="";
            }
            else if(isalpha(c)){
                curr+=c;
            }
            else if(c==']'){
                int k=nums.top();
                nums.pop();
                string prev=strs.top();
                strs.pop();
                while(k--){
                    prev+=curr;
                }
                curr=prev;
            }
        }
        return curr;
    }
};
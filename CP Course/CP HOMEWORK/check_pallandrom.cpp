class Solution {
    public:
        bool isPalindrome(string s) {
            string a="";
            for(int i=0;i<s.length();i++){
                if(s[i]>='a' && s[i]<='z'){
                    a+=s[i];
                }
                if(s[i]>='0' && s[i]<='9'){
                    a+=s[i];
                }
                if(s[i]>='A' && s[i]<='Z'){
                    a+=(s[i]+32);
                }
            }
            int k=a.length();
            for(int i=0;i<k/2;i++){
                if(a[i]!=a[k-1-i]){
                    return false;
                }
            }
            return true;
        }
    };
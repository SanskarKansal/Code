#include<iostream> 
#include<unordered_map>
#include<vector> 
using namespace std;
class VC_system{
    int cur; 
    unordered_map< int,string> mp;
    public:
    VC_system(){
        this -> cur = -1;
    }
    void add_rev(string s){
        mp[++cur] = s;
    }
    string fetch_rev(int val){
       if(cur == -1){
         return "No revision in this";
       }
       else if(val >= 0 && val <= cur){
          return mp[val];
       }
       else {
        return "Invalid Input";
       }
    }
    string latest_rev(){
        if(cur == -1)
            return "No revision exists";
       
        return mp[cur];
    }
    vector<string> all_rev(){
        if(cur == -1)
            return {"No revision is exists "};
        vector< string > ans;
        for(int i=0;i<=cur;i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};
int main(){
    VC_system  version1;
    version1.add_rev("content no 1");
    version1.add_rev("content no 2");
    version1.add_rev("content no 3");
    version1.add_rev("content no 4");
    cout << version1.latest_rev()<< endl;
    cout << version1.fetch_rev(1) << endl;
    vector<string> arr = version1.all_rev();
    for (string s : arr){
        cout << s << endl;
    }
}
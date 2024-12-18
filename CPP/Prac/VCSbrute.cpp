#include<iostream>
#include<vector>
using namespace std;
class VC_system{
    vector<string> nums; 
    public:
    void add_rev(string s){
        nums.push_back(s); 
    }
    string fetch_rev(int val){
        if(nums.empty()){
            return "NO revision in this";
        } 
        if(val >=0 && val < nums.size()) {
            return nums[val]; 
        }
        return "Invalid input";
    } 
    string latest_rev(){
        if(nums.empty()){
            return "NO Revision in this";
        }
        return nums.back(); 
    }
    vector<string> all_rev(){
        return nums; 
    }
};

int main(){
    VC_system version1;
    version1.add_rev("content no 1");
    version1.add_rev("content no 2");
    version1.add_rev("content no 3");
    version1.add_rev("content no 4");
    cout << version1.latest_rev()<< endl;
    cout << version1.fetch_rev(1) << endl;
    vector<string> arr = version1.all_rev();
    for (string s: arr){
        cout << s << endl;
    }
}

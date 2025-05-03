class Solution {
    public:
        bool checkarray(vector<int>& arr1 ,vector<int>& arr2)
        {
            for(int i =0; i<26 ; i++)
            {
                if(arr1[i] != arr2[i])
                    return false;
            }
            return true;
        }
        bool checkInclusion(string s1, string s2) {
            if(s1.size() > s2.size()) return false;
            vector<int> arr1(26,0);
            vector<int> arr2(26,0);
            for(auto it : s1)
                arr1[it - 'a']++;
            for(int i = 0 ; i < s1.size() ; i++)
            {
                arr2[s2[i] - 'a']++;
            }
            bool check = checkarray(arr1,arr2);
            if(check){
                return true;
            }
            int j = 0;
            for(int i = s1.size() ; i < s2.size() ; i++)
            {  
                arr2[s2[j++] - 'a']--;
                arr2[s2[i] - 'a']++;
                check = checkarray(arr1,arr2);
                if(check){
                    return true;
                }
            }
            return false;
        }
    };
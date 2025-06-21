#include <bits/stdc++.h>
using namespace std;

int main() {
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> s(n), p(n);
		for(auto &x : s){
            cin>>x;
        }
		for(int i = 0; i < n; i++){
            p[i]=i+1;
        }
		int l = 0, r = 0;
		bool ans = true;
		while(r < n) {
			while(r + 1 < n && s[r] == s[r + 1]){
                r++;
            }
			if(l == r) {
				ans = false;
				break;
			}
            else {
				rotate(p.begin() + l, p.begin() + r, p.begin() + r + 1);
			}
			l = r + 1;
			r = l;
		}
		if(ans) {
			for(auto i : p){
                cout << i << " ";
            }
			cout << "\n";
		} else {
			cout << -1 << "\n";
		}
	}
	return 0;
}

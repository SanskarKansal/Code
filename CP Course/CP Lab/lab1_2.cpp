#include<iostream>
using namespace std;

int gcd(int m,int n){
    if(n==0){
        return m;
    }
    return gcd(n,m%n);
}

int main(){
    int m;
    int n;
    cout<<"enter the value of m:"<<endl;
    cin>>m;
    cout<<"enter the value of n:"<<endl;
    cin>>n;
    if(m<0 || n<0){
        cout<<-1;
        return 0;
    }
    if(m==0 && n==0){
        cout<<-1;
        return 0;
    }
    int ans=gcd(m,n);
    cout<<"gcd of "<<m<<" and "<<n<<" is "<<ans;
}

// 1. 2 and 5  #1
// 2. 5 and 2 reverse  #1
// 3. 6 and 18 multiple  #6
// 4. 4 and 6  indirectly multiple #2
// 5. 0 and 2 one zero #2
// 6. 0 and 0 both zero #-1
// 7. -6 and 3 negative  #-1
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node* random;
    Node(int v){
        val=v;
        next=nullptr;
        random=nullptr;
    }
};

Node* create(Node* head,int n){
    Node* root;
    Node* last;
    vector<Node*>vec(n+1);
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(i==0){
            root=new Node(val);
            vec[i+1]=root;
            last=root;
        }
        else{
            last->next=new Node(val);
            last=last->next;
            vec[i+1]=last;
        }
    }
    last=root;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        last->random=vec[val];
        last=last->next;
    }
    head=root;
    return head;
}

Node* clone(Node* head,int n){
    Node* root;
    Node* last;
    unordered_map<Node*,Node*>mp1;
    unordered_map<Node*,vector<Node*>>mp2;
    for(int i=0;i<n;i++){
        int val=head->val;
        if(i==0){
            root=new Node(val);
            mp1[head]=root;
            last=root;
            if(mp1.find(head->random)!=mp1.end()){
                root->random=mp1[head->random];
            }
            else{
                mp2[head->random].push_back(head);
            }
        }
        else{
            last->next=new Node(val);
            last=last->next;
            mp1[head]=last;
            if(mp1.find(head->random)!=mp1.end()){
                root->random=mp1[head->random];
            }
            else{
                mp2[head->random].push_back(head);
            }
            if(mp2.find(head)!=mp2.end()){
                for(auto i: mp2[head]){
                    mp1[i]->random=last;
                }
            }
        }
        head=head->next;
    }
    return root;
}

void print(Node* head,int n){
    for(int i=0;i<n;i++){
       cout<<head->val<<" "<<head->random->val<<endl;
       head=head->next;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node* head=nullptr;
        head=create(head,n);
        Node* ans=clone(head,n);
        print(head,n);
        print(ans,n);
    }
    return 0;
}

/*
6
1
5
1
2
10 20
2 1
3
1 2 3
3 2 1
4
10 20 30 40
2 4 2 1
5
7 14 21 28 35
5 4 3 2 1
6
11 22 33 44 55 66
6 5 4 3 2 1

#
5 5
5 5
10 20
20 10
10 20
20 10
1 3
2 2
3 1
1 3
2 2
3 1
10 20
20 40
30 20
40 10
10 20
20 40
30 20
40 10
7 35
14 28
21 21
28 14
35 7
7 35
14 28
21 21
28 14
35 7
11 66
22 55
33 44
44 33
55 22
66 11
11 66
22 55
33 44
44 33
55 22
66 11

*/
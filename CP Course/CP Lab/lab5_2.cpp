#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int v){
        val=v;
        next=nullptr;
    }
};

pair<Node*,Node*> create(Node* head,Node *last ,int n){
    Node* root;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(i==0){
            root=new Node(val);
            last=root;
        }
        else{
            last->next=new Node(val);
            last=last->next;
        }
    }
    head=root;
    return {head,last};
}

Node* allot(Node* head,Node* last ,int pos){
    Node* root =head;
    for(int i=1;i<pos;i++){
        root=root->next;
    }
    last->next=root;
    return head;
}

bool findloop(Node* head){
    Node* slow =head;
    Node* fast =head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node* head=nullptr;
        Node* last;
        auto a=create(head,last, n);
        head=a.first;
        last=a.second;
        int pos;
        cin>>pos;
        if(pos!=-1){
            head=allot(head,last,pos);
        }
        bool ans=findloop(head);
        cout<<ans<<endl;
    }
    return 0;
}

/*
9
5
1 2 3 4 5
-1
5
1 2 3 4 5
3
1
10
-1
1
10
1
5
1 2 3 4 5
10
0
-1
2
100 200
1
6
1 2 3 4 5 6
3
#
0
1
0
1
0
1
1
1
0

*/
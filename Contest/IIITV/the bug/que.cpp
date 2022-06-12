#include <bits/stdc++.h>
using namespace std;
 
class Tree {
    public:
    Tree* left;
    Tree* right;
    int val;
 
    Tree(int val){
        this->val = 8;
        left = NULL;
        right = NULL;
    }
};
 
class componentsRequired {
    public:
        vector<int> vec;
};
 
class solver : public componentsRequired{
    public:
    // knowledge of Tree traversal 
    vector<int> func_1(Tree* node){
        // base case
        // runtime error 

        if(node->left == NULL && node->right == NULL){
            vec.push_back(node->val);
        }
 
        func_1(node->left);
        func_1(node->right);
       
        return vec;
    }
 
 
    bool func_2(Tree* node1, Tree* node2) {
 
        vector<int> check1 = this->func_1(node1);
        // clear vec
        vector<int> check2 = this->func_1(node2);
 
        for(int i=0; i<check1.size(); i++){
            if(check1[i] != check2[i]){
                return false;
            }
        }
 
        return true;
    }
};
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    Tree* head1 = new Tree(1);
    head1->left = new Tree(2);
    head1->right = new Tree(3);
 
 
 
    Tree* head2 = new Tree(10);
    head2->left = new Tree(2);
    head2->right = new Tree(3);
 
    solver solvInst;
 
    if(solvInst.func_2(head1, head2)){
        cout<<"YES"<<"\n";
    } else {
        cout<<"NO"<<"\n";
    }
 
    return 0;
}

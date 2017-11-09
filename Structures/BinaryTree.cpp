#include <bits/stdc++.h>
using namespace std;
struct node{
	int val;
	node *left;
	node *right;
	node( int v ){
		val = v;
		left = nullptr;
		right = nullptr;
	}
	node* insert(node *n, int val){
		if(n == nullptr ) return new node(val);	
		if(n->val > val) n->left = insert(n->left, val);
		else n->right = insert(n->right, val);
	}
	void show(node *n){
		if(n!=nullptr){
			show(n->left);
			cout << n->val << " ";
			show(n->right);
		}
	}
	string gHash(node *n) {
	 	string hash="";
	 	if(n->right!=nullptr)
	 		hash += "R"+gHash(n->right);
		if(n->left!=nullptr)
	 		hash += "L"+gHash(n->left);
		return hash+"!";
	 }
};

int main(){
	node * root = new node(7);
	root->insert(root,1);
	root->insert(root,-1);
	root->show(root);
	
	cout << endl<<root->gHash(root) <<endl;
	return 0;
}

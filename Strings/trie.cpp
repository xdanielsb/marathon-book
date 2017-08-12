#include <bits/stdc++.h>

using namespace std;

struct node {
	node * children[26];
	bool is_end;
	int num_times;
	
	node(){
		memset(children, 0, sizeof(children));
		is_end =false;
		num_times =0;
	}
};


void insert(node* nd, char *s){
	if(*s){
		if(!nd->children[*s -'a']){
			nd->children[*s -'a']  = new node();
		}
		insert(nd->children[*s -'a'], s+1);
	}else{
		nd->is_end = true;	
	}
}

int contains(node *nd, char *s){
	if(*s){
		if(!nd->children[*s - 'a']){
			return false;
		}
		return contains(nd->children[*s-'a'], s+1);
	}else{
		return nd->is_end;
	}
}

int main(){
    node * trie = new node();

    string  a = "word";
    char *cstr = new char[a.length() + 1];
    strcpy(cstr, a.c_str());

    insert (trie, cstr);
    string b = "banani";

    strcpy(cstr, b.c_str());
    if (contains(trie, cstr)){
        cout << "ohh holly xx." << endl;
    }else{
        cout << "mother ..." << endl;
    }
	return 0;
}

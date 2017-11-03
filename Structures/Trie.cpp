#include <bits/stdc++.h>

using namespace std;

/*
 * Struct for a trie
 */
struct node {
	node * son[26];
	bool is_end;
	int num_times;

	node(){
		memset(son, 0, sizeof(son));
		is_end =false;
		num_times =0;
	}
};

/*
 * insert a word in the trie
 */
void insert(node* nd, char *s){
	if(*s){
    int pos = *s - 'a';
		if(!nd->son[pos]) nd->son[pos]=new node();
			insert(nd->son[pos], s+1);
	}else{
		nd->is_end = true;
	}
}

/*
 * Check if the word is in the trie
 */
int contains(node *nd, char *s){
	if(*s){
    int pos = *s - 'a';
		if(!nd->son[pos]) return false;
		return contains(nd->son[pos], s+1);
	}else{
		return nd->is_end;
	}
}

//This is just the driver program
int main(){
    node * trie = new node();
    string  a = "word";
    char *cstr = new char[a.length() + 1];
    strcpy(cstr, a.c_str());
    insert (trie, cstr);
    string b = "banani";
    strcpy(cstr, b.c_str());
    insert (trie, cstr);
    if (contains(trie, cstr)){
        cout << "ohh holly xx." << endl;
    }else{
        cout << "mother ..." << endl;
    }
	return 0;
}

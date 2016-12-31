#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

typedef struct node {
    string val;
    bool visited = false;
    vector < node >  neighbors ;
} node;


typedef vector < node >  list_nodes;



void dfs(node start){
    stack<node> s;
    s.push(start);
    while(s.empty() == false){
        node top = s.top();
        s.pop(); 

        if (top.visited == false){
            top.visited  = true;
            cout << "Node " << top.val << " visited" << endl;
        }

        list_nodes n = top.neighbors;
        cout << "\tNum of neighbors " << n.size() << endl;
        
        for (node a: n){
            cout <<"\t\t "<<a.val<<endl;
            s.push(a);
        }
        /*for (int i=0; i< n.size(); i++){
            cout <<"\t\t "<<n[i].val<<endl;
            s.push(n[i]);
        }*/



    }
}


int main(){
 
    node a,b,c,d ;
    a.val = "a";
    b.val = "b";
    c.val = "c";
    d.val = "d";

    list_nodes la(2), lc(1);

    lc[0] = d;
    c.neighbors = lc;

    la[0] = b;
    la[1] = c;
    a.neighbors = la;

    
    cout<< " dfs -> a" <<endl<<endl;
    dfs(a);
    
    return 0; 

}

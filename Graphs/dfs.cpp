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



inline void dfs(node start){
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
            s.push(a);
        }

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
    la[0] = b;
    la[1] = c;
    

    c.neighbors = lc;
    a.neighbors = la;
    

    dfs(a);
    return 0; 

}

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
            //Check for the termination condition
        }

        list_nodes n = top.neighbors;      
        for (node a: n){
            s.push(a);
        }


    }
}


int main(){

     /*          a
     *        /    \
     *       b      c
     *       |    /   \
     *       d   e     f
     *
     */

 
    node a,b,c,d,e,f;
    a.val = "a";
    b.val = "b";
    c.val = "c";
    d.val = "d";
    e.val = "e";
    f.val = "f";

    list_nodes la(2), lc(2), lb(1);

    
    lc[0] = e;
    lc[1] = f;
    c.neighbors = lc;

    lb[0] = d;
    b.neighbors = lb;


    la[0] = b;
    la[1] = c;    
    a.neighbors = la;
    


    cout<< " dfs -> a" <<endl<<endl;
    dfs(a);
    
    return 0; 

}

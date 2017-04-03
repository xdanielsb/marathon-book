#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct node {
    string val;
    bool visited = false;
    vector < node >  neighbors ;
}

typedef vector < node >  list_nodes;

void bfs(node start){

    queue<node> s;
    s.push(start);
    start.visited = true;
    while (s.empty() == false){
        node top = s.front();
        s.pop();
        cout << "Node " << top.val << " visited" << endl;

        list_nodes n = top.neighbors;
        //Check for the termination condition
        for (node a: n){
            if (a.visited == false){
                s.push(a);
                a.visited = true;
            }
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



    cout<< " bfs -> a" <<endl<<endl;
    bfs(a);

    return 0;
}

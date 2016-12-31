import java.util.*;


public class DFS {

    public static void dfs(node  start){
        ArrayDeque<node> s = new ArrayDeque<node>();

        s.push(start);
        while(s.isEmpty() == false){
            node top = s.pop();
            
            if(top.visited == false){
                top.visited = true;
                System.out.println("Visit " + top.name);
            }
            ArrayList<node> n;
            n = top.neighbors;
            for (node a: n){
                s.push(a);
            }

        }
    }
    
    public static void main(String args[]){
        node a = new node("A");
        node b = new node("B");
        node c = new node("C");
        node d = new node("D");

        ArrayList<node> la = new ArrayList<node>();
        la.add(b);
        la.add(c);
        ArrayList<node> lc = new ArrayList<node>();
        lc.add(d);

        a.neighbors = la;
        c.neighbors = lc;
        
        dfs(a);
    }

}

class node {
   ArrayList<node> neighbors;
   String name;
   boolean visited ;
   public node(String name){
        this.name = name; 
        this.visited = false;
        this.neighbors = new ArrayList<node>();
   }
};

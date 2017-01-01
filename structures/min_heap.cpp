// C++ program to us priority_queue to implement min heap
#include <bits/stdc++.h>
using namespace std;
 
/*REFERENCES 
 *http://quiz.geeksforgeeks.org/implement-min-heap-using-stl/
 */

int main (){
    /* 
     * priority_queue supports a constructor that
     * requires two extra arguments to make it min heap.
     * priority_queue <Type, vector<Type>, ComparisonType > min_heap;
    */
      
    priority_queue <int, vector<int>, greater<int> > pq;
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);
 
    // One by one extract items from max heap
    while (pq.empty() == false){
        cout << pq.top() << " ";
        pq.pop();
    }
 
    return 0;
}

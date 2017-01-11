#include <iostream>
#include <vector> 

#define forn(i,n) for (int i=0; i<n; i++)
#define s(a) ((int) a.size())

using namespace std;

/*
 * Solve dice problem using convolution of probability distribution functions
 */
/*
 *Interesting book about  probabilities
 * http://www.cs.ubc.ca/~little/cpsc425/notes/dietossing.pdf   
 */

typedef double d;
typedef vector < d > vd;
/*
 * N --> Number of faces
 * toss -> number of toss
 */


void prob(int N, int t){
    // A[i] stand out the probability of number I  to appear

    vd  P = {1.0};


    //Here the convolution of the distribution
    /*
     * RANDOM VARIABLES
     * X,Y
     * Z = X + Y
     *
     * f(Z) = f(X) CONVOLUCION f(Y) 
     *
     */
    
    
    forn(_, t){
        vd  Pr(s(P) +N -1, 0);
        forn (j, s(P)){
            forn (k, N){
                Pr[j + k ] += P[j] / N;
            }
            
        }
        P.swap(Pr);
    }
    

    forn(i, s(P)){
        cout << "P(" << (i+t) <<"):"  << P[i] << endl;
    }

    


}

int main(){
    prob(6, 1);
    cout << endl;
    prob(6, 2);
    cout << endl;
    prob(6, 3);
}

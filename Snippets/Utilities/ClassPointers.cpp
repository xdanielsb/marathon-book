#include <iostream>
using namespace std;
class Person {
 public:
  Person() {
   cout << "Constructor called!" <<endl;
  }
  ~Person() {
   cout << "Destructor called!" <<endl;
  }
};
int main( ) {
 Person* myBoxArray = new Person[4];
 delete [] myBoxArray; // Delete array
 return 0;
}

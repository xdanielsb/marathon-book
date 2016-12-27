### Check if a word is palindrome

*n is the number of letters of the word 

|               | Case             | Time Complexity |
| ------------- |:----------------:|:---------------:|
| Worst Case    | T(n)    n > 1    | O(n/2)       |
| Best Case     | T(n)    n = 1    | O(1)            |

```c++

#include <iostream>
#include <string>

using namespace std;

/*
 * i,j positions letters in the word
 */
bool evaluate(string word, int i, int j){
    if (i >= j)
        return true;
    else if (word[i] != word[j])
        return false;
    return evaluate(word, i+1, j-1);
}   

bool is_palindrome(string word){
    int length = word.length();
    if (length == 1)
        return true;
    return evaluate(word, 0, length-1);   
}

int main(){
    string word = "anamariaairamana";
    string word2 = "Thisssiss";
    cout << word << " ";
    cout << is_palindrome(word) << endl;
    cout << word2 << " ";
    cout << is_palindrome(word2) << endl;
    return  0;
}

```


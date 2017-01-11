#include <iostream>
#include <iterator>
#include <regex>
#include <string>


using namespace std;
int main(){
    string  s = "123daniel , jajaja, lol, 234234534, I am from Earth";
    regex tel("\\d{8},\\sI");
    
    auto words_begin = sregex_iterator(s.begin(), s.end(), tel);
    auto words_end = sregex_iterator();

    cout << "Found " << distance(words_begin, words_end)<< " words\n";


    const int N = 6;

    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        smatch match = *i;
        string match_str = match.str();
        if (match_str.size() > N) {
            cout << "  " << match_str << '\n';
        }
    }
 
    return 0;

}


// simple program to do integer comparison

#include <iostream>

using namespace std;

int main(){
    cout << "Enter in first number: ";
    int first, second;
    cin >> first;
    cout << "Enter in second number: ";
    cin >> second;
    
    if (first > second)
        cout << first << " > " << second << endl;
    if (first < second)
        cout << first << " < " << second << endl;
    if (first == second)
        cout << first << " = " << second << endl;


}

// averages the numbers stored in a vector of doubles

#include <vector>
#include <iostream>
#include <istream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


int main(){
    // ask for vector input
    cout << "Please enter a vector of double seperated by spaces" << endl;
    
    // read in the vector and populate the data structure
    vector<double> myVector;
    double loader;
    while (cin >> loader)
        myVector.push_back(loader);
    
    int count=0;
    double sum=0;
    for (vector<double>::size_type i = 0; i != myVector.size(); ++i){
        ++count;
        sum += myVector[i];
    }
    
    std::cout << "The average of the vector you input is: " << sum / count << std::endl;
    
    return 0;
}

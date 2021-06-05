#include <iostream>
//#include "..\konteineri\Vector.cpp"
//#include "..\konteineri\String.cpp"
#include "konteineri\Vector.cpp"
#include "konteineri\String.cpp"
//#include <string>
//#include <vector>
#include <algorithm>

using std::cout; 
//using std::sort;
//using std::vector; 
//using std::string;
using std::endl;

int main() {
    Vector<String> arr;
    /* = { "raid ded", "implementation", "states", "all",
                           "the", "requirements poppo", "parameter", "a",
                           "and", "or", "execution", "participate",
                           "and io", "oor", "execution", "participate aai" };
        */

    arr.push_back("raid ded");
    arr.push_back("implementation");
    arr.push_back("states");
    arr.push_back("all");
    arr.push_back("the");
    arr.push_back("requirements poppo");
    arr.push_back("parameter");
    arr.push_back("a");
    arr.push_back("and");
    arr.push_back("or");
    arr.push_back("oor");
    arr.push_back("execution");
    arr.push_back("participate");
    arr.push_back("and io");
    arr.push_back("and");
    arr.push_back("participate aai");
    arr.push_back("participate aa");
    arr.push_back("execution");
/*
    for (const auto &item : arr) {
        cout << item << "; ";
    }
    cout << endl;

    sort(arr.begin(), arr.end());

    for (const auto &item : arr) {
        cout << item << "; ";
    }
    cout << endl;
    */

    //exit(EXIT_SUCCESS);
    return 0;
}

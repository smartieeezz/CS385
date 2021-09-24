/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Stephanie Martinez
 * Date        : 9/24/2021
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System
 ******************************************************************************/
#include <iostream>
#include <cctype>
#include <sstream>

using namespace std;

bool is_all_lowercase(const string &s) {
    // TODO: returns true if all characters in string are lowercase
    // letters in the English alphabet; false otherwise.
    // 1 is true 
    // 0 is false
    int i = 0;
    while (i < s.length()){
        if (!islower(s[i])){
            return false;
            break;
        }
        else{
            i++;
            continue;
        }
    }
    return true;
}

bool all_unique_letters(const string &s) {
    // TODO: returns true if all letters in string are unique, that is
    // no duplicates are found; false otherwise.
    // You may use only a single int for storage and work with bitwise
    // and bitshifting operators.
    // No credit will be given for other solutions.
    return 0;
}

int main(int argc, char * const argv[]) {
    // TODO: reads and parses command line arguments.
    // Calls other functions to produce correct output.
    string m;
    if (argc != 2) {
		cerr << "Usage:" << argv[0] << " <string>" << endl;
		return 1; 
	}

    if(!is_all_lowercase(argv[1])){
        cerr << "Error: String must contain only lowercase letters." << endl;
    }
    return 0;

}

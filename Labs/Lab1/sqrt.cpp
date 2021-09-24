/*******************************************************************************
 * Name    : sqrt.cpp
 * Author  : Stephanie Martinez
 * Version : 1.0
 * Date    : September 8, 2021
 * Description : Computes the square root of the command-line argument.
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <limits>
#include <sstream>
#include <math.h>
#include <iomanip>
using namespace std;

double sqrt(double num, double esplion){
    double x = num;
    double root;
    int count = 0;
    if (num < 0){
        return numeric_limits<double>::quiet_NaN();
    }
    if(num ==0){
        return num;
    }
    if (num == 1){
        return num;
    }
    while(1){
        count++;
        root = 0.5 * (x + (num/x));
        if(abs(root-x) < esplion){
            break;
        }
        x = root;
    }
    return root;
}

int main(int argc, char* argv[]){
    double m,n;
    string x; 
    //m = number that we will take sqrt of 
    //n = accuracy 
    istringstream iss; 
    double epi = 0.0000001; 

    if(argc < 2 || argc > 3){
        cerr<<"Usage: ./sqrt <value> [epsilon]"<<endl;
        return 1;
    }
    
    iss.str(argv[1]);

    if (!(iss >> m)) {
		cerr << "Error: Value argument must be a double." << endl;
		return 1; 
	}
    
    iss.clear();
    
    if (argc == 2){
        cout <<fixed<< setprecision(8)<< sqrt(m, epi) <<endl;
        return 0;
    }
    if (argc == 3){
        iss.str(argv[2]);
        if (!(iss>>n)){
            cerr <<"Error: Epsilon argument must be a positive double." <<endl;
            return 1;
        }
        if(n<=0){
            cerr << "Error: Epsilon argument must be a positive double." <<endl;
            return 1;
        }
        cout << fixed<< setprecision(8)<<sqrt(m, n) <<endl;
        return sqrt(m, n);
    }
    
    return 0;
}
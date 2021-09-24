/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Stephanie Martinez
 * Date        : 9.15.2021
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <array>
#include <iostream>
#include <sstream>

using namespace std;

class PrimesSieve {
public:
    PrimesSieve(int limit);

    ~PrimesSieve() {
        delete [] is_prime_;
    }

    int num_primes() const {
        return num_primes_;
    }

    void display_primes() const;

private:
    // Instance variables
    bool * const is_prime_;
    const int limit_;
    int num_primes_, max_prime_;

    // Method declarations
    int count_num_primes() const;
    int maxPrime() const;
    void sieve();
    static int num_digits(int num);
};

PrimesSieve::PrimesSieve(int limit) :
        is_prime_{new bool[limit + 1]}, limit_{limit} {
    sieve();
}

void PrimesSieve::display_primes() const {
    // TODO: write code to display the primes in the format specified in the
    // requirements document.
    int num_primes_ = count_num_primes();
    int max_prime_ = maxPrime();
     cout << endl;
        cout << "Number of primes found: "<< count_num_primes() << endl;
        cout << "Primes up to " << limit_ << ":" << endl;

        const int width = num_digits(max_prime_),row = 80/(width + 1);
        if(num_primes_>= row){ 
            for (int i=0, count=1; i<=limit_;i++){
                if (is_prime_[i] == true){
                if(count != row){
                    if (i!=max_prime_){
                        cout<<setw(width)<<i<<" "; 
                        count+=1;
                        }
                        else{
                            cout<<setw(width)<<i; 
                            count++;
                        }
                    }else if(count >= row){
                        cout<<setw(width)<<i<<endl;
                        count=1; 
                    }
                }
                }         
            }
            else{
            if(num_primes_ <= row){
                            
                for(int i = 2; i <= limit_; i++){
                    if(i ==2){                
                        cout<<i;
                    }else{
                    if(is_prime_[i] == true){
                        cout << " " << i;
                }
            }
            }
          }
        }
}


int PrimesSieve::count_num_primes() const {
    // TODO: write code to count the number of primes found
    int num_primes_ = 0;
    for(int i=2;i<=limit_; i++){
        if(is_prime_[i]==true){
            num_primes_++;
        }
    }
    return num_primes_;
}

int PrimesSieve::maxPrime() const{
    int max_prime_;
    for(int i=2; i<=limit_; i++){
        if(is_prime_[i] == true){
            max_prime_ =i;
        }
    }
    return max_prime_;
}
void PrimesSieve::sieve() {
    // TODO: write sieve algorithm
    for(int i =2; i<= limit_; i++){
        is_prime_[i] = true;
    }
    for(int i=0;i <= sqrt(limit_);i++){
        if (is_prime_[i] == true){
            for (int j=i*i; j <= limit_; j = j+i){
                is_prime_[j] = false;
            }
        }
    }
    

}

int PrimesSieve::num_digits(int num) {
    // TODO: write code to determine how many digits are in an integer
    // Hint: No strings are needed. Keep dividing by 10.
    int count = 0;
    while(num !=0){
        num= num/10;
        count++;
    }
    return count;
}

int main() {
    cout << "**************************** " <<  "Sieve of Eratosthenes" <<
            " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;

    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);

    // Check for error.
    if ( !(iss >> limit) ) {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2) {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }

    // TODO: write code that uses your class to produce the desired output.
    PrimesSieve prime(limit); 
    prime.display_primes();
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int find_less_divisor(int &n, int it){
    if(n%it == 0){
        return it;
    }
    else{
        return find_less_divisor(n, it + 1);
    }
}

void prime_factor(int &n, vector<int> &factors){
    if(n == find_less_divisor(n, 2)){
        factors.push_back(n);
    }
    else{
        int prime = find_less_divisor(n, 2);
        factors.push_back(prime);

        int next_num = n / prime;
        prime_factor(next_num, factors);
    }


}

void get_unique_vec(const vector<int> &factors, vector<int> &unique_factors){
    unique_factors  = factors; 
    sort( unique_factors.begin(), unique_factors.end() );
    unique_factors.erase( unique( unique_factors.begin(), unique_factors.end() ), unique_factors.end() );
}
int main(){
    vector<int> factors, unique_factors; 
    int number_to_descompose = 76; 
    string final_operation = ""; 

    prime_factor(number_to_descompose, factors);
    get_unique_vec(factors, unique_factors);
    
    for(auto it: unique_factors){
        final_operation+=to_string(it) + "^" + to_string(count(factors.begin(), factors.end(), it)) + "*";   
    }
    
    cout << "La descomposición en factores es: "  << final_operation.substr(0, final_operation.size()-1) << endl;
    
}
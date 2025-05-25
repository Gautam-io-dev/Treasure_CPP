#include <iostream>
#include <cmath>    
#include <cstdlib>  
#include <limits>   

using namespace std;


double computeSeries(int n) {
    double S = 0.0;
    
    for (int i = 1; i <= n; i++) {
        double term = 1.0 / pow(i, i);  
        if (i % 2 == 0) {  
            term = -term;
        }
        S += term;
    }
    
    return S;
}

int main(int argc, char *argv[]) {
    int n;

    
    if (argc > 1) {
        try {
            n = stoi(argv[1]);  
            if (n <= 0) {
                throw invalid_argument("Negative number or zero entered.");
            }
        } catch (exception &e) {
            cout << "Invalid input. Please enter a positive integer." << endl;
            return 1;
        }
    } else {
        
        cout << "Enter the number of terms (n): ";
        while (!(cin >> n) || n <= 0) {
            cout << "Invalid input. Please enter a positive integer: ";
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        }
    }

    
    double result = computeSeries(n);
    cout << "The sum of the first " << n << " terms of the series is: " << result << endl;

    return 0;
}
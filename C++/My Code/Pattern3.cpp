#include<iostream>
using namespace std;

// Function to calculate factorial
int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Function to calculate binomial coefficient
int binomialCoeff(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    int spaces, stars, rows, a, b, c, d, coeff;

    cout << "Enter the number of rows (should be an odd number): ";
    cin >> rows;
    if (rows % 2 == 0) {
        cout << "Please enter an odd number of rows." << endl;
        return 1;
    }

    // Pascal's Triangle - upper half diamond
    spaces = rows / 2;
    for (a = 0; a <= rows / 2; a++) {
        coeff = 1;
        for (c = 1; c <= spaces; c++) {
            cout << " ";
        }
        for (d = 0; d <= a; d++) {
            cout << coeff << " ";
            coeff = coeff * (a - d) / (d + 1);
        }
        spaces--;
        cout << endl;
    }

    // Pascal's Triangle - lower half diamond (reversed)
    spaces = 1;
    for (a = rows / 2 - 1; a >= 0; a--) {
        coeff = 1;
        for (c = 0; c < spaces; c++) {
            cout << " ";
        }
        for (d = 0; d <= a; d++) {
            cout << coeff << " ";
            coeff = coeff * (a - d) / (d + 1);
        }
        spaces++;
        cout << endl;
    }

    return 0;
}


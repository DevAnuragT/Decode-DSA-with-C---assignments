// Given an array of digits (values are from 0 to 9), the task is to find the minimum possible sum of
// two numbers formed from digits of the array. Please note that all digits of the given array must be
// used to form the two numbers.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSumOfTwoNumbers(vector<int>& digits) {
    sort(digits.begin(), digits.end()); // Sort the digits in non-decreasing order

    int num1 = 0, num2 = 0;
    for (int i = 0; i < digits.size(); ++i) {
        if (i % 2 == 0) {
            num1 = num1 * 10 + digits[i]; // Construct the first number
        } else {
            num2 = num2 * 10 + digits[i]; // Construct the second number
        }
    }

    return num1 + num2; // Return the sum of the two numbers
}

int main() {
    vector<int> digits = {6, 8, 4, 5, 2, 3};
    cout << "Minimum sum of two numbers: " << minSumOfTwoNumbers(digits) << endl;
    return 0;
}

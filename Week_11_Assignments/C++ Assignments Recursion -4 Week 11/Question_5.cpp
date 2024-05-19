string decimalToBinaryHelper(int n) {
    if (n == 0) return "";
    return decimalToBinaryHelper(n / 2) + to_string(n % 2);
}

string decimalToBinary(int n) {
    if (n == 0) return "0";
    return decimalToBinaryHelper(n);
}

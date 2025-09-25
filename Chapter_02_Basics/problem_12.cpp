#include <iostream>

using namespace std;

int main() {
    int rupees;
    double decimalPenny;
    int shilling, penny;

    cout << "Enter amount of rupees in decimal system:";
    cin >> rupees >> decimalPenny;

    shilling = static_cast<int>(decimalPenny * 20);
    penny = static_cast<int>(((decimalPenny * 20) - shilling) * 12);

    cout << "In old system: J" << rupees << '.' << shilling << '.' << penny << endl;

    return 0;
}

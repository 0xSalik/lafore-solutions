#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    
    const double pound = 1.487;
    const double frank = 0.172;
    const double mark = 0.584;
    const double yen = 0.00955;
    double rupee;

    cout << "Enter sum of money:";
    cin >> rupee;

    cout << "pound" << setw(8) << rupee / pound << endl
         << "frank" << setw(8) << rupee / frank << endl
         << "mark" << setw(8) << rupee / mark << endl
         << "yen" << setw(8) << rupee / yen << endl;

    return 0;
}

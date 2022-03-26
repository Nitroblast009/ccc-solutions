// Problem: Boiling Water
#include <iostream>
using namespace std;

int main()
{
    short temp;
    cin >> temp;
    short pressure = 5 * temp - 400;
    cout << pressure << "\n"
         << (pressure < 100 ? 1 : pressure > 100 ? -1
                                                 : 0);
}
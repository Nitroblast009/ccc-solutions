// Problem: Secret Instructions
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;

struct Step
{
    const string dirc;
    const int mag;
};

int main()
{
    vector<Step> steps;
    int inputNum = 0;
    string prevDirc;

    // Add steps to steps vector
    while (inputNum != 99999)
    {
        cin >> inputNum;

        // Get input string
        stringstream ss;
        ss << setw(5) << setfill('0') << inputNum;
        string inputString = ss.str();
        int sum = (inputString[0] - '0') + (inputString[1] - '0');

        Step newStep{inputString.substr(0, 2) == "00" ? prevDirc : sum % 2 != 0 ? "left"
                                                                                : "right",
                     stoi(inputString.substr(inputString.size() - 3))};
        steps.push_back(newStep);
        prevDirc = newStep.dirc;
    }

    // Print steps vector
    steps.pop_back();
    for (auto step : steps)
        cout << step.dirc << " " << step.mag << "\n";
}
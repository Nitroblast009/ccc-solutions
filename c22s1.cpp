// Problem: Good Fours and Good Fives
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sumWays = 0;
vector<int> exploredNums5;
vector<int> exploredNums4;

void minusNum(int num, int minus)
{
    if (count(exploredNums5.begin(), exploredNums5.end(), num) == 0)
    {
        exploredNums5.push_back(num);
        num -= 5;
        minusNum(num, 5);
    }
    else if (count(exploredNums4.begin(), exploredNums4.end(), num) == 0)
    {
        exploredNums4.push_back(num);
        num -= 4;
        minusNum(num, 4);
    }
    else if (num == 0)
    {
        sumWays++;
        num += minus;
        minusNum(num, minus);
    }
    else
    {
        num += minus;
        minusNum(num, minus);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Get inputNum
    int inputNum;
    cin >> inputNum;

    // Check what is divisible by
    minusNum(inputNum, 5);

    cout << sumWays << endl;
}
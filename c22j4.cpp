// Problem: Good Groups
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int goodConsts, badConsts, groupCount;
    cin >> goodConsts;
    vector<vector<string>> together(goodConsts, vector<string>(2));
    string name1, name2, name3;
    while (goodConsts--)
    {
        cin >> name1 >> name2;
        together[goodConsts] = {name1, name2};
    }
    cin >> badConsts;
    vector<vector<string>> apart(badConsts, vector<string>(2));
    while (badConsts--)
    {
        cin >> name1 >> name2;
        apart[badConsts] = {name1, name2};
    }
    cin >> groupCount;
    vector<vector<string>> groups(groupCount, vector<string>(3));
    while (groupCount--)
    {
        cin >> name1 >> name2 >> name3;
        groups[groupCount] = {name1, name2, name3};
    }

    // Check for good constraints not followed
    int constsBroken = 0;
    for (auto group : groups)
    {
        for (auto pair : together)
        {
            if (pair[0] == group[0] && pair[1] != group[1] && pair[1] != group[2])
            {
                constsBroken++;
            }
            else if (pair[0] == group[1] && pair[1] != group[0] && pair[1] != group[2])
            {
                constsBroken++;
            }
            else if (pair[0] == group[2] && pair[1] != group[1] && pair[1] != group[0])
            {
                constsBroken++;
            }
        }

        for (auto pair : apart)
        {
            if (pair[0] == group[0] && (pair[1] == group[1] || pair[1] == group[2]))
            {
                constsBroken++;
            }
            else if (pair[0] == group[1] && (pair[1] == group[0] || pair[1] == group[2]))
            {
                constsBroken++;
            }
            else if (pair[0] == group[2] && (pair[1] == group[1] || pair[1] == group[0]))
            {
                constsBroken++;
            }
        }
    }

    cout << constsBroken << endl;
}
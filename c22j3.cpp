// Problem: Harp Tuning
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string tuningInput;
    cin >> tuningInput;
    vector<string> rawInstructions;
    int lastStart = 0;
    for (int i = 0; i < tuningInput.length(); i++)
    {
        if ((isdigit(tuningInput[i]) && isalpha(tuningInput[i + 1])) || (isdigit(tuningInput[i]) && i + 1 == tuningInput.length()))
        {
            rawInstructions.push_back(tuningInput.substr(lastStart, i - lastStart + 1));
            lastStart = i + 1;
        }
    }

    for (string rawInstruction : rawInstructions)
    {
        string digits = "";
        for (char let : rawInstruction)
        {
            if (isdigit(let))
            {
                digits.append({let});
            }
        }
        cout << rawInstruction.substr(0, rawInstruction.length() - digits.length() - 1) << (rawInstruction[rawInstruction.length() - digits.length() - 1] == '+' ? " tighten " : " loosen ") << digits << endl;
    }
}
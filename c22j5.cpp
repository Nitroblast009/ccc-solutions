// Problem: Square Pool
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeLoc
{
    TreeLoc(int row, int col)
    {
        row = row;
        col = col;
    };
    int row;
    int col;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int length, treeCnt, row, col;
    cin >> length >> treeCnt;
    vector<TreeLoc> trees(treeCnt);
    while (treeCnt--)
    {
        cin >> row >> col;
        trees[treeCnt] = TreeLoc(row, col);
    }

    cout << length - treeCnt - 1;
}
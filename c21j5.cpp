// Problem: Modern Art
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    // Get artist input
    int rows, cols, strokeCount;
    string stroke;

    cin >> rows >> cols >> strokeCount;
    vector<vector<int>> board(rows, vector<int>(cols, 0));

    // Stroke magic
    int sqCount = 0;
    for (int i = 0; i < strokeCount; i++)
    {
        getline(cin >> ws, stroke);

        if (stroke[0] == 'R')
        {
            for (int i = 0; i < cols; i++)
            {
                if (board[stroke[2] - '0' - 1][i] == 0)
                {
                    board[stroke[2] - '0' - 1][i] = 1;
                    sqCount++;
                }
                else
                {
                    board[stroke[2] - '0' - 1][i] = 0;
                    sqCount--;
                }
            }
        }
        else
        {
            for (int i = 0; i < rows; i++)
            {
                if (board[i][stroke[2] - '0' - 1] == 0)
                {
                    board[i][stroke[2] - '0' - 1] = 1;
                    sqCount++;
                }
                else
                {
                    board[i][stroke[2] - '0' - 1] = 0;
                    sqCount--;
                }
            }
        }
    }

    cout << sqCount;
}
/*
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n, k;
    cin >> m >> n >> k;
    vector<int> delta_row(m);
    vector<int> delta_col(n);
    while (k--)
    {
        char op;
        int id;
        cin >> op >> id;
        --id;
        delta_row[id] += (op == 'R');
        delta_col[id] += (op == 'C');
    }
    vector<vector<int>> delta(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            delta[i][j] += delta_row[i];
        }
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            delta[i][j] += delta_col[j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cnt += (delta[i][j] % 2 == 1);
        }
    }
    cout << cnt << '\n';
    return 0;
}*/
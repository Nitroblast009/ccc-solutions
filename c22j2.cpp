// Problem: Fergusonball Ratings
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int playersCount;
    cin >> playersCount;

    unsigned int scored, fouls, stars;
    int starredPlayers = 0;
    bool allStarred = true;
    for (int i = 0; i < playersCount; i++)
    {
        cin >> scored >> fouls;
        stars = scored * 5 - fouls * 3;
        if (stars > 40)
        {
            starredPlayers++;
        }
        else
            allStarred = false;
    }

    cout << starredPlayers << (allStarred ? "+" : "");
}
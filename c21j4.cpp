// Problem: Arranging Books
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Put all books in dynamic array as characters
    vector<char> books;
    int swapCount = 0;
    int countL = 0;
    int countM = 0;
    int countS = 0;

    string booklist;
    cin >> booklist;
    for (char book : booklist)
    {
        switch (book)
        {
        case 'L':
            countL++;
            break;
        case 'M':
            countM++;
            break;
        case 'S':
            countS++;
            break;
        }
        books.push_back(book);
    }

    // Make L section
    int lastLinMIndex = countL;
    int lastLinSIndex = books.size() - 1;
    for (int i = 0; i < countL; i++)
    {
        if (books[i] == 'M')
        {
            while (books[i] != 'L')
            {
                if (books[lastLinMIndex] == 'L')
                {
                    swap(books[i], books[lastLinMIndex]);
                    swapCount++;
                }
                else
                    lastLinMIndex++;
            }
        }
        else if (books[i] == 'S')
        {
            while (books[i] != 'L')
            {
                if (books[lastLinSIndex] == 'L')
                {
                    swap(books[i], books[lastLinSIndex]);
                    swapCount++;
                }
                else
                    lastLinSIndex--;
            }
        }
    }

    // Make M section
    int lastMIndex = books.size() - 1;
    for (int i = 0; i < countM; i++)
    {
        while (books[i + countL] != 'M')
        {
            if (books[lastMIndex] == 'M')
            {
                swap(books[i + countL], books[lastMIndex]);
                swapCount++;
            }
            else
                lastMIndex--;
        }
    }

    cout << swapCount;
}
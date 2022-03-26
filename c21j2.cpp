// Problem: Silent Auction
#include <iostream>
using namespace std;

struct bid
{
    short bidId;
    string bidder;
    int bidVal;
};

int main()
{
    // Get bid data
    short bidCount;
    cin >> bidCount;

    bid bids[bidCount] = {};
    for (short i = 0; i < bidCount; i++)
    {
        bid newBid;
        newBid.bidId = i;
        cin >> newBid.bidder;
        cin >> newBid.bidVal;
        bids[i] = newBid;
    }

    // Return max bid
    bid maxBid;
    maxBid.bidVal = 0;
    for (bid bid : bids)
    {
        if (bid.bidVal > maxBid.bidVal)
            maxBid = bid;
        else if (bid.bidVal == maxBid.bidVal && bid.bidId < maxBid.bidId)
            maxBid = bid;
    }

    cout << maxBid.bidder;
}
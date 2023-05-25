/*Question #1

You are running a website, and you are trying to keep track of how much money
you make per day from advertising. Declare an advertising struct that
keeps track of how many ads you’ve shown to readers, what percentage of ads
were clicked on by users, and how much you earned on average from each ad that was clicked.
Read in values for each of these fields from the user. Pass the advertising struct to a function
that prints each of the values, and then calculates how much you made for that day
(multiply all 3 fields together).
*/
#include <iostream>
struct Advertising
{
    int ads_viewed_count{};
    double viewed_percent{};
    double profit_per_ad{};
};
Advertising getAdvertising()
{
    Advertising temp;
    std::cout << "How many ads were shown today? ";
    std::cin >> temp.ads_viewed_count;
    std::cout << "What percentage of ads were clicked on by users? (in %) ";
    std::cin >> temp.viewed_percent;
    std::cout << "What was the average earnings per click? ";
    std::cin >> temp.profit_per_ad;
    return temp;
}

void printAdvertising(const Advertising &ad)
{
    std::cout << "Number of ads shown: " << ad.ads_viewed_count << '\n';
    std::cout << "Click through rate: " << ad.viewed_percent << '\n';
    std::cout << "Average earnings per click: $" << ad.profit_per_ad << '\n';

    // The following line is split up to reduce the length
    // We need to divide ad.clickThroughRatePercentage by 100 because it's a percent of 100, not a multiplier
    std::cout << "Total Earnings: $" << (ad.ads_viewed_count * ad.viewed_percent / 100 * ad.profit_per_ad) << '\n';
}
int main()
{
    printAdvertising(getAdvertising());

    return 0;
}

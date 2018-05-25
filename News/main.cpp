#include <iostream>
#include "newsfeed.h"

#include "report.h"

using namespace std;

int main()
{
    cout << "BLOW";

    NewsFeed feed;
    cout << "BLOW";
    Report *s1 = new Report("Earthquake!", "There has been an awful disaster");
    Report *s2 = new Report ("Tornado!", "There has been an awful disaster");
    cout << "BLOW";
    NewsItem *n1 = new NewsItem(s1);
    NewsItem *n2 = new NewsItem(s2);
    cout << "BLOW";
    n1->verify();
    n1->verify();
    n1->verify();
    n2->verify();


    feed.addItem(*n1);
    feed.addItem(*n2);

    feed.print();
    cout << "BLOW";

    feed.remove(*n2);

    feed.print();
    return 0;


//    cout << "\n";
//    feed.print();
}

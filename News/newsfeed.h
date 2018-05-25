#ifndef NEWSFEED_H
#define NEWSFEED_H
#include "newsitem.h"
#include "report.h"
#include <list>
#include <stdlib.h>


class NewsFeed
{
public:
    NewsFeed();
    ~NewsFeed();
    std::list<NewsItem> feed;
    void addItem(NewsItem news);
    void remove(NewsItem news);
    void print();


};

#endif // NEWSFEED_H

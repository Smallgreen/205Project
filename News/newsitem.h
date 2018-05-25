#ifndef NEWSITEM_H
#define NEWSITEM_H
#include "report.h"
#include <iostream>
#include <time.h>

class NewsItem
{
public:
    NewsItem(Report *report);
 //   ~NewsItem();

    std::string content;
    std::string title;
    time_t timeReported;
    time_t timePosted;
    int id;
    //location l
    int verified;
    int denied;
    bool confirmed;
    bool published;

    void verify();
    void deny();
    void confirm();
    void decideConfirmation();
    void setPublished();
    bool getConfirm();
    void present();




private:
    static int idCount;

};

#endif // NEWSITEM_H

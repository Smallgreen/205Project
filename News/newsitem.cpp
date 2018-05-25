#include "newsitem.h"
#include <stdlib.h>

int NewsItem::idCount = 0;

NewsItem::NewsItem(Report *report)
{
    title = report->getTitle();
    content = report->getContent();
    timeReported = report->getTime();

    verified = 0;
    denied = 0;
    confirmed = false;
    published = false;

    id = idCount;
    idCount++;

}



void NewsItem::verify(){
    verified++;
}


void NewsItem::deny(){
    denied++;
}

bool NewsItem::getConfirm(){
    return confirmed;
}

void NewsItem::setPublished(){
    published = true;
}

void NewsItem::present(){
    char reported [80];


    struct tm * timeinfo;
    timeinfo = localtime(&timeReported);
    std::cout << '\n';
    strftime(reported,80,"Time Reported: %I:%M%p.",timeinfo);

    std::cout << reported << std::endl;
    std::cout << title << std::endl;
    std::cout << content << std::endl;
    std::cout << "Verified: " << verified << std::endl;


}

void NewsItem::decideConfirmation(){
    int percent;
    percent = (verified) / (verified+denied);

    if (percent >= .8){
        confirmed = true;
    }
}

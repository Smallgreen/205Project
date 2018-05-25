#include "report.h"

int Report::idCount = 0;

Report::Report(std::string t, std::string c)
{
    this->title = t;
    this->content = c;
    ti = time(NULL);

    id = idCount;
    idCount++;
}

void Report::read(){
    char now [80];
    struct tm * timeinfo;
    timeinfo = localtime(&ti);
    strftime(now,80,"Time Reported: %I:%M%p.",timeinfo);
    std::cout << now << std::endl;
    std::cout << title << std::endl;
    std::cout << content << std::endl;
}

std::string Report::getContent(){
    return this->content;
}

std::string Report::getTitle(){
    return this->title;
}

time_t Report::getTime(){
    return this->ti;
}

void Report::confirm(){
    confirmed = true;
}


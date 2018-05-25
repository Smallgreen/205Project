#ifndef Report_H
#define Report_H
#include <iostream>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <sstream>

class Report
{
public:
    Report(std::string title, std::string content);
    std::string content;
    int id;
    std::string title;
    time_t ti;
    //pair <double, double> location;
    bool confirmed;

    std::string getContent();
    std::string getTitle();
    time_t getTime();
    void read();
    void confirm();


private:
    static int idCount;

};

#endif // Report_H

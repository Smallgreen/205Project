#include "newsfeed.h"
#include <list>
#include <iterator>



NewsFeed::NewsFeed()
{

}


NewsFeed::~NewsFeed(){
    std:: list<NewsItem>::iterator it;
    it = feed.begin();
    while (it!= feed.end()){
         //delete *(++it);
     }
 }


void NewsFeed::addItem(NewsItem news){
    feed.push_back(news);
}

void NewsFeed::remove(NewsItem news){
    std::list<NewsItem>::iterator it;
    it = feed.begin();
    while (it!= feed.end()){
        if (it->id == news.id){
            feed.erase(it);
        }
     }
}

void NewsFeed::print(){

   std:: list<NewsItem>::iterator it;
   it = feed.begin();

   while (it != feed.end()){
        it->present();
        it++;
    }

}



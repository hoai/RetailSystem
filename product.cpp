#include <sstream>
#include <iomanip>
#include "product.h"



Product::Product(const std::string category, const std::string name, double price, int qty) :
    name_(name),
    price_(price),
    qty_(qty),
    category_(category)
{
}

Product::~Product()
{

}


double Product::getPrice() const
{
    return price_;
}

std::string Product::getName() const
{
    return name_;
}

void Product::subtractQty(int num)
{
    qty_ -= num;
}

int Product::getQty() const
{
    return qty_;
}

/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool Product::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}

void Product::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << endl;
}

void Product::addReview(Review * review)
{
    reviewList.push_back(review);
}

double Product::getAverageRating() const
{
    vector<Review*>::const_iterator it;
    double totalRatingSum = 0;
    double count = 0;
    double returnDouble = -1;
    for(it = reviewList.begin(); it != reviewList.end(); it++)
    {
        totalRatingSum += (*it)->rating;
        count++;
    }

    // for (int i = 0; i < (int)reviewList.size(); i++)
    // {  
    //     count++;
    //     totalRatingSum = reviewList.at(i)->rating;
    // }
    if(count == 0)
    {
        return -1;
    }
    returnDouble = totalRatingSum/count;
    return returnDouble;
}



#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <set>

using std::vector;
using std::string;
using std::ostream;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;
using std::multiset;

class Quote {
    public:
        Quote() = default; // = default see § 7.1.4 (p. 264)
        Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) { }
        std::string isbn() const { return bookNo; }
        // returns the total sales price for the specified number of items
        // derived classes will override and apply different discount algorithms
        virtual double net_price(std::size_t n) const { return n * price; }
        virtual ~Quote() = default; // dynamic binding for the destructor
        Quote(const Quote&) = default; // memberwise copy
        Quote(Quote&&) = default; // memberwise copy
        Quote& operator=(const Quote&) = default; // copy assign
        Quote& operator=(Quote&&) = default;
        virtual shared_ptr<Quote> clone() const & {return shared_ptr<Quote>(new Quote(*this));}
        virtual shared_ptr<Quote> clone() && {return shared_ptr<Quote>(new Quote(std::move(*this)));}
    private:
        std::string bookNo; // ISBN number of this item
    protected:
        double price = 0.0; // normal, undiscounted price
};
/*
class Bulk_quote : public Quote { // Bulk_quote inherits fromQuote
    public:
        Bulk_quote() = default;
        Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) { }
        // overrides the base version in order to implement the bulk purchase discount policy
        double net_price(std::size_t) const override;
    private:
        std::size_t min_qty = 0; // minimum purchase for the discount to apply
        double discount = 0.0; // fractional discount to apply
    };

*/

// class to hold the discount rate and quantity
// derived classes will implement pricing strategies using these data
class Disc_quote : public Quote {
    public:
        Disc_quote() = default;
        Disc_quote(const std::string& book, double price,std::size_t qty, double disc):Quote(book, price),quantity(qty), discount(disc) { }
        double net_price(std::size_t) const = 0;
    protected:
        std::size_t quantity = 0; // purchase size for the discount to apply
        double discount = 0.0; // fractional discount to apply
};

// the discount kicks in when a specified number of copies of the same book are sold
// the discount is expressed as a fraction to use to reduce the normal price
class Bulk_quote : public Disc_quote {
    public:
        Bulk_quote() = default;
        Bulk_quote(const std::string& book, double price,std::size_t qty, double disc):Disc_quote(book, price, qty, disc) { }
        // overrides the base version to implement the bulk purchase discount policy
        double net_price(std::size_t) const override;
        shared_ptr<Quote> clone() const & {return shared_ptr<Bulk_quote>(new Bulk_quote(*this));}
        shared_ptr<Quote> clone() && {return shared_ptr<Bulk_quote>(new Bulk_quote(std::move(*this)));}
};

// if the specified number of items are purchased, use the discounted price
double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

// calculate and print the price for the given number of copies, applying any discounts
double print_total(ostream &os,const Quote &item, size_t n){
    // depending on the type of the object bound to the item parameter
    // calls either Quote::net_price or Bulk_quote::net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() // calls Quote::isbn
        << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

class Basket {
    public:
        void add_item(const Quote& sale) // copy the given object
            {items.insert(sale.clone()); }
        // prints the total price for each book and the overall total for all items in the basket
        void add_item(Quote&& sale) // move the given object
            { items.insert(std::move(sale).clone()); }
        double total_receipt(std::ostream&) const;
    private:
        // function to compare shared_ptrs needed by the multiset member
        static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)  { return lhs->isbn() < rhs->isbn(); }
        // multiset to hold multiple quotes, ordered by the compare member
        multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double Basket::total_receipt(ostream &os) const
{
    double sum = 0.0; // holds the running total
    // iter refers to the first element in a batch of elements with the same ISBN
    // upper_bound returns an iterator to the element just past the end of that batch
    for (auto iter = items.cbegin(); iter != items.cend(); ++iter = items.upper_bound(*iter)) {
        // we know there’s at least one element with this key in the Basket
        // print the line item for this book
        sum += print_total(os, **iter, items.count(*iter));
        }
    os << "Total Sale: " << sum << endl; // print the final overall total
    return sum;
}
int main(){
    Quote q("theo",10);
    Bulk_quote dq("tirel",10,5,0.1);
    vector<shared_ptr<Quote>> myVect;
    myVect.push_back(make_shared<Quote>(q));
    myVect.push_back(make_shared<Bulk_quote>(dq));
    //for_each(myVect.begin(),myVect.end(),[](shared_ptr<Quote> x)-> void {print_total(cout,*x,6);});

    //Hiding pointer
    Basket bsk;
    for (int i=0;i<6;++i){
        bsk.add_item(q);
        bsk.add_item(dq);
    }
    bsk.total_receipt(cout);
    return 0;
}

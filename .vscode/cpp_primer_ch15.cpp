#include <iostream>
class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :
			bookNo(book), price(sales_price) {  }
	std::string isbn() const {return bookNo;}
	virtual double net_price(std::size_t n) const {return n * price;}
	virtual ~Quote() = default;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

class Disc_quote: public Quote {
public:
    std::pair<size_t, double> discount_policy() const
    {return {quantity, discount};}
	Disc_quote() = default;
	Disc_quote(const std::string &book, double price, std::size_t qty, double disc) :
			Quote(book, price), quantity(qty), discount(disc) {   }
	virtual double net_price(std::size_t) const = 0;
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote: public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) :
			Disc_quote(book, price, qty, disc) {   }
	double net_price(std::size_t) const override; // here is only declare bcoz don't have {}
   
private:
	std::size_t  min_qty=20;
	double discount = 0.0;

};

double print_total (std::ostream &os, const Quote &item, size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}

void main() {
	Bulk_quote b;
// b.quantity = 99;
}

double Bulk_quote::net_price(size_t cnt) const {
if (cnt >= min_qty)
	return cnt * (1 - discount) * price;
else
	return cnt * price;
}

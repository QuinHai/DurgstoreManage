#include "Order.h"

#include "Utils.h"
#include "Medicien.h"


Order::Order(int id, map<int, int> mwc, double price, bool isStock, Date date) : mwc(mwc), date(date) {
	this->id = id;
	this->price = price;
	this->isStock = isStock;
}

Order::Order(bool isStock, Date &date) :date(date) {
	this->id = Utils::GetOrderId();
	this->isStock = isStock;
	mwc = map<int, int>();
	price = 0;
}

void Order::append(Medicien &m, int count) {
	if (!isStock && count > m.inventory)
		throw string("添加错误，数量超限");
	mwc.insert(pair<int, int>(m.id, count));
	price += m.getPrice() * count;
}

void Order::update() {
	if (isStock) {
		for (map<int, int>::iterator it = mwc.begin();it != mwc.end();it++) {
			(Utils::mediciens[it->first]).inventory += it->second;
		}
	}
	else {
		for (map<int, int>::iterator it = mwc.begin(); it != mwc.end(); it++) {
			(Utils::mediciens[it->first]).inventory -= it->second;
		}
	}

	(Utils::orders).insert(pair<int, Order>(id, *this));
}


string Order::toString() {
	string o;
	o.append(to_string(id));
	o.append(" ");
	if (isStock)
		o.append("Stock");
	else
		o.append("Sell");
	o.append(" ");
	o.append(to_string(price));
	o.append(" ");
	o.append(date.toString());
	for (map<int, int>::iterator it = mwc.begin(); it != mwc.end(); it++) {
		o.append(" ");
		o.append(to_string(it->first));
		o.append(",");
		o.append(to_string(it->second));
	}
	return o;
}
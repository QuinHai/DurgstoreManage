#pragma once

#include <map>
#include "Date.h"

using std::map;

class Medicien;
class Utils;

class Order {
public:
	friend class OrderCheckPanel;
	friend class OrderFindPanel;
private:
	int id;				//订单id
	map<int, int> mwc;	//MedicienId with count
	double price;		//订单金额
	bool isStock;		//是否进货
	Date date;			//订单创建时间
public:

	Order(){}
	Order(int id, map<int, int> mwc, double price, bool isStock, Date date); 
	Order(bool isStock, Date &date);

	/*
		添加订单项
	*/
	void append(Medicien &m, int count); 

	/*
		提交订单
	*/
	void update(); 

	/*
		转化为字符串
	*/
	string toString();
};
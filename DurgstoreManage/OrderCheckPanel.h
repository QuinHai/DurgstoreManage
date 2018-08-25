#pragma once

#include "Panel.h"
#include "Order.h"
#include "Utils.h"

#include <vector>
using std::vector;

class OrderCheckPanel : public Panel
{
private:
	static OrderCheckPanel* instance; //单例模式
	vector<Order> orderList;//将要显示的订单列表
private:
	OrderCheckPanel() {
		orderList = vector<Order>();
	}
public:
	static OrderCheckPanel * getInstance() {
		return instance;
	}
	/*
	清空显示列表
	*/
	void clearList() {
		orderList.clear();
	}

	/*
	向显示列表中添加
	*/
	void addOrder(Order &m) {
		orderList.push_back(m);
	}

	/*
	添加显示列表
	*/
	void addList(vector<Order> &v) {
		orderList = vector<Order>(v);
	}

	void showPanel(); 

private:
	void input();
};


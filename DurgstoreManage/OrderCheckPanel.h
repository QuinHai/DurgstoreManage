#pragma once

#include "Panel.h"
#include "Order.h"
#include "Utils.h"

#include <vector>
using std::vector;

class OrderCheckPanel : public Panel
{
private:
	static OrderCheckPanel* instance; //����ģʽ
	vector<Order> orderList;//��Ҫ��ʾ�Ķ����б�
private:
	OrderCheckPanel() {
		orderList = vector<Order>();
	}
public:
	static OrderCheckPanel * getInstance() {
		return instance;
	}
	/*
	�����ʾ�б�
	*/
	void clearList() {
		orderList.clear();
	}

	/*
	����ʾ�б������
	*/
	void addOrder(Order &m) {
		orderList.push_back(m);
	}

	/*
	�����ʾ�б�
	*/
	void addList(vector<Order> &v) {
		orderList = vector<Order>(v);
	}

	void showPanel(); 

private:
	void input();
};


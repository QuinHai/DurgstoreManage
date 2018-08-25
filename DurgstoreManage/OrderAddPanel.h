#pragma once
#include "Panel.h"
#include "Order.h"
#include "Utils.h"

class OrderAddPanel :public Panel
{
private:
	static OrderAddPanel * instance;	//µ¥ÀýÄ£Ê½
private:
	OrderAddPanel() {}
public:
	static OrderAddPanel * getInstance() {
		return instance;
	}
	
	void showPanel();
private:
	void input();

};


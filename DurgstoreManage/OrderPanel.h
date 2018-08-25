#pragma once

#include "Panel.h"
#include "OrderCheckPanel.h"
#include "OrderFindPanel.h"
#include "OrderAddPanel.h"

class OrderPanel : public Panel {
private:
	static OrderPanel * instance;	//µ¥ÀýÄ£Ê½
private:
	OrderPanel() {}
public:
	static OrderPanel * getInstance() {
		return instance;
	}
	
	void showPanel();
private:
	void input();

};


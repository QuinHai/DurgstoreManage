#pragma once
#include "Panel.h"
#include "OrderCheckPanel.h"

class OrderFindPanel : public Panel
{
private:
	static OrderFindPanel* instance; //����ģʽ
private:
	OrderFindPanel() {}
public:
	static OrderFindPanel * getInstance() {
		return instance;
	}
	void showPanel();
private:
	void input();

};


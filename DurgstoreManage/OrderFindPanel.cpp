#include "OrderFindPanel.h"

OrderFindPanel* OrderFindPanel::instance = new OrderFindPanel();

void OrderFindPanel::showPanel() {
	system("cls");

	cout << "\t------------------------------------------------------" << endl;
	cout << "\t---                 药店管理系统                   ---" << endl;
	cout << "\t-                     订单查找                       -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t- 1.订单id查找                                       -" << endl;
	cout << "\t- 2.订单日期查找                                     -" << endl;
	cout << "\t- 0.返回                                             -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	input();
}


	void OrderFindPanel::input() {
		int in;
		cout << "\t请输入选择：";
		cin >> in;
		switch (in)
		{
		case 1:
			cout << "\t请输入id:";
			cin >> in;
			OrderCheckPanel::getInstance()->clearList();
			for (map<int, Order>::iterator it = Utils::orders.begin(); it != Utils::orders.end(); it++) {
				if (it->first == in) {
					OrderCheckPanel::getInstance()->addOrder(it->second);
				}
			}
			Panel::addPanel(OrderCheckPanel::getInstance());
			break;
		case 2:
		{
			cout << "\t请输入订单日期: %Y-%m-%d" << endl;
			string date;
			cin >> date;
			date.append(" 0:0:0");
			Date d(date);
			OrderCheckPanel::getInstance()->clearList();
			for (map<int, Order>::iterator it = Utils::orders.begin(); it != Utils::orders.end(); it++) {
				if (it->second.date.checkDay(d)) {
					OrderCheckPanel::getInstance()->addOrder(it->second);
				}
			}
			Panel::addPanel(OrderCheckPanel::getInstance());
			break;
		}
		case 0:
			Panel::removePanel();
			break;
		default:
			cout << "\t输入不合法!" << endl;
			system("pause");
			break;
		}
	}
#include "OrderPanel.h"

OrderPanel* OrderPanel::instance = new OrderPanel();

void OrderPanel::showPanel() {
	system("cls");

	cout << "\t------------------------------------------------------" << endl;
	cout << "\t---                 药店管理系统                   ---" << endl;
	cout << "\t-                     订单管理                       -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t- 1.查看所有订单                                     -" << endl;
	cout << "\t- 2.查找订单                                         -" << endl;
	cout << "\t- 3.添加订单                                         -" << endl;
	cout << "\t- 4.删除订单                                         -" << endl;
	cout << "\t- 0.返回                                             -" << endl;
	cout << "\t------------------------------------------------------" << endl;

	input();
}


	void OrderPanel::input() {
		int in;
		cout << "\t请输入选择：";
		cin >> in;
		switch (in)
		{
		case 1:
		{
			vector<Order> list;
			for (map<int, Order>::iterator it = Utils::orders.begin(); it != Utils::orders.end(); it++) {
				list.push_back(it->second);
			}
			OrderCheckPanel::getInstance()->clearList();
			OrderCheckPanel::getInstance()->addList(list);
			Panel::addPanel(OrderCheckPanel::getInstance());
			break;
		}
		case 2:
			Panel::addPanel(OrderFindPanel::getInstance());
			break;
		case 3:
			Panel::addPanel(OrderAddPanel::getInstance());
			break;
		case 4:
			cout << "\t请输入订单Id: ";
			int id;
			cin >> id;
			Utils::orders.erase(id);
			try {
				Utils::UpdateOrderFile();
			}
			catch (string s) {
				cout << s << endl;
				system("pause");
			}
			break;
		case 0:
			Panel::removePanel();
			break;
		default:
			cout << "\t输入不合法!" << endl;
			system("pause");
			break;
		}
	}
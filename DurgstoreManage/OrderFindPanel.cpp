#include "OrderFindPanel.h"

OrderFindPanel* OrderFindPanel::instance = new OrderFindPanel();

void OrderFindPanel::showPanel() {
	system("cls");

	cout << "\t------------------------------------------------------" << endl;
	cout << "\t---                 ҩ�����ϵͳ                   ---" << endl;
	cout << "\t-                     ��������                       -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t- 1.����id����                                       -" << endl;
	cout << "\t- 2.�������ڲ���                                     -" << endl;
	cout << "\t- 0.����                                             -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	input();
}


	void OrderFindPanel::input() {
		int in;
		cout << "\t������ѡ��";
		cin >> in;
		switch (in)
		{
		case 1:
			cout << "\t������id:";
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
			cout << "\t�����붩������: %Y-%m-%d" << endl;
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
			cout << "\t���벻�Ϸ�!" << endl;
			system("pause");
			break;
		}
	}
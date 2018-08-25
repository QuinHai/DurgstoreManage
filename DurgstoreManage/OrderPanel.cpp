#include "OrderPanel.h"

OrderPanel* OrderPanel::instance = new OrderPanel();

void OrderPanel::showPanel() {
	system("cls");

	cout << "\t------------------------------------------------------" << endl;
	cout << "\t---                 ҩ�����ϵͳ                   ---" << endl;
	cout << "\t-                     ��������                       -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t- 1.�鿴���ж���                                     -" << endl;
	cout << "\t- 2.���Ҷ���                                         -" << endl;
	cout << "\t- 3.��Ӷ���                                         -" << endl;
	cout << "\t- 4.ɾ������                                         -" << endl;
	cout << "\t- 0.����                                             -" << endl;
	cout << "\t------------------------------------------------------" << endl;

	input();
}


	void OrderPanel::input() {
		int in;
		cout << "\t������ѡ��";
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
			cout << "\t�����붩��Id: ";
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
			cout << "\t���벻�Ϸ�!" << endl;
			system("pause");
			break;
		}
	}
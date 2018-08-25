#include "OrderCheckPanel.h"

#include <map>

OrderCheckPanel* OrderCheckPanel::instance = new OrderCheckPanel();

void OrderCheckPanel::showPanel(){
	system("cls");

	cout << "\t------------------------------------------------------" << endl;
	cout << "\t---                 ҩ�����ϵͳ                   ---" << endl;
	cout << "\t-                     �����鿴                       -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << "\tID\t����/����\t���\t����ʱ��" << endl;
	for (vector<Order>::iterator it = orderList.begin(); it != orderList.end(); it++) {
		cout << "\t" << it->id;
		if (it->isStock)
			cout << "\t����";
		else
			cout << "\t����";
		cout << "\t" << it->price << "\t" << it->date.toString() << endl;
	}
	cout << "\t------------------------------------------------------" << endl;
	cout << "\t- ����ID�鿴��ϸ��Ϣ                                 -" << endl;
	cout << "\t- 0.����                                             -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	input();
}

void OrderCheckPanel::input() {
	int in;
	cout << "\t������ѡ��";
	cin >> in;
	if (in == 0) {
		Panel::removePanel();
		return;
	}
	cout << endl;
	for (map<int, Order>::iterator it = Utils::orders.begin(); it != Utils::orders.end(); it++) {
		if (it->first == in) {
			cout << "\tOrder: " << it->second.id << endl;
			cout << "\tҩ������\t����" << endl;
			for (map<int, int>::iterator it2 = it->second.mwc.begin(); it2 != it->second.mwc.end(); it2++) {
				cout << "\t" <<
					Utils::mediciens[it2->first].getName()
					<< "\t" << it2->second << endl;
			}
		}
	}
	cout << endl;
	system("pause");
}
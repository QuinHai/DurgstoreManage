#include "OrderCheckPanel.h"

#include <map>

OrderCheckPanel* OrderCheckPanel::instance = new OrderCheckPanel();

void OrderCheckPanel::showPanel(){
	system("cls");

	cout << "\t------------------------------------------------------" << endl;
	cout << "\t---                 药店管理系统                   ---" << endl;
	cout << "\t-                     订单查看                       -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << "\tID\t进货/卖出\t金额\t创建时间" << endl;
	for (vector<Order>::iterator it = orderList.begin(); it != orderList.end(); it++) {
		cout << "\t" << it->id;
		if (it->isStock)
			cout << "\t进货";
		else
			cout << "\t卖出";
		cout << "\t" << it->price << "\t" << it->date.toString() << endl;
	}
	cout << "\t------------------------------------------------------" << endl;
	cout << "\t- 输入ID查看详细信息                                 -" << endl;
	cout << "\t- 0.返回                                             -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	input();
}

void OrderCheckPanel::input() {
	int in;
	cout << "\t请输入选择：";
	cin >> in;
	if (in == 0) {
		Panel::removePanel();
		return;
	}
	cout << endl;
	for (map<int, Order>::iterator it = Utils::orders.begin(); it != Utils::orders.end(); it++) {
		if (it->first == in) {
			cout << "\tOrder: " << it->second.id << endl;
			cout << "\t药物名称\t数量" << endl;
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
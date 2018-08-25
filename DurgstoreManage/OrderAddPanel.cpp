#include "OrderAddPanel.h"

OrderAddPanel* OrderAddPanel::instance = new OrderAddPanel();

void OrderAddPanel::showPanel() {
	system("cls");

	cout << "\t------------------------------------------------------" << endl;
	cout << "\t---                 药店管理系统                   ---" << endl;
	cout << "\t-                     订单添加                       -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t- 1.添加进货订单                                     -" << endl;
	cout << "\t- 2.添加销售订单                                     -" << endl;
	cout << "\t- 0.返回                                             -" << endl;
	cout << "\t------------------------------------------------------" << endl;

	input();
}


void OrderAddPanel::input() {
		int in;
		cout << "\t请输入选择：";
		cin >> in;
		bool isStock = true;
		switch (in)
		{
		case 1:
			isStock = true;
			break;
		case 2:
			isStock = false;
			break;
		case 0:
			Panel::removePanel();
			return;
			break;
		default:
			cout << "\t输入不合法!" << endl;
			system("pause");
			return;
			break;
		}

		Order o(isStock, Utils::GetNow());
		bool flag = true;
		while (flag) {
			int id, count;
			cout << "\t请输入药物id:";
			cin >> id;
			cout << "\t请输入药物数量:";
			cin >> count;
			o.append(Utils::mediciens[id], count);
			cout << "\t是否继续添加药物：Y/N ";
			string s;
			cin >> s;
			if (s == "Y" || s == "y")
				flag = true;
		}
		o.update();

		try {
			Utils::UpdateMedicienFile();
			Utils::UpdateOrderFile();
		}
		catch (string s) {
			cout << s << endl;
			system("pause");
		}
	}
#include "OrderAddPanel.h"

OrderAddPanel* OrderAddPanel::instance = new OrderAddPanel();

void OrderAddPanel::showPanel() {
	system("cls");

	cout << "\t------------------------------------------------------" << endl;
	cout << "\t---                 ҩ�����ϵͳ                   ---" << endl;
	cout << "\t-                     �������                       -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t- 1.��ӽ�������                                     -" << endl;
	cout << "\t- 2.������۶���                                     -" << endl;
	cout << "\t- 0.����                                             -" << endl;
	cout << "\t------------------------------------------------------" << endl;

	input();
}


void OrderAddPanel::input() {
		int in;
		cout << "\t������ѡ��";
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
			cout << "\t���벻�Ϸ�!" << endl;
			system("pause");
			return;
			break;
		}

		Order o(isStock, Utils::GetNow());
		bool flag = true;
		while (flag) {
			int id, count;
			cout << "\t������ҩ��id:";
			cin >> id;
			cout << "\t������ҩ������:";
			cin >> count;
			o.append(Utils::mediciens[id], count);
			cout << "\t�Ƿ�������ҩ�Y/N ";
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
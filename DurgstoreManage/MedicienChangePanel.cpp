#include "MedicienChangePanel.h"
#include "Medicien.h"
#include "Utils.h"

MedicienChangePanel * MedicienChangePanel::instance = new MedicienChangePanel();

void MedicienChangePanel::showPanel() {
	system("cls");

	cout << "\t------------------------------------------------------" << endl;
	cout << "\t---                 药店管理系统                   ---" << endl;
	cout << "\t-                     药物修改                       -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t--修改内容:                                          -" << endl;
	cout << "\t- 1.药物名称                                         -" << endl;
	cout << "\t- 2.药物价格                                         -" << endl;
	cout << "\t- 3.药物分类                                         -" << endl;
	cout << "\t- 0.返回                                             -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	input();
}

void MedicienChangePanel::input() {
	int in, id;
	cout << "\t请输入选择：";
	cin >> in;
	cout << "\t请输入药物Id:";
	cin >> id;
	switch (in)
	{
	case 1:
	{
		string name;
		cout << "\t请输入名称：" << endl;
		cin >> name;
		Utils::mediciens[in].setName(name);
		try {
			Utils::UpdateMedicienFile();
		}
		catch (string s) {
			cout << s << endl;
			system("pause");
		}
		break;
	}

	case 2:
	{
		double price;
		cout << "\t请输入价格：" << endl;
		cin >> price;
		Utils::mediciens[in].setPrice(price);
		try {
			Utils::UpdateMedicienFile();
		}
		catch (string s) {
			cout << s << endl;
			system("pause");
		}
		break;
	}
	case 3:
	{
		int c;
		cout << "\t请输入分类：1.处方药 2.非处方药 3.保健品" << endl;
		cin >> c;
		Utils::mediciens[in].setCategory((Category)c);
		try {
			Utils::UpdateMedicienFile();
		}
		catch (string s) {
			cout << s << endl;
			system("pause");
		}
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
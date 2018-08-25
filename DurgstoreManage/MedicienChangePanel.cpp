#include "MedicienChangePanel.h"
#include "Medicien.h"
#include "Utils.h"

MedicienChangePanel * MedicienChangePanel::instance = new MedicienChangePanel();

void MedicienChangePanel::showPanel() {
	system("cls");

	cout << "\t------------------------------------------------------" << endl;
	cout << "\t---                 ҩ�����ϵͳ                   ---" << endl;
	cout << "\t-                     ҩ���޸�                       -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t--�޸�����:                                          -" << endl;
	cout << "\t- 1.ҩ������                                         -" << endl;
	cout << "\t- 2.ҩ��۸�                                         -" << endl;
	cout << "\t- 3.ҩ�����                                         -" << endl;
	cout << "\t- 0.����                                             -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	input();
}

void MedicienChangePanel::input() {
	int in, id;
	cout << "\t������ѡ��";
	cin >> in;
	cout << "\t������ҩ��Id:";
	cin >> id;
	switch (in)
	{
	case 1:
	{
		string name;
		cout << "\t���������ƣ�" << endl;
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
		cout << "\t������۸�" << endl;
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
		cout << "\t��������ࣺ1.����ҩ 2.�Ǵ���ҩ 3.����Ʒ" << endl;
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
		cout << "\t���벻�Ϸ�!" << endl;
		system("pause");
		break;
	}
}
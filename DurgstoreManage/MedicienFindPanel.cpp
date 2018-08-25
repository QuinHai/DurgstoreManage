#include "MedicienFindPanel.h"


MedicienFindPanel* MedicienFindPanel::instance = new MedicienFindPanel();

void MedicienFindPanel::showPanel() {
	system("cls");

	cout << "\t------------------------------------------------------" << endl;
	cout << "\t---                 ҩ�����ϵͳ                   ---" << endl;
	cout << "\t-                     ҩ�����                       -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t- 1.ҩ��id����                                       -" << endl;
	cout << "\t- 2.ҩ�����Ʋ���                                     -" << endl;
	cout << "\t- 0.����                                             -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	input();
}

void MedicienFindPanel::input() {
	int in;
	cout << "\t������ѡ��";
	cin >> in;
	switch (in)
	{
	case 1:
		cout << "\t������id:";
		cin >> in;
		MedicienCheckPanel::getInstance()->clearList();
		for (map<int, Medicien>::iterator it = Utils::mediciens.begin(); it != Utils::mediciens.end(); it++) {
			if (it->first == in) {
				MedicienCheckPanel::getInstance()->addMedicien(it->second);
			}
		}
		Panel::addPanel(MedicienCheckPanel::getInstance());
		break;
	case 2:
	{
		cout << "\t������ҩ������:";
		string name;
		cin >> name;
		MedicienCheckPanel::getInstance()->clearList();//�����ʾ�б�
		//����ʾ�б������Ҫ��ʾ��ҩ��
		for (map<int, Medicien>::iterator it = Utils::mediciens.begin(); it != Utils::mediciens.end(); it++) {
			if (it->second.getName() == name) {
				MedicienCheckPanel::getInstance()->addMedicien(it->second);
			}
		}
		Panel::addPanel(MedicienCheckPanel::getInstance());
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

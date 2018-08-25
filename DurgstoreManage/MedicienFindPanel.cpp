#include "MedicienFindPanel.h"


MedicienFindPanel* MedicienFindPanel::instance = new MedicienFindPanel();

void MedicienFindPanel::showPanel() {
	system("cls");

	cout << "\t------------------------------------------------------" << endl;
	cout << "\t---                 药店管理系统                   ---" << endl;
	cout << "\t-                     药物查找                       -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t- 1.药物id查找                                       -" << endl;
	cout << "\t- 2.药物名称查找                                     -" << endl;
	cout << "\t- 0.返回                                             -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	input();
}

void MedicienFindPanel::input() {
	int in;
	cout << "\t请输入选择：";
	cin >> in;
	switch (in)
	{
	case 1:
		cout << "\t请输入id:";
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
		cout << "\t请输入药物名称:";
		string name;
		cin >> name;
		MedicienCheckPanel::getInstance()->clearList();//清空显示列表
		//向显示列表中添加要显示的药物
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
		cout << "\t输入不合法!" << endl;
		system("pause");
		break;
	}
}

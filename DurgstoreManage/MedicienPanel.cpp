#include "MedicienPanel.h"
#include "MedicienCheckPanel.h"
#include "MedicienFindPanel.h"
#include "MedicienChangePanel.h"
#include "Utils.h"
#include "Medicien.h"

#include <map>
using std::map;


MedicienPanel* MedicienPanel::instance = new MedicienPanel();
 
void MedicienPanel::showPanel(){
	system("cls");

	cout << "\t------------------------------------------------------" << endl;
	cout << "\t---                 药店管理系统                   ---" << endl;
	cout << "\t-                     药物管理                       -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t- 1.查看所有药物                                     -" << endl;
	cout << "\t- 2.查找药物                                         -" << endl;
	cout << "\t- 3.添加新药                                         -" << endl;
	cout << "\t- 4.删除药物                                         -" << endl;
	cout << "\t- 5.更改药物                                         -" << endl;
	cout << "\t- 0.返回                                             -" << endl;
	cout << "\t------------------------------------------------------" << endl;

	input();
}

void MedicienPanel::input() {
	int in;
	cout << "\t请输入选择：";
	cin >> in;
	switch (in)
	{
	case 1:
	{
		vector<Medicien> list;
		for (map<int, Medicien>::iterator it = Utils::mediciens.begin(); it != Utils::mediciens.end(); it++) {
			list.push_back(it->second);
		}
		MedicienCheckPanel::getInstance()->clearList();
		MedicienCheckPanel::getInstance()->addList(list);
		Panel::addPanel(MedicienCheckPanel::getInstance());
		break;
	}
	case 2:
		Panel::addPanel(MedicienFindPanel::getInstance());
		break;
	case 3:
	{
		string name;
		double price;
		int c;
		int inventory;
		cout << "\t输入药物名称：";
		cin >> name;
		cout << "\t输入药物价格：";
		cin >> price;
		cout << "\t输入药物分类：1.处方药 2.非处方药 3.保健品" << endl;
		cin >> c;
		cout << "\t输入库存：";
		cin >> inventory;
		Medicien m(name, price, (Category)c, inventory);

		Utils::mediciens.insert(pair<int, Medicien>(m.getId(), m));
		try
		{
			Utils::UpdateMedicienFile();
			MedicienCheckPanel::getInstance()->clearList();
			MedicienCheckPanel::getInstance()->addMedicien(m);
			Panel::addPanel(MedicienCheckPanel::getInstance());
		}
		catch (string s) {
			cout << s << endl;
			system("pause");
		}
		break;
	}
	case 4:
		cout << "\t请输入药物id:";
		cin >> in;
		Utils::mediciens.erase(in);
		try {
			Utils::UpdateMedicienFile();
		}
		catch (string s) {
			cout << s << endl;
			system("pause");
		}
		break;
	case 5:
		Panel::addPanel(MedicienChangePanel::getInstance());
		break;
	case 0:
		Panel::removePanel();
		break;
	default:
		cout << "\t输入不合法!" << endl;
		system("pause");
		break;
	}
}
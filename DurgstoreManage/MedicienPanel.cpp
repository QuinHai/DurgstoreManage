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
	cout << "\t---                 ҩ�����ϵͳ                   ---" << endl;
	cout << "\t-                     ҩ�����                       -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t- 1.�鿴����ҩ��                                     -" << endl;
	cout << "\t- 2.����ҩ��                                         -" << endl;
	cout << "\t- 3.�����ҩ                                         -" << endl;
	cout << "\t- 4.ɾ��ҩ��                                         -" << endl;
	cout << "\t- 5.����ҩ��                                         -" << endl;
	cout << "\t- 0.����                                             -" << endl;
	cout << "\t------------------------------------------------------" << endl;

	input();
}

void MedicienPanel::input() {
	int in;
	cout << "\t������ѡ��";
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
		cout << "\t����ҩ�����ƣ�";
		cin >> name;
		cout << "\t����ҩ��۸�";
		cin >> price;
		cout << "\t����ҩ����ࣺ1.����ҩ 2.�Ǵ���ҩ 3.����Ʒ" << endl;
		cin >> c;
		cout << "\t�����棺";
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
		cout << "\t������ҩ��id:";
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
		cout << "\t���벻�Ϸ�!" << endl;
		system("pause");
		break;
	}
}
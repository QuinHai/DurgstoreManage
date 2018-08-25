#include "MedicienCheckPanel.h"


MedicienCheckPanel * MedicienCheckPanel::instance = new MedicienCheckPanel();

void MedicienCheckPanel::showPanel() {
	system("cls");

	cout << "\t------------------------------------------------------" << endl;
	cout << "\t---                 ҩ�����ϵͳ                   ---" << endl;
	cout << "\t-                     ҩ��鿴                       -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << "\t-ע��ҩ�����: 1.����ҩ 2.�Ǵ���ҩ 3.����Ʒ          -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << endl;
	cout << "\tID\tҩ������\tҩ��۸�\tҩ�����\tҩ����" << endl;
	for (vector<Medicien>::iterator it = medicienList.begin(); it != medicienList.end(); it++) {
		string str = it->toString();
		for (unsigned int i = 0; i < str.size(); i++) {
			if (str[i] == ' ')
				str[i] = '\t';
		}
		cout << "\t" << str << endl;
	}
	cout << "\t------------------------------------------------------" << endl;
	cout << "\t- 0.����                                             -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	input();
}

void MedicienCheckPanel::input() {
	int in;
	cout << "\t������ѡ��";
	cin >> in;
	switch (in)
	{
	case 0:
		Panel::removePanel();
		break;
	default:
		cout << "\t���벻�Ϸ�!" << endl;
		system("pause");
		break;
	}
}
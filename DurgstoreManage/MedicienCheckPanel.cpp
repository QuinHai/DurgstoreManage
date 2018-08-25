#include "MedicienCheckPanel.h"


MedicienCheckPanel * MedicienCheckPanel::instance = new MedicienCheckPanel();

void MedicienCheckPanel::showPanel() {
	system("cls");

	cout << "\t------------------------------------------------------" << endl;
	cout << "\t---                 药店管理系统                   ---" << endl;
	cout << "\t-                     药物查看                       -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << "\t-注：药物分类: 1.处方药 2.非处方药 3.保健品          -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << endl;
	cout << "\tID\t药物名称\t药物价格\t药物分类\t药物库存" << endl;
	for (vector<Medicien>::iterator it = medicienList.begin(); it != medicienList.end(); it++) {
		string str = it->toString();
		for (unsigned int i = 0; i < str.size(); i++) {
			if (str[i] == ' ')
				str[i] = '\t';
		}
		cout << "\t" << str << endl;
	}
	cout << "\t------------------------------------------------------" << endl;
	cout << "\t- 0.返回                                             -" << endl;
	cout << "\t------------------------------------------------------" << endl;
	input();
}

void MedicienCheckPanel::input() {
	int in;
	cout << "\t请输入选择：";
	cin >> in;
	switch (in)
	{
	case 0:
		Panel::removePanel();
		break;
	default:
		cout << "\t输入不合法!" << endl;
		system("pause");
		break;
	}
}
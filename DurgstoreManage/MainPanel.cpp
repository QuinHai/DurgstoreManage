#include "MainPanel.h"
#include "MedicienPanel.h"
#include "OrderPanel.h"


MainPanel* MainPanel::instance = new MainPanel();

void MainPanel::showPanel(){
	system("cls");

	cout << "\t------------------------------------------------------" << endl;
	cout << "\t---                 ҩ�����ϵͳ                   ---" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t- 1.ҩ��������                                     -" << endl;
	cout << "\t- 2.�����������                                     -" << endl;
	cout << "\t- 0.�˳�                                             -" << endl;
	cout << "\t------------------------------------------------------" << endl;

	input();
}

void MainPanel::input(){
	int in;
	cout << "\t������ѡ��";
	cin >> in;
	switch (in)
	{
	case 1:
		Panel::addPanel(MedicienPanel::getInstance());
		break;
	case 2:
		Panel::addPanel(OrderPanel::getInstance());
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
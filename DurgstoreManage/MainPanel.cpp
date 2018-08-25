#include "MainPanel.h"
#include "MedicienPanel.h"
#include "OrderPanel.h"


MainPanel* MainPanel::instance = new MainPanel();

void MainPanel::showPanel(){
	system("cls");

	cout << "\t------------------------------------------------------" << endl;
	cout << "\t---                 药店管理系统                   ---" << endl;
	cout << "\t------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t- 1.药物管理界面                                     -" << endl;
	cout << "\t- 2.订单管理界面                                     -" << endl;
	cout << "\t- 0.退出                                             -" << endl;
	cout << "\t------------------------------------------------------" << endl;

	input();
}

void MainPanel::input(){
	int in;
	cout << "\t请输入选择：";
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
		cout << "\t输入不合法!" << endl;
		system("pause");
		break;
	}
}
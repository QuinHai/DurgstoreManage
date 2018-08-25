#include <iostream>
#include <iomanip>

#include "Utils.h"
#include "Panel.h"
#include "MainPanel.h"

using namespace std;

class MainSystem {
public:
	/*
		����������ǰ��ʼ��
	*/
	static void Init() {
		try {
			Utils::InitMedicienContainer();
			Utils::InitOrderContainer();
		}
		catch (string s) {
			cout << "��ʼ��ʧ��" << endl;
			cout << s << endl;
			system("pause");
			exit(0);
		}
		
		Panel::addPanel(MainPanel::getInstance());
	}

	/*
		��UIѭ��
	*/
	static void MainLoop() {
		try {
			Panel::show();
		}
		catch (...) {
			exit(0);
		}
	}

};

int main() {
	

	MainSystem::Init();
	while (true) {
		MainSystem::MainLoop();
	}
	return 0;
}
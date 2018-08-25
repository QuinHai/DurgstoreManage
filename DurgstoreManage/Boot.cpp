#include <iostream>
#include <iomanip>

#include "Utils.h"
#include "Panel.h"
#include "MainPanel.h"

using namespace std;

class MainSystem {
public:
	/*
		主程序运行前初始化
	*/
	static void Init() {
		try {
			Utils::InitMedicienContainer();
			Utils::InitOrderContainer();
		}
		catch (string s) {
			cout << "初始化失败" << endl;
			cout << s << endl;
			system("pause");
			exit(0);
		}
		
		Panel::addPanel(MainPanel::getInstance());
	}

	/*
		主UI循环
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
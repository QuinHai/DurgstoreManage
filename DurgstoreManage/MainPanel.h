#pragma once
#include "Panel.h"

class MainPanel :  public Panel {
private:
	static MainPanel * instance;//����ģʽ

private:
	MainPanel() {}

public:
	static MainPanel* getInstance() {
		return instance;
	}

	void showPanel();
private:
	void input();
};

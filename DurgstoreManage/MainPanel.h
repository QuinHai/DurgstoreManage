#pragma once
#include "Panel.h"

class MainPanel :  public Panel {
private:
	static MainPanel * instance;//µ¥ÀýÄ£Ê½

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

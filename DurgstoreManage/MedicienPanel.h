#pragma once
#include "Panel.h"

class Utils;
class MedicienChangePanel;
class MedicienFindPanel;
class MedicienCheckPanel;

class MedicienPanel : public Panel {
private:
	static MedicienPanel * instance;//µ¥ÀýÄ£Ê½
private:
	MedicienPanel() {}
	
public:
	static MedicienPanel * getInstance() {
		return instance;
	}
	void showPanel();

private:
	void input();
};


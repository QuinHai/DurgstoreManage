#pragma once

#include "Panel.h"
#include "Utils.h"
#include "MedicienCheckPanel.h"

class MedicienFindPanel :public Panel
{
private:
	static MedicienFindPanel * instance;//����ģʽ
private:
	MedicienFindPanel() {}
public:
	static MedicienFindPanel * getInstance() {
		return instance;
	}
	void showPanel();

private:
	void input();
};


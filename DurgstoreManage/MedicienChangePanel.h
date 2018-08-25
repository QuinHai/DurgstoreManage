#pragma once

#include "Panel.h"
#include <string>
using namespace std;

class Medicien;
class Utils;

class MedicienChangePanel : public Panel
{
private:
	static MedicienChangePanel * instance;
private:
	MedicienChangePanel() {}
public:
	static MedicienChangePanel* getInstance() {
		return instance;
	}

	void showPanel();

private:
	void input();
};


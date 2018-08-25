#pragma once
#include <vector>
#include "Panel.h"
#include "Medicien.h"
using namespace std;

class MedicienCheckPanel : public Panel
{
private:
	static MedicienCheckPanel * instance;//单例模式
	vector<Medicien> medicienList;//将要显示的药物列表
private:
	MedicienCheckPanel() {
		medicienList = vector<Medicien>();
	}
public:
	static MedicienCheckPanel * getInstance() {
		return instance;
	}

	/*
		清空显示列表
	*/
	 void clearList() {
		medicienList.clear();
	}

	/*
		向显示列表中添加
	*/
	 void addMedicien(Medicien &m) {
		medicienList.push_back(m);
	}

	/*
		添加显示列表
	*/
	 void addList(vector<Medicien> &v) {
		medicienList = vector<Medicien>(v);
	}
	 void showPanel();
	
private:
	void input();
};


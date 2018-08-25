#pragma once
#include <vector>
#include "Panel.h"
#include "Medicien.h"
using namespace std;

class MedicienCheckPanel : public Panel
{
private:
	static MedicienCheckPanel * instance;//����ģʽ
	vector<Medicien> medicienList;//��Ҫ��ʾ��ҩ���б�
private:
	MedicienCheckPanel() {
		medicienList = vector<Medicien>();
	}
public:
	static MedicienCheckPanel * getInstance() {
		return instance;
	}

	/*
		�����ʾ�б�
	*/
	 void clearList() {
		medicienList.clear();
	}

	/*
		����ʾ�б������
	*/
	 void addMedicien(Medicien &m) {
		medicienList.push_back(m);
	}

	/*
		�����ʾ�б�
	*/
	 void addList(vector<Medicien> &v) {
		medicienList = vector<Medicien>(v);
	}
	 void showPanel();
	
private:
	void input();
};


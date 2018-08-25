#pragma once

#include <map>
#include <ctime>
#include <fstream>
#include <string>
#include <cstdlib>

#include "Medicien.h"
#include "Order.h"
#include "Date.h"
using namespace std;

#define MEDICIEN_FILE "medicien.txt"
#define ORDER_FILE "order.txt"

class Medicien;
class Order;

class Utils {
private:
	static int Medicien_id;				//ҩ��id������
	static int Order_id;				//����id������

public:
	static map<int, Medicien> mediciens;	//ҩ������
	static map<int, Order> orders;		//��������

	/*
		����ҩ��id
	*/
	static int GetMedicienId() {
		return Medicien_id++;
	}

	/*
		���ɶ���id
	*/
	static int GetOrderId() {
		return Order_id++;
	}

	/*
		��ȡ��ǰʱ��
	*/
	static Date GetNow() {
		time_t timep;
		tm timeinfo; 
		time(&timep);
		localtime_s(&timeinfo, &timep);
		return Date(timeinfo);
	}

	/*
		��ҩ����Ϣ���浽�ļ�
	*/
	static void SaveMedicien(Medicien& m) {
		fstream out(MEDICIEN_FILE, ios::out | ios::app);
		if (out.fail()) {
			throw string("���浽�ļ�ʧ��");
		}
		else {
			out << m.toString() << endl;
		}
		out.close();
	}

	/*
		��������Ϣ���浽�ļ�
	*/
	static void SaveOrder(Order &o) {
		fstream out(ORDER_FILE, ios::out | ios::app);
		if (out.fail()) {
			throw string("���浽�ļ�ʧ��");
		}
		else {
			out << o.toString() << endl;
		}
		out.close();
	}

	/*
		���ļ����ݶ�ȡ��ҩ������
	*/
	static void InitMedicienContainer() {
		mediciens.clear();
		int initId = 10001;

		fstream in(MEDICIEN_FILE, ios::in);
		if (in.fail()) {
			throw string("���ļ�ʧ��");
		}
		else {
			while (!in.eof()) {
				string str;
				in >> str;
				if (str.empty() || in.eof())
					break;
				int id = atof(str.c_str());
				if (id > initId)//���ļ��е����ݶ�id���г�ʼ��
					initId = id;
				in >> str;
				string name = str;
				in >> str;
				double price = atof(str.c_str());
				in >> str;
				Category c = (Category)((int)atof(str.c_str()));
				in >> str;
				int inventory = atof(str.c_str());
				
				Medicien m(id, name, price, c, inventory);
				mediciens.insert(pair<int, Medicien>(m.getId(), m));
			}
			Medicien_id = initId++;
		}
		in.close();
	}

	/*
		���ļ����ݶ�ȡ����������
	*/
	static void InitOrderContainer() {
		orders.clear();
		int initId = 20001;

		fstream in(ORDER_FILE, ios::in);
		if (in.fail()) {
			throw string("���ļ�ʧ��");
		}
		else {
			while (!in.eof()) {
				map<int, int> mwc;
				string str;
				in >> str;
				if (str.empty() || in.eof())
					break;
				int id = atof(str.c_str());
				if (id > initId)//���ļ��е����ݶ�id���г�ʼ��
					initId = id;
				in >> str;
				bool isStock = true;
				if (str == "Sell")
					isStock = false;
				in >> str;
				double price = atof(str.c_str());
				in >> str;
				Date date(str);
				while (in.get() == ' ' ) {
					in >> str;
					int point = str.find(',');
					int id = atof(str.substr(0, point).c_str());
					int count = atof(str.substr(point+1).c_str());
					mwc.insert(pair<int, int >(id, count));
				}
				Order o(id, mwc, price, isStock, date);
				orders.insert(pair<int, Order>(id, o));
			}
			Order_id = initId++;
		}
		in.close();
	}

	/*
		����Order.txt�ļ�
	*/
	static void UpdateOrderFile() {
		//����ļ�
		fstream out(ORDER_FILE, ios::out);
		out.close();
		//���������ݱ��浽�ļ�
		for (map<int, Order>::iterator it = orders.begin(); it != orders.end();it++) {
			Utils::SaveOrder(it->second);
		}
	}

	/*
	����Medicien.txt�ļ�
	*/
	static void UpdateMedicienFile() {
		//����ļ�
		fstream out(MEDICIEN_FILE, ios::out);
		out.close();
		//���������ݱ��浽�ļ�
		for (map<int, Medicien>::iterator it = mediciens.begin(); it != mediciens.end();it ++) {
			Utils::SaveMedicien(it->second);
		}
	}
};


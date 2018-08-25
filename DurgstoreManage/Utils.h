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
	static int Medicien_id;				//药物id生成器
	static int Order_id;				//订单id生成器

public:
	static map<int, Medicien> mediciens;	//药物容器
	static map<int, Order> orders;		//订单容器

	/*
		生成药物id
	*/
	static int GetMedicienId() {
		return Medicien_id++;
	}

	/*
		生成订单id
	*/
	static int GetOrderId() {
		return Order_id++;
	}

	/*
		获取当前时间
	*/
	static Date GetNow() {
		time_t timep;
		tm timeinfo; 
		time(&timep);
		localtime_s(&timeinfo, &timep);
		return Date(timeinfo);
	}

	/*
		将药物信息保存到文件
	*/
	static void SaveMedicien(Medicien& m) {
		fstream out(MEDICIEN_FILE, ios::out | ios::app);
		if (out.fail()) {
			throw string("保存到文件失败");
		}
		else {
			out << m.toString() << endl;
		}
		out.close();
	}

	/*
		将订单信息保存到文件
	*/
	static void SaveOrder(Order &o) {
		fstream out(ORDER_FILE, ios::out | ios::app);
		if (out.fail()) {
			throw string("保存到文件失败");
		}
		else {
			out << o.toString() << endl;
		}
		out.close();
	}

	/*
		将文件内容读取到药物容器
	*/
	static void InitMedicienContainer() {
		mediciens.clear();
		int initId = 10001;

		fstream in(MEDICIEN_FILE, ios::in);
		if (in.fail()) {
			throw string("打开文件失败");
		}
		else {
			while (!in.eof()) {
				string str;
				in >> str;
				if (str.empty() || in.eof())
					break;
				int id = atof(str.c_str());
				if (id > initId)//用文件中的数据对id进行初始化
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
		将文件内容读取到订单容器
	*/
	static void InitOrderContainer() {
		orders.clear();
		int initId = 20001;

		fstream in(ORDER_FILE, ios::in);
		if (in.fail()) {
			throw string("打开文件失败");
		}
		else {
			while (!in.eof()) {
				map<int, int> mwc;
				string str;
				in >> str;
				if (str.empty() || in.eof())
					break;
				int id = atof(str.c_str());
				if (id > initId)//用文件中的数据对id进行初始化
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
		更新Order.txt文件
	*/
	static void UpdateOrderFile() {
		//清空文件
		fstream out(ORDER_FILE, ios::out);
		out.close();
		//将容器内容保存到文件
		for (map<int, Order>::iterator it = orders.begin(); it != orders.end();it++) {
			Utils::SaveOrder(it->second);
		}
	}

	/*
	更新Medicien.txt文件
	*/
	static void UpdateMedicienFile() {
		//清空文件
		fstream out(MEDICIEN_FILE, ios::out);
		out.close();
		//将容器内容保存到文件
		for (map<int, Medicien>::iterator it = mediciens.begin(); it != mediciens.end();it ++) {
			Utils::SaveMedicien(it->second);
		}
	}
};


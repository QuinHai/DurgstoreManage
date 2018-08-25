#pragma once

#include <map>
#include "Date.h"

using std::map;

class Medicien;
class Utils;

class Order {
public:
	friend class OrderCheckPanel;
	friend class OrderFindPanel;
private:
	int id;				//����id
	map<int, int> mwc;	//MedicienId with count
	double price;		//�������
	bool isStock;		//�Ƿ����
	Date date;			//��������ʱ��
public:

	Order(){}
	Order(int id, map<int, int> mwc, double price, bool isStock, Date date); 
	Order(bool isStock, Date &date);

	/*
		��Ӷ�����
	*/
	void append(Medicien &m, int count); 

	/*
		�ύ����
	*/
	void update(); 

	/*
		ת��Ϊ�ַ���
	*/
	string toString();
};
#pragma once

#include<string>
using namespace std;

class Utils;

//ҩ�����
enum Category{
	RX,				//����ҩ
	OTC,			//�Ǵ���ҩ
	HEALTH_PRODUCT	//����Ʒ
};

class Medicien {
public:
	friend class Order;

private:
	int id;			//ҩ��id
	string name;	//ҩ������
	double price;	//�۸�
	Category category;	//����
	int inventory;	//�����
public:
	Medicien(){}
	Medicien(const Medicien &m);
	Medicien(int id, string name, double price, Category category, int inventory); 
	Medicien(string name, double price, Category category, int inventory = 0);

	string toString(); 

	
	//setter and getter
	int getId() const{
		return id;
	}

	int getPrice() const{
		return price;
	}

	string getName() const {
		return name;
	}

	void setName(string name) {
		this->name = name;
	}

	void setPrice(double price) {
		this->price = price;
	}

	void setCategory(Category c) {
		category = c;
	}
};
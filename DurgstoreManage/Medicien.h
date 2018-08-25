#pragma once

#include<string>
using namespace std;

class Utils;

//药物分类
enum Category{
	RX,				//处方药
	OTC,			//非处方药
	HEALTH_PRODUCT	//保健品
};

class Medicien {
public:
	friend class Order;

private:
	int id;			//药物id
	string name;	//药物名称
	double price;	//价格
	Category category;	//分类
	int inventory;	//库存量
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
#include "Medicien.h"

#include "Utils.h"

Medicien::Medicien(const Medicien &m): name(m.name) {
	this->id = m.id;
	this->price = m.price;
	this->category = m.category;
	this->inventory = m.inventory;
}

Medicien::Medicien(int id, string name, double price, Category category, int inventory) :name(name) {
	this->id = id;
	this->price = price;
	this->category = category;
	this->inventory = inventory;
}
Medicien::Medicien(string name, double price, Category category, int inventory) :name(name) {
	id = Utils::GetMedicienId();
	this->price = price;
	this->category = category;
	this->inventory = inventory;
}


string Medicien::toString() {
	string m;
	m.append(to_string(id));
	m.append(" ");
	m.append(name);
	m.append(" ");
	m.append(to_string(price));
	m.append(" ");
	m.append(to_string(category));
	m.append(" ");
	m.append(to_string(inventory));
	return m;
}
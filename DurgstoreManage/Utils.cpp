#include "Utils.h"
#include "Medicien.h"
#include "Order.h"

int Utils::Medicien_id = 10001;
int	Utils::Order_id = 20001;
map<int, Order> Utils::orders = map<int, Order>();
map<int, Medicien> Utils::mediciens = map<int, Medicien>();
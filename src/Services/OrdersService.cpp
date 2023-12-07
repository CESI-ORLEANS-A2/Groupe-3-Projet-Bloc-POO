#include "./OrdersService.h"

Groupe3ProjetBlocPOO::Services::OrderService::OrderService() {
	throw gcnew System::NotImplementedException();
}

Groupe3ProjetBlocPOO::Services::OrderService::OrderService(Database^ db) {
	__database = db;
}

Order^ Groupe3ProjetBlocPOO::Services::OrderService::getOrder(int id) {
	Request^ order = OrderRequestMapping::getOrder(id);
	Data::DataTable^ result = __database->runQuery(order);
	if (result->Rows->Count == 0) {
		return nullptr;
	}
	return gcnew Order(result->Rows[0]);
}

array<Order^>^ Groupe3ProjetBlocPOO::Services::OrderService::getOrders() {
	Request^ orders = OrderRequestMapping::getOrders();
	Data::DataTable^ result = __database->runQuery(orders);
	return Order::toArray(result->Rows);
}

array<Order^>^ Groupe3ProjetBlocPOO::Services::OrderService::getOrders(int limit) {
	Request^ orders = OrderRequestMapping::getOrders(limit);
	Data::DataTable^ result = __database->runQuery(orders);
	return Order::toArray(result->Rows);
}

Order^ Groupe3ProjetBlocPOO::Services::OrderService::addOrder(Order^ order) {
	Request^ request = OrderRequestMapping::addOrder(
		order->paymentDate(), order->creationDate(), order->deliveryDate(),
		order->amount(), order->paymentMethod());
	int result = __database->runScalar(request);
	return this->getOrder(Convert::ToInt32(result));
}

Order^ Groupe3ProjetBlocPOO::Services::OrderService::addOrder(DateTime^ paymentDay, DateTime^ emissionDate, DateTime^ deliveryDate, float cost, paymentType type) {
	Request^ request = OrderRequestMapping::addOrder(paymentDay, emissionDate, deliveryDate, cost, type);
	int result = __database->runScalar(request);
	return this->getOrder(Convert::ToInt32(result));
}

Order^ Groupe3ProjetBlocPOO::Services::OrderService::updateOrder(Order^ order) {
	Request^ request = OrderRequestMapping::updateOrder(
		order->id(), order->paymentDate(), order->creationDate(),
		order->deliveryDate(), order->amount(), order->paymentMethod());
	Data::DataTable^ result = __database->runQuery(request);
	return this->getOrder(order->id());
}

Order^ Groupe3ProjetBlocPOO::Services::OrderService::updateOrder(int id, DateTime^ paymentDay, DateTime^ emissionDate, DateTime^ deliveryDate, float cost, paymentType type) {
	Request^ request = OrderRequestMapping::updateOrder(id, paymentDay, emissionDate, deliveryDate, cost, type);
	Data::DataTable^ result = __database->runQuery(request);
	return this->getOrder(id);
}

Order^ Groupe3ProjetBlocPOO::Services::OrderService::removeOrder(Order^ order) {
	Request^ request = OrderRequestMapping::deleteOrder(order->id());
	Data::DataTable^ result = __database->runQuery(request);
	return order;
}

Order^ Groupe3ProjetBlocPOO::Services::OrderService::removeOrder(int id) {
	Order^ order = this->getOrder(id);
	Request^ request = OrderRequestMapping::deleteOrder(id);
	Data::DataTable^ result = __database->runQuery(request);
	return order;
}

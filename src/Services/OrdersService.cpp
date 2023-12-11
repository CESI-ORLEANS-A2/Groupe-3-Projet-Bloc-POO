#include "./OrdersService.h"

Groupe3ProjetBlocPOO::Services::OrderService::OrderService() {
	throw gcnew System::NotImplementedException();
}

Groupe3ProjetBlocPOO::Services::OrderService::OrderService(Database^ db) {
	__database = db;

	Dictionary<String^, String^>^ clientsSchema = gcnew Dictionary<String^, String^>();
	clientsSchema->Add("id", "INT PRIMARY KEY AUTO_INCREMENT");
	clientsSchema->Add("firstname", "VARCHAR(100)");
	clientsSchema->Add("lastname", "VARCHAR(100)");
	clientsSchema->Add("phone", "VARCHAR(30)");
	clientsSchema->Add("email", "VARCHAR(100)");
	clientsSchema->Add("birthdate", "VARCHAR(100)");
	clientsSchema->Add("logo", "VARCHAR(255)");
	clientsSchema->Add("company", "VARCHAR(100)");
	this->__database->createTable("clients", clientsSchema);

	Dictionary<String^, String^>^ countriesSchema = gcnew Dictionary<String^, String^>();
	countriesSchema->Add("id", "INT PRIMARY KEY AUTO_INCREMENT");
	countriesSchema->Add("name", "VARCHAR(100)");
	this->__database->createTable("countries", countriesSchema);

	Dictionary<String^, String^>^ citiesSchema = gcnew Dictionary<String^, String^>();
	citiesSchema->Add("id", "INT PRIMARY KEY AUTO_INCREMENT");
	citiesSchema->Add("name", "VARCHAR(100)");
	citiesSchema->Add("country_id", "INT NOT NULL, FOREIGN KEY (country_id) REFERENCES countries(id)");
	this->__database->createTable("cities", citiesSchema);

	Dictionary<String^, String^>^ addressesSchema = gcnew Dictionary<String^, String^>();
	addressesSchema->Add("id", "INT PRIMARY KEY AUTO_INCREMENT");
	addressesSchema->Add("client_id", "INT, FOREIGN KEY (client_id) REFERENCES clients(id)");
	addressesSchema->Add("number", "VARCHAR(10)");
	addressesSchema->Add("street", "VARCHAR(100)");
	addressesSchema->Add("city_id", "INT NOT NULL, FOREIGN KEY (city_id) REFERENCES cities(id)");
	addressesSchema->Add("zip", "INT NOT NULL");
	this->__database->createTable("addresses", addressesSchema);

	Dictionary<String^, String^>^ ordersSchema = gcnew Dictionary<String^, String^>();
	ordersSchema->Add("id", "INT PRIMARY KEY AUTO_INCREMENT");
	ordersSchema->Add("paymentDate", "VARCHAR(50)");
	ordersSchema->Add("creationDate", "VARCHAR(50)");
	ordersSchema->Add("deliveryDate", "VARCHAR(50)");
	ordersSchema->Add("amount", "FLOAT");
	ordersSchema->Add("paymentMethod", "VARCHAR(50)");
	ordersSchema->Add("billingAddress", "INT NOT NULL, FOREIGN KEY (billingAddress) REFERENCES addresses(id)");
	ordersSchema->Add("deliveryAddress", "INT NOT NULL, FOREIGN KEY (deliveryAddress) REFERENCES addresses(id)");
	ordersSchema->Add("customer", "INT NOT NULL, FOREIGN KEY (customer) REFERENCES clients(id)");
	this->__database->createTable("orders", ordersSchema);

	Dictionary<String^, String^>^ productTypeSchema = gcnew Dictionary<String^, String^>();
	productTypeSchema->Add("productType", "INT PRIMARY KEY");
	productTypeSchema->Add("name", "VARCHAR(100)");
	productTypeSchema->Add("rateTVA", "INT NOT NULL");
	this->__database->createTable("ProductType", productTypeSchema);

	Dictionary<String^, String^>^ productSchema = gcnew Dictionary<String^, String^>();
	productSchema->Add("id", "INT PRIMARY KEY AUTO_INCREMENT");
	productSchema->Add("name", "VARCHAR(100)");
	productSchema->Add("description", "VARCHAR(100)");
	productSchema->Add("cost", "FLOAT NOT NULL");
	productSchema->Add("quantity", "INT NOT NULL");
	productSchema->Add("productType ", "INT NOT NULL, FOREIGN KEY (productType) REFERENCES productType(productType) ");
	this->__database->createTable("Product", productSchema);

	Dictionary<String^, String^>^ productsInOrderSchema = gcnew Dictionary<String^, String^>();
	productsInOrderSchema->Add("orderId", "INT NOT NULL, FOREIGN KEY (orderId) REFERENCES orders(id)");
	productsInOrderSchema->Add("productId", "INT NOT NULL, FOREIGN KEY (productId) REFERENCES Product(id)");
	productsInOrderSchema->Add("quantity", "INT, PRIMARY KEY(orderId, productId)");
	this->__database->createTable("productsInOrder", productsInOrderSchema);
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
	Data::DataTable^ result = this->__database->runQuery(orders);
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
		order->amount(), order->paymentMethod(), order->deliveryAddress(), order->billingAddress(), order->customer());
	Object^ result = __database->runScalar(request);
	return this->getOrder(Convert::ToInt32(result));
}

Order^ Groupe3ProjetBlocPOO::Services::OrderService::addOrder(String^ paymentDay, String^ emissionDate, String^ deliveryDate, float cost, String^ type, int deliveryAddress, int billingAddress, int customer) {
	Request^ request = OrderRequestMapping::addOrder(paymentDay, emissionDate, deliveryDate, cost, type, deliveryAddress, billingAddress, customer);
	Object^ result = __database->runScalar(request);
	return this->getOrder(Convert::ToInt32(result));
}

Order^ Groupe3ProjetBlocPOO::Services::OrderService::updateOrder(Order^ order) {
	Request^ request = OrderRequestMapping::updateOrder(
		order->id(), order->paymentDate(), order->creationDate(),
		order->deliveryDate(), order->amount(), order->paymentMethod());
	__database->runScalar(request);
	return order;
}

Order^ Groupe3ProjetBlocPOO::Services::OrderService::updateOrder(int id, String^ paymentDay, String^ emissionDate, String^ deliveryDate, float cost, String^ type) {
	Request^ request = OrderRequestMapping::updateOrder(id, paymentDay, emissionDate, deliveryDate, cost, type);
	__database->runScalar(request);
	Order^ order = gcnew Order(id);
	order->paymentDate(paymentDay);
	order->creationDate(emissionDate);
	order->deliveryDate(deliveryDate);
	order->amount(cost);
	order->paymentDate(type);
	return order;
}

Order^ Groupe3ProjetBlocPOO::Services::OrderService::removeOrder(Order^ order) {
	Request^ request = OrderRequestMapping::deleteOrder(order->id());
	__database->runScalar(request);
	return order;
}

Order^ Groupe3ProjetBlocPOO::Services::OrderService::removeOrder(int id) {
	Order^ order = this->getOrder(id);
	Request^ request = OrderRequestMapping::deleteOrder(id);
	__database->runScalar(request);
	return order;
}

void Groupe3ProjetBlocPOO::Services::OrderService::linkProductToOrder(int orderId, int productId, int quantity) {
	Request^ request = OrderRequestMapping::linkProductToOrder(orderId, productId, quantity);
	this->__database->runScalar(request);
}
void Groupe3ProjetBlocPOO::Services::OrderService::unlinkProductToOrder(int orderId, int productId) {
	Request^ request = OrderRequestMapping::unlinkProductToOrder(orderId, productId);
	this->__database->runScalar(request);
}
void Groupe3ProjetBlocPOO::Services::OrderService::updateProductToOrder(int orderId, int productId, int quantity) {
	Request^ request = OrderRequestMapping::updateProductToOrder(orderId, productId, quantity);
	this->__database->runScalar(request);
}

void Groupe3ProjetBlocPOO::Services::OrderService::cleanAddresses() {
	Request^ request = AddressRequestMapping::cleanAddresses();
	this->__database->runScalar(request);
}
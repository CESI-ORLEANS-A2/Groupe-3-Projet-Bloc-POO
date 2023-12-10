#include "./OrderRequestMapping.h"

Request^ Groupe3ProjetBlocPOO::Components::Mapping::OrderRequestMapping::getOrders() {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "SELECT * FROM orders";
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::OrderRequestMapping::getOrders(int limit) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "SELECT * FROM orders LIMIT @limit";
	cmd->Parameters->AddWithValue("@limit", limit);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::OrderRequestMapping::getOrder(int id) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "SELECT * FROM orders WHERE id = @id";
	cmd->Parameters->AddWithValue("@id", id);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::OrderRequestMapping::addOrder(String^ paymentDay, String^ emissionDate, String^ deliveryDate, float amount, String^ type, int deliveryAddress, int billingAddress, int customer) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"INSERT INTO orders (paymentDate, creationDate, deliveryDate, amount, paymentMethod, deliveryAddress, billingAddress, customer) "
		"VALUES (@paymentDay, @emissionDate, @deliveryDate, @amount, @type, @deliveryAddress, @billingAddress, @customner)";
	cmd->Parameters->AddWithValue("@paymentDay", paymentDay);
	cmd->Parameters->AddWithValue("@emissionDate", emissionDate);
	cmd->Parameters->AddWithValue("@deliveryDate", deliveryDate);
	cmd->Parameters->AddWithValue("@amount", amount);
	cmd->Parameters->AddWithValue("@type", type);
	cmd->Parameters->AddWithValue("@deliveryAddress", deliveryAddress);
	cmd->Parameters->AddWithValue("@billingAddress", billingAddress);
	cmd->Parameters->AddWithValue("@customner", customer);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::OrderRequestMapping::updateOrder(int id, String^ paymentDay, String^ emissionDate, String^ deliveryDate, float cost, String^ type) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"UPDATE orders SET paymentDate = @paymentDay, creationDate = @emissionDate,"
		"deliveryDate = @deliveryDate, amount = @cost, paymentMethod = @type WHERE id = @id";
	cmd->Parameters->AddWithValue("@id", id);
	cmd->Parameters->AddWithValue("@paymentDay", paymentDay);
	cmd->Parameters->AddWithValue("@emissionDate", emissionDate);
	cmd->Parameters->AddWithValue("@deliveryDate", deliveryDate);
	cmd->Parameters->AddWithValue("@cost", cost);
	cmd->Parameters->AddWithValue("@type", type);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::OrderRequestMapping::deleteOrder(int id) {
	MySqlCommand^ cmd = gcnew MySqlCommand();

	cmd->CommandText =
		"DELETE FROM productsinorder WHERE orderId = @id;"
		"DELETE FROM orders WHERE id = @id";

	cmd->Parameters->AddWithValue("@id", id);

	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::OrderRequestMapping::linkProductToOrder(int orderId, int productId, int quantity) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "INSERT INTO productsinorder (orderId, productId, quantity) VALUES (@idOrder, @idProduct, @quantity)";
	cmd->Parameters->AddWithValue("@idOrder", orderId);
	cmd->Parameters->AddWithValue("@idProduct", productId);
	cmd->Parameters->AddWithValue("@quantity", quantity);
	return gcnew Request(cmd);
}
Request^ Groupe3ProjetBlocPOO::Components::Mapping::OrderRequestMapping::unlinkProductToOrder(int orderId, int productId) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "DELETE FROM productsinorder WHERE orderId = @idOrder AND productId = @idProduct";
	cmd->Parameters->AddWithValue("@idOrder", orderId);
	cmd->Parameters->AddWithValue("@idProduct", productId);
	return gcnew Request(cmd);
}
Request^ Groupe3ProjetBlocPOO::Components::Mapping::OrderRequestMapping::updateProductToOrder(int orderId, int productId, int quantity) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "UPDATE productsinorder SET quantity = @quantity WHERE orderId = @idOrder AND productId = @idProduct";
	cmd->Parameters->AddWithValue("@idOrder", orderId);
	cmd->Parameters->AddWithValue("@idProduct", productId);
	cmd->Parameters->AddWithValue("@quantity", quantity);
	return gcnew Request(cmd);
}
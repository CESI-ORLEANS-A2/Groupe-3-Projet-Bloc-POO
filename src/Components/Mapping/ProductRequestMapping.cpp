#include "./ProductRequestMapping.h"

Groupe3ProjetBlocPOO::Components::Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::getProducts() {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"SELECT * FROM Product "
		"JOIN ProductType "
		"	ON Product.productType = ProductType.productType";
	return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd);
}

Groupe3ProjetBlocPOO::Components::Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::getProducts(int rows) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"SELECT * FROM Product "
		"JOIN ProductType "
		"	ON Product.productType = ProductType.productType "
		"LIMIT @row";
	cmd->Parameters->AddWithValue("@row", rows);
	return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd);
}


Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::getOrderProducts() {
	try {
		MySqlCommand^ cmd = gcnew MySqlCommand();
		cmd->CommandText =
			"SELECT "
			"	Product.id, "
			"	Product.name, "
			"	Product.cost, "
			"	Product.quantity AS 'stock', "
			"	productType.name as 'type', "
			"	productType.rateTVA as 'tax', "
			"	0 AS 'quantity' "
			"FROM Product "
			"LEFT JOIN producttype "
			"	ON ProductType.productType = Product.productType "
			";";

		return gcnew Request(cmd);
	}
	catch (MySqlException^ ex)
	{
		MessageBox::Show("Error" + ex->Number + " has occurred: " + ex->Message,
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::getOrderProducts(int id) {
	try {
		MySqlCommand^ cmd = gcnew MySqlCommand();
		cmd->CommandText =
			"SELECT "
			"	Product.id, "
			"	Product.name, "
			"	Product.cost, "
			"	Product.quantity AS 'stock', "
			"	productType.name as 'type', "
			"	productType.rateTVA as 'tax', "
			"	IFNULL(productsinorder.quantity, 0) AS 'quantity' "
			"FROM Product "
			"LEFT JOIN productsinorder "
			"	ON Product.id = productsinorder.productId "
			"	AND productsinorder.orderId = @id "
			"LEFT JOIN producttype "
			"	ON ProductType.productType = Product.productType "
			"ORDER BY productsinorder.quantity DESC "
			";";

		cmd->Parameters->AddWithValue("@id", id);

		return gcnew Request(cmd);
	}
	catch (MySqlException^ ex)
	{
		MessageBox::Show("Error" + ex->Number + " has occurred: " + ex->Message,
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::addOrderProduct(int id, int quantity) {
	try {
		MySqlCommand^ cmd = gcnew MySqlCommand();
		cmd->CommandText = "INSERT INTO Product VALUES(id,quantity) WHERE id = @id";

		cmd->Parameters->AddWithValue("@id", id);
		cmd->Parameters->AddWithValue("@quantity", quantity);

		return gcnew Request(cmd);
	}
	catch (MySqlException^ ex)
	{
		MessageBox::Show("Error" + ex->Number + " has occurred: " + ex->Message,
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::deleteOrderProduct(int id) {
	try {
		MySqlCommand^ cmd = gcnew MySqlCommand();
		cmd->CommandText = "DELETE FROM Product WHERE id = @id";

		cmd->Parameters->AddWithValue("@id", id);

		return gcnew Request(cmd);
	}
	catch (MySqlException^ ex)
	{
		MessageBox::Show("Error" + ex->Number + " has occurred: " + ex->Message,
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

Groupe3ProjetBlocPOO::Components::Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::getProduct(int id) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "SELECT * FROM Product JOIN ProductType ON Product.productType= ProductType.productType WHERE id = @id";
	cmd->Parameters->AddWithValue("@id", id);
	return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd);
}

Groupe3ProjetBlocPOO::Components::Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::addProduct(String^ name, float cost, int quantity, int productType) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "INSERT INTO Product (name, cost, quantity, productType) VALUES(@name, @cost, @quantity, @productType)";
	cmd->Parameters->AddWithValue("@name", name);
	cmd->Parameters->AddWithValue("@cost", cost);
	cmd->Parameters->AddWithValue("@quantity", quantity);
	cmd->Parameters->AddWithValue("@productType", productType);
	return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd);

}

Groupe3ProjetBlocPOO::Components::Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::addProduct(String^ name, float cost) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "INSERT INTO Product VALUES(name,description,cost,quantity)";
	cmd->Parameters->AddWithValue("@name", name);
	cmd->Parameters->AddWithValue("@cost", cost);
	return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd);

}

Groupe3ProjetBlocPOO::Components::Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::updateProduct(int id, String^ name, float cost, int quantity, int productType) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "UPDATE product SET name = @name, cost = @cost, quantity = @quantity, productType = @productType WHERE id = @id;";
	cmd->Parameters->AddWithValue("@name", name);
	cmd->Parameters->AddWithValue("@cost", cost);
	cmd->Parameters->AddWithValue("@id", id);
	cmd->Parameters->AddWithValue("@quantity", quantity);
	cmd->Parameters->AddWithValue("@productType", productType);
	return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd);

}

Groupe3ProjetBlocPOO::Components::Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::deleteProduct(int id) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "DELETE FROM Product WHERE id = @id ";
	cmd->Parameters->AddWithValue("@id", id);
	return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd);

}
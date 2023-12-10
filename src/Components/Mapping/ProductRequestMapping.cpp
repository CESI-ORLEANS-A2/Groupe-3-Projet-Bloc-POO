#include "./ProductRequestMapping.h"

Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::getProducts() {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "SELECT id, name, quantity FROM Product";

	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::getProducts(int rows) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "SELECT id,name,quantity FROM Product LIMIT @row";

	cmd->Parameters->AddWithValue("@row", rows);

	return gcnew Request(cmd);

}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::getProduct(int id) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "SELECT id,name,quantity FROM Product WHERE id=@id";

	cmd->Parameters->AddWithValue("@id", id);

	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::addProduct(String^ name, float cost, int quantity) {
	try {
		MySqlCommand^ cmd = gcnew MySqlCommand();
		cmd->CommandText = "INSERT INTO Product (name, cost) VALUES (@name, @cost)";
		cmd->Parameters->AddWithValue("@name", name);
		cmd->Parameters->AddWithValue("@cost", cost);
		cmd->Parameters->AddWithValue("@quantity", quantity);

		return gcnew Request(cmd);
	}
	catch (MySqlException^ ex)
	{
		MessageBox::Show("Error" + ex->Number + " has occurred: " + ex->Message,
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::addProduct(String^ name, float cost) {
	try {
		MySqlCommand^ cmd = gcnew MySqlCommand();
		cmd->CommandText = "INSERT INTO Product (name, cost) VALUES (@name, @cost)";
		cmd->Parameters->AddWithValue("@name", name);
		cmd->Parameters->AddWithValue("@cost", cost);

		return gcnew Request(cmd);
	}
	catch (MySqlException^ ex)
	{
		MessageBox::Show("Error" + ex->Number + " has occurred: " + ex->Message,
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::updateProduct(int id, String^ name, float cost, int qunatity) {
	try {
		MySqlCommand^ cmd = gcnew MySqlCommand();
		cmd->CommandText = "UPDATE table SET name = @name, cost = @cost WHERE id = @id; ";
		cmd->Parameters->AddWithValue("@name", name);
		cmd->Parameters->AddWithValue("@cost", cost);
		cmd->Parameters->AddWithValue("@quantity", qunatity);
		cmd->Parameters->AddWithValue("@id", id);

		return gcnew Request(cmd);
	}
	catch (MySqlException^ ex)
	{
		MessageBox::Show("Error" + ex->Number + " has occurred: " + ex->Message,
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::deleteProduct(int id) {
	try {
		MySqlCommand^ cmd = gcnew MySqlCommand();
		cmd->CommandText = "DELETE FROM Product WHERE id =@id ";
		cmd->Parameters->AddWithValue("@id", id);

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
		cmd->CommandText =			"SELECT "			"	Product.id, "			"	Product.name, "			"	Product.cost, "			"	Product.quantity AS 'stock', "			"	productType.name as 'type', "			"	productType.rateTVA as 'tax', "			"	IFNULL(productsinorder.quantity, 0) AS 'quantity' "			"FROM Product "			"LEFT JOIN productsinorder "			"	ON Product.id = productsinorder.productId "			"	AND productsinorder.orderId = @id "			"LEFT JOIN producttype "			"	ON ProductType.productType = Product.productType "			"ORDER BY productsinorder.quantity DESC "			";";
		cmd->Parameters->AddWithValue("@id", id);

		return gcnew Request(cmd);
	}
	catch (MySqlException^ ex)
	{
		MessageBox::Show("Error" + ex->Number + " has occurred: " + ex->Message,
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::ProductRequestMapping::getOrderProducts() {
	try {
		MySqlCommand^ cmd = gcnew MySqlCommand();
		cmd->CommandText =			"SELECT "			"	Product.id, "			"	Product.name, "			"	Product.cost, "			"	Product.quantity AS 'stock', "			"	productType.name as 'type', "			"	productType.rateTVA as 'tax', "			"	0 AS 'quantity' "			"FROM Product "			"LEFT JOIN producttype "			"	ON ProductType.productType = Product.productType "			";";

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
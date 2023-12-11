#include "./ProductsService.h"

Groupe3ProjetBlocPOO::Services::ProductService::ProductService(Groupe3ProjetBlocPOO::Components::Database^ database) {

	this->__database = database;

	Dictionary<String^, String^>^ productTypeSchema = gcnew Dictionary<String^, String^>();
	productTypeSchema->Add("productType", "INT PRIMARY KEY AUTO_INCREMENT");
	productTypeSchema->Add("name", "VARCHAR(100)");
	productTypeSchema->Add("rateTVA", "INT NOT NULL");
	this->__database->createTable("ProductType", productTypeSchema);

	Dictionary<String^, String^>^ productSchema = gcnew Dictionary<String^, String^>();
	productSchema->Add("id", "INT PRIMARY KEY AUTO_INCREMENT");
	productSchema->Add("name", "VARCHAR(100)");
	productSchema->Add("description", "VARCHAR(100)");
	productSchema->Add("cost", "FLOAT NOT NULL");
	productSchema->Add("quantity", "INT NOT NULL");
	productSchema->Add("productType ", "INT NOT NULL, FOREIGN KEY(productType) REFERENCES ProductType(productType) ");
	this->__database->createTable("Product", productSchema);
}

Product^ ProductService::getProduct(int id)
{
	return gcnew Product(this->__database->runQuery(ProductRequestMapping::getProduct(id))->Rows[0]);
}

Product^ ProductService::getProduct(Product^ product)
{
	return gcnew Product(this->__database->runQuery(ProductRequestMapping::getProduct(product->id()))->Rows[0]);
}

array<Product^>^ ProductService::getProducts()
{
	Data::DataTable^ product = this->__database->runQuery(ProductRequestMapping::getProducts());
	return Product::toArray(product->Rows);
}

array<Product^>^ ProductService::getProducts(int rows)
{
	Data::DataTable^ product = this->__database->runQuery(ProductRequestMapping::getProducts(rows));
	return Product::toArray(product->Rows);
}

Product^ ProductService::addProduct(Product^ product) {
	if (product->id() > 0) {
		return this->updateProduct(product);
	}
	int id = Convert::ToInt32(this->__database->runScalar(ProductRequestMapping::addProduct(product->name(), product->cost(), product->quantity(), product->productType())));;
	return gcnew Product(id, product);
}

Product^ ProductService::addProduct(String^ name, float cost, int quantity, int productType) {
	int id = Convert::ToInt32(this->__database->runScalar(ProductRequestMapping::addProduct(name, cost, quantity, productType)));
	Product^ product = gcnew Product(id);
	product->name(name);
	product->quantity(quantity);
	product->cost(cost);
	return product;
}

Product^ Groupe3ProjetBlocPOO::Services::ProductService::addOrderProduct(int productId, int orderId)
{
	Windows::Forms::DataGridView^ dataGridView = gcnew Windows::Forms::DataGridView();
	Windows::Forms::DataGridViewRowCollection^ dataGridViewRowCollection = gcnew Windows::Forms::DataGridViewRowCollection(dataGridView);
	Windows::Forms::DataGridViewRow^ dataGridViewRow = gcnew Windows::Forms::DataGridViewRow();
	for (int i = 0; i < dataGridView->ColumnCount; i++) {
		if (dataGridView->Columns[i]->Name == "quantity") {
			for (int j = 0; dataGridViewRowCollection->Count; j++)
				if (Convert::ToInt32(dataGridViewRow->Cells[j]->Value) > 0) {
					int id = Convert::ToInt32(this->__database->runScalar(ProductRequestMapping::addOrderProduct(productId, orderId)));
					Product^ product = gcnew Product(id);
					return product;
				}
		}
	}
}
array<Product^>^ Groupe3ProjetBlocPOO::Services::ProductService::getOrderProducts(int orderId) {
	Data::DataTable^ product = this->__database->runQuery(ProductRequestMapping::getOrderProducts(orderId));
	return Product::toArray(product->Rows);
}

array<Product^>^ Groupe3ProjetBlocPOO::Services::ProductService::getOrderProducts() {
	Data::DataTable^ product = this->__database->runQuery(ProductRequestMapping::getOrderProducts());
	return Product::toArray(product->Rows);
}

Product^ ProductService::addProduct(String^ name, float cost) {
	int id = Convert::ToInt32(this->__database->runScalar(ProductRequestMapping::addProduct(name, cost)));
	Product^ product = gcnew Product(id);
	product->name(name);
	product->cost(cost);
	return product;
}

Product^ ProductService::updateProduct(Product^ product) {
	int id = Convert::ToInt32(this->__database->runScalar(ProductRequestMapping::updateProduct(product->id(), product->name(), product->cost(), product->quantity(), product->productType())));
	return gcnew Product(this->__database->runQuery(ProductRequestMapping::getProduct(product->id()))->Rows[0]);
}

Product^ ProductService::updateProduct(int id, String^ name/*, String^ description*/, float cost, int stock, int productType) {
	this->__database->runQuery(ProductRequestMapping::updateProduct(id, name, cost, stock, productType))->Rows[0];
	return gcnew Product(this->__database->runQuery(ProductRequestMapping::getProduct(id))->Rows[0]);
}

Product^ ProductService::removeProduct(Product^ product) {
	Product^ newProduct = gcnew Product(this->__database->runQuery(ProductRequestMapping::deleteProduct(product->id()))->Rows[0]);
	return newProduct;
}

Product^ ProductService::removeProduct(int id) {
	Product^ product = gcnew Product(this->__database->runQuery(ProductRequestMapping::getProduct(id))->Rows[0]);
	this->__database->runQuery(ProductRequestMapping::deleteProduct(id));
	return product;
}

Product^ Groupe3ProjetBlocPOO::Services::ProductService::removeOrderProduct(int id)
{
	Product^ product = gcnew Product(this->__database->runQuery(ProductRequestMapping::getOrderProducts(id))->Rows[0]);
	this->__database->runScalar(ProductRequestMapping::deleteOrderProduct(id));
	return product;
}

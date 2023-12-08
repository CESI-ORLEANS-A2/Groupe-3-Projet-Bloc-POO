#include "./ProductsService.h"


ProductService::ProductService(Database^database) {

	this->__database = database;

	Dictionary<String^, String^>^ productSchema = gcnew Dictionary<String^, String^>();
	productSchema->Add("id", "INT PRIMARY KEY AUTO_INCREMENT");
	productSchema->Add("name", "VARCHAR(100)");
	productSchema->Add("description", "VARCHAR(100)");
	productSchema->Add("cost", "FLOAT NOT NULL");
	productSchema->Add("quantity", "INT NOT NULL");
	this->__database->createTable("product", productSchema);

	Dictionary<String^, String^>^ productTypeSchema = gcnew Dictionary<String^, String^>();
	productSchema->Add("productType", "VARCHAR(100) PRIMARY KEY AUTO_INCREMENT");
	productSchema->Add("rateTVA", "INT NOT NULL");
	this->__database->createTable("productType", productTypeSchema);
}

Product^ ProductService::viewProduct(int id)
{
	return gcnew Product(this->__database->runQuery(ProductRequestMapping::getProduct(id))->Rows[0]);
}

Product^ ProductService::viewProduct(Product^product)
{
	return gcnew Product(this->__database->runQuery(ProductRequestMapping::getProduct(product->id()))->Rows[0]);
}

array<Product^>^ ProductService::viewProducts()
{
	Data::DataTable^ product = this->__database->runQuery(ProductRequestMapping::getProducts());
	return Product::toArray(product->Rows);
}

array<Product^>^ ProductService::viewProducts(int rows)
{
	Data::DataTable^ product = this->__database->runQuery(ProductRequestMapping::getProducts(rows));
	return Product::toArray(product->Rows);
}

Product^ ProductService::addProduct(Product^product) {
	int id = Convert::ToInt32(this->__database->runScalar(ProductRequestMapping::addProduct(product->name(), product->description(), product->cost(),product->quantity())));;
	return gcnew Product(id,product);
}

Product^ ProductService::addProduct(String^name, String^description, float cost, int quantity){
	int id = Convert::ToInt32(this->__database->runScalar(ProductRequestMapping::addProduct(name,description, cost,quantity)));
	Product^ product = gcnew Product(id);
	product->name(name);
	product->quantity(quantity);
	product->cost(cost);
	product->description(description);
	return product;
}

Product^ ProductService::addProduct(String^ name, String^ description, float cost) {
	int id = Convert::ToInt32(this->__database->runScalar(ProductRequestMapping::addProduct(name, description, cost)));
	Product^ product = gcnew Product(id);
	product->name(name);
	product->cost(cost);
	product->description(description);
	return product;
}


Product^ ProductService::updateProduct(Product^product) {
	this->__database->runQuery(ProductRequestMapping::updateProduct(product->id(),product->name(),product->description(),product->cost(),product->quantity()))->Rows[0];
	return gcnew Product(this->__database->runQuery(ProductRequestMapping::getProduct(product->id()))->Rows[0]);
}

Product^ ProductService::updateProduct(int id, String^ name, String^ description, float cost, int quantity) {
	this->__database->runQuery(ProductRequestMapping::updateProduct(id, name, description, cost, quantity))->Rows[0];
	return gcnew Product(this->__database->runQuery(ProductRequestMapping::getProduct(id))->Rows[0]);
}


Product^ ProductService::removeProduct(Product^product) {
	Product^ newProduct = gcnew Product(this->__database->runQuery(ProductRequestMapping::deleteProduct(product->id()))->Rows[0]);
	return newProduct;
}

Product^ ProductService::removeProduct(int id) {
	Product^product = gcnew Product(this->__database->runQuery(ProductRequestMapping::getProduct(id))->Rows[0]);
	this->__database->runQuery(ProductRequestMapping::deleteProduct(id));
	return product;
}
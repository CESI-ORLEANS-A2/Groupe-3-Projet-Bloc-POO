#include "./ProductsService.h"


ProductService::ProductService(Database^database) {
	this->__database = database;
}

Product^ ProductService::addProduct(Product^product) {
	int id = Convert::ToInt32(this->__database->runScalar(ProductRequestMapping::addProduct(product->name(), product->description(), product->cost(),product->quantity())));
	Product^ product = gcnew Product(id);
	product->name();
	product->quantity();
	product->cost();
	product->description();
	return product;

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
	Product^ product = gcnew Product(this->__database->runQuery(ProductRequestMapping::deleteProduct(product->id()))->Rows[0]);
	return product;
}

Product^ ProductService::removeProduct(int id) {
	Product^product = gcnew Product(this->__database->runQuery(ProductRequestMapping::getProduct(id))->Rows[0]);
	this->__database->runQuery(ProductRequestMapping::deleteProduct(id));
	return product;
}
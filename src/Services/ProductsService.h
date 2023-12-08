#pragma once

#include "../Components/Database.h"
#include "../Components/DataType/Product.h"
#include "../Components/Mapping/ProductRequestMapping.h"
#include "../Components/Request.h"

using namespace System;

ref class ProductService {
private :
		Database^ __database;
public :
	ProductService(Database^);
	Product^ viewProduct(int);
	Product^ viewProduct(Product^);
	array<Product^>^ viewProducts();
	array<Product^>^ viewProducts(int);;
	Product^ addProduct(Product^);
	Product^ addProduct(String^, String^, float);
	Product^ addProduct(String^, String^,float,int);
	Product^ updateProduct(Product^);
	Product^ updateProduct(int,String^, String^, float, int);
	Product^ removeProduct(Product^);
	Product^ removeProduct(int);
};
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
	Product^ getProduct(int);   
	Product^ getProduct(Product^); 
	array<Product^>^ getProducts(); 
	array<Product^>^ getProducts(int); 
	array<Product^>^ getOrderProducts(int,int); // a voir
	Product^ addProduct(Product^); 
	Product^ addProduct(String^, float);
	Product^ addProduct(String^,float,int);
	Product^ addOrderProduct(int, int);
	Product^ updateProduct(Product^);
	Product^ updateProduct(int,String^, String^, float, int);
	Product^ removeProduct(Product^);
	Product^ removeProduct(int);
	Product^ removeOrderProduct(int);
};
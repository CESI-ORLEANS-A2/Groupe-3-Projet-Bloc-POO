#include "../Request.h"
#include <string>
#pragma once
using namespace System;
ref class ProductRequestMapping {

public :
	static Request^ getProducts(int);
	static Request^ getProduct(int);
	static Request^ addProduct(String^, String^,float);
	static Request^ updateProduct(int,String^, String^, float);
	static Request^ deleteProduct(int);
};
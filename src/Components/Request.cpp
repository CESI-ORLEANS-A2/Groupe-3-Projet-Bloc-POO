#include "./Request.h"
using namespace System;

Request::Request(String^ sql) {
	this->__sql = sql;
}

String^ Request::sql(){
	return __sql;
}
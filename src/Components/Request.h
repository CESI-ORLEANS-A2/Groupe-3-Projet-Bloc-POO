#pragma once
using namespace System;

ref class Request {
public :
	Request(String^sql);
	String^ sql();
private :
	String^ __sql;
};
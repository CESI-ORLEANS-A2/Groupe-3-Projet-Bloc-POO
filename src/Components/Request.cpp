#include "./Request.h"

using namespace System;

Groupe3ProjetBlocPOO::Components::Request::Request(String^ sql) {
	this->__sql = sql;
}
Groupe3ProjetBlocPOO::Components::Request::Request(MySqlCommand^ cmd) {
	this->__mySqlCmd = cmd;
}

String^ Groupe3ProjetBlocPOO::Components::Request::sql() {
	return this->__sql;
}
MySqlCommand^ Groupe3ProjetBlocPOO::Components::Request::mySqlCmd() {
	return this->__mySqlCmd;
}
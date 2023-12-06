#include "./Request.h"

using namespace System;

Groupe3ProjetBlocPOO::Components::Request::Request(String^ sql) {
	this->__sql = sql;
}
Groupe3ProjetBlocPOO::Components::Request::Request(MySqlCommand^ cmd) : Request(cmd->ToString()) { }

String^ Groupe3ProjetBlocPOO::Components::Request::sql() {
	return __sql;
}
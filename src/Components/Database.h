#pragma once
#include "./Request.h"
using namespace std;
using namespace MySql::Data::MySqlClient;
using namespace System;
ref class Database {
private :
	MySqlConnection^ __connection;
public :
	Data::DataSet^ runQuery(Request^);
	Object^ runScalar(Request^);
};
#pragma once
#include "./Request.h"
using namespace std;
using namespace MySql::Data::MySqlClient;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
ref class Database {
private :
	MySqlConnection^ __connection;
public :
	Database();
	void createTable(String^, Dictionary<String^, String^>^schema);
	Data::DataTable^ runQuery(Request^);
	Data::DataTable^ runQuery(String^ query);
	Object^ runScalar(String^ query);
	Object^ runScalar(Request^);
};



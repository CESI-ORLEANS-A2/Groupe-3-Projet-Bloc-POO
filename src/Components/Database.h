#pragma once

#include "./Request.h"

using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

namespace Groupe3ProjetBlocPOO {
	namespace Components {
		public ref class Database {
		private:
			MySqlConnection^ __connection;
		public:
			Database(String^ connectionString);
			Database(String^ server, String^ username, String^ password);
			void createTable(String^, Dictionary<String^, String^>^ schema);
			Data::DataTable^ runQuery(Request^);
			Data::DataTable^ runQuery(String^ query);
			Object^ runScalar(String^ query);
			Object^ runScalar(Request^);
			Object^ runScalarData(Request^ query);
			bool testConnection(void);
		};
	}
}

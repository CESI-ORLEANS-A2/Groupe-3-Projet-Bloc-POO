#pragma once

#include "./Request.h"

using namespace System::Collections::Generic;

namespace Groupe3ProjetBlocPOO {
	namespace Components {
		public ref class Database {
		private:
			MySqlConnection^ __connection;
		public:
			Database();
			void createTable(String^, Dictionary<String^, String^>^ schema);
			Data::DataTable^ runQuery(Request^);
			Data::DataTable^ runQuery(String^ query);
			Object^ runScalar(String^ query);
			Object^ runScalar(Request^);
		};
	}
}
#include "./Database.h"

Groupe3ProjetBlocPOO::Components::Database::Database(String^ connectionString) {
	this->__connection = gcnew MySqlConnection(connectionString);

	try {
		this->__connection->Open();
	}
	catch (MySql::Data::MySqlClient::MySqlException^ ex) {
		MessageBox::Show("Error" + ex->Number + " has occurred: " + ex->Message,
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
DataTable^ Groupe3ProjetBlocPOO::Components::Database::runQuery(String^ query) {
	Data::DataSet^ dataset = gcnew DataSet();
	MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
	adapter->SelectCommand = gcnew MySqlCommand(query, this->__connection);
	adapter->Fill(dataset, "result");
	return dataset->Tables["result"];
}

DataTable^ Groupe3ProjetBlocPOO::Components::Database::runQuery(Request^ query) {
	Data::DataSet^ dataset = gcnew DataSet();
	MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
	adapter->SelectCommand = query->mySqlCmd();
	adapter->SelectCommand->Connection = this->__connection;
	adapter->Fill(dataset, "result");
	return dataset->Tables["result"];

}
Object^ Groupe3ProjetBlocPOO::Components::Database::runScalar(String^ query) {
	MySqlCommand^ cmd = gcnew MySqlCommand(query, this->__connection);
	cmd->CommandText += "; SELECT LAST_INSERT_ID();";
	Object^ result = cmd->ExecuteScalar();
	return result;
}
Object^ Groupe3ProjetBlocPOO::Components::Database::runScalar(Request^ query) {
	MySqlCommand^ cmd = query->mySqlCmd();
	cmd->Connection = this->__connection;
	return cmd->ExecuteScalar();
}

void Groupe3ProjetBlocPOO::Components::Database::createTable(String^ table, Dictionary<String^, String^>^ schema) {
	String^ query = "CREATE TABLE IF NOT EXISTS " + table + " ( ";
	for each (KeyValuePair<String^, String^> ^ kvp in schema) {
		query += kvp->Key + " " + kvp->Value;
		query += ", ";
	}
	this->runScalar(query->Substring(0, query->Length - 2) + ")");
}
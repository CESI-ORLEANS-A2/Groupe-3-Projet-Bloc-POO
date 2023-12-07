#include "./Database.h"

Database::Database() {
    try
    {
        __connection = gcnew MySqlConnection();
    }
    catch  (MySql::Data::MySqlClient::MySqlException^ ex)
    {
        MessageBox::Show("Error" + ex->Number + " has occurred: " + ex->Message,
            "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
Data::DataTable^ Database::runQuery(String^ query) {
    Data::DataSet^ dataset;
    MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
    adapter->SelectCommand = gcnew MySqlCommand(query, __connection);
    adapter->Fill(dataset, "result");
    return dataset->Tables["result"];
}

Data::DataTable^ Database::runQuery(Request^query){
    return this->runQuery(query->ToString());
   
}
Object^ Database::runScalar(String^ query) {
    MySqlCommand^ cmd = gcnew MySqlCommand(query, __connection);
    Object^ result = cmd->ExecuteScalar();
    return result;
}
Object^ Database::runScalar(Request^ query){
    return this->runScalar(query->ToString()); 
}

void Database::createTable(String^table, Dictionary<String^, String^>^ schema) {
    String^ query = "CREATE TABLE IF NOT EXIST" + table + "(";
    for each(KeyValuePair<String^, String^>^ kvp in schema) {
        query += kvp->Key + "=" + kvp->Value;
        query += ",";
     }
    query += ")";
    this->runScalar(query);
}
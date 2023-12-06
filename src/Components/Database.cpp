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

Data::DataTable^ Database::runQuery(Request^query){
    String^ data= query->ToString();
    Data::DataSet^ dataset;
    MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
    adapter->SelectCommand = gcnew MySqlCommand(data,__connection);
    adapter->Fill(dataset,"result");
    return dataset->Tables["result"];
}
Object^ Database::runScalar(Request^query){
    String^ data = query->ToString();
    MySqlCommand^ cmd = gcnew MySqlCommand(data,__connection);
    Object^result = cmd->ExecuteScalar();
    return result;
}

void Database::createTable(String^table, Dictionary<String^, String^>^ schema) {
    String^ query = "CREATE TABLE IF NOT EXIST" + table + "(";
    for (int i; i < schema->Count; i++) {
        query += schema[Convert::ToString(i), Convert::ToString(0)];
     }
}
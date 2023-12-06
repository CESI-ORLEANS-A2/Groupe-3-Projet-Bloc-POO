#include "./Database.h"


Data::DataSet^ Database::runQuery(Request^query){
    String^ data= query->ToString();
    Data::DataSet^ table;
    __connection = gcnew MySqlConnection();
    MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
    adapter->SelectCommand = gcnew MySqlCommand(data,__connection);
    adapter->Fill(table);
    return table;
}
Object^ Database::runScalar(Request^query){
    String^ data = query->ToString();
    __connection = gcnew MySqlConnection();
    MySqlCommand^ cmd = gcnew MySqlCommand(data,__connection);
    Object^result = cmd->ExecuteScalar();
    return result;
}
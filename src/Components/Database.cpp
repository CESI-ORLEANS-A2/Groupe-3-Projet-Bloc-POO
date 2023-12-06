#include "./Database.h"


Data::DataSet^ Database::runQuery(Request^query){
    String^ data= query->ToString();
    MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter();
    adapter->SelectCommand = gcnew MySqlCommand(data);
    adapter->Fill(data);
    return data->table[];
}
Object^ Database::runScalar(Request^){}
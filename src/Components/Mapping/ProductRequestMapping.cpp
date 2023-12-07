#include "./ProductRequestMapping.h"


Request^ ProductRequestMapping::getProducts(int rows) {
    MySqlCommand^ cmd = gcnew MySqlCommand();
    cmd->CommandText = "SELECT id,name,quantity FROM Product LIMIT @row";
    cmd->Prepare();
    cmd->Parameters->AddWithValue("@row", rows);
    return gcnew Request(cmd->ToString());
    
}

Request^ ProductRequestMapping::getProduct(int id) {
    MySqlCommand^ cmd = gcnew MySqlCommand();
    cmd->CommandText = "SELECT id,name,quantity FROM Product WHERE id=@id";
    cmd->Prepare();
    cmd->Parameters->AddWithValue("@id", id);
    return gcnew Request(cmd->ToString());
}

Request^ ProductRequestMapping::addProduct(String^name, String^description, float cost,int quantity) {
    try {
        MySqlCommand^ cmd = gcnew MySqlCommand();
        cmd->CommandText = "INSERT INTO Product VALUES(name,description,cost,quantity)";
        cmd->Prepare();
        cmd->Parameters->AddWithValue("@name", name);
        cmd->Parameters->AddWithValue("@description", description);
        cmd->Parameters->AddWithValue("@cost", cost);
        cmd->Parameters->AddWithValue("@quantity", quantity);
        return gcnew Request(cmd->ToString());
    }
    catch (MySqlException^ ex)
    {
        MessageBox::Show("Error" + ex->Number + " has occurred: " + ex->Message,
            "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
Request^ ProductRequestMapping::addProduct(String^ name, String^ description, float cost) {
    try {
        MySqlCommand^ cmd = gcnew MySqlCommand();
        cmd->CommandText = "INSERT INTO Product VALUES(name,description,cost,quantity)";
        cmd->Prepare();
        cmd->Parameters->AddWithValue("@name", name);
        cmd->Parameters->AddWithValue("@description", description);
        cmd->Parameters->AddWithValue("@cost", cost);
        return gcnew Request(cmd->ToString());
    }
    catch (MySqlException^ ex)
    {
        MessageBox::Show("Error" + ex->Number + " has occurred: " + ex->Message,
            "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
Request^ ProductRequestMapping::updateProduct(int id,String^ name, String^ description, float cost,int quantity) {
    try {
        MySqlCommand^ cmd = gcnew MySqlCommand();
        cmd->CommandText = "UPDATE table SET name = @name, description = @description, cost = @cost, quantity = @quantity WHERE id = @id;";
        cmd->Prepare();
        cmd->Parameters->AddWithValue("@name", name);
        cmd->Parameters->AddWithValue("@description", description);
        cmd->Parameters->AddWithValue("@cost", cost);
        cmd->Parameters->AddWithValue("@id", id);
        cmd->Parameters->AddWithValue("@quantity", quantity);
        return gcnew Request(cmd->ToString());
    }
    catch (MySqlException^ ex)
    {
        MessageBox::Show("Error" + ex->Number + " has occurred: " + ex->Message,
            "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

Request^ ProductRequestMapping::deleteProduct(int id) {
    try {
        MySqlCommand^ cmd = gcnew MySqlCommand();
        cmd->CommandText = "DELETE FROM Product WHERE id =@id ";
        cmd->Prepare();
        cmd->Parameters->AddWithValue("@id",id);
        return gcnew Request(cmd->ToString());
    }
    catch (MySqlException^ ex)
    {
        MessageBox::Show("Error" + ex->Number + " has occurred: " + ex->Message,
            "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}
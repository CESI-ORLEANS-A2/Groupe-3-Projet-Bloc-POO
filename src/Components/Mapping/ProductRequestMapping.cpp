#include "./ProductRequestMapping.h"


Groupe3ProjetBlocPOO::Components::Request^ ProductRequestMapping::getProducts()
{
    MySqlCommand^ cmd = gcnew MySqlCommand();
    cmd->CommandText = "SELECT (id, FROM Product  JOIN ProductType ON Product.id = ProductType.productType";
    cmd->Prepare();
    return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd->ToString());
}

Groupe3ProjetBlocPOO::Components::Request^ ProductRequestMapping::getProducts(int rows) {
    MySqlCommand^ cmd = gcnew MySqlCommand();
    cmd->CommandText = "SELECT * FROM Product  JOIN ProductType ON Product.id = ProductType.productType LIMIT @row";
    cmd->Prepare();
    cmd->Parameters->AddWithValue("@row", rows);
    return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd->ToString());
    
}

Groupe3ProjetBlocPOO::Components::Request^ ProductRequestMapping::getOrderProducts(int limit,int id)
{
    MySqlCommand^ cmd = gcnew MySqlCommand();
    cmd->CommandText = "SELECT (id,name,cost,productInOrder.quantity,(product.quantity) AS stock) FROM Product LEFT JOIN (SELECT* FROM productsInOrder WHERE orderId = @orderId) ON productInOrder.id = Product.id LIMIT @limit";
    cmd->Prepare();
    cmd->Parameters->AddWithValue("@limit", limit);
    cmd->Parameters->AddWithValue("@orderId", id);
    return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd->ToString());
}

Groupe3ProjetBlocPOO::Components::Request^ ProductRequestMapping::getOrderProducts(int id)
{
    MySqlCommand^ cmd = gcnew MySqlCommand();
    cmd->CommandText = "SELECT (id,name,cost,productInOrder.quantity,product.quantity AS stock) FROM Product LEFT JOIN (SELECT* FROM productsInOrder WHERE orderId = @orderId) ON productInOrder.id = Product.id";
    cmd->Prepare();
    cmd->Parameters->AddWithValue("@orderId", id);
    return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd->ToString());
}




Groupe3ProjetBlocPOO::Components::Request^ ProductRequestMapping::getProduct(int id) {
    MySqlCommand^ cmd = gcnew MySqlCommand();
    cmd->CommandText = "SELECT * FROM Product JOIN ProductType ON Product.id = ProductType.productType WHERE id=@id";
    cmd->Prepare();
    cmd->Parameters->AddWithValue("@id", id);
    return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd->ToString());
}

Groupe3ProjetBlocPOO::Components::Request^ ProductRequestMapping::addTypeProduct(float rate)
{
    MySqlCommand^ cmd = gcnew MySqlCommand();
    cmd->CommandText = "INSERT INTO ProductType(rateTVA) VALUE (@rateTVA)";
    cmd->Prepare();
    cmd->Parameters->AddWithValue("@rateTVA", rate);
    return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd->ToString());
}

Groupe3ProjetBlocPOO::Components::Request^ ProductRequestMapping::addOrderProduct(int productId, int orderId)
{
        
        MySqlCommand^ cmd = gcnew MySqlCommand();
        cmd->CommandText = "INSERT INTO productsInOrder(orderId, productId, quantity) VALUE (@orderId, @productId)";
        cmd->Prepare();
        cmd->Parameters->AddWithValue("@orderId", orderId);
        cmd->Parameters->AddWithValue("@productId", productId);
        return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd->ToString());

   
}

Groupe3ProjetBlocPOO::Components::Request^ ProductRequestMapping::addProduct(String^name, float cost,int quantity) {
    
        MySqlCommand^ cmd = gcnew MySqlCommand();
        cmd->CommandText = "INSERT INTO Product VALUES(name,description,cost,quantity)";
        cmd->Prepare();
        cmd->Parameters->AddWithValue("@name", name);
        cmd->Parameters->AddWithValue("@cost", cost);
        cmd->Parameters->AddWithValue("@quantity", quantity);
        return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd->ToString());
    }
   

Groupe3ProjetBlocPOO::Components::Request^ ProductRequestMapping::addProduct(String^ name,  float cost) {
   
        MySqlCommand^ cmd = gcnew MySqlCommand();
        cmd->CommandText = "INSERT INTO Product VALUES(name,description,cost,quantity)";
        cmd->Prepare();
        cmd->Parameters->AddWithValue("@name", name);
        cmd->Parameters->AddWithValue("@cost", cost);
        return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd->ToString());
    
 
}
Groupe3ProjetBlocPOO::Components::Request^ ProductRequestMapping::updateProduct(int id,String^ name,  float cost,int quantity) {
    
        MySqlCommand^ cmd = gcnew MySqlCommand();
        cmd->CommandText = "UPDATE table SET name = @name, description = @description, cost = @cost, quantity = @quantity WHERE id = @id;";
        cmd->Prepare();
        cmd->Parameters->AddWithValue("@name", name);
        cmd->Parameters->AddWithValue("@cost", cost);
        cmd->Parameters->AddWithValue("@id", id);
        cmd->Parameters->AddWithValue("@quantity", quantity);
        return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd->ToString());

}

Groupe3ProjetBlocPOO::Components::Request^ ProductRequestMapping::deleteProduct(int id) {
    
        MySqlCommand^ cmd = gcnew MySqlCommand();
        cmd->CommandText = "DELETE FROM Product WHERE id =@id ";
        cmd->Prepare();
        cmd->Parameters->AddWithValue("@id",id);
        return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd->ToString());
   
}

Groupe3ProjetBlocPOO::Components::Request^ ProductRequestMapping::deleteOrderProduct(int id)
{
    
        MySqlCommand^ cmd = gcnew MySqlCommand();
        cmd->CommandText = "DELETE FROM productsInOrder WHERE orderId = @orderId";
        cmd->Prepare();
        cmd->Parameters->AddWithValue("@orderId", id);
        return gcnew Groupe3ProjetBlocPOO::Components::Request(cmd->ToString());
}

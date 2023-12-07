#include "./OrderRequestMapping.h"

Request^ Groupe3ProjetBlocPOO::Components::Mappings::OrderRequestMapping::getOrders(){
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "SELECT * FROM commande";
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mappings::OrderRequestMapping::getOrders(int limit){
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "SELECT * FROM commande LIMIT @limit";
	cmd->Parameters->AddWithValue("@limit", limit);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mappings::OrderRequestMapping::getOrder(int id){
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "SELECT * FROM commande WHERE IDCommande = @id";
	cmd->Parameters->AddWithValue("@id", id);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mappings::OrderRequestMapping::addOrder(DateTime^ paymentDay, DateTime^ emissionDate, DateTime^ deliveryDate, float cost, paymentType type){
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = 
"INSERT INTO commande (DatePaiement, DateEmission, DateLivraison, Montant, MoyenPaiement)"
		"VALUES(@paymentDay, @emissionDate, @deliveryDate, @cost, @type)";
	cmd->Parameters->AddWithValue("@paymentDay", paymentDay);
	cmd->Parameters->AddWithValue("@emissionDate", emissionDate);
	cmd->Parameters->AddWithValue("@deliveryDate", deliveryDate);
	cmd->Parameters->AddWithValue("@cost", cost);
	cmd->Parameters->AddWithValue("@type", type);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mappings::OrderRequestMapping::updateOrder(int id, DateTime^ paymentDay, DateTime^ emissionDate, DateTime^ deliveryDate, float cost, paymentType type){
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = 
		"UPDATE commande SET DatePaiement = @paymentDay, DateEmission = @emissionDate,"
		"DateLivraison = @deliveryDate, Montant = @cost, MoyenPaiement = @type WHERE IDCommande = @id";
	cmd->Parameters->AddWithValue("@id", id);
	cmd->Parameters->AddWithValue("@paymentDay", paymentDay);
	cmd->Parameters->AddWithValue("@emissionDate", emissionDate);
	cmd->Parameters->AddWithValue("@deliveryDate", deliveryDate);
	cmd->Parameters->AddWithValue("@cost", cost);
	cmd->Parameters->AddWithValue("@type", type);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mappings::OrderRequestMapping::addOrder(DateTime^ paymentDay, DateTime^ emissionDate, DateTime^ deliveryDate, float cost, String^ type){
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = 
		"INSERT INTO commande (DatePaiement, DateEmission, DateLivraison, Montant, MoyenPaiement)"
		"VALUES (@paymentDay, @emissionDate, @deliveryDate, @cost, @type);";
	cmd->Parameters->AddWithValue("@paymentDay", paymentDay);
	cmd->Parameters->AddWithValue("@emissionDate", emissionDate);
	cmd->Parameters->AddWithValue("@deliveryDate", deliveryDate);
	cmd->Parameters->AddWithValue("@cost", cost);
	cmd->Parameters->AddWithValue("@type", type);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mappings::OrderRequestMapping::updateOrder(int id, DateTime^ paymentDay, DateTime^ emissionDate, DateTime^ deliveryDate, float cost, String^ type){
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "UPDATE commande SET DatePaiement = @paymentDay, DateEmission = @emissionDate, DateLivraison = @deliveryDate, Montant = @cost, MoyenPaiement = @type WHERE IDCommande = @id";
	cmd->Parameters->AddWithValue("@id", id);
	cmd->Parameters->AddWithValue("@paymentDay", paymentDay);
	cmd->Parameters->AddWithValue("@emissionDate", emissionDate);
	cmd->Parameters->AddWithValue("@deliveryDate", deliveryDate);
	cmd->Parameters->AddWithValue("@cost", cost);
	cmd->Parameters->AddWithValue("@type", type);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mappings::OrderRequestMapping::deleteOrder(int id){
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "DELETE FROM commande WHERE IDCommande = @id";
	cmd->Parameters->AddWithValue("@id", id);
	return gcnew Request(cmd);
}

#include "AdressRequestMapping.h"

Request^ Groupe3ProjetBlocPOO::Components::Mapping::AdressRequestMapping::getAdresses(){
    MySqlCommand^ cmd = gcnew MySqlCommand();
    cmd->CommandText =
        "SELECT * FROM Adresse NATURAL JOIN"
        "(Ville NATURAL JOIN Pays)";
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::AdressRequestMapping::getAdresses(int limit){
    MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"SELECT * FROM Adresse NATURAL JOIN"
		"(Ville NATURAL JOIN Pays) LIMIT @limit";
	cmd->Parameters->AddWithValue("@limit", limit);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::AdressRequestMapping::getAdresse(int id){
    MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"SELECT * FROM Adresse NATURAL JOIN"
		"(Ville NATURAL JOIN Pays) WHERE IDAdresse = @id";
	cmd->Parameters->AddWithValue("@id", id);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::AdressRequestMapping::addAdresse(int number, String^ street, int zipCode, String^ city, String^ country){
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"INSERT INTO Adresse (NumeroAdresse, RueAdresse, CodePostal, IDVille)"
		"VALUES (@number, @street, @zipCode, (SELECT IDVille FROM Ville WHERE NomVille = @city"
		"AND IDPays = (SELECT IDPays FROM Pays WHERE NomPays = @country)))";
	cmd->Parameters->AddWithValue("@number", number);
	cmd->Parameters->AddWithValue("@street", street);
	cmd->Parameters->AddWithValue("@zipCode", zipCode);
	cmd->Parameters->AddWithValue("@city", city);
	cmd->Parameters->AddWithValue("@country", country);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::AdressRequestMapping::updateAdresse(int id, int number, String^ street, int zipCode, String^ city, String^ country){
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"UPDATE Adresse SET NumeroAdresse = @number, RueAdresse = @street, CodePostal = @zipCode, IDVille = (SELECT IDVille FROM Ville WHERE NomVille = @city"
		"AND IDPays = (SELECT IDPays FROM Pays WHERE NomPays = @country)) WHERE IDAdresse = @id";
	cmd->Parameters->AddWithValue("@id", id);
	cmd->Parameters->AddWithValue("@number", number);
	cmd->Parameters->AddWithValue("@street", street);
	cmd->Parameters->AddWithValue("@zipCode", zipCode);
	cmd->Parameters->AddWithValue("@city", city);
	cmd->Parameters->AddWithValue("@country", country);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::AdressRequestMapping::deleteAdresse(int id){
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "DELETE FROM Adresse WHERE IDAdresse = @id";
	cmd->Parameters->AddWithValue("@id", id);
	return gcnew Request(cmd);
}

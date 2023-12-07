#include "AddressRequestMapping.h"

Request^ Groupe3ProjetBlocPOO::Components::Mapping::AddressRequestMapping::getAddresses() {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"SELECT * FROM addresses NATURAL JOIN"
		"(cities NATURAL JOIN countries)";
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::AddressRequestMapping::getAddresses(int client) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"SELECT addresses.id,addresses.number,addresses.street,cities.name AS 'city',addresses.zip,countries.name AS 'country' "
		"FROM addresses JOIN(cities JOIN countries ON countries.id = cities.country_id) ON cities.id = addresses.city_id "
		"WHERE addresses.client_id = @client";
	cmd->Parameters->AddWithValue("@client", client);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::AddressRequestMapping::getAddressesWithLimit(int limit) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"SELECT * FROM addresses NATURAL JOIN"
		"(cities NATURAL JOIN countries) LIMIT @limit";
	cmd->Parameters->AddWithValue("@limit", limit);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::AddressRequestMapping::getAddress(int id) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"SELECT * FROM addresses NATURAL JOIN"
		"(cities NATURAL JOIN countries) WHERE addresses.id = @id";
	cmd->Parameters->AddWithValue("@id", id);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::AddressRequestMapping::addAddress(int number, String^ street, int zipCode, String^ city, String^ country) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"INSERT INTO addresses (number, street, zip, city_id)"
		"VALUES (@number, @street, @zipCode, (SELECT cities.id FROM cities WHERE cities.name = @city"
		"AND countries.id = (SELECT countries.id FROM countries WHERE countries.name = @country)))";
	cmd->Parameters->AddWithValue("@number", number);
	cmd->Parameters->AddWithValue("@street", street);
	cmd->Parameters->AddWithValue("@zipCode", zipCode);
	cmd->Parameters->AddWithValue("@city", city);
	cmd->Parameters->AddWithValue("@country", country);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::AddressRequestMapping::updateAddress(int id, int number, String^ street, int zipCode, String^ city, String^ country) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"UPDATE addresses SET number = @number, street = @street, zip = @zipCode, city_id = (SELECT cities.id FROM cities WHERE cities.name = @city"
		"AND countries.id = (SELECT countries.id FROM countries WHERE countries.name = @country)) WHERE addresses.id = @id";
	cmd->Parameters->AddWithValue("@id", id);
	cmd->Parameters->AddWithValue("@number", number);
	cmd->Parameters->AddWithValue("@street", street);
	cmd->Parameters->AddWithValue("@zipCode", zipCode);
	cmd->Parameters->AddWithValue("@city", city);
	cmd->Parameters->AddWithValue("@country", country);
	return gcnew Request(cmd);
}

Request^ Groupe3ProjetBlocPOO::Components::Mapping::AddressRequestMapping::deleteAddress(int id) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "DELETE FROM addresses WHERE addresses.id = @id";
	cmd->Parameters->AddWithValue("@id", id);
	return gcnew Request(cmd);
}
Request^ Groupe3ProjetBlocPOO::Components::Mapping::AddressRequestMapping::deleteAddresses(int client) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "DELETE FROM addresses WHERE addresses.client_id = @client";
	cmd->Parameters->AddWithValue("@client", client);
	return gcnew Request(cmd);
}
Request^ Groupe3ProjetBlocPOO::Components::Mapping::AddressRequestMapping::deleteAddresses() {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "DELETE FROM addresses";
	return gcnew Request(cmd);
}
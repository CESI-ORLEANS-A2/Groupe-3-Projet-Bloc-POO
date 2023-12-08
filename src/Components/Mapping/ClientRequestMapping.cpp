#include "./ClientRequestMapping.h"

Groupe3ProjetBlocPOO::Components::Request^ Groupe3ProjetBlocPOO::Components::Mapping::ClientRequestMapping::getClients() {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText = "SELECT * FROM clients;";

	return gcnew Request(cmd);
}
Groupe3ProjetBlocPOO::Components::Request^ Groupe3ProjetBlocPOO::Components::Mapping::ClientRequestMapping::getClients(int limit) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"SELECT * FROM clients "
		"LIMIT @limit; ";

	cmd->Parameters->AddWithValue("@limit", limit);

	return gcnew Request(cmd);
}
Groupe3ProjetBlocPOO::Components::Request^ Groupe3ProjetBlocPOO::Components::Mapping::ClientRequestMapping::getClients(int limit, int offset) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"SELECT * FROM clients "
		"LIMIT @limit OFFSET @offset;";

	cmd->Parameters->AddWithValue("@limit", limit);
	cmd->Parameters->AddWithValue("@offset", offset);

	return gcnew Request(cmd);
}
Groupe3ProjetBlocPOO::Components::Request^ Groupe3ProjetBlocPOO::Components::Mapping::ClientRequestMapping::getClient(int id) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"SELECT * FROM clients "
		"WHERE id = @id;";

	cmd->Parameters->AddWithValue("@id", id);

	return gcnew Request(cmd);
}
Groupe3ProjetBlocPOO::Components::Request^ Groupe3ProjetBlocPOO::Components::Mapping::ClientRequestMapping::addClient(DataType::Client^ client) {
	return ClientRequestMapping::addClient(
		client->firstname(),
		client->lastname(),
		client->phone(),
		client->email(),
		client->birthdate(),
		client->logo(),
		client->company()
	);
}
Groupe3ProjetBlocPOO::Components::Request^ Groupe3ProjetBlocPOO::Components::Mapping::ClientRequestMapping::addClient(
	String^ firstname,
	String^ lastname,
	String^ phone,
	String^ email,
	String^ birthdate,
	String^ logo,
	String^ company
) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"INSERT INTO clients "
		"(firstname, lastname, phone, email, birthdat, logo, company) "
		"VALUES (@firstname, @lastname, @phone, @email, @birthdate, @logo, @company);";

	cmd->Parameters->AddWithValue("@firstname", firstname);
	cmd->Parameters->AddWithValue("@lastname", lastname);
	cmd->Parameters->AddWithValue("@phone", phone);
	cmd->Parameters->AddWithValue("@email", email);
	cmd->Parameters->AddWithValue("@birthdate", birthdate);
	cmd->Parameters->AddWithValue("@logo", logo);
	cmd->Parameters->AddWithValue("@company", company);

	return gcnew Request(cmd);
}
Groupe3ProjetBlocPOO::Components::Request^ Groupe3ProjetBlocPOO::Components::Mapping::ClientRequestMapping::updateClient(DataType::Client^ client) {
	return ClientRequestMapping::updateClient(
		client->id(),
		client->firstname(),
		client->lastname(),
		client->phone(),
		client->email(),
		client->birthdate(),
		client->logo(),
		client->company()
	);
}
Groupe3ProjetBlocPOO::Components::Request^ Groupe3ProjetBlocPOO::Components::Mapping::ClientRequestMapping::updateClient(
	int id,
	String^ firstname,
	String^ lastname,
	String^ phone,
	String^ email,
	String^ birthdate,
	String^ logo,
	String^ company
) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"UPDATE clients "
		"SET firstname = @firstname, "
		"	lastname = @lastname, "
		"	phone = @phone, "
		"	email = @email, "
		"	birthdate = @birthdate, "
		"	logo = @logo, "
		"	company = @company "
		"WHERE id = @id;";

	cmd->Parameters->AddWithValue("@id", id);
	cmd->Parameters->AddWithValue("@firstname", firstname);
	cmd->Parameters->AddWithValue("@lastname", lastname);
	cmd->Parameters->AddWithValue("@phone", phone);
	cmd->Parameters->AddWithValue("@email", email);
	cmd->Parameters->AddWithValue("@birthdate", birthdate);
	cmd->Parameters->AddWithValue("@logo", logo);
	cmd->Parameters->AddWithValue("@company", company);

	return gcnew Request(cmd);
}
Groupe3ProjetBlocPOO::Components::Request^ Groupe3ProjetBlocPOO::Components::Mapping::ClientRequestMapping::deleteClient(int id) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"DELETE FROM clients "
		"WHERE id = @id;";

	cmd->Parameters->AddWithValue("@id", id);

	return gcnew Request(cmd);
}
Groupe3ProjetBlocPOO::Components::Request^ Groupe3ProjetBlocPOO::Components::Mapping::ClientRequestMapping::emptyClient() {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"DELETE FROM clients;";

	return gcnew Request(cmd);
}
Groupe3ProjetBlocPOO::Components::Request^ Groupe3ProjetBlocPOO::Components::Mapping::ClientRequestMapping::deleteClients(array<int>^ ids) {
	MySqlCommand^ cmd = gcnew MySqlCommand();
	cmd->CommandText =
		"DELETE FROM clients "
		"WHERE id IN (";

	for (int i = 0; i < ids->Length; i++) {
		cmd->CommandText += "@id" + i + ",";
		cmd->Parameters->AddWithValue("@id" + i, ids[i]);
	}

	cmd->CommandText = cmd->CommandText->Substring(0, cmd->CommandText->Length - 1);
	cmd->CommandText += ");";

	return gcnew Request(cmd);
}
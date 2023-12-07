#include "./ClientsService.h"

Groupe3ProjetBlocPOO::Services::ClientService::ClientService(Database^ database) {
	this->__database = database;

	Dictionary<String^, String^>^ clientsSchema = gcnew Dictionary<String^, String^>();
	clientsSchema->Add("id", "INT PRIMARY KEY AUTO_INCREMENT");
	clientsSchema->Add("firstname", "VARCHAR(100)");
	clientsSchema->Add("lastname", "VARCHAR(100)");
	clientsSchema->Add("phone", "VARCHAR(30)");
	clientsSchema->Add("email", "VARCHAR(100)");
	clientsSchema->Add("birthdate", "VARCHAR(100)");
	clientsSchema->Add("logo", "VARCHAR(255)");
	clientsSchema->Add("company", "VARCHAR(100)");
	this->__database->createTable("clients", clientsSchema);

	Dictionary<String^, String^>^ addressesSchema = gcnew Dictionary<String^, String^>();
	addressesSchema->Add("id", "INT PRIMARY KEY AUTO_INCREMENT");
	addressesSchema->Add("client_id", "INT");
	addressesSchema->Add("number", "VARCHAR(10)");
	addressesSchema->Add("street", "VARCHAR(100)");
	addressesSchema->Add("city", "INT NOT NULL");
	addressesSchema->Add("zip", "INT NOT NULL");
	addressesSchema->Add("country", "INT NOT NULL");
	this->__database->createTable("addresses", addressesSchema);
}

Client^ Groupe3ProjetBlocPOO::Services::ClientService::getClient(int id) {
	return gcnew Client(this->__database->runQuery(ClientRequestMapping::getClient(id))->Rows[0]);
}
Client^ Groupe3ProjetBlocPOO::Services::ClientService::getClient(Client^ client) {
	return gcnew Client(this->__database->runQuery(ClientRequestMapping::getClient(client->id()))->Rows[0]);
}
array<Client^>^ Groupe3ProjetBlocPOO::Services::ClientService::getClients() {
	DataTable^ clients = this->__database->runQuery(ClientRequestMapping::getClients());
	array<Client^>^ clientsArray = gcnew array<Client^>(clients->Rows->Count);
	for (int i = 0; i < clients->Rows->Count; i++) {
		clientsArray[i] = gcnew Client(clients->Rows[i]);
	}
	return clientsArray;
}
array<Client^>^ Groupe3ProjetBlocPOO::Services::ClientService::getClients(int limit) {
	DataTable^ clients = this->__database->runQuery(ClientRequestMapping::getClients(limit));
	array<Client^>^ clientsArray = gcnew array<Client^>(clients->Rows->Count);
	for (int i = 0; i < clients->Rows->Count; i++) {
		clientsArray[i] = gcnew Client(clients->Rows[i]);
	}
	return clientsArray;
}
array<Client^>^ Groupe3ProjetBlocPOO::Services::ClientService::getClients(int limit, int offset) {
	DataTable^ clients = this->__database->runQuery(ClientRequestMapping::getClients(limit, offset));
	array<Client^>^ clientsArray = gcnew array<Client^>(clients->Rows->Count);
	for (int i = 0; i < clients->Rows->Count; i++) {
		clientsArray[i] = gcnew Client(clients->Rows[i]);
	}
	return clientsArray;
}
Client^ Groupe3ProjetBlocPOO::Services::ClientService::createClient(Client^ client) {
	int id = Convert::ToInt32(this->__database->runScalar(ClientRequestMapping::addClient(client->firstname(), client->lastname(), client->phone(), client->email(), client->birthdate(), client->logo(), client->company())));

	return gcnew Client(id, client);
}
Client^ Groupe3ProjetBlocPOO::Services::ClientService::createClient(String^ firstname, String^ lastname, String^ phone, String^ email, String^ birthdate, String^ logo, String^ company) {
	int id = Convert::ToInt32(this->__database->runScalar(ClientRequestMapping::addClient(firstname, lastname, phone, email, birthdate, logo, company)));
	Client^ client = gcnew Client(id);
	client->firstname(firstname);
	client->lastname(lastname);
	client->phone(phone);
	client->email(email);
	client->birthdate(birthdate);
	client->logo(logo);
	client->company(company);
	return client;
}
Client^ Groupe3ProjetBlocPOO::Services::ClientService::updateClient(Client^ client) {
	this->__database->runQuery(ClientRequestMapping::updateClient(client))->Rows[0];
	return gcnew Client(this->__database->runQuery(ClientRequestMapping::getClient(client->id()))->Rows[0]);
}
Client^ Groupe3ProjetBlocPOO::Services::ClientService::updateClient(int id, String^ firstname, String^ lastname, String^ phone, String^ email, String^ birthdate, String^ logo, String^ company) {
	this->__database->runQuery(ClientRequestMapping::updateClient(id, firstname, lastname, phone, email, birthdate, logo, company))->Rows[0];
	return gcnew Client(this->__database->runQuery(ClientRequestMapping::getClient(id))->Rows[0]);
}
Client^ Groupe3ProjetBlocPOO::Services::ClientService::deleteClient(Client^ client) {
	this->__database->runQuery(ClientRequestMapping::deleteClient(client->id()));
	return client;
}
Client^ Groupe3ProjetBlocPOO::Services::ClientService::deleteClient(int id) {
	Client^ client = gcnew Client(this->__database->runQuery(ClientRequestMapping::getClient(id))->Rows[0]);
	this->__database->runQuery(ClientRequestMapping::deleteClient(id));
	return client;
}

array<Address^>^ Groupe3ProjetBlocPOO::Services::ClientService::getAddresses(Client^ client) {
	DataTable^ addresses = this->__database->runQuery(ClientRequestMapping::getAddresses(client->id()));
	array<Address^>^ addressesArray = gcnew array<Address^>(addresses->Rows->Count);
	for (int i = 0; i < addresses->Rows->Count; i++) {
		addressesArray[i] = gcnew Address(addresses->Rows[i]);
	}
	return addressesArray;
}
array<Address^>^ Groupe3ProjetBlocPOO::Services::ClientService::getAddresses(int id) {
	DataTable^ addresses = this->__database->runQuery(ClientRequestMapping::getAddresses(id));
	array<Address^>^ addressesArray = gcnew array<Address^>(addresses->Rows->Count);
	for (int i = 0; i < addresses->Rows->Count; i++) {
		addressesArray[i] = gcnew Address(addresses->Rows[i]);
	}
	return addressesArray;
}
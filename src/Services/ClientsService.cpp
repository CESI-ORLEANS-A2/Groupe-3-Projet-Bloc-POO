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

	Dictionary<String^, String^>^ countriesSchema = gcnew Dictionary<String^, String^>();
	countriesSchema->Add("id", "INT PRIMARY KEY AUTO_INCREMENT");
	countriesSchema->Add("name", "VARCHAR(100)");
	this->__database->createTable("countries", countriesSchema);

	Dictionary<String^, String^>^ citiesSchema = gcnew Dictionary<String^, String^>();
	citiesSchema->Add("id", "INT PRIMARY KEY AUTO_INCREMENT");
	citiesSchema->Add("name", "VARCHAR(100)");
	citiesSchema->Add("country_id", "INT NOT NULL, FOREIGN KEY (country_id) REFERENCES countries(id)");
	this->__database->createTable("cities", citiesSchema);

	Dictionary<String^, String^>^ addressesSchema = gcnew Dictionary<String^, String^>();
	addressesSchema->Add("id", "INT PRIMARY KEY AUTO_INCREMENT");
	addressesSchema->Add("client_id", "INT NOT NULL, FOREIGN KEY (client_id) REFERENCES clients(id)");
	addressesSchema->Add("number", "VARCHAR(10)");
	addressesSchema->Add("street", "VARCHAR(100)");
	addressesSchema->Add("city_id", "INT NOT NULL, FOREIGN KEY (city_id) REFERENCES cities(id)");
	addressesSchema->Add("zip", "INT NOT NULL");
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

	this->__database->runQuery(AddressRequestMapping::deleteAddresses(id));
	this->__database->runQuery(ClientRequestMapping::deleteClient(id));
	return client;
}

Address^ Groupe3ProjetBlocPOO::Services::ClientService::createAddress(Address^ address) {
	int id = Convert::ToInt32(this->__database->runScalar(AddressRequestMapping::addAddress(
		address->clientId(),
		address->number(),
		address->street(),
		address->city(),
		address->zip(),
		address->country()
	)));
	return gcnew Address(id, address);
}
Address^ Groupe3ProjetBlocPOO::Services::ClientService::createAddress(Client^ client, String^ number, String^ street, String^ city, int zipCode, String^ country) {
	int id = Convert::ToInt32(this->__database->runScalar(AddressRequestMapping::addAddress(
		client->id(),
		number,
		street,
		city,
		zipCode,
		country
	)));
	return gcnew Address(id, client->id(), number, street, city, zipCode, country);
}
Address^ Groupe3ProjetBlocPOO::Services::ClientService::createAddress(int clientId, String^ number, String^ street, String^ city, int zipCode, String^ country) {
	int id = Convert::ToInt32(this->__database->runScalar(AddressRequestMapping::addAddress(
		clientId,
		number,
		street,
		city,
		zipCode,
		country
	)));
	return gcnew Address(id, clientId, number, street, city, zipCode, country);
}
Address^ Groupe3ProjetBlocPOO::Services::ClientService::updateAddress(Address^ address) {
	this->__database->runQuery(AddressRequestMapping::updateAddress(
		address->id(),
		address->number(),
		address->street(),
		address->city(),
		address->zip(),
		address->country()
	));
	return gcnew Address(this->__database->runQuery(AddressRequestMapping::getAddress(address->id()))->Rows[0]);
}
Address^ Groupe3ProjetBlocPOO::Services::ClientService::updateAddress(int id, String^ number, String^ street, String^ city, int zipCode, String^ country) {
	this->__database->runQuery(AddressRequestMapping::updateAddress(
		id,
		number,
		street,
		city,
		zipCode,
		country
	));
	return gcnew Address(this->__database->runQuery(AddressRequestMapping::getAddress(id))->Rows[0]);
}
Address^ Groupe3ProjetBlocPOO::Services::ClientService::deleteAddress(Address^ address) {
	this->__database->runQuery(AddressRequestMapping::deleteAddress(address->id()));
	return address;
}
Address^ Groupe3ProjetBlocPOO::Services::ClientService::deleteAddress(int id) {
	Address^ address = gcnew Address(this->__database->runQuery(AddressRequestMapping::getAddress(id))->Rows[0]);
	this->__database->runQuery(AddressRequestMapping::deleteAddress(id));
	return address;
}
array<Address^>^ Groupe3ProjetBlocPOO::Services::ClientService::getAddresses(Client^ client) {
	DataTable^ addresses = this->__database->runQuery(AddressRequestMapping::getAddresses(client->id()));
	array<Address^>^ addressesArray = gcnew array<Address^>(addresses->Rows->Count);
	for (int i = 0; i < addresses->Rows->Count; i++) {
		addressesArray[i] = gcnew Address(addresses->Rows[i]);
	}
	return addressesArray;
}
array<Address^>^ Groupe3ProjetBlocPOO::Services::ClientService::getAddresses(int id) {
	DataTable^ addresses = this->__database->runQuery(AddressRequestMapping::getAddresses(id));
	array<Address^>^ addressesArray = gcnew array<Address^>(addresses->Rows->Count);
	for (int i = 0; i < addresses->Rows->Count; i++) {
		addressesArray[i] = gcnew Address(addresses->Rows[i]);
	}
	return addressesArray;
}
array<Address^>^ Groupe3ProjetBlocPOO::Services::ClientService::updateAddresses(array<Address^>^ addresses) {
	array<Address^>^ updatedAddresses = gcnew array<Address^>(addresses->Length);
	for (int i = 0; i < addresses->Length; i++) {
		updatedAddresses[i] = this->updateAddress(addresses[i]);
	}
	return updatedAddresses;
}
array<Address^>^ Groupe3ProjetBlocPOO::Services::ClientService::deleteAddresses(Client^ client) {
	DataTable^ addresses = this->__database->runQuery(AddressRequestMapping::getAddresses(client->id()));
	array<Address^>^ addressesArray = gcnew array<Address^>(addresses->Rows->Count);
	for (int i = 0; i < addresses->Rows->Count; i++) {
		addressesArray[i] = gcnew Address(addresses->Rows[i]);
	}
	this->__database->runQuery(AddressRequestMapping::deleteAddresses(client->id()));
	return addressesArray;
}
array<Address^>^ Groupe3ProjetBlocPOO::Services::ClientService::deleteAddresses(int id) {
	DataTable^ addresses = this->__database->runQuery(AddressRequestMapping::getAddresses(id));
	array<Address^>^ addressesArray = gcnew array<Address^>(addresses->Rows->Count);
	for (int i = 0; i < addresses->Rows->Count; i++) {
		addressesArray[i] = gcnew Address(addresses->Rows[i]);
	}
	this->__database->runQuery(AddressRequestMapping::deleteAddresses(id));
	return addressesArray;
}
array<Address^>^ Groupe3ProjetBlocPOO::Services::ClientService::deleteAddresses(array<Address^>^ addresses) {
	array<Address^>^ deletedAddresses = gcnew array<Address^>(addresses->Length);
	for (int i = 0; i < addresses->Length; i++) {
		deletedAddresses[i] = this->deleteAddress(addresses[i]);
	}
	return deletedAddresses;
}

int Groupe3ProjetBlocPOO::Services::ClientService::getCityId(String^ city) {
	return Convert::ToInt32(this->__database->runScalar(AddressRequestMapping::getCityId(city)));
}
int Groupe3ProjetBlocPOO::Services::ClientService::getCountryId(String^ country) {
	return Convert::ToInt32(this->__database->runScalar(AddressRequestMapping::getCountryId(country)));
}
#include <iostream>
using namespace std;

class PC {
public:
	virtual void setInfo(string name, int size, int ram, string owner) = 0;
	virtual void getInfo() = 0;
};

class PC_HDD : public PC {
public:
	void setInfo(string name, int size, int ram, string owner);
	void getInfo();
private:
	string name;
	int size;
	int ram;
	string owner;
};

void PC_HDD::setInfo(string name, int size, int ram, string owner) {
	this->name = name;
	this->size = size;
	this->ram = ram;
	this->owner = owner;
}

void PC_HDD::getInfo() {
	cout << "Komputere stacjonarny: " << this->name << ", o pojemnosci HDD: " << this->size << "GB, RAM: " << this->ram << "GB. Wlasciciel: " << this->owner << endl;
}

class PC_SSD : public PC {
public:
	void setInfo(string name, int size, int ram, string owner);
	void getInfo();
private:
	string name;
	int size;
	int ram;
	string owner;
};

void PC_SSD::setInfo(string name, int size, int ram, string owner) {
	this->name = name;
	this->size = size;
	this->ram = ram;
	this->owner = owner;
}

void PC_SSD::getInfo() {
	cout << "Komputere stacjonarny: " << this->name << ", o pojemnosci SSD: " << this->size << "GB, RAM: " << this->ram << "GB. Wlasciciel: " << this->owner << endl;
}

class Laptop {
public:
	virtual void setInfo(string name, int size, int ram, string owner) = 0;
	virtual void getInfo() = 0;
};

class Laptop_HDD : public Laptop {
public:
	void setInfo(string name, int size, int ram, string owner);
	void getInfo();
private:
	string name;
	int size;
	int ram;
	string owner;
};


void Laptop_HDD::setInfo(string name, int size, int ram, string owner) {
	this->name = name;
	this->size = size;
	this->ram = ram;
	this->owner = owner;
}

void Laptop_HDD::getInfo() {
	cout << "Laptop: " << this->name << ", o pojemnosci HDD: " << this->size << "GB, RAM: " << this->ram << "GB. Wlasciciel: " << this->owner << endl;
}

class Laptop_SSD : public Laptop {
public:
	void setInfo(string name, int size, int ram, string owner);
	void getInfo();
private:
	string name;
	int size;
	int ram;
	string owner;
};


void Laptop_SSD::setInfo(string name, int size, int ram, string owner) {
	this->name = name;
	this->size = size;
	this->ram = ram;
	this->owner = owner;
}

void Laptop_SSD::getInfo() {
	cout << "Laptop: " << this->name << ", o pojemnosci SSD: " << this->size << "GB, RAM: " << this->ram << "GB. Wlasciciel: " << this->owner << endl;
}

class ComputerFactory {
public:
	virtual PC* createPC(string name, int size, int ram, string owner) = 0;
	virtual Laptop* createLaptop(string name, int size, int ram, string owner) = 0;
};

class HDD_CF : public ComputerFactory {
public:
	PC* createPC(string name, int size, int ram, string owner);
	Laptop* createLaptop(string name, int size, int ram, string owner);
};

class SSD_CF : public ComputerFactory {
public:
	PC* createPC(string name, int size, int ram, string owner);
	Laptop* createLaptop(string name, int size, int ram, string owner);
};

PC* HDD_CF::createPC(string name, int size, int ram, string owner) {
	PC* pc1 = new PC_HDD;
	pc1->setInfo(name, size, ram, owner);
	return pc1;
}

Laptop* HDD_CF::createLaptop(string name, int size, int ram, string owner) {
	Laptop* lap1 = new Laptop_HDD;
	lap1->setInfo(name, size, ram, owner);
	return lap1;
}

PC* SSD_CF::createPC(string name, int size, int ram, string owner) {
	PC* pc1 = new PC_SSD;
	pc1->setInfo(name, size, ram, owner);
	return pc1;
}

Laptop* SSD_CF::createLaptop(string name, int size, int ram, string owner) {
	Laptop* lap1 = new Laptop_SSD;
	lap1->setInfo(name, size, ram, owner);
	return lap1;
}

int main() {
	HDD_CF* hdd1 = new HDD_CF;
	PC* pc1 = hdd1->createPC("GamingRig", 1024, 32, "Igor");
	pc1->getInfo();
	Laptop* lap1 = hdd1->createLaptop("Acer", 128, 16, "Jaroslaw");
	lap1->getInfo();

	SSD_CF* ssd1 = new SSD_CF;
	PC* pc2 = ssd1->createPC("Razer", 512, 16, "Janek");
	pc2->getInfo();
	Laptop* lap2 = ssd1->createLaptop("Lenovo", 256, 8, "Marek");
	lap2->getInfo();
	
    return 0;
}

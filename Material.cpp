#include "Material.h"



Material::Material()
{
}

Material::Material(int number, string matText, int stock)
{
	this->matNumber = number;
	this->matText = matText;
	this->stock = stock;
}


Material::~Material()
{
}

int Material::getMatNumber()
{
	return this->matNumber;
}

int Material::getStock()
{
	return this->stock;
}

void Material::setStock(int number)
{
	this->stock = number;
}

vector<int>* Material::getLocations()
{
	return &locations;
}


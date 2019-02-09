#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Material
{
public:
	Material();
	Material(int number, string matText, int stock);
	~Material();
	//void changeStock(int test);
	int getMatNumber();
	int getStock();
	void setStock(int number);
	vector<int>* getLocations();

private:
	int matNumber;
	string matText;
	int stock;
	vector<int> locations;
};


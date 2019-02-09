#include"Material.h"
#include<time.h>

class Warehouse
{
public:
	Warehouse();
	~Warehouse();
	void goodsReceipt();
	void goodsIssue();
	int freeSpace();
	int usedSpaceBy(int number);
	void createMaterial();

private:
	static const int maxBins = 840;
	int storageBins[maxBins];
	vector<Material*> materials;
};


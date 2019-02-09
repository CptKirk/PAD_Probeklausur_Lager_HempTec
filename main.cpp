#include "Warehouse.h"

int main() {
	Warehouse myWarehouse = Warehouse::Warehouse();
	int input;

	while (true) {
		cout << endl << endl << endl <<
			"1: Wareneingang buchen" << endl <<
			"2: Warenausgang buchen" << endl <<
			"3: Material hinzufuegen" << endl << 
			"0: Prorammende" << endl << endl;

		cin >> input;

		switch (input) {
		case(1): myWarehouse.goodsReceipt(); break;
		case(2): myWarehouse.goodsIssue(); break;
		case(3): myWarehouse.createMaterial(); break;
		case(0): return 0; break;
		default: return 0; break;
		}
	}
}
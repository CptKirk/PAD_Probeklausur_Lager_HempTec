#include "Warehouse.h"



Warehouse::Warehouse()
{
	for (int i = 0; i < 840; i++) {
		storageBins[i] = -1;
	}
	
	Material *newMaterial = new Material(1, "Daemmstoff_16cm", 0);
	materials.push_back(newMaterial);
}


Warehouse::~Warehouse()
{
}

void Warehouse::goodsReceipt()
{
	srand(time(NULL));

	int randomPlace, currentStock, 
		regal, fach, ebene, 
		palettenAnzahl, counter = 0, materialNumber, placeInVec;

	cout << "Welches Material wollen sie einlagern? ";
	cin >> materialNumber;

	for (int k = 0; k < materials.size(); k++) {
		if (materials[k]->getMatNumber() == materialNumber)
			placeInVec = k;
	}

	cout << endl << "Wie viele Paletten wollen Sie einlagern? ";
	cin >> palettenAnzahl;

	if (palettenAnzahl > freeSpace()) {
		cout << endl << "Im Lager ist kein Platz für " << palettenAnzahl << " Paletten." << endl <<
			"Wir nehmen stattdessen " << freeSpace() << " Paletten.";
		palettenAnzahl = freeSpace();
	}

	while (counter != palettenAnzahl) {
		randomPlace = rand() % 839;

		if (storageBins[randomPlace] == -1) {
			storageBins[randomPlace] = materialNumber;
			currentStock = materials[placeInVec]->getStock();
			materials[placeInVec]->setStock(currentStock + 1);

			regal = ((randomPlace + 1) / 60) + 1;
			ebene = ((randomPlace - (((randomPlace + 1) / 60) * 60)) / 10) + 1;
			fach = ((randomPlace - (((randomPlace + 1) / 60) * 60)) % 10);

			cout << "randomPlace = " << randomPlace << endl <<
				"regal = " << regal << endl <<
				"ebene = " << ebene << endl <<
				"fach = " << fach << endl << endl;
			counter += 1;
			materials[placeInVec]->getLocations()->push_back(randomPlace);
		}
		else
			continue;
	}
}

void Warehouse::goodsIssue()
{
	int counter = 0, currentStock, regal, ebene, fach, place, palettenAnzahl, materialNumber, placeInVec;

	cout << "Welches Material wollen sie auslagern? ";
	cin >> materialNumber;

	for (int k = 0; k < materials.size(); k++) {
		if (materials[k]->getMatNumber() == materialNumber)
			placeInVec = k;
	}

	cout << endl << "Wie viele Paletten wollen Sie auslagern? ";
	cin >> palettenAnzahl;

	if (usedSpaceBy(materialNumber) == 0)
		cout << "Kein Bestand vorhanden";

	else if (palettenAnzahl > usedSpaceBy(materialNumber)) {
		cout << endl << "Im Lager sind keine " << palettenAnzahl << "Paletten." << endl <<
			"Wir nehmen stattdessen " << usedSpaceBy(materialNumber) << "Paletten.";
		palettenAnzahl = usedSpaceBy(materialNumber);
	}

	vector<int>* test = materials[placeInVec]->getLocations();

	for (int i = test->size(); i > 0; i--) {
		int loc = test->at(i-1);

		if ((storageBins[loc] == materialNumber) && counter < palettenAnzahl) {
			storageBins[loc] = -1;
			currentStock = materials[placeInVec]->getStock();
			materials[placeInVec]->setStock(currentStock - 1);
			counter += 1;
			place = loc;

			regal = ((place + 1) / 60) + 1;
			ebene = ((place - (((place + 1) / 60) * 60)) / 10) + 1;
			fach = ((place - (((place + 1) / 60) * 60)) % 10);

			cout << endl <<
				"place = " << place << endl <<
				"regal = " << regal << endl <<
				"ebene = " << ebene << endl <<
				"fach = " << fach << endl;
		}
	}
	cout << "Momentaner Bestand: " << materials[placeInVec]->getStock();
}

int Warehouse::freeSpace()
{
	int counter = 0;

	for (int i = 0; i < 840; i++) {
		if (storageBins[i] == -1)
			counter += 1;
	}

	return counter;
}

int Warehouse::usedSpaceBy(int number)
{
	int counter = 0;

	for (int i = 0; i < 840; i++) {
		if (storageBins[i] == number)
			counter += 1;
	}

	return counter;
}

void Warehouse::createMaterial()
{
	int number;
	string name;

	cout << "Wie heißt das Material? ";
	cin >> name;

	cout << endl << "Welche Nummer hat es? ";
	cin >> number;

	Material *newMaterial = new Material(number, name, 0);

	materials.push_back(newMaterial);
}

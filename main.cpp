#include <iostream>
#include "image.h"
#include "Operation.h"

using namespace std;
using namespace cv;

int main() {
	
	
	string cheminImage = "C:/Users/marie/OneDrive - ISEP/Isep/A2/S2/Appli multimedia/TP/TP2/TP2/img/HappyFish.jpg";
	Image inputImage(cheminImage);
	inputImage.display();

	//Exemple pour dilatation et erosion: 
	char choix;
	cout << "Voulez-vous faire une érosion (e) ou une dilatation (d) ? ";
	cin >> choix;

	bool isErosion;
	if (choix == 'e' || choix == 'E') {
		isErosion = true;
	}
	else {
		isErosion = false;
	}

	int size;
	cout << "Entrez la taille de l'érosion/dilatation (entre 0 et 30) : ";
	cin >> size;

	Image outputImage = Operation::DilatationOrErosion(inputImage, size, isErosion);
	outputImage.display();

	//Exemple pour resize:
	char choix;
	cout << "Voulez-vous spécifier les nouvelles dimensions (d) ou un facteur de redimensionnement (f) ? ";
	cin >> choix;

	if (choix == 'd' || choix == 'D') {
		int width, height;
		cout << "Entrez les nouvelles dimensions (largeur hauteur) : ";
		cin >> width >> height;

		Image outputImage = Operation::Resizing(inputImage, 0, width, height);
		outputImage.display();
	}
	else if (choix == 'f' || choix == 'F') {
		float factor;
		cout << "Entrez le facteur de redimensionnement (> 0) : ";
		cin >> factor;

		Image outputImage = Operation::Resizing(inputImage, factor, 0, 0);
		outputImage.display();
	}
	else {
		cout << "Choix invalide." << endl;
	}
	

	//Exemple pour brigtnessChange:
	char choix;
	cout << "Voulez-vous effectuer un changement de luminosité (b) ou de saturation (s) ? ";
	cin >> choix;
	float factor;

	if (choix == 'b' || choix == 'B') {
		cout << "Entrez le facteur de luminosité (entre -255 et 255): ";
		cin >> factor;

		Image outputImage = Operation::BrightnessChange(inputImage, factor,true);
		outputImage.display();
	}
	else if (choix == 's' || choix == 'S') {
		cout << "Entrez le facteur de saturation (entre 0 et 3) : ";
		cin >> factor;

		Image outputImage = Operation::BrightnessChange(inputImage, factor, false);
		outputImage.display();
	}
	else {
		cout << "Choix invalide." << endl;
	}


	return 0;
}
#include <iostream>

int main() {
	//Exemple pour dilatation et erosion: 
	string cheminImage = "C:/Users/marie/OneDrive - ISEP/Isep/A2/S2/Appli multimedia/TP/TP2/TP2/img/HappyFish.jpg";
	Image inputImage(cheminImage);
	inputImage.display();

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


	return 0;
}
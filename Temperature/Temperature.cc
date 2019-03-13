#include <iostream>

using namespace std;

float convertFtoC(float f);
float convertCtoK(float c);

int main(){

	char choice = 'y';
	float fahrenheit, celcius, kelvin;
	while(choice == 'y'){
		
		cout << "\nEnter a fahrenheit:\n";
		cin >> fahrenheit;
		
		celcius = convertFtoC(fahrenheit);
		
		kelvin = convertCtoK(celcius);
		
		cout << "\nFarenheit = " << fahrenheit << "\nCelcius = "
		<< celcius << "\nKelvin = " << kelvin << endl;
		
		cout << "Do you want to continue? y/n\n";
		cin >> choice;
	}
	return 1;
}

float convertFtoC(float f){
	return ((f - 32)*5/9);
}

float convertCtoK(float c){
	return (c + 273.15);
} 


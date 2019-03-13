#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int computersPick();

class Tronmon{
	private:
		string pickedTronmon;
		float allStats[6];
		string nameStats[6] = {"Hitpoints", "Attack", "Defence",
								"Special Attack", "Special Defence",
								"Accuracy"};
		void setStats();
		void moveSet(Tronmon T);
		void typeOfTronmon(int T);
		int selectMove(string pickedTronmon);
		void attackMove(int Move, Tronmon &T);
		int computersAttackPick();
		
	public:
		Tronmon(int whichTronmon);
		bool alive();
		friend ostream &operator<<(ostream &out, Tronmon &T){
			out << T.pickedTronmon << "'s stats are: "
				<< endl;
			for (int i=0; i<6; i++)
				out << T.nameStats[i] << ": " <<
				T.allStats[i] << endl;
			out << endl;
			return out;
		}
		void userBattle(Tronmon &T);
		void computerBattle(Tronmon &T);
		
};
// Constructor
Tronmon::Tronmon(int T){
	typeOfTronmon(T);
	setStats();
}

// Sets which type/starter of Tronmon.
void Tronmon::typeOfTronmon(int T){
	if(T <= 1){ pickedTronmon = "Tronamander";}
	else if(T == 2){ pickedTronmon = "Bulbatron";}
	else{ pickedTronmon = "Squirtron";}
}

// Sets the stats of a Tronmon using rand()
// from 5 - 20.
void Tronmon::setStats(){
	allStats[0] = 100;
	for(int i = 1; i < 6; i++){
		allStats[i] = rand() % 16 + 5;
	}
}

// Sees if Tronmon is alive.
bool Tronmon::alive(){
	if(allStats[0] <= 0){
		return false;
		}
	return true;
}

// User battle
void Tronmon::userBattle(Tronmon &T){
	int Move = selectMove(pickedTronmon);
	attackMove(Move, T);
	
}

// Computer Battle
void Tronmon::computerBattle(Tronmon &T){
	int Move = computersAttackPick();
	cout << "\nComputer picked: " << Move << "!\n";
	attackMove(Move, T);
}

// Move computer picks
int Tronmon::computersAttackPick(){
	int Move = rand() % 4 + 1; // Picks 1-4
	return Move;
}

// Select move for battle
int Tronmon::selectMove(string pT){
	int Move;
	cout << "What would you like to do?\n";
	if(pT == "Tronamander"){
		cout << " 1. Scratch\n 2. Growl\n 3. Ember\n 4. Heal\n";
	}
	else if(pT == "Bulbatron"){
		cout << " 1. Tackle\n 2. Growl\n 3. Vine Whip\n 4. Heal\n";
	}
	else{
		cout << " 1. Tackle\n 2. Tail Whip\n 3. Water Gun\n 4. Heal\n";
	}
	cin >> Move;
	return Move;
}

// Attacks
void Tronmon::attackMove(int Move, Tronmon &T){
	float damage = 0, critical, type = 1, base;
	
	
	// Basic Move
	if(Move == 1){
		base = 10;
	}
	
	// Stat Modifiers
	else if(Move == 2){
		if(pickedTronmon == "Tronamander") T.allStats[1] -= 1;
		else if(pickedTronmon == "Bulbatron") T.allStats[1] -= 1;
		else T.allStats[2] -= 1;
		
		if(T.allStats[1] < 5) T.allStats[1] += 1;
		if(T.allStats[2] < 5) T.allStats[2] += 1;
	}
	
	// Type. Same type *1 SuperEffective type *1.2 NonEffective type *0.8
	else if(Move == 3){
		base = 8;
		if(pickedTronmon == "Tronamander")
			if(T.pickedTronmon == "Bulbatron")
				type = 1.4;
			else
				type = 1.0;
			
		else if(pickedTronmon == "Bulbatron")
			if(T.pickedTronmon == "Squirtron")
				type = 1.4;
			else
				type = 1.0;
			
		else
			if(T.pickedTronmon == "Tronamander")
				type = 1.4;
			else
				type = 1.0;
			
	}
	
	// Heal. Heals 25 Hp
	else{
		allStats[0] += 25;
		if(allStats[0] > 100) allStats[0] = 100;
	}
	
	// Critical
	int doesCrit = rand() % 100 + 1;
	if(doesCrit >= 85) critical = 2;
	else critical = 1;
	
	// Damage
	if(Move == 1){ // OR MIGHT NOT WORK
		
		damage = ((allStats[1] / T.allStats[2]) + base) * critical;
		if(damage > 35) damage = 35;
		T.allStats[0] -= damage;
		if(T.allStats[0] < 0) T.allStats[0] = 0;
	}
	else if(Move == 3){
		
		damage = ((allStats[3] / T.allStats[4]) + base) * critical;
		if(damage > 35) damage = 35;
		T.allStats[0] -= damage;
		if(T.allStats[0] < 0) T.allStats[0] = 0;
	
	}
	
	cout << fixed << setprecision(0) << damage << " damage dealt!\n";
}


// Picks the computers Tronmon
int computersPick(){
	int Pick = rand() % 2 + 1;
	return Pick;
}

int main(){
	srand(time(NULL));
	char playAgain = 'y';
	while(playAgain == 'y'){
		cout << "Which Tronmon would you like?\n 1. Tronamander\n" <<
		" 2. Bulbatron\n 3. Squirtron\n\n";
		int numberType;
		cin >> numberType;
		Tronmon a(numberType);
		numberType = computersPick();
		Tronmon b(numberType);
		
		cout << "\nYour " << a;
		cout << "The computer's " << b;
		while(a.alive() && b.alive()){
			a.userBattle(b);
			b.computerBattle(a);
			
			cout << "\nYour " << a;
			cout << "The computer's " << b;
		}
		if(a.alive())
			cout << "YOU WIN!!!!\n";
		else
			cout << "COMPUTER WINS!!!!\n";
		
		
		cout << "\n\nWant to play again? y/n?\n";
		cin >> playAgain;
}
	return 0;
}
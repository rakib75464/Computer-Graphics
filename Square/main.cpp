#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

enum Color {RED, GREEN, BLUE, YELLOW, PURPLE };

Color generateRandomColor() {
    int randomNum = rand() % 5;
    return static_cast<Color>(randomNum);
}

 string colorToString(Color color) {
    switch (color) {
        case RED:
            return "Red";
        case GREEN:
            return "Green";
        case BLUE:
            return "Blue";
        case YELLOW:
            return "Yellow";
        case PURPLE:
            return "Purple";
        default:
            return "Unknown";
    }
}

int main(){
	srand(time(0));

	Color targetColor = generateRandomColor();

	string guess;

	while(true){
		system("cls");
	cout << "Welcome to the Colored Square Game!" << endl;
cout << "***********************************" <<endl;
cout << "Guess the color of the square (Red, Green, Blue, Yellow, or Purple)." <<endl;
cout<<"Enter your guess: ";
cin>>guess;

for (int i = 0; i < guess.length(); ++i) {
            guess[i] =tolower(guess[i]);
        }

 if (guess == "red" || guess == "green" || guess == "blue" ||
	guess == "yellow" || guess == "purple"){

	Color userColor;
	if(guess == "red")
	userColor = RED;

	else if (guess == "green")
        userColor = GREEN;

       else if (guess == "blue")
        userColor = BLUE;

       else if (guess == "yellow")
         userColor = YELLOW;

       else if (guess == "purple")
         userColor = PURPLE;

      if (userColor == targetColor) {
    cout<<endl;
  cout << "Congratulations! You guessed the correct color." << endl;
     break;
   }

	 else {
          cout << "Wrong guess. Try again!" << endl;
        }
	}

else {
    cout << "Invalid color. Please enter a valid color." << endl;
        }
        Sleep(1000);
	}//while
}//main

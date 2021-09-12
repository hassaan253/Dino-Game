#include "header.hpp"

/*****   Take care that x_obj_movcon, score, speed, k, wing,choice and legs are all static variables, some declared as global variable in header file *****/

int main() {
	/*display opening screen fucntion*/
	/*set up game screen*/
	gui();
	setup();
	char user_input; // declared before loop 
	while (true) { //infinite loop
		static int random_number = 1;
			/*initially set it to 1, then it will change between 1 and 2 depending
											 upon which either tree or bird will be rendered*/
		
		while (!_kbhit()) {
			dinosaur();
			random_object();

			
		}
		user_input = _getch();
		
		if (user_input == ' ') {
			for (int i = 0; i<10; i++) { // the sequence of dino jumping and goin up!)
				dinosaur(1);
				random_object();
				
			}
			for (int j = 0; j<10; j++) { //sequence of dino falling
	dinosaur(2);
	random_object();
	}
}
	if (user_input == 'x') {
		go_to(36,8);
		printf("Game Over");
		delay(500);
		return 0;
			
		}
	}
}
			



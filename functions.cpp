#include "header.hpp"

/*****  Take care that x_obj_movcon, score, speed, k, choice,wing and legs are all static/macro/global in header file ***************/
void go_to(int x, int y) { //a function to allow us to move around console screen by own choice
    COORD coordinate; // defines co-ordinates of character cell in console, origin is (0,0) the top left cell
    coordinate.X = x;
    coordinate.Y = y;
    /*this function sets new cursor position to given coordinate*/
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void gui() {
    system("cls"); // clear screen 
    system("Color 0B"); //makes the background color black, and text color light aqua//


    printf("=============        =========    ====      ====    ==========       ==========      ===           ===    ====      ===\n");
    printf("|   _______  \\\\          |         | \\       |     //        \\\\     ||       \\\\       ||          ||       | \\       |\n");
    printf("|  |       | ||          |         |  \\      |     ||        ||     ||        ||      ||          ||       |  \\      |\n");
    printf("|  |       | ||          |         |   \\     |     ||        ||     ||        ||      ||          ||       |   \\     |\n");
    printf("|  |       | ||          |         |    \\    |     ||        ||     ||        //      ||          ||       |    \\    |\n");
    printf("|  |       | ||          |         |     \\   |     ||        ||     ||========        ||          ||       |     \\   | \n");
    printf("|  |       | ||          |         |      \\  |     ||        ||     ||        \\\\      ||          ||       |      \\  |\n");
    printf("|  |       | ||          |         |       \\ |     ||        ||     ||        ||      ||          ||       |       \\ |\n");
    printf("|  |_______| ||          |         |        \\|     \\\\        //     ||        ||      \\\\          //       |        \\|\n");
    printf("===============      =========   ====       ===      ========      ===       ===        ==========        ===       ===\n");
    
    printf("\nEnter S to start\n");
    char c;
    std::cin >> c;
    while (c != 'S') {
        printf("Please focus!\n");
        std::cin >> c;
    }

}




void setup() { /*sets up screen*/
    system("cls");
    system("Color 08"); // sets color to gray
    go_to(10, 2);
    printf("Enter space to jump, x to exit");
    go_to(62, 2);
    printf("Score:");
    go_to(1, 25); // to print the 'ground' for dino to run on, 80 cells long
    for (int i = 0; i < 80; i++) printf("%c",upperhalf);
}

void delay(int mseconds) {
    clock_t goal = mseconds + clock(); //this is acting like a timer, for the amount of mseconds given
    while (goal > clock()); //this will delay program by setting up empty loop
}
/* Ü renders bottom half of cell, Û renders whole cell,ß renders top half */

void random_object (){ /* this function generates a random choice int , based on it chooses to output either tree or bird, choice is randomt*/
    static int k = 0;  /* k is arbitrary counter, it counts iterations of function in while, in 74 iterations, object will reach left end of screen, then k will allow choice integer to be changed to random value and be reset to 0*/
	
	static int choice = 0; /* kept static so that each time function is called value isnt reset to 0*/
	if (k == 73) {
 	choice = rand() % 2;
	 k = 0;
               }
    
	if (choice == 0) {
             bird();
 } 
             else if (choice == 1) {
        tree();
 }
    k++;
   }

                  





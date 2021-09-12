#include "header.hpp"
/*****   Take care that x_obj_movcon, score, speed, k, wing, legs,choice and y are all static/global variables ***************/

/**** ascii character codes for cells, are contained as macrodefinitions in header.hpp ********/

int y; // will control dino movement when it jumps
int score = 0; /* score declared here as it needs to be acessed by both bird and tree function */


void dinosaur(int jump) { 
//render dino, ß is printed on console as a space covering top half of cell, while Ü prints lower half and Û covers whole cell 
/* jump set to zero intially, jump = 1 when dino is going up, and jump = 2 when dino is coming down*/

	if (jump == 0) {
        y = 0;           }  /* so if dino isnt jumping, y will also stay at zero*/
        else if (jump == 2) {
        y--;}
    	else  {
        y++;  }
/** rendering starts **/ 
	go_to(2, 15 - y);
printf("                    "); // cleans the line above the dino's head
	go_to(2, 16 - y);
printf("         %c%c%c%c%c%c%c ",lowerhalf,upperhalf,wholeblock,wholeblock,wholeblock,wholeblock,lowerhalf);
	go_to(2, 17 - y);
printf("         %c%c%c%c%c%c%c%c ", wholeblock,wholeblock,wholeblock,wholeblock,wholeblock, wholeblock,wholeblock,wholeblock);	
	go_to(2, 18 - y);
printf("         %c%c%c%c%c%c%c%c ", wholeblock, wholeblock, wholeblock, wholeblock, wholeblock,lowerhalf,lowerhalf,lowerhalf);
	go_to(2, 19 - y);
printf(" %c     %c%c%c%c%c%c%c%c     ", lowerhalf, lowerhalf,wholeblock, wholeblock, wholeblock, wholeblock, upperhalf,upperhalf,upperhalf);
	go_to(2, 20 - y);
printf(" %c%c%c  %c%c%c%c%c%c%c%c%c%c   ", wholeblock, wholeblock, lowerhalf, wholeblock, wholeblock, wholeblock, wholeblock, wholeblock, wholeblock, lowerhalf, lowerhalf, lowerhalf,lowerhalf);
    go_to(2, 21 - y);
printf(" %c%c%c%c%c%c%c%c%c%c%c%c  %c      ", upperhalf, wholeblock, wholeblock, wholeblock, wholeblock, wholeblock, wholeblock, wholeblock, wholeblock, wholeblock, wholeblock, wholeblock, upperhalf);
    go_to(2, 22 - y);
printf("   %c%c%c%c%c%c%c%c%c    ", upperhalf, wholeblock, wholeblock, wholeblock, wholeblock, wholeblock, wholeblock, wholeblock, upperhalf);
    go_to(2, 23 - y);
    // to give illusion of dino moving its legs
    static int legs = 1; // for legs being 1 and 2, rendered image will switch between 2 images, kept static so it's value isnt changed automatically between function calls
    
    if (jump == 1 or jump == 2) { // checks if dino is jumping or not
        
        printf("    %c%c%c %c%c", wholeblock, wholeblock, upperhalf, upperhalf, wholeblock);
        go_to(2, 24 - y);
        printf("    %c%c   %c%c      ", wholeblock, lowerhalf, wholeblock, lowerhalf);
    }

    else if (legs == 1) {
        printf("    %c%c%c%c  %c%c%c     ", upperhalf, wholeblock, wholeblock, lowerhalf, lowerhalf, lowerhalf, lowerhalf);
        go_to(2, 24 - y);
        printf("      %c%c         ", wholeblock, lowerhalf);
        legs = 2;
    }
    else if (legs == 2) {
      
        printf("     %c%c%c %c%c      ",upperhalf,wholeblock,lowerhalf,upperhalf,wholeblock);
        go_to(2, 24 - y);
    
        printf("          %c%c     ",wholeblock,lowerhalf);
        legs = 1;
    }
    go_to(2, 25 - y);
    if (jump != 0) printf("                "); //this serves as a cleaner and erases the previous characters below the dino
    else printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf); // and if its not jumping then it will just render the ground
    delay(speed); // will pause programme for 400ms
}





void tree() {
    // will control movement of tree in horizontal direction
    if (x_obj_movcon == 55 && y < 4) // for this condition the tree and dino will collide
    { // game will be reset
    score=-1; //reset score
    speed=40; //reset speed
    go_to(36,8);
    printf("Game Over");
    getch();
    go_to(36,8);
    printf("         ");
    }
    
     //space is left around the printf symbols so that previous rendered characters can be clear
    go_to(74 - x_obj_movcon, 20);
    printf("%c    %c  ", wholeblock, wholeblock);
    go_to(74 - x_obj_movcon, 21);
    printf("%c    %c  ", wholeblock, wholeblock);
    go_to(74 - x_obj_movcon, 22);
    printf("%c%c%c%c%c%c  ", wholeblock, lowerhalf, lowerhalf, lowerhalf, lowerhalf, wholeblock);
    go_to(74 - x_obj_movcon, 23);
    printf("  %c     ",wholeblock);
    go_to(74 - x_obj_movcon, 24);
    printf("  %c   ",wholeblock);


    x_obj_movcon++; // x will increase after each time its run, making it look like tree is moving horizontally
    if (x_obj_movcon == 73) /* when x = 73, cactus will be at left end of screen*/ {
        x_obj_movcon = 0;
        score++;
	go_to(70,2);
	printf("     ");
    	go_to(70,2);
    	printf("%d",score);
    	if(speed>20)
        speed--;
}
}





void bird() {
    // will control movement of bird in horizontal direction
    if (x_obj_movcon == 57 && y < 3) // for this condition the bird and dino will collide
    { // game will be reset
    score= -1; //reset score,
    speed=40; //reset speed
    go_to(36,8);
    printf("Game Over");
    getch();
    go_to(36,8);
    printf("         ");
        
    }
    static int wing = 1;
    if (wing == 1) {
        go_to(74 - x_obj_movcon, 19); // add extra space to clear characters behind it
        printf("     %c    ",lowerhalf);
        go_to(74 - x_obj_movcon, 20);
        printf("     %c%c    ",wholeblock,lowerhalf);
        go_to(74 - x_obj_movcon, 21);
        printf("  %c  %c%c%c ", lowerhalf, wholeblock, wholeblock, lowerhalf);
        go_to(74 - x_obj_movcon, 22);
        printf("%c%c%c%c%c%c%c%c%c  ", lowerhalf, wholeblock, wholeblock, wholeblock, wholeblock, wholeblock, wholeblock, wholeblock, lowerhalf);
        go_to(74 - x_obj_movcon, 23);
        printf("  %c%c%c%c%c%c%c   ", upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, lowerhalf, lowerhalf);
        go_to(74 - x_obj_movcon, 24);
        printf("          "); // clears the space of previous wing
        go_to(74 - x_obj_movcon, 25);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf, upperhalf); // re-renders ground
        wing = 2;
    }
    else if (wing == 2) {

        go_to(74 - x_obj_movcon, 19); // add extra space to clear characters behind it
        printf("        ");
        go_to(74 - x_obj_movcon, 20);
        printf("         ");
        go_to(74 - x_obj_movcon, 21);
        printf("  %c       ",lowerhalf);
        go_to(74 - x_obj_movcon, 22);
        printf("%c%c%c%c%c%c%c%c%c   ", lowerhalf, wholeblock, wholeblock, wholeblock, wholeblock, wholeblock, wholeblock, wholeblock, lowerhalf);
        go_to(74 - x_obj_movcon, 23);
        printf("  %c%c%c%c%c%c%c  ", upperhalf, upperhalf, upperhalf, wholeblock, wholeblock, wholeblock, wholeblock);
        go_to(74 - x_obj_movcon, 24);
        printf("      %c%c%c  ", upperhalf, wholeblock, wholeblock);
        go_to(74 - x_obj_movcon, 25);
        printf("        %c  ",upperhalf);
        wing = 1; //reset wing switch to 1

    }
    x_obj_movcon++; // x will increase after each time its run, making it look like tree is moving horizontally
    if (x_obj_movcon == 73) /* when x = 73, bird will be at left end of screen*/ {
    x_obj_movcon = 0;
    score++;
    go_to(70,2);
    printf("     ");
    go_to(70,2);
    printf("%d",score);
    if(speed>20)
        speed--;
}
}

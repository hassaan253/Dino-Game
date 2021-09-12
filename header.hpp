

#include <conio.h> /*contains keyboard hit and getch*/
#include <iostream>
#include <windows.h>
#include <time.h> /*for the clock_t() function*/
#define wholeblock 219
#define upperhalf 223
#define lowerhalf 220 /*code for ascii characters that are blocks, covering half, and full cells*/

static int x_obj_movcon, speed = 40; /*declared as global variables, all functions have access to them throughout program, must be careful*/
/*****   Take care that 'x_obj_movcon', 'score', 'speed', 'k', 'wing', 'choice' and 'legs' are all static variables *****/


void gui();
void go_to(int x, int y); 
void setup();
void dinosaur(int jump = 0);
void tree();
void delay(int mseconds);
void bird();
void random_object();




/*
 *  Music Quiz 2019 - OCR Programming Task 1
 *  Copyright (C) 2019 - Jack Honour (Jackthehack21/JaxkDev/Jackthehaxk21)
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with this program.
 *  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Auth.h"
#include "Boot.h"

void start();
void startGame();
void printRules();
void authLoop();
char* getRandomSong();

int main()
{
	puts("Music Quiz 2019 by Jackthehack21");
	preboot();
	authLoop();
	start();

	return 1; //*note to self, always return a int, or prog will not end.
}

void authLoop(){
	//returns when finally authenticated.
	printf("\nWelcome, Please enter your username: ");
	char username[255];
	gets(username);
	printf("And your password please: ");
	char password[255];
	gets(password);
	printf("Please wait while we verify your details...\n");
	if(checkAuth(username, password) == 1){
		printf("Authentication Success.\n\n");
		return;
	} else {
		printf("Authentication Failed, Please try again...\n\n");
		authLoop();
	}
	return;
}

void start(){
	printRules();
	//todo main loop.
	startGame();
}

void startGame(){
	int score = 0;
	int try = 0;
	int question = 1;
	int playing = 1; //1-true, 0-false

	while(playing == 1){
		try = 0;
		printf("Question %d:\n",question);
		char* song = getRandomSong();
		puts(song);
		playing = 0;
	}
}

char* getRandomSong(){
	srand(time(NULL));
	int index = ( rand() % 45 ); //get random int between 0-45

	printf("%d",index);
	return "Hi";
}

void printRules(){
	puts("--- Rules of the game ---");
	puts("1. No cheating (eg. Internet)");
	puts("2. No using exploits/bugs found.");
	puts("3. Remember all the above ^");
	puts("-------------------------");
	//todo implement a decent sleep, not one that wastes thread for certain amount of time.
	return;
}
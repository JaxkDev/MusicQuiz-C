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
#define BUFSIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "Auth.h"
#include "Boot.h"

void start();
void startGame();
void printRules();
void authLoop();
void loadAllSongs();
char* getRandomSong();

char songs[0][40] = {}; //0 for current size, 40 for max char* length that goes in it in this case 36 but rounded for safety.
int songsSize = 0;

int main()
{
	srand(time(NULL));
	puts("Music Quiz 2019 by Jackthehack21");
	preboot();
	authLoop();
	loadAllSongs();
	start();

	return 0; //*note to self, always return a int, or prog will not end.
}

void authLoop(){
	//returns when finally authenticated.
	printf("\nWelcome, Please enter your username: ");
	char username[BUFSIZE];
	fgets(username, BUFSIZE, stdin);
	username[strcspn(username, "\n")] = 0; //remove trailing new lines from fgets.
	printf("And your password please: ");
	char password[BUFSIZE];
	fgets(password, BUFSIZE, stdin);
	password[strcspn(password, "\n")] = 0; //remove trailing new lines from fgets.
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
	startGame();
}

void startGame(){
	//int score = 0;
	int try = 1;
	int question = 1;

	while(try < 100){
		printf("Question %d:\n",question);
		char* song = getRandomSong();
		printf(song);
		question++;
		try++;
		//return; //for now
	}
	return;
}

void loadAllSongs(){
	int i = 0;
	char buffer[BUFSIZE];
	FILE *file = fopen("music.txt","r");
    while(fgets(buffer, BUFSIZE, file)){         
        if(strcmp(buffer,"\n") != 0 && strcmp(buffer,"") != 0){
			//puts(buffer);
			strcpy(songs[i], buffer);
			i++;
		}
	}
	songsSize = i;
	return;
}

char* getRandomSong(){
	int index = ( rand() % songsSize ); //get random int between 0 and array size
	return songs[index];
}

void printRules(){
	printf("--- Rules of the game ---\n");
	printf("1. No cheating (eg. Internet)\n");
	printf("2. Dont edit external files.\n");
	printf("\nYou get 2 chances to guess the song.\n");
	printf("^ Remember all the above ^\n");
	printf("-------------------------\n");
	
	//todo implement a decent sleep, not one that wastes thread for certain amount of time.
	return;
}
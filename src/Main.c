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

#include "Auth.h"
#include "Boot.h"

void start();
void printRules();

int main()
{
	puts("Music Quiz 2019 by Jackthehack21");
	preboot();
	printf("\nWelcome, Please enter your username: ");
	char username[255];
	gets(username);
	printf("And your password please: ");
	char password[255];
	gets(password);
	printf("Please wait while we verify your details...\n");
	if(checkAuth(username, password) == 1){
		printf("Authentication Success.\n\n");
		start();
	} else {
		printf("Authentication Failed, Rebooting...\n\n");
		main(); //hmm is this a good way to loop back around ?
		return 0;
	}
	return 0;
}

void start(){
}

void printRules(){
	printf("--- Rules of the game ---");
	//todo
}
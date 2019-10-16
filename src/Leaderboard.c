/*
 *  Music Quiz 2019 - OCR Programming Task 1
 *  Copyright (C) 2019 - Jack Honour (JaxkDev)
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

//Player structure, char* name and int score.
#include "Leaderboard.h"

int saveScore(Player player){
    /*FILE *scoreboardfile = fopen("leaderboard.txt", "a");
 
    fprintf(scoreboardfile, "%s %d\n", player.name, player.score);
    fflush(scoreboardfile);
    fclose(scoreboardfile);
    showLeaderboard();*/
	
	//Load data from leaderboard, parse and sort, then find position and save. (return index/position)
	//Always have 10 items in txt file used for counting the lines.
	return 1;
};

void showLeaderboard(){
    puts("Show LB here...");
};

int getFileSize(char* name){
    puts("TODO getFileSize();");
	return 10;
};

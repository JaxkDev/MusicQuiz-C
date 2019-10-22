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
    FILE *scoreboardFile = fopen("leaderboard.txt", "a");
    
	Player LoadedP[10];
	int i,index, place = 0;
	
	//LOADED DATA:
	
    for(i = 0; (!feof(scoreboardFile) && i<10); i++)
    {
        fscanf(scoreboardFile, "%s %d%*c", LoadedP[i].name, LoadedP[i].score);
        index++;
    }
	
	//INSERT DATA:
	if(index != 9){
		puts("Beware the scoreboard data is not complete and has been tampered with.");
	}
	
	for(i = 0; i <= index; i++){
		if(LoadedP[i].score < player.score){
			int z;
    		for(z=i-1;z>0;z--)
    		{
        		LoadedP[z]=LoadedP[z-1];
    		}
			LoadedP[i] = player;
			place = i+1; //starts at 0.
		}
	}
	
	fclose(scoreboardFile);
	
	FILE *scoreboardfile = fopen("leaderboard.txt", "w");
 
	printf("Current Leaderboard:\n");
    for(i = 0; i <= index; i++){
		printf("%s : %d\n", LoadedP[i].name, LoadedP[i].score);
		fprintf(scoreboardfile, "%s %d\n", LoadedP[i].name, LoadedP[i].score);
	}
    fflush(scoreboardfile);
    fclose(scoreboardfile);
	
	//Load data from leaderboard, parse and sort, then find position and save. (return index/position)
	//Always have 10 items in txt file used for counting the lines.
	return place;
};

#include "rugby.h"

#include <string.h>
#include <assert.h>

int TotalGamesPlayed(void *results, char *team_name)
{
	int cnt = 0;
	char *cur = results;
	while(1){
		int team1_n = 0;
		char* team1_name = cur;
		while(1){
			team1_n++;
			cur++;
			if(*cur == ' ') {
				break;
			}
		}
		// *cur == ' '
		assert(*cur == ' ');
		cur++;
		// *cur == team_1_score
		int sc1 = *cur;
		cur++;
		// *cur == team_2_score
		int sc2 = *cur;
		cur++;
		// *cur == ' '
		assert(*cur == ' ');
		cur++;
		int team2_n = 0;
		char* team2_name = cur;
		while(1){
			team2_n++;
			cur++;
			if(*cur == ';' || *cur == '\0') {
				break;
			}
		}
		assert(*cur == ';' || *cur == '\0');
		// *cur == ';' | '\0'
		if(*cur == '\0') {
			break;
		}
		cur++;
		// *cur == next team

		int team_name_size = strlen(team_name);
		if(team_name_size == team1_n) {
			if(strncmp(team_name, team1_name, team_name_size) == 0) { // EQUAL
				cnt++;
			}
		}
		if(team_name_size == team2_n) {
			if(strncmp(team_name, team2_name, team_name_size) == 0) { // EQUAL
				cnt++;
			}
		}
	}
	return cnt;
}

int TotalPointsScored(void *results, char *team_name)
{
	int cnt = 0;
	char *cur = results;
	while(1){
		int team1_n = 0;
		char* team1_name = cur;
		while(1){
			team1_n++;
			cur++;
			if(*cur == ' ') {
				break;
			}
		}
		// *cur == ' '
		assert(*cur == ' ');
		cur++;
		// *cur == team_1_score
		int sc1 = *cur;
		cur++;
		// *cur == team_2_score
		int sc2 = *cur;
		cur++;
		// *cur == ' '
		assert(*cur == ' ');
		cur++;
		int team2_n = 0;
		char* team2_name = cur;
		while(1){
			team2_n++;
			cur++;
			if(*cur == ';' || *cur == '\0') {
				break;
			}
		}
		assert(*cur == ';' || *cur == '\0');
		// *cur == ';' | '\0'
		if(*cur == '\0') {
			break;
		}
		cur++;
		// *cur == next team

		int team_name_size = strlen(team_name);
		if(team_name_size == team1_n) {
			if(strncmp(team_name, team1_name, team_name_size) == 0) { // EQUAL
				cnt+=sc1;
			}
		}
		if(team_name_size == team2_n) {
			if(strncmp(team_name, team2_name, team_name_size) == 0) { // EQUAL
				cnt+=sc2;
			}
		}
	}
	return cnt;
}

int NumWins(void *results, char *team_name)
{
	int cnt = 0;
	char *cur = results;
	while(1){
		int team1_n = 0;
		char* team1_name = cur;
		while(1){
			team1_n++;
			cur++;
			if(*cur == ' ') {
				break;
			}
		}
		// *cur == ' '
		assert(*cur == ' ');
		cur++;
		// *cur == team_1_score
		int sc1 = *(unsigned char*)cur;
		cur++;
		// *cur == team_2_score
		int sc2 = *cur;
		cur++;
		// *cur == ' '
		assert(*cur == ' ');
		cur++;
		int team2_n = 0;
		char* team2_name = cur;
		while(1){
			team2_n++;
			cur++;
			if(*cur == ';' || *cur == '\0') {
				break;
			}
		}
		assert(*cur == ';' || *cur == '\0');
		// *cur == ';' | '\0'

		int team_name_size = strlen(team_name);
		if(team_name_size == team1_n && strncmp(team_name, team1_name, team_name_size) == 0) {
			if(sc1 > sc2) {
				cnt++;
			}
		}
		cnt+=team_name_size == team2_n && strncmp(team_name, team2_name, team_name_size) == 0 && sc2>sc1;

		if(*cur == '\0') {
			break;
		}
		cur++;
		// *cur == next team
	}
	return cnt;
}

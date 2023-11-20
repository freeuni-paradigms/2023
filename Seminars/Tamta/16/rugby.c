#include "rugby.h"

#include <stdio.h>
#include <string.h>


// ქულად აღვიქვათ ის რიცხვი, რასაც char-ად დაბეჭდავს.
// მაგალითად თუ სტრინგი არის "a 02 b", 
// 0-იანის შესაბამისი ქარაქთერის ბიტური ჩანაწერი ინტად წაკითხვისას იქნება 48. 
// ამ ამოხსნაში a გუნდის მიერ მიღებულ ქულაში ვგულისხმობთ 0 ქულას და არა 48-ს.

// Returns total number of games played by team with given name.
int TotalGamesPlayed(void *results, char *team_name)
{
    int answer = 0;
    char * ptr = results;
    int i = 0; // point to team name start
    int j = 0; // point to team name end
    while(1) {
        while(*ptr != ' ') {
            j++;
            ptr++;
        }
        int len = j-i;
        if (strlen(team_name) == len && strncmp((char*)results + i, team_name, len) == 0) {
            answer++;
        }
        j += 4;
        i = j;
        ptr += 4;
        while(*ptr != ';' && *ptr != '\0') {
            j++;
            ptr++;
        }
        len = j-i;
        if (strlen(team_name) == len && strncmp((char*)results + i, team_name, len) == 0) {
            answer++;
        }
        if (*ptr == '\0') {
            return answer;
        }
        ptr++; // skip ;
        j++;
        i = j;
    }
    return -1;
}

// Returns total points scored across all games by team with given name.
int TotalPointsScored(void *results, char *team_name)
{
    int answer = 0;
    char * ptr = results;
    int i = 0; // point to team name start
    int j = 0; // point to team name end
    while(1) {
        while(*ptr != ' ') {
            j++;
            ptr++;
        }
        int len = j-i;
        if (strlen(team_name) == len && strncmp((char*)results + i, team_name, len) == 0) {
            answer += *((unsigned char*)results + j + 1) - '0';
        }
        j += 4;
        i = j;
        ptr += 4;
        while(*ptr != ';' && *ptr != '\0') {
            j++;
            ptr++;
        }
        len = j-i;
        if (strlen(team_name) == len && strncmp((char*)results + i, team_name, len) == 0) {
            answer += *((unsigned char*)results + i - 2) - '0';
        }
        if (*ptr == '\0') {
            return answer;
        }
        ptr++; // skip ;
        j++;
        i = j;
    }
    return -1;
}

// Returns number of games won by team with given name.
int NumWins(void *results, char *team_name)
{
    int answer = 0;
    char * ptr = results;
    int i = 0; // point to team name start
    int j = 0; // point to team name end
    while(1) {
        while(*ptr != ' ') {
            j++;
            ptr++;
        }
        int len = j-i;
        if (strlen(team_name) == len && strncmp((char*)results + i, team_name, len) == 0) {
            int first_score = *((unsigned char*)results + j + 1);
            int second_score = *((unsigned char*)results + j + 2);
            if (first_score > second_score) answer++;
        }
        j += 4;
        i = j;
        ptr += 4;
        while(*ptr != ';' && *ptr != '\0') {
            j++;
            ptr++;
        }
        len = j-i;
        if (strlen(team_name) == len && strncmp((char*)results + i, team_name, len) == 0) {
            int first_score = *((unsigned char*)results + i - 3);
            int second_score = *((unsigned char*)results + i - 2);
            if (first_score < second_score) answer++;
        }
        if (*ptr == '\0') {
            return answer;
        }
        ptr++; // skip ;
        j++;
        i = j;
    }
    return -1;
}

int main(){
    char* result = "a 02 b;b 10 c";
    printf("%s\n", result);
    printf("TotalGamesPlayed by a: %d\n", TotalGamesPlayed(result, "a"));
    printf("TotalGamesPlayed by b: %d\n", TotalGamesPlayed(result, "b"));
    printf("TotalGamesPlayed by c: %d\n", TotalGamesPlayed(result, "c"));

    printf("TotalPointsScored by a: %d\n", TotalPointsScored(result, "a"));
    printf("TotalPointsScored by b: %d\n", TotalPointsScored(result, "b"));
    printf("TotalPointsScored by c: %d\n", TotalPointsScored(result, "c"));

    printf("NumWins by a: %d\n", NumWins(result, "a"));
    printf("NumWins by b: %d\n", NumWins(result, "b"));
    printf("NumWins by c: %d\n", NumWins(result, "c"));

    return 0;
}
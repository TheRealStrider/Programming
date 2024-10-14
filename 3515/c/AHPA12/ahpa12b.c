#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 100

int main(void) { // Made by Aiden Peyton | Hey that's me!
    FILE *movieReleases = fopen("AHPA #12 - Movie Data.txt","r"); // The sacred file :o
    int year, releases, average;
    float total;
    char title[MAX_LEN];
    char str[MAX_LEN];
    int movieLengthMoney[48] = {0};
    char *starWarsMovies[MAX_LEN];
    size_t starWarsCount = 0;

    while (fgets (str, MAX_LEN, movieReleases ) != NULL ) { // Reading the file
        if (str[0] == 'Y') {
            continue;
        }
        sscanf(str,"%d %f %d %d %[^\n]s",&year,&total,&releases,&average,title);
        movieLengthMoney[strlen(title)] += average;
        if (strstr(title,"Star Wars") != NULL) { // Dynamic memory allocation for Star Wars movies | Hell yeah, memory leaks
            starWarsMovies[starWarsCount] = (char *)malloc(strlen(title) + 1);
            strcpy(starWarsMovies[starWarsCount],title);
            starWarsCount++;
        }
    }
    fclose(movieReleases); // Closing the file | It's over now :)

    printf("0: 0\n");
    for (int i = 0; i < 48; i++) { // Printing the movie title length and the money it made | Limited to 47 for the sake of the console
        if (i == 47) {break;}
        printf("%d: %d\n",i + 1, movieLengthMoney[i]);
    }

    printf("\nThe movie title length that made the most money was "); // Printing the movie title length that made the most money | Duh
    int max = 0;
    int maxIndex;
    for (int i = 0; i < 48; i++) {
        if (movieLengthMoney[i] > max) {
            max = movieLengthMoney[i];
            maxIndex = i;
        }
    }
    printf("%d characters long.\n",maxIndex + 1);

    printf("Star Wars Movies In List:\n"); // Printing Star Wars movies | May the force be with you
    for (int i = 0; i < starWarsCount; i++) {
        printf("%d. %s\n",i, starWarsMovies[i]);
    }

} // I tried so hard and got so far, but in the end, it doesn't even matter
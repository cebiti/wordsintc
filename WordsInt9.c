/*
 * Consider all the 9-letter words from the vocabulary 
 * { 1, 2, 3, 4, 5, 6, 7, 8, 9}
 * in which each letter appears only once. If these words get converted to 
 * numbers, how many words are perfect squares ???
 *
 * Algorihtm design and implementation by Nikolaos Soulios, 21/3/2000.
 * Hardware/Software: p166mmx.32mbedoram/linux 2.2.13 jdk1.1.7
 *
 * Revised: 10/1/2004
 * --Ported from JAVA to C
 * --Function do_it() rewritten using recursion
 * 
 * Development Box: P4@2.4.256MB@333/linux-2.4.22 gcc 3.2.2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void do_it(int);
void checkThisWord(void);

int vocab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // my vocabulary
int used[] = {0, 0, 0, 0, 0, 0, 0, 0, 0}; // flag for each letter of the vocab.
int word[9]; // my word as an array. each letter takes up a slot
int counter = 0;


void do_it(int position) {

	/*
	We scan for the first unused letter.
	and we assign it in the [position]th (first, second, third)
	slot of our word.
	if (we have not reached the last letter)
		We proceed recursively for the letter in the next position.
	else
		we have just created a valid word, which we must now check
	end if
	Release the letter we have just used
	*/
	int i=0;
	for (i=0; i<9; i++) {
		if (used[i] == 0) {
			word[position]=vocab[i];
			used[i]=1;
			if (position<8) {
				do_it(position+1);
			} else 	if (position==8) {
				checkThisWord();
			}
			used[i]=0;
		}
	}
}

void checkThisWord(void) {
	double number=0;
	double multiplier=0;
	double sqrtOfnumber=0;
	int i=0;
	for (i=8; i>=0; i--) {
		multiplier=pow((double)10, (double)i);
		number+= ( (word[i]) * (multiplier) ); // number = word[i]*10^i
	}
	sqrtOfnumber = sqrt(number);
	if ( sqrtOfnumber == floor(sqrtOfnumber) ) {
		printf("Number: %f , square of: %f\n", number,sqrtOfnumber);
		counter++;
	}
}

int main(void) {
	printf("--------------------------------------------------------------------------------\n");
	printf("Consider all the 9-letter words from the vocabulary {1, 2, 3, 4, 5, 6, 7, 8, 9},\n");
	printf("in which each letter appears only once. If these words get converted to numbers,\n");
	printf("how many and which of there words are perfect squares ???\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("\n");printf("\n");
	printf("Algorith Copyright, Design and Implementation by Nikolaos Soulios, 21/3/00\n");
	printf("Third revision 10/1/2004: complete rewrite in C.\n");
	printf("\n");
	//printf("Press [ENTER] to start...\n");
	printf("Scanning...\n");
	do_it(0);
	printf("I've found %d valid words\n", counter);
	getc(stdin);
	return 0;
}






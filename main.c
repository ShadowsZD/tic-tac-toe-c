#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "velha.h"

/*  Field
   0  1  2
   3  4  5
   6  7  8
*/

int main(){
    Table* states;         //Array of possible game fields
    Table initialState;
    int totalStates, i;
    totalStates = 1;
    strcpy(initialState.field, "X...O....");     //defining initial field
    initialState.nextSymbol = 'O';               //defining next "player"
    states = malloc(3000*sizeof(Table));         //allocating space for the possible fields combination
    strcpy(states[0].field, initialState.field);
    states[0].nextSymbol = initialState.nextSymbol;
    generateNextStates(states, &totalStates, initialState);        //generate possible combinations out of given one
    removeParsed(states, &totalStates);                            //remove the given state from the list of combinations
    while(totalStates != 0){
        if(!gameEnded(states[0])){
            generateNextStates(states, &totalStates, states[0]);      //always generates combination from the first element of array
        }
        removeParsed(states, &totalStates);                           //removes first element after treating it
    }
	return 0;
}

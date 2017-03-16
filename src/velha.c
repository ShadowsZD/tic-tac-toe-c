#include "velha.h"
#include <stdlib.h>

void generateNextStates(Table* states, int* totalStates, Table state){
    int i, add, j;
    Table newState;
    add = 1;
    for(i=0;i<9;i++){
        strcpy(newState.field, states[0].field);              //resets the field for next iteration
        if(state.field[i] == '.'){
            newState.field[i] = state.nextSymbol;
            if(state.nextSymbol == 'O') newState.nextSymbol = 'X';
            else newState.nextSymbol = 'O';
            for(j=0;j<*totalStates;j++){                                //TO DO: improving loop ?
                if(strcmp(states[j].field, newState.field) == 0){
                    add = 0;                       //if the field already exists in the array, do not add because of duplicates
                    break;
                }
            }
            printf("\"%s\" -> \"%s\"\n", state.field, newState.field);        //print state -> nextPossible combination
            if(add == 1){
                strcpy(states[*totalStates].field, newState.field);
                states[*totalStates].nextSymbol = newState.nextSymbol;
                *totalStates = *totalStates + 1;
            }
        }
        add = 1;
    }
}

int gameEnded(Table state){

	int i, free_spaces = 0;
	//rows
	if (state.field[0] == state.field[1] && state.field[1] == state.field[2]){
        if (state.field[0] == 'O' || state.field[0] == 'X'){
            return 1;
		}
	}
    if (state.field[3] == state.field[4] && state.field[4] == state.field[5]){
        if (state.field[3] == 'O' || state.field[3] == 'X'){
            return 1;
		}
	}
    if (state.field[6] == state.field[7] && state.field[7] == state.field[8]){
        if (state.field[6] == 'O' || state.field[6] == 'X'){
            return 1;
		}
	}


	//columns
	if (state.field[0] == state.field[3] && state.field[3] == state.field[6]){
        if (state.field[0] == 'O' || state.field[0] == 'X'){
            return 1;
		}
	}
	if (state.field[1] == state.field[4] && state.field[4] == state.field[7]){
        if (state.field[1] == 'O' || state.field[1] == 'X'){
            return 1;
		}
	}
	if (state.field[2] == state.field[5] && state.field[5] == state.field[8]){
        if (state.field[2] == 'O' || state.field[2] == 'X'){
            return 1;
		}
	}


	//diagonals
	if (state.field[0] == state.field[4] && state.field[4] == state.field[8]){
        if (state.field[0] == 'O' || state.field[0] == 'X'){
            return 1;
		}
	}
	if (state.field[2] == state.field[4] && state.field[4] == state.field[6]){
        if (state.field[2] == 'O' || state.field[2] == 'X'){
            return 1;
		}
	}

	//full
	for(i=0;i<9;i++){
		if(state.field[i] == '.') free_spaces++;
	}
	if(free_spaces == 0) return 1;
	return 0;
}


void removeParsed(Table* states, int* totalStates){
    int i;
    for(i=0;i<*totalStates;i++){
        strcpy(states[i].field, states[i+1].field);
        states[i].nextSymbol = states[i+1].nextSymbol;
    }
    *totalStates =  *totalStates - 1;
}



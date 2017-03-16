#ifndef VELHA_H_INCLUDED
#define VELHA_H_INCLUDED

typedef struct{
    char field[10];      //Field + /0
    char nextSymbol;     //Next "player" to move ('X' or 'O')
}Table;

int gameEnded(Table);
void generateNextStates(Table*, int*, Table);
void removeParsed(Table*, int*);

#endif // VELHA_H_INCLUDED

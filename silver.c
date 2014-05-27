/*
    Acest program probabil este prost.
    Scopul vostru este sa ii re-aduceti inteligenta!
*/

#include <stdio.h>

char v[30];

int main()
{
    int n, i;
    int dupaX, inainteX, posX;
    char c;

    n = 0;
    i = 0;
    posX = -1;
    inainteX = dupaX = 0;
    c = fgetc(stdin);
    //Punem valorile in vector si numaram cate 'O'-uri sunt inainte de X si cate dupa X
    while ( c != '\n' ){
        if ( c == 'X' ){
            posX = i;
            v[posX] = 'X';
        }
        else if ( c != '-' ){
            v[i] = c;

            if ( posX == -1 )
                inainteX++;
            else
                dupaX++;
        }
        i++;
        c = fgetc( stdin );
    }
    //Castigam jocul daca putem
    n = i;
    if ( inainteX == 0 ){
        v[posX] = 0;
    }
    //Daca nr. de 'O'-uri inaintea lui X este impar, incercam sa creem o sansa de castig, mutand o piesa de dupa
    //X la dreapta
    else if ( inainteX % 2 == 1 ){
        i = posX + 2;
        while ( i < n && v[i] == 0 )
            i++;
        if ( i == n ){
            if ( posX - 1 > 0 && inainteX == 1 && v[posX - 1] == 'O' ){
                v[posX - 2] = 'O';
                v[posX - 1] = 0;
            }
            else if( posX > 1 && v[posX - 1] == 0 ){
                v[posX - 1] = 'X';
                v[posX] = 0;
                posX--;
            }
            else{
                i = 0;
                while ( i < n && v[i] == 0 )
                    i++;
                v[i] = 0;
            }
        }
        else {
            if ( i > posX + 2 || (i == posX + 2 && v[posX + 1] == 0) ){
                v[i - 1] = v[i];
                v[i] = 0;
            }
            else{
                i++;
                while ( i < n && v[i] == 0 )
                    i++;
                v[i - 1] = v[i];
                v[i] = 0;
            }
        }
    }
    else {
        i = 0;
        while ( i < n && v[i] == 0 )
            i++;
        v[i] = 0;
    }

    for ( i = 0; i < n; i++ ){
        if ( v[i] == 0 )
            fputc( '-', stdout );
        else
            fputc( v[i], stdout );
    }
    fputc( '\n', stdout );
    return 0;
}

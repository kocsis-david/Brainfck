#include <stdio.h>
#include <stdlib.h>
int main() {
    char programkod[] = {"++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>+++++.>+++++++++++.------------.++++++++++++++++.----------.++++++++++.<<++.>-------.>------------------.+++++++++++++++++++++.-------------.-----."};
    int szalag[32768] = {0};
    int i=0, pointer=0, tempindex=0, zar=0, szintax=0;
    int szintaxi=0;
    char checker;

    while(programkod[szintaxi]!=0){
        if(programkod[szintaxi]=='[')szintax++;

        if(programkod[szintaxi]==']')szintax--;

        szintaxi++;
    }
    if(szintax!=0){
        printf("Szintax hiba a kódban!");
        exit(-1);
    }

    while(programkod[i] != 0){


        switch (programkod[i]) {
            case '-': 
                szalag[pointer]--;
                break;

            case '+':
                szalag[pointer]++;
                break;


            case '>':
                pointer+=1;
                break;

            case '<':
                pointer-=1;
                break;

            case ',':
                scanf("%c",&checker);
                if(checker!=0){
                    programkod[pointer]=checker;
                }else programkod[pointer]=(-1);

                break;

            case '.':
                checker=(char) szalag[pointer];
                printf("%c",checker);
                break;

            case '[':
                if( szalag[pointer]==0) {
                    tempindex = i + 1;
                    zar=1;
                    while(zar){
                        if(programkod[tempindex]=='['){
                            zar++;
                        }
                        if(programkod[tempindex]==']'){
                            zar--;
                        }
                        tempindex++;
                    }
                    i=tempindex-1;
                }

                break;
            case ']':
                tempindex = i - 1;
                zar=1;
                while (zar){
                    if(programkod[tempindex]==']'){
                        zar++;
                    }
                    if(programkod[tempindex]=='['){
                        zar--;
                    }
                    tempindex--;
                }
                i = tempindex;
                break;


            default:
                break;

        }

    i++;
    }

    return 0;
}

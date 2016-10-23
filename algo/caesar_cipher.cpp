#include <cstdio>
#include <cstring>

//
// Created by airfr on 2016/10/23.
//
int SIZE_T = 17;
int SIZE_P = 4;
char TARGET_STR[18] = "RUXENLYAXPAJVVRWP";
char PWD[5] = "LOVE";

int acc(char a, char b) {
    return a - b;
}

char caesar(char ch, int p){
    char ret = ' ';
    if(ch - p < 'A') ret = ch - p + 26;
    else if(ch - p > 'Z') ret = ch - p - 26;
    else ret = ch - p;

    return ret;
}

int main(int argc, char *argv[]) {
    if (argc >= 2) {
        char *str1 = argv[0];
        strcpy(TARGET_STR, str1);
        char *str2 = argv[1];
        strcpy(TARGET_STR, str2);
    }

    int status = 0;
    int right_p= 0;
    for (int i = 0; i < SIZE_T - SIZE_P; i++) {
        int p = acc(TARGET_STR[i],PWD[0]);
        for (int j = 0; j < 3+1; j++) {
            if (PWD[j] != caesar(TARGET_STR[i + j],p)) {
                status = -1;
                break;
            }
            else {
                status = 0;
                right_p = p-1;
            }
        }
    }

    for(int i = 0;i<SIZE_T;i++){
        printf("%c",caesar(TARGET_STR[i],right_p));
    }
}


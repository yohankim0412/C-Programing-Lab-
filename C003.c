#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findRoom(int persons[5]); 
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc, int person[2][5]);

int main() {
    char mnames[10][20]; 
    int mroom[10];       
    char wnames[10][20]; 
    int wroom[10];       
    int person[2][5] = {0}; 
    int mcount = 0, wcount = 0; 
    int menu;

    printf("===========================================\n");
    printf("생활관 호실 배정 프로그램\n");
    printf("===========================================\n");

    while (1) {
        printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
        scanf("%d", &menu);
        if (menu == 0) break;
        else if (menu == 1) {  
            if (mcount >= 10) {
                printf("정원 초과입니다. 등록불가!\n");
                continue;
            }
            printf("학생 이름은? > ");
            scanf("%s", mnames[mcount]);
            int roomno = findRoom(person[0]); 
            if (roomno == -1) {
                printf("남학생 방이 모두 찼습니다. 배정 불가!\n\n");
                continue;
            }
            mroom[mcount] = 100 + roomno;
            person[0][roomno - 1]++;  
            printf("%s 학생 %d호실 배정되었습니다.\n\n", mnames[mcount], mroom[mcount]);
            mcount++;
        }
        else if (menu == 2) {  
            if (wcount >= 10) {
                printf("정원 초과입니다. 등록불가!\n");
                continue;
            }
            printf("학생 이름은? > ");
            scanf("%s", wnames[wcount]);
            int roomno = findRoom(person[1]); 
            if (roomno == -1) {
                printf("여학생 방이 모두 찼습니다. 배정 불가!\n\n");
                continue;
            }
            wroom[wcount] = 200 + roomno;
            person[1][roomno - 1]++;  
            printf("%s 학생 %d호실 배정되었습니다.\n\n", wnames[wcount], wroom[wcount]);
            wcount++;
        }
    }

    printf("===========================================\n");
    printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
    printf("===========================================\n");
    printReport(mnames, mroom, mcount, wnames, wroom, wcount, person);

    return 0;
}


int findRoom(int persons[5]) {
    for (int i = 0; i < 5; i++) {
        if (persons[i] < 2) {  
            return i + 1;  
        }
    }
    return -1; 
}


void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc, int person[2][5]) {
    printf("\n남학생 명단 (%d명)\n", mc);
    for (int i = 0; i < mc; i++) {
        printf("%d. %s [%d]\n", i + 1, mn[i], mr[i]);
    }

    printf("\n여학생 명단 (%d명)\n", wc);
    for (int i = 0; i < wc; i++) {
        printf("%d. %s [%d]\n", i + 1, wn[i], wr[i]);
    }

    printf("\n호실별 학생 명단\n");
    for (int i = 0; i < 5; i++) {
        printf("%d호: ", 101 + i);
        int found = 0;
        for (int j = 0; j < mc; j++) {
            if (mr[j] == 101 + i) {
                printf("%s ", mn[j]);
                found = 1;
            }
        }
        if (!found) printf("빈 방");
        printf("\n");
    }
    for (int i = 0; i < 5; i++) {
        printf("%d호: ", 201 + i);
        int found = 0;
        for (int j = 0; j < wc; j++) {
            if (wr[j] == 201 + i) {
                printf("%s ", wn[j]);
                found = 1;
            }
        }
        if (!found) printf("빈 방");
        printf("\n");
    }
}

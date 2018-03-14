#include<stdio.h>
#include<Windows.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>
char a[30][50];
int main(){
	int score = 0;
	int f = 0;
	while (f == 0){
		printf("1.게임 시작\n2.조작법\n3.종료\n");
		int in;
		scanf("%d", &in);
		switch (in){
		case 1: f = 1; break;
		case 2: printf("wasd:이동  space bar:폭탄\n"); break;
		case 3: return 0;
		}
	}
	a[25][25] = 'o';
	int i = 25, j = 25;
	int bomb = 3;
	char insert = 0;
	while (1){
		for (int s = 29; s >= 0; s--){
			for (int v = 0; v<50; v++){
				if (a[s][v] == '*'){
					if (s == 29){
						a[s][v] = NULL;
						continue;
					}
					if (a[s + 1][v] == 'o'){
						system("cls");
						printf("score:%d\ngame over", score);
						return 0;
					}
					a[s][v] = NULL;
					a[s + 1][v] = '*';
				}
				else if (a[s][v] == 'b'){
					if (s == 29){
						a[s][v] = NULL;
						continue;
					}
					if (a[s + 1][v] == 'o'){
						a[s][v] = NULL;
						bomb++;
						break;
					}
					a[s][v] = NULL;
					a[s + 1][v] = 'b';
				}
			}
		}
		for (int s = 0; s<10; s++){
			int i1 = rand() % (3 + 1 - 0) + 0;
			int j1 = rand() % (50 + 1 - 0) + 0;
			if (a[i1][j1] == 'o'){
				continue;
			}
			a[i1][j1] = '*';
		}
		if (score % 40 == 0){
			int i1 = rand() % (3 + 1 - 0) + 0;
			int j1 = rand() % (50 + 1 - 0) + 0;
			a[i1][j1] = 'b';
		}
		system("cls");
		printf("bomb:%d  score:%d\n", bomb, score);
		printf("--------------------------------------------------\n");
		for (int s = 0; s < 30; s++){
			for (int v = 0; v < 50; v++){
				printf("%c", a[s][v]);
			}
			printf("|\n");
		}
		printf("--------------------------------------------------");
		insert = getch();
		switch (insert){
		case 'w':score++; a[i][j] = NULL; i--; break;
		case 'a':score++; a[i][j] = NULL; j--; break;
		case 's':score++; a[i][j] = NULL; i++; break;
		case 'd':score++; a[i][j] = NULL; j++; break;
		case 32:if (bomb>0){
			for (int s = -3; s <= 3; s++){
				for (int v = -3; v <= 3; v++){
					if (v == 0 && s == 0)continue;
					a[i + s][j + v] = NULL;
				}
			}
			bomb--;
		}break;
		}
		if (i < 0){
			a[i][j] = NULL;
			i = 0;
		}
		if (j < 0){
			a[i][j] = NULL;
			j = 1;
		}
		if (i >= 30){
			a[i][j] = NULL;
			i = 29;
		}
		if (j >= 50){
			a[i][j] = NULL;
			j = 49;
		}
		if (a[i][j] == '*'){
			system("cls");
			printf("score:%d\ngame over", score);
			return 0;
		}
		else if (a[i][j] == 'b'){
			bomb++;
		}
		a[i][j] = 'o';
		system("cls");
		printf("bomb:%d  score:%d\n", bomb, score);
		printf("--------------------------------------------------\n");
		for (int s = 0; s < 30; s++){
			for (int v = 0; v < 50; v++){
				printf("%c", a[s][v]);
			}
			printf("|\n");
		}
		printf("--------------------------------------------------\n");
	}
}

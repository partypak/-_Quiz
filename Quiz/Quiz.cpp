#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000     // 파일에 저장된 값을 보여줄때
#include<stdio.h>    // 입출력을 하기 위해 선언 
#include<ctype.h>    // 대소문자를 대문자로 변화시 사용시 사용
#include <conio.h>   // getch 함수를 사용하기 위해 선언 
#include<windows.h>  // 화면을 지우기 위해서 선언 

void help(); // 도움말
void save_score(char[], int, char[], char[]); // 80점 이상이면 txt 파일을 저장하는 함수
void show_record();                           // 저장된 파일을 보여주는 함수

#include "stdio.h"
int main() {
	int r, count = 0, i;
	int score = 0;
	char choice;
	char playername[20];
	char jump1[20] = { "이름 :  " };   //점수보기 화면에서 이름을 나타내주는 배열
	char jump2[20] = { "   점수 : " }; //점수보기 화면에서 점수를 나타내주는 배열
mainhome: // goto 함수의 목적지
	system("cls"); //화면지우기
	printf("\t\t\t   프로그램 퀴즈 게임\n");
	printf("\n\t\t________________________________________");

	printf("\n\n\t\t\t     환영합니다.  ");
	printf("\n\t\t\t       ");
	printf("\n\t\t\t     퀴즈를 시작하세요.  ");
	printf("\n\t\t________________________________________");
	printf("\n\t\t________________________________________");
	printf("\n\n\t\t     넌센스 퀴즈 맞추기  !!!!!!!!!!!    ");
	printf("\n\t\t________________________________________");
	printf("\n\t\t________________________________________");
	printf("\n\n\t\t > 게임 시작은  S");
	printf("\n\n\t\t >  점수 보기 V  ");
	printf("\n\n\t\t > 도움말  H             ");
	printf("\n\n\t\t > 중단은  Q 를 클릭해 주세요. ");
	printf("\n\n\t\t________________________________________\n\n");
	choice = toupper(_getche()); //  S, V, H, Q를 입력하면 무조건 대문자로 입력되고 화면에 출력
	if (choice == 'V') // V를 누를시
	{
		system("cls"); //화면 지우기
		show_record(); // 파일에 저장된 점수판 보여주는 함수
		printf("홈으로 돌아가고 싶으시면 아무 버튼이나 누르세요");
		if (toupper(_getche())) //  S, V, H, Q를 입력하면 무조건 대문자로 입력되고 화면에 출력
			goto mainhome; //goto 
	}

	else if (choice == 'H')
	{
		help(); 	_getche();
		goto mainhome;
	}
	else if (choice == 'Q')
		exit(1);
	else if (choice == 'S')
	{
		system("cls"); //화면지우기
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t이름을 입력하세요 : ");
		gets_s(playername, sizeof(playername)); // 이름 입력
		fflush(stdin);


		system("cls");// 화면지우기
		printf("\n\t\t\t 환영합니다.");
		printf("\n\n\n\t\t	%s 님의    퀴즈 게임입니다 ", playername);
		printf("\n\n\t     -------------------------------------------   ");
		printf("\n\n\n\t 1.  문제풀이는 사지선다를 선택하도록 되어 있습니다.  ");
		printf("\n\n\n\t2. A, B ,C , D 의 옵션중 원하는 답을 선택하시면 됩니다. ");
		printf("\n\n\n\t   @@ 꼭 정답을 마추셔서 100점을 취득하세요 ^.^ @@ ");
		printf("\n\n\n\t -------- 게임을 시작하실려면   'Y' 를 누르세요 ! -------\n");

	hard:
		if (toupper(_getche()) == 'Y') // if문을 사용하여 Y 입력시 goto문으로 이동
		{
			goto game;
		}
		else // Y 가 아닐시
		{
			printf("다시입력하세요\n");
			goto hard; // 다시입력하시오 화면으로 이동

		}

	game:
		count = 0; //카운트 변수
		for (i = 1; i <= 5; i++) // for문을 이용하여 5개의 문제 반복
		{
			system("cls"); // 화면지우기
			r = i;// 변수에 값 할당
			switch (r) //switch 문을 사용하여 값에 따라 문제 출력
			{
			case 1:// 1번 문제
				printf("\n\n\n  문제1. '등겹살'이며 목심과 등심의 연결부위에 있는 사람 손바닥만한 오각형 모양의 고기 부위는?");
				printf("\n\n\n\t\tA.삼겹  \n\n\t\tB.갈비  \n\n\t\tC.가브리살\n\n\t\tD.양치살 ");
				printf("\n\n\n\t        정답:_");
				if (toupper(_getche()) == 'C') //입력하면 무조건 대문자로 입력되고 화면에 출력
				{
					printf("\n\n\n\t        정답입니다!!!   \n\n\n\t화면을 넘기시려면 <Enter>"); count++;
					_getche();//입력하면 무조건 대문자로 입력되고 화면에 출력
					break;
				}
				else
				{
					printf("\n\n\n\t        오답입니다  정답은  C.가브리살   \n\n\n\t화면을 넘기시려면 <Enter>");
					_getche();
					break;

				}

			case 2:
				printf("\n\n\n  문제2. 바다가 뜨거우면?");
				printf("\n\n\n\t\tA.열받아 \n\n\t\tB.해운대 \n\n\t\tC.광안리 \n\n\t\tD.지중해 ");
				printf("\n\n\n\t        정답:_");
				if (toupper(_getche()) == 'A') {
					printf("\n\n\n\t        정답입니다!!!   \n\n\n\t화면을 넘기시려면 <Enter>");
					count++;
					_getche();
					break;
				}
				else {
					printf("\n\n\n\t        오답입니다 정답은 C.열받아    \n\n\n\t화면을 넘기시려면 <Enter> ");
					_getche();
					break;
				}

			case 3:
				printf("\n\n\n  문제3. 사람처럼 웃는 동물은 무엇인가요?");
				printf("\n\n\n\t\tA.곰   \n\n\t\tB.하이에나\n\n\t\tC.토끼  \n\n\t\tD.호랑이 ");
				printf("\n\n\n\t        정답:_");
				if (toupper(_getche()) == 'B') {
					printf("\n\n\n\t        정답입니다!!!   \n\n\n\t화면을 넘기시려면 <Enter>"); count++;
					_getche();
					break;
				}
				else {
					printf("\n\n\n\t        오답입니다 !!! 정답은 B.하이에나   \n\n\n\t화면을 넘기시려면 <Enter>");
					_getche();
					break;
				}

			case 4:
				printf("\n\n\n  문제4. 2006 월드컵이 열린 나라는?");
				printf("\n\n\n\t\tA.일본  \n\n\t\tB.독일  \n\n\t\tC.영국  \n\n\t\tD.네덜란드 ");
				printf("\n\n\n\t        정답:_");
				if (toupper(_getche()) == 'B')
				{
					printf("\n\n\n\t        정답입니다!!!   \n\n\n\t화면을 넘기시려면 <Enter>"); count++;
					_getche();
					break;
				}
				else {
					printf("\n\n\n\t        오답입니다 !!! 정답은  B.독일   \n\n\n\t화면을 넘기시려면 <Enter>");
					_getche();
					break;
				}

			case 5:
				printf("\n\n\n  문제5. 쥐 네 마리가 모이면???");
				printf("\n\n\n\t\tA.일포  \n\n\t\tB.이포  \n\n\t\tC.쥐포  \n\n\t\tD.사포   ");

				printf("\n\n\n\t        정답:_");
				if (toupper(_getche()) == 'C')
				{
					printf("\n\n\n\t        정답입니다 !!!   \n\n\n\t화면을 넘기시려면 <Enter>"); count++;
					_getche();
					break;
				}
				else
				{
					printf("\n\n\n\t        오답입니다 !!!정답은  C.쥐포   \n\n\n\t화면을 넘기시려면 <Enter>");
					_getche();
					break;
				}

			}
		}
		system("cls");
		score = count * 20;                    // 점수는 
		if (score >= 80 && score < 100) {

			save_score(jump1, score, jump2, playername);

			printf("\n\n\t\t**************** 우수한 성적입니다  *****************\n\n\n\n");
			printf("\n\n\t\t ***************%s님의 점수는 [%d]입니다.\n\n\n\n", playername, score);

			goto go;
		}
		else if (score == 100) {
			save_score(jump1, score, jump2, playername);

			printf("\n\n\n \t\t**************** 축하합니다.  ****************");
			printf("\n\n\t\t * ***************%s님의 점수는 [%d]입니다.\n\n\n\n", playername, score);
			printf("\n\t\t\t\t 만점입니다 !!!!!!!!!");
			printf("\n\t\t 최고입니다  %d", score);
			goto go;
		}
		else {
			printf("\n\t\t 다시 도전하세요 ^.^");
			goto go;
		}
	go:
		puts("\n\n 게임을 계속하려면 Y를 입력하세요 ");
		puts("\n\n 메인으로 가려면 아무키나 입력하세요  ");
		if (toupper(_getche()) == 'Y') {
			goto game;
		}
		else {

			goto mainhome;
		}
	}
	else
	{
		printf("잘못눌렀습니다.");
		Sleep(1000);
		goto mainhome;
	}
}



void help() {
	system("cls");
	printf("\n\n                              HELP");
	printf("\n -------------------------------------------------------------------------");
	printf("\n ......................... C program 도전과제 ..........");
	printf("\n\n\n1.  총 5개의 문제가 4지 선다형으로 진행되며 \n\n\t10회를 연속으로 진행할 수 있습니다  ");
	printf("\n\n\n2. (A,B,C,D)중 답을 선택합니다 ");
	printf("\n\n\n3. 총 100점이며 한문제당 20점입니다. ");
	printf("\n\n\n4. 80점 미만이 되면  문제를 다시 풀어야 합니다. ");
	printf("\n\n\n5. 80점 이상만 점수가 파일에 저장됩니다.  ");
}

void show_record()

{

	FILE* foc;

	foc = fopen("Game[80 score]_name_score.txt", "r");


	char buffer[MAX] = { 0, };


	fread(buffer, 1, MAX, foc);

	printf("\n\n\t%s\n\n\n", buffer);


	fclose(foc);

}



void save_score(char jump1[20], int score, char jump2[20], char playername[20])
{



	system("cls");

	int cnt = 0;
	char newscore[20];
	sprintf(newscore, "%d", score);

	FILE* foc;



	foc = fopen("Game[80 score]_name_score.txt", "w");




	for (cnt = 0; jump1[cnt] != NULL; cnt++)
		fputc(jump1[cnt], foc);
	for (cnt = 0; playername[cnt] != NULL; cnt++)
		fputc(playername[cnt], foc);
	for (cnt = 0; jump2[cnt] != NULL; cnt++)
		fputc(jump2[cnt], foc);
	for (cnt = 0; newscore[cnt] != NULL; cnt++)
		fputc(newscore[cnt], foc);

	fclose(foc);

}

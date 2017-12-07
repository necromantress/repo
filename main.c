#include <stdio.h>


void print_map(int N, int M, int x, int y, char character,
	       int l1, int l2, int l3, int c1, int c2, int c3)
{
	int i, j;
	for (i = 0; i <= N + 1; i++) {
		for (j = 0; j <= M + 1; j++) {
			if (i == 0 ||  i == N + 1 || j == 0 || j == M + 1) {
				printf("*");
			} else {
				if ((i == l1 && j == c1)
				    || (i == l2 && j == c2)
				    || (i == l3 && j == c3)
				    || (i == y && j == x)) {

					if (i == l1 && j == c1) {
						printf("x");
					}
					if (i == l2 && j == c2) {
						printf("x");
					}
					if (i == l3 && j == c3) {
						printf("x");
                                        }

					if (i == y && j == x)
						printf("%c", character);
				} else printf(" ");
			}
		}
		printf("\n");
	}
}

int main(void)
{
	int N, M, x, y, P;
	int l1 = -1;
       	int l2 = -1;
	int l3 = -1;
	int c1 = -1;
        int c2 = -1;
       	int c3 = -1;
	char type1 = 'a';
	char type2 = 'a';
	char type3 = 'a';
	char move;
	int counter = 0;
	char character = 'v';
    printf("Introdu nr linii si coloane al tablei, coloana si linia personajului, si nr obstacole(maxim3)\n");
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &P);

	if (P == 1){
        printf("Introdu linia, coloana si tipul obiectului\n");
		scanf("%d %d %c", &l1, &c1, &type1);}
	if (P == 2) {
	    printf("Introdu linia, coloana si tipul obiectului\n");
		scanf("%d %d %c", &l1, &c1, &type1);
        printf("Introdu linia, coloana si tipul obiectului\n");
		scanf("%d %d %c", &l2, &c2, &type2);
	}
	if (P == 3) {
        printf("Introdu linia, coloana si tipul obiectului\n");
		scanf("%d %d %c", &l1, &c1, &type1);
        printf("Introdu linia, coloana si tipul obiectului\n");
		scanf("%d %d %c", &l2, &c2, &type2);
		printf("Introdu linia, coloana si tipul obiectului\n");
		scanf("%d %d %c", &l3, &c3, &type3);
	}
	print_map(N, M, x, y, character, l1, l2, l3, c1, c2, c3);
	while ((y + x) != (M + N)) {
		counter++;
		scanf(" %c", &move);
		switch (move) {
			case 'a':
				if (x < 2) break;
				x--;
				if((l1 == y && c1 == x)
				   || (l2 == y && c2 == x)
				   || (l3 == y && c3 == x)) {
					printf("GAME OVER\n");
					return 0;
				} else {
					character = '<';
				}
				break;

			case 'd':
				if (x > M - 1) break;
				x++;
				if((l1 == y && c1 == x)
				   || (l2 == y && c2 == x)
				   || (l3 == y && c3 == x)) {
                                        printf("GAME OVER\n");
                                        return 0;
                                } else {
					character = '>';
				}
				break;

			case 'w':
				if (y < 2) break;
				y--;
				if((l1 == y && c1 == x)
				   || (l2 == y && c2 == x)
				   || (l3 == y && c3 == x)) {
                                        printf("GAME OVER\n");
                                        return 0;
                                } else {
					character = '^';
				}
				break;

			case 's':
				if (y > N - 1) break;
				y++;
				if((l1 == y && c1 == x)
				   || (l2 == y && c2 == x)
				   || (l3 == y && c3 == x)) {
                                        printf("GAME OVER\n");
                                        return 0;
                                } else {
					character = 'v';
				}
				break;

			case 'q':
				return 0;
		/*	default:
				return 0;
		*/
		}

		if (counter % 2 == 0) {
			if (type1 == 'm' || type2 == 'm' || type3 == 'm') {
				if (type1 == 'm') {

					if (x < c1) {
						c1--;
					}
					if (x > c1) {
						c1++;
					}
					if (y < l1) {
						l1--;
					}
					if (y > l1) {
						l1++;
					}

				}

				if(type2 == 'm'){
					if (x < c2) {
						c2--;
					}
					if (x > c2) {
						c2++;
					}
					if (y < l2) {
						l2--;
					}
					if (y > l2) {
						l2++;
					}
				}

				if(type3 == 'm'){
					if (x > c3) {
						c3++;
					}
					if (x < c3) {
						c3--;
					}
					if (y < l3) {
						l3--;
					}
					if (y > l3) {
						l3++;
					}

				}

				if(x == c1 && y == l1) {
					printf("GAME OVER\n");
					return 0;
				}

				if(x == c2 && y == l2){
					printf("GAME OVER\n");
					return 0;
				}

				if(x == c3 && y == l3){
					printf("GAME OVER\n");
					return 0;
				}

			}
		}
		print_map(N, M, x, y, character, l1, l2, l3, c1, c2, c3);
	}

	printf("GAME COMPLETED\n");

	return 0;
}

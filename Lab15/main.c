#include <stdio.h>

void inputFileA();
void task1();
void task2();
void print2System(int num);

int main() {

int choice;

	while (1) {
		puts("1.Input File A:");
		puts("2.Task 1:");
		puts("3.Task 2:");
		puts("0.Exit:");

		printf("\nChoice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1: inputFileA(); break;
		case 2: task1(); break;
		case 3: task2(); break;
		case 0: return 0;
		}
	}
}



void inputFileA() {

	int a, b;

	FILE* A;
	if ((A = fopen("A.txt", "wb")) == NULL) {
		printf("\nError open	A");
		return;
	}

	printf("\nEnter a: ");
	scanf("%d", &a);

	printf("\nEnter b: ");
	scanf("%d", &b);

	fwrite(&a, sizeof(int), 1, A);
	fwrite(&b, sizeof(int), 1, A);

	fclose(A);
}

void task1() {

	int a , b , y;

	FILE* A, *B;
	if ((A = fopen("A.txt", "rb")) == NULL) {
		printf("\nError open	A");
		return;
	}
	if ((B = fopen("B.txt", "w")) == NULL) {
		printf("\nError open   B");
		return;
	}

	fread(&a, sizeof(int), 1, A);
	fread(&b, sizeof(int), 1, A);


	y = (((a >> 2) + (b << 1)) << 3 ) - ((a >> 2) + (b << 1));
	printf("\nY: %d", y);
	printf("\nY right: %d", 7 * (a / 4 + 2 * b));

	fprintf(B, "Y: %d", y);

	fclose(A);
	fclose(B);
}


void task2() {

	int num = 106, res, mask;


	mask = 6;
	res = num & mask;

	puts("\n\nHighlight (probably)");
	printf(" Num =  "); print2System(num);
	printf("\n Mask = "); print2System(mask);
	printf("\n Res =  "); print2System(res);


	mask = 9;
	res = num & ~mask;

	puts("\n\nClearing a bit");
	printf(" Num =  "); print2System(num);
	printf("\n Mask = "); print2System(mask);
	printf("\n Res =  "); print2System(res);


	mask = 32;
	res = num | mask;

	puts("\n\nSetting a bit");
	printf(" Num =  "); print2System(num);
	printf("\n Mask = "); print2System(mask);
	printf("\n Res =  "); print2System(res);


	mask = 80;
	res = num ^ mask;

	puts("\n\nToggling a bit");
	printf(" Num =  "); print2System(num);
	printf("\n Mask = "); print2System(mask);
	printf("\n Res =  "); print2System(res);
}

void print2System(int num) {
	if (num == 0) {
		puts("  0 ");
		return;
	}

	for (int i = 6; i >= 0; i--) printf(" %d", (num >> i) % 2);

}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 80

unsigned int *tower[3];
unsigned int n;

void delay(void);
void showNewFrame(void);
void moveTower(unsigned int **tower1, unsigned int **tower2, unsigned int **tower3, unsigned int n);

int main()
{
	unsigned int c;
	unsigned int *top[3];


	printf("Give the number of disks: ");
	for(;;)
	{
		scanf("%u",&n);
		if(n) break;
		else printf("It can't be zero!\n");
	}

	for(c=0;c<3;c++)
	{
		if(!(tower[c] = calloc(n,sizeof(unsigned int))))
		{
			printf("hi!");
			perror("Unable to continue");
			exit(EXIT_FAILURE);
		}
		top[c] = tower[c] - 1;
	}

	for(c=0;c<n;c++)
	{
		top[0]++;
		*top[0] = n - c;
	}

	showNewFrame();
	moveTower(&top[0],&top[1],&top[2],n);

	showNewFrame();
	system("PAUSE");
	return 0;
}

void showNewFrame(void)
{
	unsigned int h,c,i;
	unsigned int temp;

	system("CLS");
	for(h=0;h<3;h++)
		putchar('\n');
	temp = SCREEN_WIDTH/4;
	for(i=0;i<3;i++)
	{
		for(c=1;c<temp;c++)
		{
			putchar(' ');
		}
		putchar(210);
	}
	putchar('\n');

	for(h=0;h<3;h++)
	{
		for(i=0;i<3;i++)
		{
			for(c=1;c<temp;c++)
			{
				putchar(' ');
			}
			putchar(186);
		}
		putchar('\n');
	}

	h = n;
	while(h--)
	{
		temp = SCREEN_WIDTH/4 - tower[0][h];
		while(--temp > 0)
			putchar(' ');
		temp = tower[0][h];
		while(temp--)
			putchar(205);
		if(tower[0][h])
			putchar(205);
		else
			putchar(186);
		for(c=1;c<3;c++)
		{
			temp = tower[c-1][h];
			while(temp--)
				putchar(205);
			temp = SCREEN_WIDTH/4 - tower[c-1][h] - tower[c][h];
			while(--temp > 0)
				putchar(' ');
			temp = tower[c][h];
			while(temp--)
				putchar(205);
			if(tower[c][h])
				putchar(205);
			else
				putchar(186);
		}
		temp = tower[2][h];
		while(temp--)
			putchar(205);
		putchar('\n');
	}
	temp = SCREEN_WIDTH/4;
	c = SCREEN_WIDTH/8;
	for(i=1;i<c;i++)
		putchar(' ');
	putchar(218);
	for(i++;i<temp;i++)
			putchar(196);
	putchar(208);
	
	for(i=1;i<3;i++)
	{
		for(c=1;c<temp;c++)
		{
			putchar(196);
		}
		putchar(208);
	}

	c = SCREEN_WIDTH/8;
	for(i=1;i<c;i++)
		putchar(196);
	putchar(191);
	for(i++;i<temp;i++)
		putchar(' ');
	putchar('\n');

	for(i=1;i<c;i++)
		putchar(' ');
	putchar(192);
	temp = 3*SCREEN_WIDTH/4;
	for(i=1;i<temp;i++)
		putchar(196);
	putchar(217);
	putchar('\n');putchar('\n');putchar('\n');

}

void moveTower(unsigned int **tower1, unsigned int **tower2, unsigned int **tower3, unsigned int n)
{
	if(n == 1)
	{

		(*tower3)++;
		**tower3 = **tower1;
		**tower1 = 0;
		(*tower1)--;
		delay();
		showNewFrame();
	}
	else
	{
		moveTower(tower1,tower3,tower2,n-1);
		(*tower3)++;
		**tower3 = **tower1;
		**tower1 = 0;
		(*tower1)--;
		delay();
		showNewFrame();
		moveTower(tower2,tower1,tower3,n-1);
	}
}

void delay(void)
{
	unsigned int temp;

	temp = clock() + CLOCKS_PER_SEC;
	while(clock() <= temp);
}

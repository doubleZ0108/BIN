#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile()
{
	char buffer[1000] = { 0 };
	int len = 0;
	FILE* fp = fopen("this.txt", "r");
	if (!fp) {
		printf("Failed to open this.txt\n");
		return;
	}

	while (!feof(fp))
	{
		memset(buffer, 0, sizeof(buffer));
		fgets(buffer, sizeof(buffer - 1), fp);
		printf("%s", buffer);
	}

	fclose(fp);
	printf("\n");
}

int main(void)
{
	readFile();

	system("pause");
	return 0;
}

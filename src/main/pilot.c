#include <stdio.h>
#include <stdlib.h>
#include "hbd.h"

#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif
#define FNAME "dump"

int main(int argc, char *argv[]) {

	FILE *ff;
	size_t fsiz;
	int c, n;
	char *filebuf, shortstr[3];

	if ((ff = fopen(FNAME, "r")) == NULL) {
		perror("fopen err");
		return EXIT_FAILURE;
	}
	fseek(ff, 0, SEEK_END);
	fsiz = ftell(ff);
	if ((filebuf = malloc(sizeof(char) * fsiz)) == NULL) {
		perror("malloc err");
		return EXIT_FAILURE;
	}
	rewind(ff);
	n = 0;
	while ((c = fgetc(ff)) != EOF)
		if ((c >= 0x30 && c <= 0x39) || (c >= 0x41 && c <= 0x46))
			filebuf[n++] = c;
	filebuf[n] = '\0';
	shortstr[2] = '\0';
	for (int i = 0; i < n; i += 2) {
		shortstr[0] = filebuf[i];
		shortstr[1] = filebuf[i+1];
		printf("%c", translate(shortstr));
	}
	printf("\n");
	free(filebuf);
	fclose(ff);
	return 0;

}

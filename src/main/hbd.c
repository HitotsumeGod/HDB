#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hbd.h"

int *hextobinary(char *hex) {

	int *binarr = malloc(sizeof(int) * 8);
	memset(binarr, 0, 8);

	switch (hex[0]) {
	case '0':
		;
		break;
	case '1':
		binarr[3] = 1;
		break;
	case '2':
		binarr[2] = 1;
		break;
	case '3':
		binarr[2] = 1;
		binarr[3] = 1;
		break;
	case '4':
		binarr[1] = 1;
		break;
	case '5':
		binarr[1] = 1;
		binarr[3] = 1;
		break;
	case '6':
		binarr[1] = 1;
		binarr[2] = 1;
		break;
	case '7':
		binarr[1] = 1;
		binarr[2] = 1;
		binarr[3] = 1;
		break;
	case '8':
		binarr[0] = 1;
		break;
	case '9':
		binarr[0] = 1;
		binarr[3] = 1;
		break;
	case 'A':
		binarr[0] = 1;
		binarr[2] = 1;
		break;
	case 'B':
		binarr[0] = 1;
		binarr[2] = 1;
		binarr[3] = 1;
		break;
	case 'C':
		binarr[0] = 1;
		binarr[1] = 1;
		break;
	case 'D':
		binarr[0] = 1;
		binarr[1] = 1;
		binarr[3] = 1;
		break;
	case 'E':
		binarr[0] = 1;
		binarr[1] = 1;
		binarr[2] = 1;
		break;
	case 'F':
		for (int i = 0; i < 4; i++)
			binarr[i] = 1;
		break;
	default:
		fprintf(stderr, "INVALID HEX CHARACTER\n");
		exit(EXIT_FAILURE);
	}
	switch (hex[1]) {
	case '0':
		;
		break;
	case '1':
		binarr[7] = 1;
		break;
	case '2':
		binarr[6] = 1;
		break;
	case '3':
		binarr[6] = 1;
		binarr[7] = 1;
		break;
	case '4':
		binarr[5] = 1;
		break;
	case '5':
		binarr[5] = 1;
		binarr[7] = 1;
		break;
	case '6':
		binarr[5] = 1;
		binarr[6] = 1;
		break;
	case '7':
		binarr[5] = 1;
		binarr[6] = 1;
		binarr[7] = 1;
		break;
	case '8':
		binarr[4] = 1;
		break;
	case '9':
		binarr[4] = 1;
		binarr[7] = 1;
		break;
	case 'A':
		binarr[4] = 1;
		binarr[6] = 1;
		break;
	case 'B':
		binarr[4] = 1;
		binarr[6] = 1;
		binarr[7] = 1;
		break;
	case 'C':
		binarr[4] = 1;
		binarr[5] = 1;
		break;
	case 'D':
		binarr[4] = 1;
		binarr[5] = 1;
		binarr[7] = 1;
		break;
	case 'E':
		binarr[4] = 1;
		binarr[5] = 1;
		binarr[6] = 1;
		break;
	case 'F':
		for (int i = 4; i < 8; i++)
			binarr[i] = 1;
		break;
	default:
		fprintf(stderr, "INVALID HEX CHARACTER\n");
		exit(EXIT_FAILURE);
	}

	return binarr;

}

int binarytodecimal(int *bin) {

	int sum = 0;

	if (bin[0])
		sum += 128;
	if (bin[1])
		sum += 64;
	if (bin[2])
		sum += 32;
	if (bin[3])
		sum += 16;
	if (bin[4])
		sum += 8;
	if (bin[5])
		sum += 4;
	if (bin[6])
		sum += 2;
	if (bin[7])
		++sum;
	return sum;
}

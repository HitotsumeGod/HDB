#include <stdio.h>
#include <stdlib.h>
#include "hbd.h"

int translate(char *hex) {

	int sum, binarr[8] = {0,0,0,0,0,0,0,0};

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
	sum = 0;
	if (binarr[0])
		sum += 128;
	if (binarr[1])
		sum += 64;
	if (binarr[2])
		sum += 32;
	if (binarr[3])
		sum += 16;
	if (binarr[4])
		sum += 8;
	if (binarr[5])
		sum += 4;
	if (binarr[6])
		sum += 2;
	if (binarr[7])
		++sum;
	return sum;

}

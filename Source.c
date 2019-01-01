#define _CRT_SECURE_NO_WARNINGS
#define SIZE 3
#define SIZE2 3
#include <stdio.h>

void main() {     //main function
	int i, j, k, sum = 0;
	int* ptr1;
	int* ptr2;
	int* ptr3;
	int matrix1[][SIZE] = { {1,3,1},{2,1,1},{1,2,1} };   //first SIZExSIZE matrix
	int matrix2[][SIZE2] = { {2,3,2},{1,1,1},{1,3,2} };  //second SIZExSIZE matrix
	//int matrix2[][SIZE2] = { {2,2},{4,3} };
	ptr1 = &matrix1[0][0];
	ptr2 = &matrix2[0][0];
	printf("The first matrix is:\n");     //printing the first matrix values
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			//printf("%d ", matrix1[i][j]);
			printf("%d ", *(ptr1+i*SIZE+j));
		}
		printf("\n");
	}
	printf("The second matrix is:\n");     //printing the second matrix values
	for (i = 0; i < SIZE2; i++) {
		for (j = 0; j < SIZE2; j++) {
			//printf("%d ", matrix2[i][j]);
			printf("%d ", *(ptr2 + i * SIZE + j));
		}
		printf("\n");
	}
	if (SIZE == SIZE2) {       //checking if both of the matrices have same size
		int new_matrix[SIZE][SIZE];    //create a new matrix for a product
		
		ptr3 = &new_matrix[0][0];
		for (i = 0; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++) {
				for (k = 0; k < SIZE; k++) {
					//sum += (matrix1[i][k] * matrix2[k][j]);     //add to the sum multiply of 2 numbers -for example matrix1[0][1]*matrix2[1][0]
					sum += ((*(ptr1+i*SIZE+k)) * (*(ptr2+k*SIZE+j)));
				}
				//new_matrix[i][j] = sum;
				(*(ptr3 + i * SIZE + j)) = sum;
				sum = 0;
			}
		}
		printf("Product of two matrices:\n ");   //printing the new matrix which contains a multiply product
		for (i = 0; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++) {
				//printf("%d ", new_matrix[i][j]);
				printf("%d ", *(ptr3 + i * SIZE + j));
			}
			printf("\n");
		}
	}
	else {      //if the size of the matrices different
		printf("This matrices cannot be multiplied\n");
	}
	getchar();


}
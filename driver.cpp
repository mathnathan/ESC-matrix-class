# include "Matrix.h"
# include <stdio.h>

int main() {

	double input[6] = {1,2,3,4,5,6};
	Mat A( 2, 3, input );

	for( int i = 0; i < 2; i++ ) {
		for (int j = 0; j < 3; j++ ) {
			printf( "A(%d,%d) = %f\n", i, j, A(i,j) );
		}
	}
		
	return 0;

}

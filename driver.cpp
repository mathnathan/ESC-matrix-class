# include "Matrix.h"
# include <stdio.h>

int main() {

	char cities[3] = {'A', 'B'};

	double inputA[4] = {.5,.2,.5,.8};
	Mat A( 2, 2, inputA );
    A.show();

	double inputB[2] = {0, 1000};
    Mat B( 2, 1, inputB );
    B.show();
    Mat C = A.mul( B );
    C.show();
	for( int i = 0; i < 1000; i++ )
		C = A.mul( C );
    C.show();

	if( C(0,0) > C(1,0) )
		printf( "I should go to city %c\n", cities[0] );
	else
		printf( "I should go to city %c\n", cities[1] );

	return 0;

}

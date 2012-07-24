# include "Matrix.h"
# include <stdio.h>

int main() {

	double input[6] = {1,2,3,4,5,6};
	Mat A( 2, 3, input );
    A.show();

    Mat B = A;
    B.show();

    Mat C = B.eye(5);
    C.show();

    Mat Arow1 = A.row(1);
    Arow1.show();
    Mat Acol2 = A.col(2);
    Acol2.show();
		
	return 0;

}

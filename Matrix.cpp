# include <stdio.h>
// Can you guys think of more cool things we might want to do with a matrix?
// We can basically implement ANYTHING!! I want to hear your ideas

// CONSTRUCTOR
Mat::Mat( int n, int m ) {
    printf( "Inside the CONSTRUCTOR with params(n=%d, m=%d)\n", n, m );

    rows=n;
    cols=m;
    num_elements=n*m;
    data = new double[num_elements];
    for (int i=0; i<num_elements; i++) {
		data[i]=0.0;
	}

}

// CONSTRUCTOR
Mat::Mat( int n, int m, double* input_array ) {
    printf( "Inside the CONSTRUCTOR with params(n=%d, m=%d, input_array)\n", n, m );

    rows = n;
    cols = m;
    num_elements = n*m;
    data = new double[num_elements];
    for(int i=0; i<num_elements; i++) {
       data[i] = input_array[i];
    }

}

// CONSTRUCTOR
Mat::Mat( int n, int m, double value ) {
    printf( "Inside the CONSTRUCTOR with params(n=%d, m=%d, value=%f)\n", n, m, value );

    rows = n;
    cols = m;
    num_elements = n * m;
    data = new double[num_elements];
    for (int i=0; i<num_elements; i++) {
        data[i] = value;
    }

}

// COPY CONSTRUCTOR
Mat::Mat( const Mat& input_matrix ) {
    printf( "Inside the COPY CONSTRUCTOR\n" );

    rows = input_matrix.rows;
    cols = input_matrix.cols;
	num_elements = input_matrix.num_elements; 
	data = new double[input_matrix.num_elements];
	for (int k = 0; k < input_matrix.num_elements; k++) 
		data[k] = input_matrix.data[k]; 

}

// DESTRUCTOR
Mat::~Mat() {
    printf( "Inside the DESTRUCTOR\n" );

    delete [] data;

}

// Don't do more work here, just call the constructor defined previously!
Mat Mat::zeros( int n, int m ) {
    printf( "Inside the ZEROS function with params( n=%d, m=%d )\n", n, m );

    Mat zero(n,m,0.0); 
    return zero;  

}

// Call another previously defined constructor
Mat Mat::eye( int n ) {
    printf( "Inside the EYE function with param( n=%d )\n", n );

    Mat A(n,n);
    for( int i = 0; i < n; i++ ) {
            int k = i*(n+i);
            A.data[k] = 1.0;
    }

    // This looked great! I just added this return statement for you (Nathan Crock)
    return A;

}

Mat Mat::mul( const Mat& B ) {
    printf( "Inside the MUL function\n" );

	if( cols == B.rows ) {
		Mat C( rows, B.cols );
		int row, col;
		for (int k = 0; k < rows*B.cols; k++) {
			row = k / B.cols;
			col = k % B.cols;
			for (int i = 0; i < cols; i++) {
				C.data[k] += data[row*cols + i]*B.data[col + i*B.cols];
			}
		}
		return C;
	}
    else
        printf( "Sorry, your matrices cannot be multiplied.\n" );

}

// Extract row i from the matrix
Mat Mat::row( int i ) {
    printf( "Inside the ROW function with param( i=%d )\n", i );
	double array[cols];

	for (int j=0; j<=cols; j++) {
		int x = i*cols+j; 
		array[j]=data[x];
	}
		
	return Mat(1, cols, array);
		
}


// Extract column j from the matrix
Mat Mat::col( int j ) {
    printf( "Inside the COL function with param( j=%d )\n", j );
    double array[rows];

    for (int i=0; i<=rows; i++) {
        int x = i * cols + j;
        array[i]=data[x];
    }

    return Mat(rows, 1, array);

}


Mat Mat::add( const Mat& B ) {
    printf( "Inside the ADD function\n" );
		if( cols != B.cols || rows != B.rows ) {
			printf("Cannot add matrices, not the same size\n");
		}
		else {

			double result[num_elements];
			for( int i=0; i<num_elements; i++) { 
				result[i] = data[i] + B.data[i];
		 	} 
		 	
			return Mat(rows, cols, result);
		 }
}

// Function OVERLOADING! We discussed this in class, and in some notes I sent you.
double Mat::operator()( int i, int j ) {
    printf( "Inside the OPERATOR() function with params( i=%d, j=%d )\n", i, j );

    return data[(i * cols) + j];

}

Mat Mat::operator=( Mat B ) {
    printf( "Inside the OPERATOR=\n" );

	if( B == *this ) 
		return *this;
	rows = B.rows;
	cols = B.cols;
	num_elements = B.num_elements;
	delete [] data;
	data = new double[B.num_elements];
	for (int k = 0; k <= B.num_elements; k++) 
		data[k] = B.data[k]; 

	return *this;

}

bool Mat::operator==( Mat B ) {

	if( data != B.data )
		return false;
	if( rows != B.rows )
		return false;
	if( cols != B.cols )
		return false;
	if( num_elements != B.num_elements )
		return false;
	return true;
	
}
	
// Use this to print out small matrices to aid in the testing of these routines
void Mat::show() {
    printf( "Inside the SHOW function\n");
	if ( cols == 1 ) {
    	printf( "\n" );
		for ( int k=0; k<num_elements; k++ ) {
			printf( "| %f |\n", data[k]);
		}
    	printf( "\n" );
	}
	else {
    	printf( "\n| " );
		for ( int k=0; k<num_elements; k++ ) {
			printf( "%f ", data[k]);
			if( (k+1)%cols == 0 && k != 0 && k != num_elements-1 )
            	printf( "|\n| " );	
		}
    	printf( "|\n\n" );
    }
}

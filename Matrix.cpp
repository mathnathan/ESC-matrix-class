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
    for (int i=0; i<num_elements; i++)
    {data[i]=0;}

}

// CONSTRUCTOR
Mat::Mat( int n, int m, double* input_array ) {
    printf( "Inside the CONSTRUCTOR with params(n=%d, m=%d, input_array)\n", n, m );

    rows = n;
    cols = m;
    num_elements = n*m;
    data = new double[num_elements];
    // This doesn't quite work. We need to check the size of input_array, right? (Nathan Crock)
    //if(sizeof(num_elements)!= n*m)
       //cout << "error";
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

    int rows = input_matrix.rows;
    int cols = input_matrix.cols;
	int num_elements = input_matrix.num_elements; 
	data = new double [input_matrix.num_elements];
       	 for (int k = 0; k <= input_matrix.num_elements; k++) 
            data [k] = input_matrix[k]; 

}

// DESTRUCTOR
Mat::~Mat() {
    printf( "Inside the DESTRUCTOR\n" );

    delete []data;

}

// Don't do more work here, just call the constructor defined previously!
Mat Mat::zeros( int n, int m ) {
    printf( "Inside the ZEROS function with params( n=%d, m=%d )\n", n, m );

    // We need to make a new matrix here, and return it
    // What about something like this?
    //      Mat zeros( n, m, 0 ); 
    //      return zeros;
    // Notice how we just call a constructor from before? This way we do less
    // programming and provide more functionality (Nathan Crock)
    for (int a=0; a<n*m; a=a+1)
        data[a] = 0;

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

    // looks good, but now
    // You now need to change everything to operate on the input matrx B!
    // for example, r2 stands for rows of B right? then r2 would be changed to
    // B.rows and c1 is the cols of the original matrix right? So it would just be cols.
    // You also need to create a NEW matrix to store the results in, THEN return it
    // something like 
    //      Mat r(B.rows,cols);
    //      return r;
    // would be appropriate, don't you think? I'm commenting it out so that it will compile
    // for eveyone else. But when you're ready uncomment it and compile to
    // check the errors and begin fixing

    /*
    if (r2 == c1) {
        for(int k=0; k<r1*c2; k++) {
            for (int i=0; i<c1; i++) {
                r.data[k] += m1.data[(k/c2)*c1 + i]*m2.data[(k % c2)+i*c2];
                }
        }
    }
    else
        cout << "Sorry, your matrices cannot be multiplied.\n";
    */
}

// Extract row i from the matrix
Mat Mat::row( int i ) {
    printf( "Inside the ROW function with param( i=%d )\n", i );

}


// Extract column j from the matrix
Mat Mat::col( int j ) {
    printf( "Inside the COL function with param( j=%d )\n", j );

    for (int i=0; i<=rows; i++) {
        // x is actually the INDEX right? So you want to use x to access the
        // elements in data and put them in array. Like this
        // array[i] = data[x]; OR
        // array[i] = data[i*cols+j];
        int x = i * cols + j;
        // array has not been declared! You need to dynamically allocate it
        // above, before this line will work
        // I'm going to comment it out for now so that the program will compile. 
        // When you're ready uncomment it and compile to see the error.
        //array[i]=x;
        // This doens't work because you're making a new matrix every loop!!
        // You want this line outside of the for loop. PLUS you aren't
        // returning this. You want to actually return this matrix
        // so add a return statement before it.
        //Mat(rows, 1, array[i]);
    }

}

Mat Mat::add( const Mat& B ) {
    printf( "Inside the ADD function\n" );

}

// Function OVERLOADING! We discussed this in class, and in some notes I sent you.
double Mat::operator()( int i, int j ) {
    return data[(i * cols) + j];
    printf( "Inside the OPERATOR() function with params( i=%d, j=%d )\n", i, j );

}

// Use this to print out small matrices to aid in the testing of these routines
void Mat::show() {
    printf( "Inside the SHOW function\n");

}

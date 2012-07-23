// Can you guys think of more cool things we might want to do with a matrix?
// We can basically implement ANYTHING!! I want to hear your ideas


// CONSTRUCTOR
Mat::Mat( int n, int m ) {

rows=n;
columns=m;
num_elements=n*m;
data=new  double[num_elements];
for (i=0; i<num_elements;i++)
{data[i]=0};}

}


// CONSTRUCTOR
Mat::Mat( int n, int m, double* input_array ) {

}


// CONSTRUCTOR
Mat::Mat( int n, int m, double value ) {
        rows = n;
        cols = m;
        num_elements = n * m;
        data = new double [num_elements];
        for (int i=0; i<num_elements; i++)
                data[i] = value;
}

}


// COPY CONSTRUCTOR
Mat::Mat( const Mat& input_matrix ) {

}


// DESTRUCTOR
Mat::~Mat() {

}


// Don't do more work here, just call the constructor defined previously!
Mat Mat::zeros( int n, int m ) {

}


// Call another previously defined constructor
Mat Mat::eye( int n, int m ) {
      Mat A(n,n);
        for( int i = 0; i < n; i++ ) {
                int k = i*(n+i);
                A.data[k] = 1;
        }

}


// Extract row i from the matrix
Mat Mat::row( int i ) {

}


// Extract column j from the matrix

Mat Mat::col( int j ) {
for (int i=0; i<=rows; i++) {
    int x = i * cols + j;
    array[i]=x;
    Mat (rows, 1, array[i]);
}
}



// Function OVERLOADING! We discussed this in class, and in some notes I sent you.
double Mat::operator()( int i, int j ) {

}

// Use this to print out small matrices to aid in the testing of these routines
void Mat::show() {

}

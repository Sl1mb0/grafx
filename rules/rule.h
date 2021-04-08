#ifndef RULE_H_
#define RULE_H_

class rule {
    public:
        rule(int r, int c);
	void rule30();
	void rule187();
    public: 
        int rows, columns;
	int **array; 
};

rule::rule(int r, int c) {
    this->rows = r;
    this->columns = c;
    array = new int*[rows];
    for(int i = 0; i < columns; ++i)
       array[i] = new int[columns];

    this->array[0][columns / 2] = 1; // color center cell of first row. 
}

/**
 *
 * This function returns the next iteration of a 1D cellular automaton known as rule 30.
 *
 * Given an initial linear array of 0's and 1's, rule 30 produces a new array using 
 * transformations based on each value and the value of its left and right neighbors, as follows:
 *
 *    111  110  101  100  011  010  001  000
 *    V    V    V    V    V    V    V    V
 *    0    0    0    1    1    1    1    0     
 *    
 * Note that there are 256 = 2^8 possible ways to fill in this output chart, 
 * and that rule 30 gets its index by the fact that (0,0,0,1,1,1,1,0) 
 * can be interpreted as the binary representation of 30.
 * For instance, if the current values of X(4), X(5) and X(6) are 0, 1 and 1, respectively, then the new value of X(5) will be 1.
 *
 * The first and last entries of the array must be treated specially, since they don't have a left or right neighbor. 
 * One simple treatment is to assume that there are phantom neighbors whose values are both 0. Another is to enforce periodic boundary conditions.
 *
 */
void rule::rule30() {
    int l, r;
    for(int row = 1; row < this->rows; ++row) {
        for(int column = 0; column < this->columns; ++column){
            if(column)           
	        l = this->array[row-1][column-1]; 
	    else 
	        l = this->array[row-1][this->columns-1];
            if(column != this->columns-1) 
	        r = this->array[row-1][column+1]; 
	    else 
	        r = this->array[row-1][0];
            if(this->array[row-1][column])
              if(l)       
	          this->array[row][column] = 0; 
	      else 
	          this->array[row][column] = 1;
            else
              if(l^r)     
	          this->array[row][column] = 1; 
	      else 
	          this->array[row][column] = 0;
        }
    }
}

void rule::rule187() {
    int l, r;
    for(int row = 1; row < this->rows; ++row) {
        for(int column = 0; column < this->columns; ++column) {
	    if(column)          
	        l = this->array[row-1][column-1]; 
	    else 
	        l = this->array[row-1][this->columns-1];
	    if(column != this->columns - 1)
	        r = this->array[row-1][column+1];
	    else
	        r = this->array[row-1][0];
	    if(this->array[row-1][column])
	        if(l || r)
	         
	}
    }
}
#endif

// In section we will make a calculater application which will take the input from console stream.

/*
    In this section we will take about the handling of the every kind of operation with order, we will use Tokenization 
    mechanism to to handle every kind of operation.

    Process of Tokenization can be divided into four stages.

    Expression:
        Term
        Expression '+' Term;
        Expression '-' Term;

    Term:
        Primary
        Term '*' Primary;
        Term '/' Primary;
        Term '%' Primary; // In this calculator % is not included yet for making things simple

    Primary:
        Number 
        "(" expression ")"  // grouping.

    Number:
        floating-point-literal


    Above stages are described below:

    1. Expression: An expression must be a Term or end with a Term.
    2. Term: The Term must be a Primary or end with a Primary.
    3. Primary: The Primary must start with a '(' or be a Number.
    4. Number: 2 is not a '(' but it is a floating-point-literal, which is a Number, which is a Primary.

    Note: 
    1. The Primary (the Number 2) isn't preceded by /,* or %, so it is complete Term (rather than the end of a /, * or % expression)
    2. That Term (the Number 2) isn't preceded by + or -, os it is complete Expression (rather than the end of a + or - expression)

    Note: 
*/

#include<iostream>
using namespace std;

// first of all we will make a class to token

class Token{
    public:
        char kind;
        double value;

        // A constructor to construct the token with it's kind
        Token(char ch): kind(ch), value(0) {}

        // A constructor to construct the token with it's kind and value;
        Token(char ch, double val): kind(ch), value(val) {}

        // These constructor are only used to set the values.
};

// Now we will make have to make get_token function to get the input value as token.

Token get_token(){
    // This funciton will get the input from the input stream "cin" and it will return the token.

    char ch;
    cin>>ch;

    switch(ch){

        case '(': case ')': case '+': case '-': case '*': case '/':
            return Token(ch);        // let each character represent itself
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin>> val;              // read a floating-point number
            return Token('N', val);   // let 'N' represent "a number"
        }
        default:
            throw("Bad token");
    }
}

// Now we will make the three more function in reverse this order.
/*
    1. Expression
    2. Term
    3. Primary
*/

// declaring all the required funcitons.
double Expression();
double Term();
double Primary();


// Now we will 
int main(){

   while(cin){
       cout<<Expression()<<endl;
   }
    return 0;
}

/*==============================================================================================================*/
// 1. Defining the expression function opearion.
double Expression(){
    /*
        This function will return the double dtype value and it will compute the + and - computation

        Expression:
            Term
            Expression "+" Term;
            Expression "-" Term;
    */

   // Now first of all we will get the term as the left operand of the + or -;

   double left = Term(); // this will return the a double value.
   
   // Now we will get the next token to get the Opearator.

   Token t = get_token();
   cout<<"Got "<<t.kind<<" Operator"<<endl;
   while(true){
       // while we dont return the left we will run the loop 
       cout<<"In expression while loop"<<endl;
       switch (t.kind)
        {
            case '+':
                cout<<"adding values"<<endl;
                left += Term();  // if we get the + operator then we will add next term with this.
                t = get_token(); // we will get next token after getting calculated the above value 
                break;

            case '-':
                cout<<"Subtracting values"<<endl;
                left -= Term();
                t = get_token(); // we will get next token after getting calculated the above value 
                break;
            default:
                return left; // if ther is no + or - then we will return the result.
        }
    }
}

// 2. defining the Term operation.
double Term(){

    /*
        This function will be used to compute the *, / operation.
        Term:
            Primary
            Term * Primary;
            Term / Primary;

        The defination of this function is almost similar to the expression fucntion. 
    */

    // first of all we will get the double dtype value from the Primary function.
    double left = Primary();

    // Now we will get the next token
    Token t = get_token();
    cout<<"Got "<<t.kind<<" Operator"<<endl;
    // Now we will use the switch cases while don't return the result form this funciton.
    while (true) // infinte loop
    {   
        cout<<"In term while loop"<<endl;     
        switch (t.kind)
        {
            case '*':
                left *= Primary();
                t = get_token();
                break;
            
            case '/':
                // here to avoid the devision by zero we need to use the exception.
                { // if we are initializing a variable in a case then we need to put them into a block.
                    double result = Primary();
                    if(result == 0) throw("Devision By Zero");
                    left /= result;
                    t = get_token();
                    break;
                }

            default:
                return left;
        }    /* code */
    }
    
}

double Primary(){
    // This function will return the double value after calculation.
    /*
        Primary:
            Number
            "(" expression ")"
        
        Now this will handle two kind of operations, either it will return the Number or it will compute the expression
        binded by paranthesis.

    */


   Token t = get_token();  // Now after getting the token we need to check it's kind.
   cout<<"Got "<<t.kind<<" Operator"<<endl;
   cout<<"In Primary after getting Token"<<endl;
   switch (t.kind)
   {
    case '(': // handle the "(" expression ")";
        {
            double d = Expression();
            // after getting the result form the expression we expect a token of '(' 
            t = get_token();

            if(t.kind != ')' ) throw("expected ')' token ");
            return d; // return the result if we get the full '(expression)'
        }
   
    case 'N':
        return t.value;  // if we get a number then we will return the number.

    default:
        throw("Primary expected");
       
   }
}
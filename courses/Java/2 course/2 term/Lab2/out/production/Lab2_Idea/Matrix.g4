/*grammar Matrix;

rule: 'hello' id+;
id: STRING;

STRING: CHAR+;
CHAR: [a-zA-Z];
WS: ' '+ -> skip;
*/

// det(A/k - C) === (A/k - C)^D
// A/det(B)
//a = [[1,2,3],[4,5,6],[7,8,9]]
//a=[[1,2,3],[4,5.4,6],[7,8,9],[4,-98.3,2]]
grammar Matrix;
/*
INT    : '-'?[0-9]+;
DOUBLE : '\\d'+'.'[0-9]+;
*/

NL     : '\n';
WS     : [ \t\r]+ -> skip;
ID     : [a-zA-Z_][a-zA-Z_0-9]*;

NUM    : '-'?([0-9]+ | [0-9]+'.'[0-9]+);
VEC    : '['NUM(','NUM)*']';
MATRIX : '['VEC(','VEC)*']';

EQUAL : '=';
MINUS : '-';
PLUS  : '+';
DIV   : '/';
DET   : '^D';
LPAR  : '(';
RPAR  : ')';

root:
    input EOF               #MainRule
    ;

input:
    init                    #GoToInitialize
    | plusMinus             #StartCalculation
    ;

init:
    ID EQUAL input          #Initialize
    ;

plusMinus:
    plusMinus PLUS div      #Plus
    | plusMinus MINUS div   #Minus
    | div                   #GoToDivision
    ;

div:
    div DIV NUM             #DivisionByNum
    | div DIV det           #DivisionByDeterminant
    | det                   #GoToDeterminant
    ;

det:
    exp (DET)?              #Determinant
    ;

exp:
    MATRIX                  #Matrix
    | ID                    #Variable
    | LPAR plusMinus RPAR   #Braces
    ;
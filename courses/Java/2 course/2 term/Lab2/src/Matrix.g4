grammar Matrix;

NL     : '\n';
WS     : [ \t\r]+ -> skip;
ID     : [a-zA-Z_][a-zA-Z_0-9]*;

NUMBER    : '-'?([0-9]+ | [0-9]+'.'[0-9]+);

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
    div DIV NUMBER            #DivisionByNum
    | div DIV det           #DivisionByDeterminant
    | det                   #GoToDeterminant
    ;

det:
    exp (DET)?              #Determinant
    ;

matr:
    '['vect(','vect)*']'    #GoToVect
    ;

vect:
    '['NUMBER(','NUMBER)*']'      #GoToNumber
    ;

exp:
    matr                    #GoToMatrix
    | ID                    #Variable
    | LPAR plusMinus RPAR   #Braces
    ;
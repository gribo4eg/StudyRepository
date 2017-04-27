import Jama.Matrix;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;

import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main{

    public static void main(String [] args) throws Exception{

        Scanner scan = new Scanner(System.in);
        MatrixBaseVisitorImpl matrix = new MatrixBaseVisitorImpl();
        while (true){
            System.out.println("\n>");
            String input = scan.nextLine();
            if (input.isEmpty()){
                continue;
            }
            else if (input.equals("exit")) {
                scan.close();
                break;
            }

            ANTLRInputStream in = new ANTLRInputStream(input);
            MatrixLexer lexer = new MatrixLexer(in);
            CommonTokenStream tokens = new CommonTokenStream(lexer);
            MatrixParser parser = new MatrixParser(tokens);

            parser.setErrorHandler(new DefaultErrorStrategy(){

                @Override
                public Token recoverInline(Parser recognizer){
                    throw new IllegalArgumentException("Invalid input due to grammar");
                }

                @Override
                public void reportError(Parser recognizer, RecognitionException e){
                    throw new IllegalArgumentException("Invalid input due to grammar");
                }
            });
            try {
                ParseTree tree = parser.root();
                Matrix result = matrix.visit(tree);
                result.print(1, 2);
            }
            catch (IllegalArgumentException | NoSuchElementException exception){
                System.out.println(exception.getMessage());
            }
        }

    }
}

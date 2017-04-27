import org.antlr.v4.runtime.*;

import java.util.regex.Pattern;

public class Main{

    public static void main(String [] args) throws Exception{

        ANTLRInputStream in = new ANTLRInputStream("12*(5-6)");
        MatrixLexer lexer = new MatrixLexer(in);
        CommonTokenStream tokens = new CommonTokenStream(lexer);
        MatrixParser parser = new MatrixParser(tokens);


        Pattern.compile("-?[0-9]+");
    }
}

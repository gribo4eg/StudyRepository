import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.ParseTree;
import org.junit.Test;

import java.util.Arrays;
import java.util.NoSuchElementException;

import static org.junit.Assert.*;

public class Testing {

    MatrixBaseVisitorImpl matrixVisitor = new MatrixBaseVisitorImpl();
    ANTLRInputStream in;
    MatrixLexer lexer;
    CommonTokenStream tokens;
    MatrixParser parser;
    ParseTree tree;

    double[][] parser(String expression){
        in = new ANTLRInputStream(expression);
        lexer = new MatrixLexer(in);
        tokens = new CommonTokenStream(lexer);
        parser = new MatrixParser(tokens);
        tree = parser.root();

        try{
            return matrixVisitor.visit(tree).getArray();
        }
        catch (IllegalArgumentException | NoSuchElementException e){
            throw e;
        }
    }

    @Test
    public void testMinusTrue(){
        double[][] test = {
                {1,2,3},
                {4,5,6},
                {7,8,9}
        };

        assertTrue(Arrays.deepEquals(parser(
                "[[2,1,5],[5,2,7],[10,23,4]]-" +
                        "[[1,-1,2],[1,-3,1],[3,15,-5]]"),test));
    }

    @Test(expected = IllegalArgumentException.class)
    public void testMinusIllegalException(){
        parser("[[2,1,5],[5,2,7],[10,23,4]]-[[1,2,3]]");
    }

    @Test
    public void divideByNumberFalse()
    {
        double[][] notExpected = {
                {2,4,3},
                {8,9,1}
        };

        assertFalse(Arrays.deepEquals(parser("[[4,-2,7],[33,12,56]]/3"), notExpected));
    }

    @Test
    public void divideByNumberTrue()
    {
        double[][] expected = {
                {2,-4,3},
                {8,-9,-1}
        };

        assertTrue(Arrays.deepEquals(parser("[[6,-12,9],[24,-27,-3]]/3"), expected));
    }

    @Test(expected = IllegalArgumentException.class)
    public void divideMatricesException(){
        parser("[[6,-12,9],[24,-27,-3]]/[[3,4,5],[5,63,2]]");
    }

    @Test
    public void detCalculationTrue(){
        assertEquals(-13, parser("[[1,5],[4,7]]^D")[0][0], 1E-6);
    }

    @Test
    public void divideMatrixByDeterminant(){
        double[][] expected =
                {
                        {1,-2},
                        {-3,2}
                };

        assertTrue(Arrays.deepEquals(expected, parser(
                "[[-13,26],[39,-26]]/[[1,5],[4,7]]^D")));
    }


}
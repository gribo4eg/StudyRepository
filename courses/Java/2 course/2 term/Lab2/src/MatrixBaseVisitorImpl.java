import Jama.Matrix;

import java.util.Hashtable;


public class MatrixBaseVisitorImpl extends MatrixBaseVisitor<Matrix> {
    Hashtable<String, Matrix> var = new Hashtable<String, Matrix>();

    @Override
    public Matrix visitMainRule(MatrixParser.MainRuleContext context){
        return visit(context.getChild(0));
    }

    @Override
    public Matrix visitPlus(MatrixParser.PlusContext context){
        try {
            return visit(context.plusMinus()).plus(visit(context.div()));
        }
        catch (IllegalArgumentException exception) {
            throw new IllegalArgumentException("\nWrong dimension while adding matrices\n"
                    + exception.getMessage());
        }
    }

    @Override
    public Matrix visitMinus(MatrixParser.MinusContext context){
        try {
            return visit(context.plusMinus()).minus(visit(context.div()));
        }
        catch (IllegalArgumentException exception){
            throw new IllegalArgumentException("\nWrong dimension while subtracting matrices\n"
                    + exception.getMessage());
        }
    }

    @Override
    public Matrix visitDivisionByNum(MatrixParser.DivisionByNumContext context) {
        System.out.println("visitDivisionByNum");
        try{
            Matrix target = visit(context.div());
            double divider = Double.parseDouble(context.NUM().getText());

                return target.times(1/divider);
        }
        catch (IllegalArgumentException exception){
            throw new IllegalArgumentException("\nError while dividing matrix by num\n"
                    + exception.getMessage());
        }
    }

    @Override
    public Matrix visitDivisionByDeterminant(MatrixParser.DivisionByDeterminantContext context) {
        System.out.println("visitDivisionByDeterminant");
        try {
            Matrix target = visit(context.div());
            Matrix divider = visit(context.det());

            if(divider.getRowDimension() == 1 &&
                    divider.getColumnDimension() == 1){
                return target.times(1/divider.get(0,0));
            }
            else {
                throw new IllegalArgumentException("\nCant divide matrices");
            }
        }
        catch (IllegalArgumentException exception){
            throw new IllegalArgumentException("\nError while dividing matrix by det\n"
                    + exception.getMessage());
        }
    }

    @Override
    public Matrix visitDeterminant(MatrixParser.DeterminantContext context) {

    }
}

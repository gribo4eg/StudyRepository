import Jama.Matrix;

import java.util.Hashtable;
import java.util.NoSuchElementException;


public class MatrixBaseVisitorImpl extends MatrixBaseVisitor<Matrix> {
    Hashtable<String, Matrix> var = new Hashtable<String, Matrix>();

    @Override
    public Matrix visitStartCalculation(MatrixParser.StartCalculationContext context) {
        return visit(context.plusMinus());
    }

    @Override
    public Matrix visitMainRule(MatrixParser.MainRuleContext context){
        return visit(context.getChild(0));
    }

    @Override
    public Matrix visitInitialize(MatrixParser.InitializeContext context) {
        Matrix toSave = visit(context.input());
        if(toSave != null){
            var.put(context.ID().getText(), toSave);
        }
        else {
            throw new
                    IllegalArgumentException("\nCant save null value");
        }
        return toSave;
    }

    @Override
    public Matrix visitPlus(MatrixParser.PlusContext context){
        try {
            return visit(context.plusMinus()).plus(visit(context.div()));
        }
        catch (IllegalArgumentException exception) {
            throw new IllegalArgumentException("\nWrong dimension while adding matrices");
        }
    }

    @Override
    public Matrix visitMinus(MatrixParser.MinusContext context){
        try {
            return visit(context.plusMinus()).minus(visit(context.div()));
        }
        catch (IllegalArgumentException exception){
            throw new IllegalArgumentException("\nWrong dimension while subtracting matrices");
        }
    }

    @Override
    public Matrix visitDivisionByNum(MatrixParser.DivisionByNumContext context) {
        try{
            Matrix target = visit(context.div());
            double divider = Double.parseDouble(context.NUMBER().getText());

                return target.times(1/divider);
        }
        catch (IllegalArgumentException exception){
            throw new IllegalArgumentException("\nError while dividing matrix by num");
        }
    }

    @Override
    public Matrix visitDivisionByDeterminant(MatrixParser.DivisionByDeterminantContext context) {
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
            throw new IllegalArgumentException("\nError while dividing matrix. Cant divide matrices.");
        }
    }

    @Override
    public Matrix visitDeterminant(MatrixParser.DeterminantContext context) {
        if(context.DET() != null){
            if (visit(context.exp()).getColumnDimension() !=
                    visit(context.exp()).getRowDimension())
                throw new IllegalArgumentException("\nInvalid dimensions for this operation" +
                        "only NxN");
            double determinant = visit(context.exp()).det();
            double[][] detArr = new double[1][1];
            detArr[0][0] = determinant;
            return new Matrix(detArr);
        }
        return visit(context.exp());
    }

    @Override
    public Matrix visitVariable(MatrixParser.VariableContext context) {
        String id = context.ID().getText();
        boolean haveId = var.containsKey(id);
        if (haveId)
            return var.get(id);
        else
            throw new NoSuchElementException("\nNo such element in table");
    }

    @Override
    public Matrix visitBraces(MatrixParser.BracesContext context) {
        return visit(context.plusMinus());
    }


    @Override
    public Matrix visitGoToVect(MatrixParser.GoToVectContext ctx) {
        double[][] values = new double[ctx.vect().size()][];
        int vectorIndex = 0;
        for(int i = 1; i < ctx.getChildCount();i+=2) {
            values[vectorIndex] = new double[ctx.getChild(i).getChildCount()/2];
            int numberIndex = 0;
            for (int j = 1; j < ctx.getChild(i).getChildCount(); j+=2) {
                values[vectorIndex][numberIndex++] = Double.parseDouble(ctx.getChild(i).getChild(j).getText());
            }
            vectorIndex++;
        }

        try {
            return new Matrix(values);
        }
        catch (IllegalArgumentException e){
            throw new IllegalArgumentException("\nInvalid dimensions inside matrix");
        }
    }
}

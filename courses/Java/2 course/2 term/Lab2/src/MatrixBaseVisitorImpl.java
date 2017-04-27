import Jama.Matrix;

import java.util.Hashtable;
import java.util.LinkedList;
import java.util.NoSuchElementException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


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
            double divider = Double.parseDouble(context.NUM().getText());

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
    public Matrix visitMatrix(MatrixParser.MatrixContext context) {
        String arrayString = context.getText();

        // region Finding Vectors
        LinkedList<String> vectors = new LinkedList<String>();

        Pattern pattern = Pattern.compile("\\[-?\\w+(\\.\\w+)?(,-?\\w+(\\.\\w+)?)*]");
        Matcher matcher = pattern.matcher(arrayString);
        while (matcher.find())
            vectors.add(matcher.group());
        // endregion
        //region Counting Dimensions and creating array
        int firstDim = vectors.size();

        pattern = Pattern.compile(",");

        int comas = 0, tmp = 0;
        matcher = pattern.matcher(vectors.get(0));
        while (matcher.find()) comas ++;
        for (int i = 1; i < firstDim; i++){
            matcher = pattern.matcher(vectors.get(i));
            while (matcher.find()) tmp++;
            if (comas != tmp)
                throw new IllegalArgumentException("\nWrong dimensions count!");
            tmp = 0;
        }

        double[][] arrayForMatrix = new double[firstDim][comas+1];
        //endregion
        //region Full Matrix
        for (int i = 0; i < vectors.size(); i++){
            String[] temp = vectors.get(i).split("\\[|,|]");
            for (int j = 1; j < temp.length; j++){
                arrayForMatrix[i][j-1] = Double.parseDouble(temp[j]);
            }
        }
        //endregion
        return new Matrix(arrayForMatrix);
    }


}

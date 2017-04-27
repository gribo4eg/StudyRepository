// Generated from C:/Users/Саша/workspace/Lab2_Idea/src\Matrix.g4 by ANTLR 4.7
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link MatrixParser}.
 */
public interface MatrixListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by the {@code MainRule}
	 * labeled alternative in {@link MatrixParser#root}.
	 * @param ctx the parse tree
	 */
	void enterMainRule(MatrixParser.MainRuleContext ctx);
	/**
	 * Exit a parse tree produced by the {@code MainRule}
	 * labeled alternative in {@link MatrixParser#root}.
	 * @param ctx the parse tree
	 */
	void exitMainRule(MatrixParser.MainRuleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code GoToInitialize}
	 * labeled alternative in {@link MatrixParser#input}.
	 * @param ctx the parse tree
	 */
	void enterGoToInitialize(MatrixParser.GoToInitializeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code GoToInitialize}
	 * labeled alternative in {@link MatrixParser#input}.
	 * @param ctx the parse tree
	 */
	void exitGoToInitialize(MatrixParser.GoToInitializeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code StartCalculation}
	 * labeled alternative in {@link MatrixParser#input}.
	 * @param ctx the parse tree
	 */
	void enterStartCalculation(MatrixParser.StartCalculationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code StartCalculation}
	 * labeled alternative in {@link MatrixParser#input}.
	 * @param ctx the parse tree
	 */
	void exitStartCalculation(MatrixParser.StartCalculationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Initialize}
	 * labeled alternative in {@link MatrixParser#init}.
	 * @param ctx the parse tree
	 */
	void enterInitialize(MatrixParser.InitializeContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Initialize}
	 * labeled alternative in {@link MatrixParser#init}.
	 * @param ctx the parse tree
	 */
	void exitInitialize(MatrixParser.InitializeContext ctx);
	/**
	 * Enter a parse tree produced by the {@code GoToDivision}
	 * labeled alternative in {@link MatrixParser#plusMinus}.
	 * @param ctx the parse tree
	 */
	void enterGoToDivision(MatrixParser.GoToDivisionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code GoToDivision}
	 * labeled alternative in {@link MatrixParser#plusMinus}.
	 * @param ctx the parse tree
	 */
	void exitGoToDivision(MatrixParser.GoToDivisionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Plus}
	 * labeled alternative in {@link MatrixParser#plusMinus}.
	 * @param ctx the parse tree
	 */
	void enterPlus(MatrixParser.PlusContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Plus}
	 * labeled alternative in {@link MatrixParser#plusMinus}.
	 * @param ctx the parse tree
	 */
	void exitPlus(MatrixParser.PlusContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Minus}
	 * labeled alternative in {@link MatrixParser#plusMinus}.
	 * @param ctx the parse tree
	 */
	void enterMinus(MatrixParser.MinusContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Minus}
	 * labeled alternative in {@link MatrixParser#plusMinus}.
	 * @param ctx the parse tree
	 */
	void exitMinus(MatrixParser.MinusContext ctx);
	/**
	 * Enter a parse tree produced by the {@code DivisionByNum}
	 * labeled alternative in {@link MatrixParser#div}.
	 * @param ctx the parse tree
	 */
	void enterDivisionByNum(MatrixParser.DivisionByNumContext ctx);
	/**
	 * Exit a parse tree produced by the {@code DivisionByNum}
	 * labeled alternative in {@link MatrixParser#div}.
	 * @param ctx the parse tree
	 */
	void exitDivisionByNum(MatrixParser.DivisionByNumContext ctx);
	/**
	 * Enter a parse tree produced by the {@code DivisionByDeterminant}
	 * labeled alternative in {@link MatrixParser#div}.
	 * @param ctx the parse tree
	 */
	void enterDivisionByDeterminant(MatrixParser.DivisionByDeterminantContext ctx);
	/**
	 * Exit a parse tree produced by the {@code DivisionByDeterminant}
	 * labeled alternative in {@link MatrixParser#div}.
	 * @param ctx the parse tree
	 */
	void exitDivisionByDeterminant(MatrixParser.DivisionByDeterminantContext ctx);
	/**
	 * Enter a parse tree produced by the {@code GoToDeterminant}
	 * labeled alternative in {@link MatrixParser#div}.
	 * @param ctx the parse tree
	 */
	void enterGoToDeterminant(MatrixParser.GoToDeterminantContext ctx);
	/**
	 * Exit a parse tree produced by the {@code GoToDeterminant}
	 * labeled alternative in {@link MatrixParser#div}.
	 * @param ctx the parse tree
	 */
	void exitGoToDeterminant(MatrixParser.GoToDeterminantContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Determinant}
	 * labeled alternative in {@link MatrixParser#det}.
	 * @param ctx the parse tree
	 */
	void enterDeterminant(MatrixParser.DeterminantContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Determinant}
	 * labeled alternative in {@link MatrixParser#det}.
	 * @param ctx the parse tree
	 */
	void exitDeterminant(MatrixParser.DeterminantContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Matrix}
	 * labeled alternative in {@link MatrixParser#exp}.
	 * @param ctx the parse tree
	 */
	void enterMatrix(MatrixParser.MatrixContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Matrix}
	 * labeled alternative in {@link MatrixParser#exp}.
	 * @param ctx the parse tree
	 */
	void exitMatrix(MatrixParser.MatrixContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Variable}
	 * labeled alternative in {@link MatrixParser#exp}.
	 * @param ctx the parse tree
	 */
	void enterVariable(MatrixParser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Variable}
	 * labeled alternative in {@link MatrixParser#exp}.
	 * @param ctx the parse tree
	 */
	void exitVariable(MatrixParser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by the {@code Braces}
	 * labeled alternative in {@link MatrixParser#exp}.
	 * @param ctx the parse tree
	 */
	void enterBraces(MatrixParser.BracesContext ctx);
	/**
	 * Exit a parse tree produced by the {@code Braces}
	 * labeled alternative in {@link MatrixParser#exp}.
	 * @param ctx the parse tree
	 */
	void exitBraces(MatrixParser.BracesContext ctx);
}
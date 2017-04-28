// Generated from C:/Users/Саша/workspace/Lab2_Idea/src\Matrix.g4 by ANTLR 4.7
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link MatrixParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface MatrixVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by the {@code MainRule}
	 * labeled alternative in {@link MatrixParser#root}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMainRule(MatrixParser.MainRuleContext ctx);
	/**
	 * Visit a parse tree produced by the {@code GoToInitialize}
	 * labeled alternative in {@link MatrixParser#input}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitGoToInitialize(MatrixParser.GoToInitializeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code StartCalculation}
	 * labeled alternative in {@link MatrixParser#input}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStartCalculation(MatrixParser.StartCalculationContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Initialize}
	 * labeled alternative in {@link MatrixParser#init}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitInitialize(MatrixParser.InitializeContext ctx);
	/**
	 * Visit a parse tree produced by the {@code GoToDivision}
	 * labeled alternative in {@link MatrixParser#plusMinus}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitGoToDivision(MatrixParser.GoToDivisionContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Plus}
	 * labeled alternative in {@link MatrixParser#plusMinus}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitPlus(MatrixParser.PlusContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Minus}
	 * labeled alternative in {@link MatrixParser#plusMinus}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMinus(MatrixParser.MinusContext ctx);
	/**
	 * Visit a parse tree produced by the {@code DivisionByNum}
	 * labeled alternative in {@link MatrixParser#div}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDivisionByNum(MatrixParser.DivisionByNumContext ctx);
	/**
	 * Visit a parse tree produced by the {@code DivisionByDeterminant}
	 * labeled alternative in {@link MatrixParser#div}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDivisionByDeterminant(MatrixParser.DivisionByDeterminantContext ctx);
	/**
	 * Visit a parse tree produced by the {@code GoToDeterminant}
	 * labeled alternative in {@link MatrixParser#div}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitGoToDeterminant(MatrixParser.GoToDeterminantContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Determinant}
	 * labeled alternative in {@link MatrixParser#det}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDeterminant(MatrixParser.DeterminantContext ctx);
	/**
	 * Visit a parse tree produced by the {@code GoToVect}
	 * labeled alternative in {@link MatrixParser#matr}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitGoToVect(MatrixParser.GoToVectContext ctx);
	/**
	 * Visit a parse tree produced by the {@code GoToNumber}
	 * labeled alternative in {@link MatrixParser#vect}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitGoToNumber(MatrixParser.GoToNumberContext ctx);
	/**
	 * Visit a parse tree produced by the {@code GoToMatrix}
	 * labeled alternative in {@link MatrixParser#exp}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitGoToMatrix(MatrixParser.GoToMatrixContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Variable}
	 * labeled alternative in {@link MatrixParser#exp}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariable(MatrixParser.VariableContext ctx);
	/**
	 * Visit a parse tree produced by the {@code Braces}
	 * labeled alternative in {@link MatrixParser#exp}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBraces(MatrixParser.BracesContext ctx);
}
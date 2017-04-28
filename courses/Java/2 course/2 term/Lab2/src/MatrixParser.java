// Generated from C:/Users/Саша/workspace/Lab2_Idea/src\Matrix.g4 by ANTLR 4.7
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MatrixParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.7", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, NL=4, WS=5, ID=6, NUMBER=7, EQUAL=8, MINUS=9, 
		PLUS=10, DIV=11, DET=12, LPAR=13, RPAR=14;
	public static final int
		RULE_root = 0, RULE_input = 1, RULE_init = 2, RULE_plusMinus = 3, RULE_div = 4, 
		RULE_det = 5, RULE_matr = 6, RULE_vect = 7, RULE_exp = 8;
	public static final String[] ruleNames = {
		"root", "input", "init", "plusMinus", "div", "det", "matr", "vect", "exp"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'['", "','", "']'", "'\n'", null, null, null, "'='", "'-'", "'+'", 
		"'/'", "'^D'", "'('", "')'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, null, null, null, "NL", "WS", "ID", "NUMBER", "EQUAL", "MINUS", 
		"PLUS", "DIV", "DET", "LPAR", "RPAR"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Matrix.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public MatrixParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class RootContext extends ParserRuleContext {
		public RootContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_root; }
	 
		public RootContext() { }
		public void copyFrom(RootContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class MainRuleContext extends RootContext {
		public InputContext input() {
			return getRuleContext(InputContext.class,0);
		}
		public TerminalNode EOF() { return getToken(MatrixParser.EOF, 0); }
		public MainRuleContext(RootContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).enterMainRule(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).exitMainRule(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MatrixVisitor ) return ((MatrixVisitor<? extends T>)visitor).visitMainRule(this);
			else return visitor.visitChildren(this);
		}
	}

	public final RootContext root() throws RecognitionException {
		RootContext _localctx = new RootContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_root);
		try {
			_localctx = new MainRuleContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(18);
			input();
			setState(19);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class InputContext extends ParserRuleContext {
		public InputContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_input; }
	 
		public InputContext() { }
		public void copyFrom(InputContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class GoToInitializeContext extends InputContext {
		public InitContext init() {
			return getRuleContext(InitContext.class,0);
		}
		public GoToInitializeContext(InputContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).enterGoToInitialize(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).exitGoToInitialize(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MatrixVisitor ) return ((MatrixVisitor<? extends T>)visitor).visitGoToInitialize(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class StartCalculationContext extends InputContext {
		public PlusMinusContext plusMinus() {
			return getRuleContext(PlusMinusContext.class,0);
		}
		public StartCalculationContext(InputContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).enterStartCalculation(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).exitStartCalculation(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MatrixVisitor ) return ((MatrixVisitor<? extends T>)visitor).visitStartCalculation(this);
			else return visitor.visitChildren(this);
		}
	}

	public final InputContext input() throws RecognitionException {
		InputContext _localctx = new InputContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_input);
		try {
			setState(23);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				_localctx = new GoToInitializeContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(21);
				init();
				}
				break;
			case 2:
				_localctx = new StartCalculationContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(22);
				plusMinus(0);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class InitContext extends ParserRuleContext {
		public InitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_init; }
	 
		public InitContext() { }
		public void copyFrom(InitContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class InitializeContext extends InitContext {
		public TerminalNode ID() { return getToken(MatrixParser.ID, 0); }
		public TerminalNode EQUAL() { return getToken(MatrixParser.EQUAL, 0); }
		public InputContext input() {
			return getRuleContext(InputContext.class,0);
		}
		public InitializeContext(InitContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).enterInitialize(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).exitInitialize(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MatrixVisitor ) return ((MatrixVisitor<? extends T>)visitor).visitInitialize(this);
			else return visitor.visitChildren(this);
		}
	}

	public final InitContext init() throws RecognitionException {
		InitContext _localctx = new InitContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_init);
		try {
			_localctx = new InitializeContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(25);
			match(ID);
			setState(26);
			match(EQUAL);
			setState(27);
			input();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PlusMinusContext extends ParserRuleContext {
		public PlusMinusContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_plusMinus; }
	 
		public PlusMinusContext() { }
		public void copyFrom(PlusMinusContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class GoToDivisionContext extends PlusMinusContext {
		public DivContext div() {
			return getRuleContext(DivContext.class,0);
		}
		public GoToDivisionContext(PlusMinusContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).enterGoToDivision(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).exitGoToDivision(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MatrixVisitor ) return ((MatrixVisitor<? extends T>)visitor).visitGoToDivision(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class PlusContext extends PlusMinusContext {
		public PlusMinusContext plusMinus() {
			return getRuleContext(PlusMinusContext.class,0);
		}
		public TerminalNode PLUS() { return getToken(MatrixParser.PLUS, 0); }
		public DivContext div() {
			return getRuleContext(DivContext.class,0);
		}
		public PlusContext(PlusMinusContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).enterPlus(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).exitPlus(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MatrixVisitor ) return ((MatrixVisitor<? extends T>)visitor).visitPlus(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class MinusContext extends PlusMinusContext {
		public PlusMinusContext plusMinus() {
			return getRuleContext(PlusMinusContext.class,0);
		}
		public TerminalNode MINUS() { return getToken(MatrixParser.MINUS, 0); }
		public DivContext div() {
			return getRuleContext(DivContext.class,0);
		}
		public MinusContext(PlusMinusContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).enterMinus(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).exitMinus(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MatrixVisitor ) return ((MatrixVisitor<? extends T>)visitor).visitMinus(this);
			else return visitor.visitChildren(this);
		}
	}

	public final PlusMinusContext plusMinus() throws RecognitionException {
		return plusMinus(0);
	}

	private PlusMinusContext plusMinus(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		PlusMinusContext _localctx = new PlusMinusContext(_ctx, _parentState);
		PlusMinusContext _prevctx = _localctx;
		int _startState = 6;
		enterRecursionRule(_localctx, 6, RULE_plusMinus, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			_localctx = new GoToDivisionContext(_localctx);
			_ctx = _localctx;
			_prevctx = _localctx;

			setState(30);
			div(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(40);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(38);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
					case 1:
						{
						_localctx = new PlusContext(new PlusMinusContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_plusMinus);
						setState(32);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(33);
						match(PLUS);
						setState(34);
						div(0);
						}
						break;
					case 2:
						{
						_localctx = new MinusContext(new PlusMinusContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_plusMinus);
						setState(35);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(36);
						match(MINUS);
						setState(37);
						div(0);
						}
						break;
					}
					} 
				}
				setState(42);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class DivContext extends ParserRuleContext {
		public DivContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_div; }
	 
		public DivContext() { }
		public void copyFrom(DivContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class DivisionByNumContext extends DivContext {
		public DivContext div() {
			return getRuleContext(DivContext.class,0);
		}
		public TerminalNode DIV() { return getToken(MatrixParser.DIV, 0); }
		public TerminalNode NUMBER() { return getToken(MatrixParser.NUMBER, 0); }
		public DivisionByNumContext(DivContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).enterDivisionByNum(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).exitDivisionByNum(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MatrixVisitor ) return ((MatrixVisitor<? extends T>)visitor).visitDivisionByNum(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class DivisionByDeterminantContext extends DivContext {
		public DivContext div() {
			return getRuleContext(DivContext.class,0);
		}
		public TerminalNode DIV() { return getToken(MatrixParser.DIV, 0); }
		public DetContext det() {
			return getRuleContext(DetContext.class,0);
		}
		public DivisionByDeterminantContext(DivContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).enterDivisionByDeterminant(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).exitDivisionByDeterminant(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MatrixVisitor ) return ((MatrixVisitor<? extends T>)visitor).visitDivisionByDeterminant(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class GoToDeterminantContext extends DivContext {
		public DetContext det() {
			return getRuleContext(DetContext.class,0);
		}
		public GoToDeterminantContext(DivContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).enterGoToDeterminant(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).exitGoToDeterminant(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MatrixVisitor ) return ((MatrixVisitor<? extends T>)visitor).visitGoToDeterminant(this);
			else return visitor.visitChildren(this);
		}
	}

	public final DivContext div() throws RecognitionException {
		return div(0);
	}

	private DivContext div(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		DivContext _localctx = new DivContext(_ctx, _parentState);
		DivContext _prevctx = _localctx;
		int _startState = 8;
		enterRecursionRule(_localctx, 8, RULE_div, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			_localctx = new GoToDeterminantContext(_localctx);
			_ctx = _localctx;
			_prevctx = _localctx;

			setState(44);
			det();
			}
			_ctx.stop = _input.LT(-1);
			setState(54);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(52);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
					case 1:
						{
						_localctx = new DivisionByNumContext(new DivContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_div);
						setState(46);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(47);
						match(DIV);
						setState(48);
						match(NUMBER);
						}
						break;
					case 2:
						{
						_localctx = new DivisionByDeterminantContext(new DivContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_div);
						setState(49);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(50);
						match(DIV);
						setState(51);
						det();
						}
						break;
					}
					} 
				}
				setState(56);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class DetContext extends ParserRuleContext {
		public DetContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_det; }
	 
		public DetContext() { }
		public void copyFrom(DetContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class DeterminantContext extends DetContext {
		public ExpContext exp() {
			return getRuleContext(ExpContext.class,0);
		}
		public TerminalNode DET() { return getToken(MatrixParser.DET, 0); }
		public DeterminantContext(DetContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).enterDeterminant(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).exitDeterminant(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MatrixVisitor ) return ((MatrixVisitor<? extends T>)visitor).visitDeterminant(this);
			else return visitor.visitChildren(this);
		}
	}

	public final DetContext det() throws RecognitionException {
		DetContext _localctx = new DetContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_det);
		try {
			_localctx = new DeterminantContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(57);
			exp();
			setState(59);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				{
				setState(58);
				match(DET);
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class MatrContext extends ParserRuleContext {
		public MatrContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_matr; }
	 
		public MatrContext() { }
		public void copyFrom(MatrContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class GoToVectContext extends MatrContext {
		public List<VectContext> vect() {
			return getRuleContexts(VectContext.class);
		}
		public VectContext vect(int i) {
			return getRuleContext(VectContext.class,i);
		}
		public GoToVectContext(MatrContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).enterGoToVect(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).exitGoToVect(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MatrixVisitor ) return ((MatrixVisitor<? extends T>)visitor).visitGoToVect(this);
			else return visitor.visitChildren(this);
		}
	}

	public final MatrContext matr() throws RecognitionException {
		MatrContext _localctx = new MatrContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_matr);
		int _la;
		try {
			_localctx = new GoToVectContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(61);
			match(T__0);
			setState(62);
			vect();
			setState(67);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__1) {
				{
				{
				setState(63);
				match(T__1);
				setState(64);
				vect();
				}
				}
				setState(69);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(70);
			match(T__2);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VectContext extends ParserRuleContext {
		public VectContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_vect; }
	 
		public VectContext() { }
		public void copyFrom(VectContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class GoToNumberContext extends VectContext {
		public List<TerminalNode> NUMBER() { return getTokens(MatrixParser.NUMBER); }
		public TerminalNode NUMBER(int i) {
			return getToken(MatrixParser.NUMBER, i);
		}
		public GoToNumberContext(VectContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).enterGoToNumber(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).exitGoToNumber(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MatrixVisitor ) return ((MatrixVisitor<? extends T>)visitor).visitGoToNumber(this);
			else return visitor.visitChildren(this);
		}
	}

	public final VectContext vect() throws RecognitionException {
		VectContext _localctx = new VectContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_vect);
		int _la;
		try {
			_localctx = new GoToNumberContext(_localctx);
			enterOuterAlt(_localctx, 1);
			{
			setState(72);
			match(T__0);
			setState(73);
			match(NUMBER);
			setState(78);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__1) {
				{
				{
				setState(74);
				match(T__1);
				setState(75);
				match(NUMBER);
				}
				}
				setState(80);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(81);
			match(T__2);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpContext extends ParserRuleContext {
		public ExpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exp; }
	 
		public ExpContext() { }
		public void copyFrom(ExpContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class VariableContext extends ExpContext {
		public TerminalNode ID() { return getToken(MatrixParser.ID, 0); }
		public VariableContext(ExpContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).enterVariable(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).exitVariable(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MatrixVisitor ) return ((MatrixVisitor<? extends T>)visitor).visitVariable(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class BracesContext extends ExpContext {
		public TerminalNode LPAR() { return getToken(MatrixParser.LPAR, 0); }
		public PlusMinusContext plusMinus() {
			return getRuleContext(PlusMinusContext.class,0);
		}
		public TerminalNode RPAR() { return getToken(MatrixParser.RPAR, 0); }
		public BracesContext(ExpContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).enterBraces(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).exitBraces(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MatrixVisitor ) return ((MatrixVisitor<? extends T>)visitor).visitBraces(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class GoToMatrixContext extends ExpContext {
		public MatrContext matr() {
			return getRuleContext(MatrContext.class,0);
		}
		public GoToMatrixContext(ExpContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).enterGoToMatrix(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof MatrixListener ) ((MatrixListener)listener).exitGoToMatrix(this);
		}
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MatrixVisitor ) return ((MatrixVisitor<? extends T>)visitor).visitGoToMatrix(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ExpContext exp() throws RecognitionException {
		ExpContext _localctx = new ExpContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_exp);
		try {
			setState(89);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__0:
				_localctx = new GoToMatrixContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(83);
				matr();
				}
				break;
			case ID:
				_localctx = new VariableContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(84);
				match(ID);
				}
				break;
			case LPAR:
				_localctx = new BracesContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(85);
				match(LPAR);
				setState(86);
				plusMinus(0);
				setState(87);
				match(RPAR);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 3:
			return plusMinus_sempred((PlusMinusContext)_localctx, predIndex);
		case 4:
			return div_sempred((DivContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean plusMinus_sempred(PlusMinusContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 3);
		case 1:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean div_sempred(DivContext _localctx, int predIndex) {
		switch (predIndex) {
		case 2:
			return precpred(_ctx, 3);
		case 3:
			return precpred(_ctx, 2);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\20^\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\3\2\3\2\3\2"+
		"\3\3\3\3\5\3\32\n\3\3\4\3\4\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3"+
		"\5\7\5)\n\5\f\5\16\5,\13\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\7\6\67"+
		"\n\6\f\6\16\6:\13\6\3\7\3\7\5\7>\n\7\3\b\3\b\3\b\3\b\7\bD\n\b\f\b\16\b"+
		"G\13\b\3\b\3\b\3\t\3\t\3\t\3\t\7\tO\n\t\f\t\16\tR\13\t\3\t\3\t\3\n\3\n"+
		"\3\n\3\n\3\n\3\n\5\n\\\n\n\3\n\2\4\b\n\13\2\4\6\b\n\f\16\20\22\2\2\2^"+
		"\2\24\3\2\2\2\4\31\3\2\2\2\6\33\3\2\2\2\b\37\3\2\2\2\n-\3\2\2\2\f;\3\2"+
		"\2\2\16?\3\2\2\2\20J\3\2\2\2\22[\3\2\2\2\24\25\5\4\3\2\25\26\7\2\2\3\26"+
		"\3\3\2\2\2\27\32\5\6\4\2\30\32\5\b\5\2\31\27\3\2\2\2\31\30\3\2\2\2\32"+
		"\5\3\2\2\2\33\34\7\b\2\2\34\35\7\n\2\2\35\36\5\4\3\2\36\7\3\2\2\2\37 "+
		"\b\5\1\2 !\5\n\6\2!*\3\2\2\2\"#\f\5\2\2#$\7\f\2\2$)\5\n\6\2%&\f\4\2\2"+
		"&\'\7\13\2\2\')\5\n\6\2(\"\3\2\2\2(%\3\2\2\2),\3\2\2\2*(\3\2\2\2*+\3\2"+
		"\2\2+\t\3\2\2\2,*\3\2\2\2-.\b\6\1\2./\5\f\7\2/8\3\2\2\2\60\61\f\5\2\2"+
		"\61\62\7\r\2\2\62\67\7\t\2\2\63\64\f\4\2\2\64\65\7\r\2\2\65\67\5\f\7\2"+
		"\66\60\3\2\2\2\66\63\3\2\2\2\67:\3\2\2\28\66\3\2\2\289\3\2\2\29\13\3\2"+
		"\2\2:8\3\2\2\2;=\5\22\n\2<>\7\16\2\2=<\3\2\2\2=>\3\2\2\2>\r\3\2\2\2?@"+
		"\7\3\2\2@E\5\20\t\2AB\7\4\2\2BD\5\20\t\2CA\3\2\2\2DG\3\2\2\2EC\3\2\2\2"+
		"EF\3\2\2\2FH\3\2\2\2GE\3\2\2\2HI\7\5\2\2I\17\3\2\2\2JK\7\3\2\2KP\7\t\2"+
		"\2LM\7\4\2\2MO\7\t\2\2NL\3\2\2\2OR\3\2\2\2PN\3\2\2\2PQ\3\2\2\2QS\3\2\2"+
		"\2RP\3\2\2\2ST\7\5\2\2T\21\3\2\2\2U\\\5\16\b\2V\\\7\b\2\2WX\7\17\2\2X"+
		"Y\5\b\5\2YZ\7\20\2\2Z\\\3\2\2\2[U\3\2\2\2[V\3\2\2\2[W\3\2\2\2\\\23\3\2"+
		"\2\2\13\31(*\668=EP[";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}
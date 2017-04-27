// Generated from C:/Users/Саша/workspace/Lab2_Idea/src\Matrix.g4 by ANTLR 4.7
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MatrixLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.7", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		NL=1, WS=2, ID=3, NUM=4, VEC=5, MATRIX=6, EQUAL=7, MINUS=8, PLUS=9, DIV=10, 
		DET=11, LPAR=12, RPAR=13;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"NL", "WS", "ID", "NUM", "VEC", "MATRIX", "EQUAL", "MINUS", "PLUS", "DIV", 
		"DET", "LPAR", "RPAR"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'\n'", null, null, null, null, null, "'='", "'-'", "'+'", "'/'", 
		"'^D'", "'('", "')'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "NL", "WS", "ID", "NUM", "VEC", "MATRIX", "EQUAL", "MINUS", "PLUS", 
		"DIV", "DET", "LPAR", "RPAR"
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


	public MatrixLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Matrix.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\17g\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\3\2\3\2\3\3\6\3!\n\3\r\3\16\3\"\3\3\3\3"+
		"\3\4\3\4\7\4)\n\4\f\4\16\4,\13\4\3\5\5\5/\n\5\3\5\6\5\62\n\5\r\5\16\5"+
		"\63\3\5\6\5\67\n\5\r\5\16\58\3\5\3\5\6\5=\n\5\r\5\16\5>\5\5A\n\5\3\6\3"+
		"\6\3\6\3\6\7\6G\n\6\f\6\16\6J\13\6\3\6\3\6\3\7\3\7\3\7\3\7\7\7R\n\7\f"+
		"\7\16\7U\13\7\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\f\3"+
		"\r\3\r\3\16\3\16\2\2\17\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f"+
		"\27\r\31\16\33\17\3\2\6\5\2\13\13\17\17\"\"\5\2C\\aac|\6\2\62;C\\aac|"+
		"\3\2\62;\2o\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2"+
		"\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27"+
		"\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\3\35\3\2\2\2\5 \3\2\2\2\7&\3\2\2\2"+
		"\t.\3\2\2\2\13B\3\2\2\2\rM\3\2\2\2\17X\3\2\2\2\21Z\3\2\2\2\23\\\3\2\2"+
		"\2\25^\3\2\2\2\27`\3\2\2\2\31c\3\2\2\2\33e\3\2\2\2\35\36\7\f\2\2\36\4"+
		"\3\2\2\2\37!\t\2\2\2 \37\3\2\2\2!\"\3\2\2\2\" \3\2\2\2\"#\3\2\2\2#$\3"+
		"\2\2\2$%\b\3\2\2%\6\3\2\2\2&*\t\3\2\2\')\t\4\2\2(\'\3\2\2\2),\3\2\2\2"+
		"*(\3\2\2\2*+\3\2\2\2+\b\3\2\2\2,*\3\2\2\2-/\7/\2\2.-\3\2\2\2./\3\2\2\2"+
		"/@\3\2\2\2\60\62\t\5\2\2\61\60\3\2\2\2\62\63\3\2\2\2\63\61\3\2\2\2\63"+
		"\64\3\2\2\2\64A\3\2\2\2\65\67\t\5\2\2\66\65\3\2\2\2\678\3\2\2\28\66\3"+
		"\2\2\289\3\2\2\29:\3\2\2\2:<\7\60\2\2;=\t\5\2\2<;\3\2\2\2=>\3\2\2\2><"+
		"\3\2\2\2>?\3\2\2\2?A\3\2\2\2@\61\3\2\2\2@\66\3\2\2\2A\n\3\2\2\2BC\7]\2"+
		"\2CH\5\t\5\2DE\7.\2\2EG\5\t\5\2FD\3\2\2\2GJ\3\2\2\2HF\3\2\2\2HI\3\2\2"+
		"\2IK\3\2\2\2JH\3\2\2\2KL\7_\2\2L\f\3\2\2\2MN\7]\2\2NS\5\13\6\2OP\7.\2"+
		"\2PR\5\13\6\2QO\3\2\2\2RU\3\2\2\2SQ\3\2\2\2ST\3\2\2\2TV\3\2\2\2US\3\2"+
		"\2\2VW\7_\2\2W\16\3\2\2\2XY\7?\2\2Y\20\3\2\2\2Z[\7/\2\2[\22\3\2\2\2\\"+
		"]\7-\2\2]\24\3\2\2\2^_\7\61\2\2_\26\3\2\2\2`a\7`\2\2ab\7F\2\2b\30\3\2"+
		"\2\2cd\7*\2\2d\32\3\2\2\2ef\7+\2\2f\34\3\2\2\2\f\2\"*.\638>@HS\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}
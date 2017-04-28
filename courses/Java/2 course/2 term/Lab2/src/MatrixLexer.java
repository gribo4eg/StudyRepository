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
		T__0=1, T__1=2, T__2=3, NL=4, WS=5, ID=6, NUMBER=7, EQUAL=8, MINUS=9, 
		PLUS=10, DIV=11, DET=12, LPAR=13, RPAR=14;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"T__0", "T__1", "T__2", "NL", "WS", "ID", "NUMBER", "EQUAL", "MINUS", 
		"PLUS", "DIV", "DET", "LPAR", "RPAR"
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\20Y\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\3\2\3\2\3\3\3\3\3\4\3\4\3\5\3"+
		"\5\3\6\6\6)\n\6\r\6\16\6*\3\6\3\6\3\7\3\7\7\7\61\n\7\f\7\16\7\64\13\7"+
		"\3\b\5\b\67\n\b\3\b\6\b:\n\b\r\b\16\b;\3\b\6\b?\n\b\r\b\16\b@\3\b\3\b"+
		"\6\bE\n\b\r\b\16\bF\5\bI\n\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r"+
		"\3\r\3\16\3\16\3\17\3\17\2\2\20\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23"+
		"\13\25\f\27\r\31\16\33\17\35\20\3\2\6\5\2\13\13\17\17\"\"\5\2C\\aac|\6"+
		"\2\62;C\\aac|\3\2\62;\2_\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2"+
		"\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25"+
		"\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\3\37\3\2"+
		"\2\2\5!\3\2\2\2\7#\3\2\2\2\t%\3\2\2\2\13(\3\2\2\2\r.\3\2\2\2\17\66\3\2"+
		"\2\2\21J\3\2\2\2\23L\3\2\2\2\25N\3\2\2\2\27P\3\2\2\2\31R\3\2\2\2\33U\3"+
		"\2\2\2\35W\3\2\2\2\37 \7]\2\2 \4\3\2\2\2!\"\7.\2\2\"\6\3\2\2\2#$\7_\2"+
		"\2$\b\3\2\2\2%&\7\f\2\2&\n\3\2\2\2\')\t\2\2\2(\'\3\2\2\2)*\3\2\2\2*(\3"+
		"\2\2\2*+\3\2\2\2+,\3\2\2\2,-\b\6\2\2-\f\3\2\2\2.\62\t\3\2\2/\61\t\4\2"+
		"\2\60/\3\2\2\2\61\64\3\2\2\2\62\60\3\2\2\2\62\63\3\2\2\2\63\16\3\2\2\2"+
		"\64\62\3\2\2\2\65\67\7/\2\2\66\65\3\2\2\2\66\67\3\2\2\2\67H\3\2\2\28:"+
		"\t\5\2\298\3\2\2\2:;\3\2\2\2;9\3\2\2\2;<\3\2\2\2<I\3\2\2\2=?\t\5\2\2>"+
		"=\3\2\2\2?@\3\2\2\2@>\3\2\2\2@A\3\2\2\2AB\3\2\2\2BD\7\60\2\2CE\t\5\2\2"+
		"DC\3\2\2\2EF\3\2\2\2FD\3\2\2\2FG\3\2\2\2GI\3\2\2\2H9\3\2\2\2H>\3\2\2\2"+
		"I\20\3\2\2\2JK\7?\2\2K\22\3\2\2\2LM\7/\2\2M\24\3\2\2\2NO\7-\2\2O\26\3"+
		"\2\2\2PQ\7\61\2\2Q\30\3\2\2\2RS\7`\2\2ST\7F\2\2T\32\3\2\2\2UV\7*\2\2V"+
		"\34\3\2\2\2WX\7+\2\2X\36\3\2\2\2\n\2*\62\66;@FH\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}
package Part2;

import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class Main {

    public static final String REG_EXP = "(\\+|-)[5-9]+([0-4]*|[AG]*)-";
    public static final String TEST_STRING = "-5689AGGA-";

    public static final String[] TEST_STRINGS = {
            "-5689AGGA-",
            "+5554231A-",
            "587142-",
            "+587142-",
            "+58788AAGGAG-",
            "-0004",
            "-67AAG-",
            "+AAAG-",
            "-5500-",
            "+5775-",
            "+556AAG--",
            "+56G",
    };

    public static void main(String[] args) {
        Pattern p = Pattern.compile(REG_EXP);
        Matcher m;
	    SwitchFSM switchFSM = new SwitchFSM();
        TransitionTable transitionTable = new TransitionTable();
        StateFSM stateFSM = new StateFSM();

        System.out.println("Word\t|\t\tRegex\t\tSwitch\t\tTable\t\tState");
        for (String s:TEST_STRINGS) {
            m = p.matcher(s);
            System.out.println(s+"\t|\t\t"+m.matches()+"\t\t"+switchFSM.scanString(s)+
                "\t\t"+transitionTable.scanString(s)+"\t\t"+stateFSM.scanString(s));
        }


    }
}

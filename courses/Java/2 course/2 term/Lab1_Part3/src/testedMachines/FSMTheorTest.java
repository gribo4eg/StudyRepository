package testedMachines;

import static org.junit.Assert.*;
import org.junit.experimental.theories.DataPoints;
import org.junit.experimental.theories.Theories;
import org.junit.experimental.theories.Theory;
import org.junit.runner.RunWith;

@RunWith(Theories.class)
public class FSMTheorTest {

	@DataPoints
	public static Object[][] testData = new Object[][] {
		
			// test case when word starts with "-"
			{ true, "-567AG-"},
			// test case when word DONT starts with "+" or "-"
			{ false, "567AGGA-" },
			// test case when word starts with "--"
			{ false, "--56GA-" },
			// test case when word starts with "+"
			{ true, "+567-" },
			// test case when word ends with "--"
			{ false, "-56GA--"},
			// test case when word contain only sign and "-"
			{ false, "+-" },
			// test case when word contains needed signs and 
			// special digit (5-9) between them
			{ true, "+6-" },
			// test case with empty string
			{ false, " " },
			// test case when word contains only needed signs
			// and digits 5-6 between them
			{ true, "+5567-" },
			// test case when word contains letters and digits 0-4
			{ false, "+5032AG-" },
			// test case when word ends with no minus sign
			{ false, "+567A" }
	};

	@Theory
	public void testStrings(final Object... testData) {
		final boolean actual = Machines.fsm.scanString((String)testData[1]);
		assertEquals(testData[0], actual);

	}
}

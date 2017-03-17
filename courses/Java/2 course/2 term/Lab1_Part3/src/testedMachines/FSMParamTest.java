package testedMachines;

import org.jetbrains.annotations.NotNull;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameter;
import org.junit.runners.Parameterized.Parameters;

import java.util.Arrays;
import java.util.Collection;

import static org.junit.Assert.assertEquals;

@RunWith(Parameterized.class)
public class FSMParamTest {

	@Parameter(value = 0)
	public boolean result;
	@Parameter(value = 1)
	public String stringToTest;
	
	@NotNull
	@Parameters(name = "{1}")
	public static Collection<Object[]> data() {
		return Arrays.asList(new Object[][] {
			
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
		});
	}

	@Test
	public void testStrings(){
		assertEquals(result, Machines.fsm.scanString(stringToTest));
	}
}

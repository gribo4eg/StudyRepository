package testedMachines;

import static org.junit.Assert.*;

import org.junit.Test;

public class FSMAsserts {

	@Test
	public void wordStartsWithMinus() {
		assertTrue(Machines.fsm.scanString("-567AG-"));
	}
	
	@Test
	public void wordStartsWithPlus() {
		assertTrue(Machines.fsm.scanString("+567-"));
	}
	
	@Test
	public void wordDontStartWithSign(){
		assertFalse(Machines.fsm.scanString("567AGGA-"));
	}
	
	@Test
	public void twoMinusesOnTheBeggining(){
		assertFalse(Machines.fsm.scanString("--56GA-"));
	}
	
	@Test
	public void twoMinusesInTheEnd(){
		assertFalse(Machines.fsm.scanString("-56GA--"));
	}
	
	@Test
	public void onlyTwoSigns(){
		assertFalse(Machines.fsm.scanString("+-"));
	}
	
	@Test
	public void digitOneBetweenSigns(){
		assertTrue(Machines.fsm.scanString("+6-"));
	}
	
	@Test
	public void emptyString(){
		assertFalse(Machines.fsm.scanString(" "));
	}
	
	@Test
	public void noLettersOrDigitsTwoAfterFirstDigits(){
		assertTrue(Machines.fsm.scanString("+5567-"));
	}
	
	@Test
	public void lettersAfterDigitsTwo(){
		assertFalse(Machines.fsm.scanString("+5032AG-"));
	}
	
	@Test
	public void noMinusAtTheEnd(){
		assertFalse(Machines.fsm.scanString("+567A"));
	}
	
}

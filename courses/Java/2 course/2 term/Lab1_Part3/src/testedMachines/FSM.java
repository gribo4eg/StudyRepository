package testedMachines;


enum State {
    q0,
    q1,
    q2,
    q3,
    q4,
    q5,
    ERROR
}

enum Event{
    PLUS,
    MINUS,
    DIGIT1,
    DIGIT2,
    LETTER,
    ANY
}

abstract class FSM {

    protected State currentState;

    abstract void start();

    private Event recognizeEvent(char symbol) {
        if (symbol == '+')
            return Event.PLUS;
        else if (symbol == '-')
            return Event.MINUS;
        else if (symbol >= '5' && symbol <= '9')
            return Event.DIGIT1;
        else if (symbol >= '0' && symbol <= '4')
            return Event.DIGIT2;
        else if (symbol == 'A' || symbol == 'G')
            return Event.LETTER;
        else
            return Event.ANY;
    }

   public boolean scanString(String string){
        start();
        Event event = Event.ANY;
        for (int i = 0; i < string.length() && currentState != State.ERROR; i++) {
            event = recognizeEvent(string.charAt(i));
            currentState = nextState(event);
        }

        return currentState == State.q5 ? true : false;
    }

    abstract State nextState(Event event);

}

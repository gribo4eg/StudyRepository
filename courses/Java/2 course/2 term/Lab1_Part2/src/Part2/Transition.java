package Part2;

import java.util.ArrayList;

class Transition {

    State startState;
    Event trigger;
    State endState;

    Transition(State startState, Event event, State endState){
        this.startState = startState;
        this.trigger = event;
        this.endState = endState;
    }

    State getStartState() {
        return startState;
    }

    Event getTrigger() {
        return trigger;
    }

    State getEndState() {
        return endState;
    }
}

class TransitionTable extends FSM{

    private ArrayList<Transition> transitions;

    @Override
    void start() {
        currentState = State.q0;
    }

    public TransitionTable(){
        transitions = new ArrayList<>();
        buildTransitionTable();
    }

    private void addTransition(State startstate, Event event, State endstate){
        transitions.add(new Transition(startstate, event, endstate));
    }

    private void buildTransitionTable(){
        addTransition(State.q0, Event.PLUS, State.q1);
        addTransition(State.q0, Event.MINUS, State.q1);
        addTransition(State.q0, Event.ANY, State.ERROR);
        addTransition(State.q1, Event.DIGIT1, State.q2);
        addTransition(State.q1, Event.ANY, State.ERROR);
        addTransition(State.q2, Event.DIGIT1, State.q2);
        addTransition(State.q2, Event.DIGIT2, State.q3);
        addTransition(State.q2, Event.LETTER, State.q4);
        addTransition(State.q2, Event.MINUS, State.q5);
        addTransition(State.q2, Event.ANY, State.ERROR);
        addTransition(State.q3, Event.DIGIT2, State.q3);
        addTransition(State.q3, Event.MINUS, State.q5);
        addTransition(State.q3, Event.ANY, State.ERROR);
        addTransition(State.q4, Event.LETTER, State.q4);
        addTransition(State.q4, Event.MINUS, State.q5);
        addTransition(State.q4, Event.ANY, State.ERROR);
    }

    @Override
    State nextState(Event event) {
        for (int i = 0; i < transitions.size(); i++){
            Transition transition = transitions.get(i);
            if (currentState == transition.getStartState()
                    && event == transition.getTrigger()) {
                return transitions.get(i).getEndState();
            }
        }
        return State.ERROR;
    }
}

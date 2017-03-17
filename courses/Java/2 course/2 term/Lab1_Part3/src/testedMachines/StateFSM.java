package testedMachines;

public class StateFSM extends FSM{

    States state;

    public StateFSM(){
        start();
    }

    @Override
    public void start(){
        currentState = State.q0;
        state = new Q0();
    }

    public void setState(States state) {
        this.state = state;
    }

    @Override
    State nextState(Event event) {
        state.setState(this, event);
        return state.getStateEnum();
    }
}

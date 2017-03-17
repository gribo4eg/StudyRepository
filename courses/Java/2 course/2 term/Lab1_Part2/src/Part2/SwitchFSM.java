package Part2;

public class SwitchFSM extends FSM{

    @Override
    public void start(){
        currentState = State.q0;
    }

    @Override
    State nextState(Event event) {

        switch (currentState){
            case q0:
                switch (event){
                    case PLUS:
                    case MINUS:
                        return State.q1;
                    default:
                        return State.ERROR;
                }
            case q1:
                switch (event){
                    case DIGIT1:
                        return State.q2;
                    default:
                        return State.ERROR;
                }
            case q2:
                switch (event){
                    case MINUS:
                        return State.q5;
                    case DIGIT1:
                        return State.q2;
                    case DIGIT2:
                        return State.q3;
                    case LETTER:
                        return State.q4;
                    default:
                        return State.ERROR;
                }
            case q3:
                switch (event){
                    case DIGIT2:
                        return State.q3;
                    case MINUS:
                        return State.q5;
                    default:
                        return State.ERROR;
                }
            case q4:
                switch (event){
                    case MINUS:
                        return State.q5;
                    case LETTER:
                        return State.q4;
                    default:
                        return State.ERROR;
                }
            case q5:
            case ERROR:
            default:
                return State.ERROR;
        }
    }
}

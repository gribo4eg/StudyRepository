package Part2;

interface States{
    void setState(StateFSM object, Event event);
    State getStateEnum();
}

class Q0 implements States{
    @Override
    public void setState(StateFSM stateFSM, Event event) {
        switch (event){
            case PLUS:
            case MINUS:
                stateFSM.setState(new Q1()); break;
            default:
                stateFSM.setState(new Error());
        }
    }

    @Override
    public State getStateEnum(){
        return State.q0;
    }
}

class Q1 implements States{
    @Override
    public void setState(StateFSM stateFSM, Event event) {
        switch (event){
            case DIGIT1:
                stateFSM.setState(new Q2()); break;
            default:
                stateFSM.setState(new Error());
        }
    }

    @Override
    public State getStateEnum(){
        return State.q1;
    }
}

class Q2 implements States{
    @Override
    public void setState(StateFSM stateFSM, Event event) {
        switch (event){
            case DIGIT1:
                stateFSM.setState(new Q2()); break;
            case DIGIT2:
                stateFSM.setState(new Q3()); break;
            case LETTER:
                stateFSM.setState(new Q4()); break;
            case MINUS:
                stateFSM.setState(new Q5()); break;
            default:
                stateFSM.setState(new Error());
        }
    }

    @Override
    public State getStateEnum(){
        return State.q2;
    }
}

class Q3 implements States{
    @Override
    public void setState(StateFSM stateFSM, Event event) {
        switch (event){
            case DIGIT2:
                stateFSM.setState(new Q3()); break;
            case MINUS:
                stateFSM.setState(new Q5()); break;
            default:
                stateFSM.setState(new Error());
        }
    }

    @Override
    public State getStateEnum(){
        return State.q3;
    }
}

class Q4 implements States{
    @Override
    public void setState(StateFSM stateFSM, Event event) {
        switch (event){
            case LETTER:
                stateFSM.setState(new Q4()); break;
            case MINUS:
                stateFSM.setState(new Q5()); break;
            default:
                stateFSM.setState(new Error());
        }
    }

    @Override
    public State getStateEnum(){
        return State.q4;
    }
}

class Q5 implements States{
    @Override
    public void setState(StateFSM stateFSM, Event event) {
    	stateFSM.setState(new Error()); 
    }

    @Override
    public State getStateEnum(){
        return State.q5;
    }
}

class Error implements States{
    @Override
    public void setState(StateFSM stateFSM, Event event) {
        stateFSM.setState(new Error());
    }

    @Override
    public State getStateEnum(){
        return State.ERROR;
    }
}
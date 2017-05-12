using System;

namespace landlord
{
    public abstract class PeopleFactory
    {
        public abstract ITool CreateTool();
        public abstract Experience CreateExperience();
        public abstract int SetEnergy();
    }

    public class PeasantHighLvlFactory : PeopleFactory
    {
        public override ITool CreateTool() => new Axe();
        public override Experience CreateExperience() => new HighExperience();
        public override int SetEnergy() => Experience.HighMiddleBorder +1;
    }

    public class PeasantMiddleLvlFactory : PeopleFactory
    {
        public override ITool CreateTool() => new Sickle();
        public override Experience CreateExperience() => new MiddleExperience();
        public override int SetEnergy() => Experience.LowMiddleBorder +1;
    }

    public class WarriorHighLvlFactory : PeopleFactory
    {
        public override ITool CreateTool() => new Sword();
        public override Experience CreateExperience() => new HighExperience();
        public override int SetEnergy() => Experience.HighMiddleBorder +1;
    }

    public class WarriorMiddleLvlFactory : PeopleFactory
    {
        public override ITool CreateTool() => new Bow();
        public override Experience CreateExperience() => new MiddleExperience();
        public override int SetEnergy() => Experience.LowMiddleBorder +1;
    }

    public class BuilderHighLvlFactory : PeopleFactory
    {
        public override ITool CreateTool() => new Hammer();
        public override Experience CreateExperience() => new HighExperience();
        public override int SetEnergy() => Experience.HighMiddleBorder +1;
    }

    public class BuilderMiddleLvlFactory : PeopleFactory
    {
        public override ITool CreateTool() => new Hammer();
        public override Experience CreateExperience() => new MiddleExperience();
        public override int SetEnergy() => Experience.LowMiddleBorder +1;
    }
}
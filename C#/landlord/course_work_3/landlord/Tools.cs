using System;
using System.Runtime.Serialization;

namespace landlord
{

    /// <summary>
    /// BRIDGE
    /// LITTLE BIT FACTORY METHOD
    /// </summary>
    public interface ITool
    {
        int DoWork(Work work, DecoratorForSettler pupil);
        Building Build();
    }

    public class Sickle : ITool
    {
        public Building Build() => throw new NotImplementedException();

        public int DoWork(Work work, DecoratorForSettler pupil) => work.DoWork(pupil);

    }

    public class Axe : ITool
    {
        public Building Build() => throw new NotImplementedException();

        public int DoWork(Work work, DecoratorForSettler pupil) => work.DoWork(pupil);

    }

    public class Sword : ITool
    {
        public Building Build() => throw new NotImplementedException();

        public int DoWork(Work work, DecoratorForSettler pupil) => work.DoWork(pupil);

    }

    public class Bow : ITool
    {
        public Building Build() => throw new NotImplementedException();

        public int DoWork(Work work, DecoratorForSettler pupil) => work.DoWork(pupil);
    }

    public class Pickaxe : Developer, ITool // Castle developer
    {
        public override Building Build() => new Castle();

        public int DoWork(Work work, DecoratorForSettler pupil) => work.DoWork(pupil);
    }

    public class Hammer : Developer, ITool //Pub developer
    {
        public override Building Build() => new Pub();

        public int DoWork(Work work, DecoratorForSettler pupil) => work.DoWork(pupil);
    }

    public class Saw : Developer, ITool // Farm developer
    {
        public override Building Build() => new Farm();

        public int DoWork(Work work, DecoratorForSettler pupil) => work.DoWork(pupil);
    }
}
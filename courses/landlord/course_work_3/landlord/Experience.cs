using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace landlord
{

    public enum Penalty { HighLvl = 1, MiddleLvl, LowLvl}

    /// <summary>
    /// STATE
    /// </summary>

    public abstract class Experience
    {
        public static int StartEnergy = 30;
        public static int LowMiddleBorder = 20;
        public static int HighMiddleBorder = 10;

        public Penalty Penalty { get; protected set; }
        public abstract void Handle(DecoratorForSettler pupil);
    }

    public class HighExperience : Experience
    {
        public HighExperience()
        {
            Penalty = Penalty.HighLvl;
        }

        public override void Handle(DecoratorForSettler pupil)
        {
            if (pupil.Energy > HighMiddleBorder && pupil.Energy <= LowMiddleBorder)
            {
                pupil.Exp = new MiddleExperience();
            }
            else if (pupil.Energy > LowMiddleBorder)
            {
                pupil.Exp = new LowExperience();
            }

            pupil.Name = pupil.SetName(pupil, pupil.Tool);
        }
    }

    public class MiddleExperience : Experience
    {
        public MiddleExperience()
        {
            Penalty = Penalty.MiddleLvl;
        }

        public override void Handle(DecoratorForSettler pupil)
        {
            if (pupil.Energy <= HighMiddleBorder)
            {
                pupil.Exp = new HighExperience();
            }
            else if (pupil.Energy > LowMiddleBorder)
            {
                pupil.Exp = new LowExperience();
            }
            pupil.Name = pupil.SetName(pupil, pupil.Tool);
        }
    }

    public class LowExperience : Experience
    {
        public LowExperience()
        {
            Penalty = Penalty.LowLvl;
        }

        public override void Handle(DecoratorForSettler pupil)
        {
            if (pupil.Energy > HighMiddleBorder && pupil.Energy <= LowMiddleBorder)
            {
                pupil.Exp = new MiddleExperience();
            }
            else if (pupil.Energy <= HighMiddleBorder)
            {
                pupil.Exp = new HighExperience();
            }

            pupil.Name = pupil.SetName(pupil, pupil.Tool);
        }
    }
}

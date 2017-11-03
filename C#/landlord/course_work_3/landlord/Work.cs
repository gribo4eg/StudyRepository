using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace landlord
{

    /// <summary>
    /// PROXY
    /// </summary>
    public abstract class Work
    {
        protected string _name;
        protected int _profit;
        protected int _needEnergy;

        public virtual string Name { get => _name; set => _name = value; }
        public virtual int Profit { get => _profit; set => _profit = value; }
        public virtual int NeedEnergy { get => _needEnergy; set => _needEnergy = value; }

        public Work()
        {}
        public Work(string name, int profit, int neededEnergy)
        {
            _name = name;
            _profit = profit;
            _needEnergy = neededEnergy;
        }


        public virtual int DoWork(DecoratorForSettler pupil)
        {
            int penalty = (int) pupil.Exp.Penalty;
            pupil.Energy -= NeedEnergy;
            pupil.CheckExperience();
            return Profit - penalty;
        }

        public virtual Building Build(DecoratorForSettler pupil)
        {
            pupil.Energy -= NeedEnergy;
            pupil.CheckExperience();
            return pupil.Tool.Build();
        }
    }

    public class PeasantSickleWork : Work
    {
        public override string Name
        {
            set => _name = value + " (Sickle)";
        }

    }

    public class PeasantAxeWork : Work
    {
        public override string Name
        {
            set => _name = value + " (Axe)";
        }
    }

    public class WarriorSwordWork : Work
    {
        public override string Name
        {
            set => _name = value + " (Sword)";
        }
    }

    public class WarriorBowWork : Work
    {
        public override string Name
        {
            set => _name = value + " (Bow)";
        }
    }

    public class BuilderPickaxeWork : Work
    {
        public override string Name
        {
            set => _name = value + " (Pickaxe)";
        }
    }

    public class BuilderHammerWork : Work
    {
        public override string Name
        {
            set => _name = value + " (Hammer)";
        }
    }

    public class BuilderSawWork : Work
    {
        public override string Name
        {
            set => _name = value + " (Saw)";
        }
    }

    public class ProxyWork<T, TW> : Work
        where T : Work, new()
    {
        private readonly T _target;

        public override string Name => _target.Name;
        public override int Profit => _target.Profit;
        public override int NeedEnergy => _target.NeedEnergy;

        public ProxyWork(string name, int profit, int neededEnergy)
        {
            _target = new T()
            {
                Name = name,
                Profit = profit,
                NeedEnergy = neededEnergy
            };
        }

        public override int DoWork(DecoratorForSettler pupil)
        {
            if (pupil.Tool is TW)
            {
                return _target.DoWork(pupil);
            }

            MessageBox.Show("Wrong tool!", "Warning!", MessageBoxButton.OK, MessageBoxImage.Warning);
            return 0;
        }

        public override Building Build(DecoratorForSettler pupil)
        {
            if (pupil.Tool is TW)
                return _target.Build(pupil);

            MessageBox.Show("Wrong tool!", "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
            return null;
        }
    }
}

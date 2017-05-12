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
        public virtual string Name { get; set; }
        public virtual int Profit { get; set; }
        public virtual int NeedEnergy { get; set; }

        protected Work (string name, int profit, int neededEnergy)
        {
            Name = name;
            Profit = profit;
            NeedEnergy = neededEnergy;
        }

        protected Work()
        {}

        public virtual int DoWork(DecoratorForSettler pupil)
        {
            int penalty = (int)pupil.Exp.Penalty;
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
        public PeasantSickleWork(string name, int profit, int neededEnergy)
            :base(name+ " (Sickle)", profit, neededEnergy)
        {}
    }

    public class ProxyPeasantSickleWork : Work
    {
        private readonly PeasantSickleWork _target;

        public override string Name => _target.Name;
        public override int Profit => _target.Profit;
        public override int NeedEnergy => _target.NeedEnergy; 

        public ProxyPeasantSickleWork(string name, int profit, int neededEnergy)
        {
            _target = new PeasantSickleWork(name, profit, neededEnergy);
        }

        public override int DoWork(DecoratorForSettler pupil)
        {
            if (pupil.Tool is Sickle)
            {
                return _target.DoWork(pupil);
            }
            
            MessageBox.Show("Wrong tool!", "Warning!", MessageBoxButton.OK, MessageBoxImage.Warning);
            return 0;

        }
    }

    public class PeasantAxeWork : Work
    {
        public PeasantAxeWork(string name, int profit, int neededEnergy)
            :base(name + " (Axe)", profit, neededEnergy)
        { }
    }

    public class ProxyPeasantAxeWork : Work
    {
        private readonly PeasantAxeWork _target;

        public override string Name => _target.Name;
        public override int Profit => _target.Profit;
        public override int NeedEnergy => _target.NeedEnergy;

        public ProxyPeasantAxeWork(string name, int profit, int neededEnergy)
        {
            _target = new PeasantAxeWork(name, profit, neededEnergy);
        }

        public override int DoWork(DecoratorForSettler pupil)
        {
            if (pupil.Tool is Axe)
            {
                return _target.DoWork(pupil);
            }

            MessageBox.Show("Wrong tool!", "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
            return 0;

        }
    }

    public class WarriorSwordWork : Work
    {
        public WarriorSwordWork(string name, int profit, int neededEnergy)
            :base(name+ " (Sword)", profit, neededEnergy)
        {}
    }

    public class ProxyWarriorSwordWork : Work
    {
        private readonly WarriorSwordWork _target;

        public override string Name => _target.Name;
        public override int Profit => _target.Profit;
        public override int NeedEnergy => _target.NeedEnergy;

        public ProxyWarriorSwordWork(string name, int profit, int neededEnergy)
        {
            _target = new WarriorSwordWork(name, profit, neededEnergy);
        }

        public override int DoWork(DecoratorForSettler pupil)
        {
            if (pupil.Tool is Sword)
            {
                return _target.DoWork(pupil);
            }

            MessageBox.Show("Wrong tool!", "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
            return 0;
        }
    }

    public class WarriorBowWork : Work
    {
        public WarriorBowWork(string name, int profit, int neededEnergy)
            :base(name+ " (Bow)", profit, neededEnergy)
        {}
    }

    public class ProxyWarriorBowWork : Work
    {
        private readonly WarriorBowWork _target;

        public override string Name => _target.Name;
        public override int Profit => _target.Profit;
        public override int NeedEnergy => _target.NeedEnergy;

        public ProxyWarriorBowWork(string name, int profit, int neededEnergy)
        {
            _target = new WarriorBowWork(name, profit, neededEnergy);
        }

        public override int DoWork(DecoratorForSettler pupil)
        {
            if (pupil.Tool is Bow)
            {
                return _target.DoWork(pupil);
            }
            MessageBox.Show("Wrong tool!", "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
            return 0;
        }
    }

    public class BuilderPickaxeWork : Work
    {
        public BuilderPickaxeWork(string name, int profit, int neededEnergy)
            :base(name + " (Pickaxe)", profit, neededEnergy)
        {}
    }

    public class ProxyBuilderPickaxeWork : Work
    {
        private readonly BuilderPickaxeWork _target;

        public override string Name => _target.Name;
        public override int Profit => _target.Profit;
        public override int NeedEnergy => _target.NeedEnergy;

        public ProxyBuilderPickaxeWork(string name, int profit, int neededEnergy)
        {
            _target = new BuilderPickaxeWork(name, profit, neededEnergy);
        }

        public override int DoWork(DecoratorForSettler pupil)
        {
            if (pupil.Tool is Pickaxe)
            {
                return _target.DoWork(pupil);
            }

            MessageBox.Show("Wrong tool!", "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
            return 0;
        }

        public override Building Build(DecoratorForSettler pupil)
        {
            if (pupil.Tool is Pickaxe)
                return _target.Build(pupil);

            MessageBox.Show("Wrong tool!", "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
            return null;
        }

    }

    public class BuilderHammerWork : Work
    {
        public BuilderHammerWork(string name, int profit, int neededEnergy)
            : base(name + " (Hammer)", profit, neededEnergy)
        { }
    }

    public class ProxyBuilderHammerWork : Work
    {
        private readonly BuilderHammerWork _target;

        public override string Name => _target.Name;
        public override int Profit => _target.Profit;
        public override int NeedEnergy => _target.NeedEnergy;

        public ProxyBuilderHammerWork(string name, int profit, int neededEnergy)
        {
            _target = new BuilderHammerWork(name, profit, neededEnergy);
        }

        public override int DoWork(DecoratorForSettler pupil)
        {
            if (pupil.Tool is Hammer)
            {
                return _target.DoWork(pupil);
            }

            MessageBox.Show("Wrong tool!", "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
            return 0;
        }

        public override Building Build(DecoratorForSettler pupil)
        {
            if (pupil.Tool is Hammer)
                return _target.Build(pupil);

            MessageBox.Show("Wrong tool!", "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
            return null;
        }
    }

    public class BuilderSawWork : Work
    {
        public BuilderSawWork(string name, int profit, int neededEnergy)
            : base(name + " (Saw)", profit, neededEnergy)
        { }
    }

    public class ProxyBuilderSawWork : Work
    {
        private readonly BuilderSawWork _target;

        public override string Name => _target.Name;
        public override int Profit => _target.Profit;
        public override int NeedEnergy => _target.NeedEnergy;

        public ProxyBuilderSawWork(string name, int profit, int neededEnergy)
        {
            _target = new BuilderSawWork(name, profit, neededEnergy);
        }

        public override int DoWork(DecoratorForSettler pupil)
        {
            if (pupil.Tool is Saw)
            {
                return _target.DoWork(pupil);
            }

            MessageBox.Show("Wrong tool!", "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
            return 0;
        }

        public override Building Build(DecoratorForSettler pupil)
        {
            if (pupil.Tool is Saw)
                return _target.Build(pupil);

            MessageBox.Show("Wrong tool!", "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
            return null;
        }
    }
}

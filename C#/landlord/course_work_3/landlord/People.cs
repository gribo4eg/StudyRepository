using System;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Automation.Peers;
using GalaSoft.MvvmLight;
using GalaSoft.MvvmLight.Messaging;

namespace landlord
{
    public abstract class People : ObservableObject
    {
        protected int energy;
        protected string name;
        protected Experience experience;

    
        public virtual string Name { get => name;
            set { name = value; RaisePropertyChanged(() => Name);}
        }
        
        public virtual int Energy { get => energy;
            set { energy = value; RaisePropertyChanged(() => Energy);}
        }

        public virtual Experience Exp { get => experience; set => experience = value; } //STATE

    }
    
    public class Settler : People
    {
        public Settler()
        {
            experience = new LowExperience();
            energy = Experience.StartEnergy;
            name = "Simple Settler " + experience.Penalty;
        }
    }

    /// <summary>
    /// DECORATOR
    /// BRIDGE
    /// CHAIN OF RESPONSIBILITY
    /// LITTLE ABSTRACT FACTORY
    /// </summary>
    
    public abstract class DecoratorForSettler : People
    {
        protected People Pupil;

        public ITool Tool { get; protected set; }// FOR BRIDGE
        
        public override int Energy { get => Pupil.Energy; set { Pupil.Energy = value; RaisePropertyChanged(() => Pupil.Energy); } }
        
        public override string Name { get => name; set { name = value; RaisePropertyChanged(() => Name); } }

        public override Experience Exp { get => Pupil.Exp; set => Pupil.Exp = value; }

        public DecoratorForSettler Successor { get; set; } // FOR CHAIN

        protected DecoratorForSettler(People pupil)
        {
            Pupil = pupil;
        }

        protected DecoratorForSettler(PeopleFactory factory)
        {
            Pupil = new Settler {Exp = factory.CreateExperience(), Energy = factory.SetEnergy()};
            Tool = factory.CreateTool();
            Name = SetName(this, Tool);
        }

        public People GetPupil
        {
            get
            {
               Pupil.Name = "Simple Settler " + Pupil.Exp.Penalty;
               return Pupil;
            }
        }

        public virtual int HandleWork(Work work)
        {
            if (Energy >= work.NeedEnergy)
            {
                return DoWork(work);
            }
            if (Successor != null)
            {
                return Successor.HandleWork(work);
            }
            MessageBox.Show("None of the successors can do this", "Warning!", MessageBoxButton.OK,
                MessageBoxImage.Information);
            return 0;
        }

        protected virtual int DoWork(Work work) => Tool.DoWork(work, this);

        public Building HandleBuild(Work work)
        {
            if (Energy >= work.NeedEnergy)
            {
                return Build(work);
            }
            if (Successor != null)
            {
                return Successor.HandleBuild(work);
            }
            MessageBox.Show("None of the successors can do this", "Warning!", MessageBoxButton.OK,
                MessageBoxImage.Information);
            return null;
        }

        protected Building Build(Work work) => work.Build(this);


        public abstract void SetTool(ITool newTool);

        public void CheckExperience() => Exp.Handle(this);

        public string SetName(DecoratorForSettler decor, ITool tool)
                    => decor.GetType().Name + " with " + tool.GetType().Name + " " + decor.Exp.Penalty;

    }

    public class Builder : DecoratorForSettler
    {
        public Builder(People pupil)
            : base(pupil)
        {
            Tool = new Hammer();
            Name = SetName(this, Tool);
        }

        public Builder(PeopleFactory factory)
            : base(factory)
        { }

        public override void SetTool(ITool newTool)
        {
            if (newTool is Hammer || newTool is Saw || newTool is Pickaxe)
            {
                Tool = newTool;
                Name = SetName(this, Tool);
            }
        }
    }

    public class Peasant : DecoratorForSettler
    {

        public Peasant(People pupil)
            : base(pupil)
        {
            Tool = new Sickle();
            Name = SetName(this, Tool);
        }

        public Peasant(PeopleFactory factory)
            : base(factory)
        {}

        public override void SetTool(ITool newTool)
        {
            if(newTool is Sickle || newTool is Axe)
            {
                Tool = newTool;
                Name = SetName(this, Tool);
            }
        }
    }
    
    public class Warrior : DecoratorForSettler
    {
        public Warrior(People pupil)
            : base(pupil)
        {
            Tool = new Sword();
            Name = SetName(this, Tool);
        }

        public Warrior(PeopleFactory factory)
            : base(factory)
        {}

        public override void SetTool(ITool newTool)
        {
            if (newTool is Sword || newTool is Bow)
            {
                Tool = newTool;
                Name = SetName(this, Tool);
            }
        }
    }
    
}
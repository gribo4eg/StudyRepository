using System.Runtime.InteropServices;
using System.Windows;
using GalaSoft.MvvmLight;
using System;

namespace landlord
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    { 
        public MainWindow()
        {
            InitializeComponent();
        }

        private void ToSettlerButt_Click(object sender, RoutedEventArgs e)
        {
            int index;
            if(peasantsList.SelectedItem != null)
            {
                index = ViewModel.Peasants.IndexOf((Peasant)peasantsList.SelectedItem);
                Peasant peasant = ViewModel.Peasants[index];
                peasant.Successor = null;
                ViewModel.Peasants.Remove(peasant);
                ViewModel.Settlers.Add((Settler)peasant.GetPupil);
                
            }
            else if(warriorsList.SelectedItem != null)
            {
                index = ViewModel.Warriors.IndexOf((Warrior)warriorsList.SelectedItem);
                Warrior warrior = ViewModel.Warriors[index];
                warrior.Successor = null;
                ViewModel.Warriors.Remove(warrior);
                ViewModel.Settlers.Add((Settler)warrior.GetPupil);
            }
            else if(buildersList.SelectedItem != null)
            {
                index = ViewModel.Builders.IndexOf((Builder)buildersList.SelectedItem);
                Builder builder = ViewModel.Builders[index];
                builder.Successor = null;
                ViewModel.Builders.Remove(builder);
                ViewModel.Settlers.Add((Settler)builder.GetPupil);
            }

            ViewModel.SetSuccessors();
            UnselectItems();
        }

        private void ToBuilderButt_Click(object sender, RoutedEventArgs e)
        {
            if (settlersList.SelectedItem != null)
            {
                int index = ViewModel.Settlers.IndexOf((Settler)settlersList.SelectedItem);
                Settler settler = ViewModel.Settlers[index];
                ViewModel.Settlers.Remove(settler);
                ViewModel.Builders.Add(new Builder(settler));
                ViewModel.SetSuccessors();
                UnselectItems();
            }
        }

        private void ToPeasantButt_Click(object sender, RoutedEventArgs e)
        {
            if (settlersList.SelectedItem != null)
            {
                int index = settlersList.SelectedIndex;
                Settler settler = ViewModel.Settlers[index];
                Peasant peasant = new Peasant(settler);
                ViewModel.Peasants.Add(peasant);
                ViewModel.Settlers.Remove(settler);
                ViewModel.SetSuccessors();
                UnselectItems();
            }
        }

        private void ToWarriorButt_Click(object sender, RoutedEventArgs e)
        {
            if (settlersList.SelectedItem != null)
            {
                int index = ViewModel.Settlers.IndexOf((Settler)settlersList.SelectedItem);
                Settler settler = ViewModel.Settlers[index];
                ViewModel.Settlers.Remove(settler);
                ViewModel.Warriors.Add(new Warrior(settler));
                ViewModel.SetSuccessors();
                UnselectItems();
            }
        }

        private void ChangeToolButt_Click(object sender, RoutedEventArgs e)
        {
            int index;
            if (peasantsList.SelectedItem != null)
            {
                index = ViewModel.Peasants.IndexOf((Peasant)peasantsList.SelectedItem);
                Peasant peasant = ViewModel.Peasants[index];

                if (peasant.Tool is Sickle)
                    peasant.SetTool(new Axe());
                else
                    peasant.SetTool(new Sickle());
                
            }
            else if (warriorsList.SelectedItem != null)
            {
                index = ViewModel.Warriors.IndexOf((Warrior)warriorsList.SelectedItem);
                Warrior warrior = ViewModel.Warriors[index];

                if (warrior.Tool is Sword)
                    warrior.SetTool(new Bow());
                else
                    warrior.SetTool(new Sword());
            }
            else if (buildersList.SelectedItem != null)
            {
                index = ViewModel.Builders.IndexOf((Builder)buildersList.SelectedItem);
                Builder builder = ViewModel.Builders[index];

                if (builder.Tool is Pickaxe)
                    builder.SetTool(new Hammer());
                else if (builder.Tool is Hammer)
                    builder.SetTool(new Saw());
                else
                    builder.SetTool(new Pickaxe());
            }
            UnselectItems();
        }

        private void DoWorkButt_Click(object sender, RoutedEventArgs e)
        {   
            int workerIndex, workIndex;
            if (peasantsList.SelectedItem != null)
            {
                workerIndex = ViewModel.Peasants.IndexOf((Peasant)peasantsList.SelectedItem);
                Peasant peasant = ViewModel.Peasants[workerIndex];

                workIndex = ViewModel.Jobs.IndexOf((Work)jobsList.SelectedItem);
                Work work = ViewModel.Jobs[workIndex];

                int profit = peasant.HandleWork(work);
                if (profit <= 0) return;
                ViewModel.Jobs.Remove(work);

                if (peasant.Tool is Sickle) ViewModel.FoodCount += profit;
                else ViewModel.WoodCount += profit;

            }
            else if (warriorsList.SelectedItem != null)
            {
                workerIndex = ViewModel.Warriors.IndexOf((Warrior)warriorsList.SelectedItem);
                Warrior warrior = ViewModel.Warriors[workerIndex];

                workIndex = ViewModel.Jobs.IndexOf((Work)jobsList.SelectedItem);
                Work work = ViewModel.Jobs[workIndex];

                int profit = warrior.HandleWork(work);
                if (profit <= 0) return;
                ViewModel.Jobs.Remove(work);
                ViewModel.GoldCount += profit;
                ViewModel.FoodCount -= profit / 2;

            }
            else if (buildersList.SelectedItem != null)
            {
                workerIndex = ViewModel.Builders.IndexOf((Builder)buildersList.SelectedItem);
                Builder builder = ViewModel.Builders[workerIndex];

                workIndex = ViewModel.Jobs.IndexOf((Work)jobsList.SelectedItem);
                Work work = ViewModel.Jobs[workIndex];

                if (work.Profit == 0)
                {
                    ViewModel.Jobs.Remove(work);
                    Building building = builder.HandleBuild(work);
                    int energy = building.IncreaseEnergy;
                    ViewModel.WoodCount -= energy;
                    ViewModel.IncreaseEnergyForAll(energy);
                    ViewModel.Buildings.Add(building);
                }
                else
                {
                    int profit = builder.HandleWork(work);
                    if (profit <= 0) return;
                    ViewModel.Jobs.Remove(work);
                    ViewModel.GoldCount += profit;
                    ViewModel.FoodCount -= profit / 2;
                }   
            }
            CheckResources();
            UnselectItems();
            MessageBox.Show("Job Done!", "Message!", MessageBoxButton.OK, MessageBoxImage.Information);
        }

        private void AddSettlerButt_Click(object sender, RoutedEventArgs e)
        {
            if (ViewModel.Capacity < ViewModel.MaxCapacity)
            {
                if (ViewModel.GoldCount >= 10 && ViewModel.FoodCount >= 10)
                {
                    ViewModel.Settlers.Add(new Settler()); ViewModel.GoldCount -= 10; ViewModel.FoodCount -= 10;
                    CheckResources();
                }
                else
                    MessageBox.Show("Not enough Gold or Food to buy Settler", "Warning!", MessageBoxButton.OK, MessageBoxImage.Warning);
            }
            else
                MessageBox.Show("Not enough space for new Units!", "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
        }

        #region HelpMethods

        private void CheckFood() => FoodBox.Text = ViewModel.FoodCount.ToString();
        private void CheckWood() => WoodBox.Text = ViewModel.WoodCount.ToString();
        private void CheckGold() => GoldBox.Text = ViewModel.GoldCount.ToString();
        private void CheckCapacity() { Capacity.Text = ViewModel.Capacity.ToString(); MaxCapacity.Text = ViewModel.MaxCapacity.ToString(); }

        private void CheckResources() { CheckFood(); CheckGold(); CheckWood(); ViewModel.SetAllCapacities(); CheckCapacity(); }

        private void UnselectItems()
        {
            warriorsList.SelectedItem = null;
            peasantsList.SelectedItem = null;
            buildersList.SelectedItem = null;
        }



        #endregion

        private void ToBoughtButt_Click(object sender, RoutedEventArgs e)
        {
            string expLvl = ToBoughtExpLvl.SelectionBoxItem.ToString();
            string type = ToBoughtPupilType.SelectionBoxItem.ToString();
            int cost;

            if (ViewModel.Capacity >= ViewModel.MaxCapacity)
            {
                MessageBox.Show("Not enough space for new Units!", "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
                return;
            }

            switch (expLvl)
            {
                case "High":
                    cost = 30;
                    if (ViewModel.FoodCount >= cost && ViewModel.GoldCount >= cost)
                    {
                        switch (type)
                        {
                            case "Peasant":
                                ViewModel.Peasants.Add(new Peasant(new PeasantHighLvlFactory()));
                                ViewModel.GoldCount -= cost;
                                ViewModel.FoodCount -= cost;
                                break;
                            case "Warrior":
                                ViewModel.Warriors.Add(new Warrior(new WarriorHighLvlFactory()));
                                ViewModel.GoldCount -= cost;
                                ViewModel.FoodCount -= cost;
                                break;
                            case "Builder":
                                ViewModel.Builders.Add(new Builder(new BuilderHighLvlFactory()));
                                ViewModel.GoldCount -= cost;
                                ViewModel.FoodCount -= cost;
                                break;
                        }
                    }
                    else
                        MessageBox.Show("Not enough Gold or Food to buy this guy", "Warning!", MessageBoxButton.OK, MessageBoxImage.Warning);
                    break;
                case "Middle":
                    cost = 20;
                    if (ViewModel.FoodCount >= cost && ViewModel.GoldCount >= cost)
                    {
                        switch (type)
                        {
                            case "Peasant":
                                ViewModel.Peasants.Add(new Peasant(new PeasantMiddleLvlFactory()));
                                ViewModel.GoldCount -= cost;
                                ViewModel.FoodCount -= cost;
                                break;
                            case "Warrior":
                                ViewModel.Warriors.Add(new Warrior(new WarriorMiddleLvlFactory()));
                                ViewModel.GoldCount -= cost;
                                ViewModel.FoodCount -= cost;
                                break;
                            case "Builder":
                                ViewModel.Builders.Add(new Builder(new BuilderMiddleLvlFactory()));
                                ViewModel.GoldCount -= cost;
                                ViewModel.FoodCount -= cost;
                                break;
                        }
                    }
                    else
                        MessageBox.Show("Not enough Gold or Food to buy this guy", "Warning!", MessageBoxButton.OK, MessageBoxImage.Warning);
                    break;
            }

            ViewModel.SetSuccessors();
            CheckResources();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            string name = "",
                type = "";
            int profit, energy;
            try
            {
                name = JobName.Text;
                type = JobType.SelectionBoxItem.ToString();
                profit = Int32.Parse(JobProfit.Text);
                energy = Int32.Parse(JobEnergy.Text);
            }
            catch(Exception exc)
            {
                MessageBox.Show(exc.Message, "Alert!", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }

            Work work = null;

            switch (type)
            {
                case "Sickle":
                    work = new ProxyWork<PeasantSickleWork, Sickle>(name, profit, energy);
                    break;
                case "Axe":
                    work = new ProxyWork<PeasantAxeWork, Axe>(name, profit, energy);
                    break;
                case "Sword":
                    work = new ProxyWork<WarriorSwordWork, Sword>(name, profit, energy);
                    break;
                case "Bow":
                    work = new ProxyWork<WarriorBowWork, Bow>(name, profit, energy);
                    break;
                case "Pickaxe":
                    work = new ProxyWork<BuilderPickaxeWork, Pickaxe>("Repaire Castle", 20, 10);
                    break;
                case "Hammer":
                    work = new ProxyWork<BuilderHammerWork, Hammer>("Repaire Pub", 15, 7);
                    break;
                case "Saw":
                    work = new ProxyWork<BuilderSawWork, Saw>("Repaire Farm", 10, 5);
                    break;
            }

            ViewModel.Jobs.Add(work);
        }
    }
}

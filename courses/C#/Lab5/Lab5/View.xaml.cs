using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Runtime.ExceptionServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Lab5
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        private ViewModel _model;

        public MainWindow()
        {
            InitializeComponent();
            _model = new ViewModel();
            SubscribeOnDisableBut();
            SubscribeOnUpdBut();
        }

        public void CmdDelete(object sender, RoutedEventArgs e)
        {
            _model.DeleteWatchman((Watchman) WtchList.SelectedItem);
        }

        public void CmdUpdate(object sender, RoutedEventArgs e)
        {
            GetDataForUpdate();
            _model.UpdateWatchman((Watchman)WtchList.SelectedItem);
        }

        public void DisableAddButton(object sender, System.EventArgs eventArgs)
        {
            try
            {
                int age = Int32.Parse(AgeBox.Text);
                int weight = Int32.Parse(WeightBox.Text);
                if (Validator.Valid(NameBox.Text, SurnameBox.Text, age, weight))
                {
                    Addwatch.IsEnabled = true;
                }
                else
                {
                    Addwatch.IsEnabled = false;
                }
            }
            catch (Exception exception)
            {
                if(exception is FormatException || exception is OverflowException)
                    Addwatch.IsEnabled = false;
            }
        }

        public void DisableUpdButton(object sender, System.EventArgs eventArgs)
        {
            try
            {
                int age = Int32.Parse(UpdAge.Text);
                int weight = Int32.Parse(UpdWeight.Text);
                if (Validator.Valid(UpdName.Text, UpdSurname.Text, age, weight))
                {
                    UpdButton.IsEnabled = true;
                }
                else
                {
                    UpdButton.IsEnabled = false;
                }
            }
            catch (Exception exception)
            {
                if(exception is FormatException || exception is OverflowException)
                    UpdButton.IsEnabled = false;
            }
        }

        private void GetDataForUpdate()
        {
            _model.WatchmanNameUpdate = UpdName.Text;
            _model.WatchmanSurnameUpdate = UpdSurname.Text;
            _model.WatchmanAgeUpdate = Int32.Parse(UpdAge.Text);
            _model.WatchmanWeightUpdate = Int32.Parse(UpdWeight.Text);            
        }

        private void SubscribeOnUpdBut()
        {
            UpdName.TextChanged += DisableUpdButton;
            UpdSurname.TextChanged += DisableUpdButton;
            UpdAge.TextChanged += DisableUpdButton;
            UpdWeight.TextChanged += DisableUpdButton;
        }

        private void SubscribeOnDisableBut()
        {
            NameBox.TextChanged += DisableAddButton;
            SurnameBox.TextChanged += DisableAddButton;
            AgeBox.TextChanged += DisableAddButton;
            WeightBox.TextChanged += DisableAddButton;
        }

    }
}

using System;
using System.Collections.Generic;
using System.Linq;
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
            NameBox.TextChanged += DisableAddButton;
            SurnameBox.TextChanged += DisableAddButton;
            AgeBox.TextChanged += DisableAddButton;
            WeightBox.TextChanged += DisableAddButton;
        }

        public void CmdDelete(object sender, RoutedEventArgs e)
        {
            _model.DeleteWatchman((Watchman) WtchList.SelectedItem);
        }

        public void CmdUpdate(object sender, RoutedEventArgs e)
        {

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

    }
}

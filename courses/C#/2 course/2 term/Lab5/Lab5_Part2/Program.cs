namespace Lab5_Part2
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            Menu menu = new Menu();
            Array array = new Array();
            menu.AddCommand = new AddToArrayCommand(array);
            menu.RemoveCommand = new RemoveFromArrayCommand(array);
            menu.ModifyCommand = new ModifyInArrayCommand(array);

            menu.AddNumber(45);
            menu.AddNumber(12);
            menu.AddNumber(1);

            menu.RemoveNumber(12);
            menu.ModifyNumber(1, 31);

        }
    }
}
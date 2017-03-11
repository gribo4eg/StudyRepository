using System;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;
using System.Threading;

/* Функции принимают слишком много аргументов >=3
    Функции должны иметь небольшое кол-во аргументов <3: каждый метод
    в этом решении принимает в себя не больше 2 аргументов


*/

/* Мертвые функции
    Функции которые не используются должны быть удалены:
    Dog.sleep, Cat.jumpOnTable, Horse.Run, Horse.Training,
    Watcher.BrainStorm, Watcher.Training
*/

/* Несколько языков в одном исходном файле
    В идеале исходный код должен содержать код на одном! языке.
    Иначе результат получается запутанным и не надежным.
    В данном решении каждый файл содержит только код на языке
    C#
*/

/* Закомментированный код
    Такой код должен быть удален: в классе Zoo имеется
    код который должен быть удален в следствии свого
    закоментированного состояния
*/

/* Имена функций должны описывать выполняемую операцию
    addWatchman->AddWatchmanInZoo с животными аналогично
    из-за начального названия можно было не понять куда и как добавляется
    экземпляр объекта Watchman
    Feeding->FeedAnimalsInZoo
*/

/* Заменяйте магические числа истроки на именованые константы
    Объявите константу и проинициализируйте ее значением магическое число/строку.
    Найдите все вхождения магического числа/строки.
    Проверьте, согласуется ли магическое число/строка с использованием константы; если да, замените магическое
    число/строку константой. После замены всех магических чисел выполните компиляцию и тестирование. Все должно работать так,
    как если бы ничего не изменялось.

    В каждом классе животных магические строки издаваемых звуков были заменены на константы
    "WOOF" -> private const string DOG_SOUND = "WOOF";
*/

/* Функции выполняют одно действие
    Подписка на ивент кормления при добавлении/удалении животного из зоопарка была
    вынесена в отдельную функцию, раньше же она находилась в коде добавления
    животного в зоопарк
*/

/* Инкапсулируйте условные конструкции
    Проверка на существования в зоопарке смотрителя вынесена в отдельную функцию
    Так же в отдельный метод было вынесено несколько условий сосредоточеных на проверке
    валидности смотрителя
*/

/* Избегайте негативных условий
    Все проверки были изменены с !IsWatchman(false) на NoWatchman(false)
*/

/* Используйте информативные имена переменных
    Имена переменных должны быть содержательны
*/

/* Длинные тела методов
    Тело метода должно быть как можно меньше. Программы, использующие объекты,
    живут долго и счастливо, когда методы этих объектов короткие. Чем длинне метод тем
    сложнее понять что он делает
    В решении даже самые большие методы занимают около 20 строк, все возможные части кода были
    вынесены в отдельные методы(декомпозиция)
    Чтобы укоротить метод, требуется лишь «Выделение метода» (Extract Method ). Найдите те
    части метода, которые кажутся согласованными друг с другом, и образуйте новый метод.
*/

/* Поднятие метода
    Изучите методы и убедитесь, что они идентичны. Создайте в родительском классе новый метод,
    скопируйте в него тело одного из методов. Удалите один метод подкласса. Выполните
    компиляцию и тестирование. Продолжайте удаление методов подклассов и тестирование, пока не останется только метод родительского
    класса.
    Методы Dispose() и Dispose(bool) были вынесены из классов животных в один общий
*/

/* Переименование методов
    Объявите новый метод с новым именем. Скопируйте тело прежнего метода в метод с новым именем
    Измените тело прежнего метода так, чтобы в нем вызывался новый метод.
    Найдите все ссылки на прежний метод и замените их ссылками на новый.
    Удалите старый метод.
    Feeding->FeedAnimalsInZoo addWatchman->AddWatchmanInZoo
*/

/* Поднятие конструктора
    Создайте конструктор в родительском классе. Переместите общий начальный код из
    подкласса в конструктор родительского класса. Вызовите конструктор родительского класса.
    Выполните компиляцию и тестирование. Удалите конструкторы из подклассов.

    Конструкторы с иницализацией имен из классов животных были вынесены в один конструктор
    класса Animal в котором переменная name была инициализирована
*/

/* Декомпозиция условного оператора
    Выделите условие в собственный метод.
    Выделите части «then» и «else» в собственные методы.

    watchman.Name.Length < 2 || watchman.Name.Length > 20 =>
    private static bool WatchmanIsNotValid(Watchman watchman)
        {
            return (watchman.Name.Length < 2 || watchman.Name.Length > 20);
        }
*/

namespace Lab3
{
    class MainClass
    {

        private static WeakReference weakRef;

        private static void ShowWeakReference()
        {

            if (weakRef == null || ((Watchman)weakRef.Target) == null)
            {
                weakRef = new WeakReference(new Watchman());
            }
            //GC.Collect();

        }

        public static void Main()
        {
            {
                var bird = new Bird("Chiki", 3);
                Console.WriteLine(bird.Name);
                Console.WriteLine(GC.GetTotalMemory(true) + " " + bird.Name + " created");
                bird.Dispose();
                Console.WriteLine(GC.GetTotalMemory(true) + " disposed");
            }

            {
                Watchman watchman = new Watchman("Darth Vader", 23);
                Zoo<IAnimal> zoo = Zoo<IAnimal>.GetInstance("TOP ZOO");
                Horse horse = new Horse("Horse", 10);
                Dog dog = new Dog("Dog", 3);
                zoo.AddWatcherInZoo(watchman);
                zoo.AddAnimalInZoo(horse);
                zoo.AddAnimalInZoo(dog);

                Console.WriteLine(zoo.Name);
                Console.WriteLine(GC.GetTotalMemory(true) + " Zoo created");
                zoo.Dispose();
                Console.WriteLine(GC.GetTotalMemory(true) + " Zoo disposed");

                Fox fox = new Fox("Fox", 6);
                fox = null;
                GC.Collect();
            }



            /*{
                WeakReference wr = new WeakReference(new Watchman("PANIN", 40));
                GC.GetTotalMemory(true);
                Console.WriteLine((Watchman)wr.Target);
                Console.WriteLine(wr.IsAlive ? "Im alive" : "Im dead");
                GC.Collect(0, GCCollectionMode.Forced);
                GC.GetTotalMemory(true);
                Console.WriteLine(wr.IsAlive ? "Im alive" : "Im dead");
            }*/

            Console.Write(GC.GetTotalMemory(true));

                ShowWeakReference();
                Thread.Sleep(50);
                Console.Write(GC.GetTotalMemory(true));
                Console.WriteLine((Watchman)weakRef.Target == null ? "Im dead" : "Im alive" );


            Console.WriteLine((Watchman)weakRef.Target == null ? "Im dead" : "Im alive" );
        }

        static void WatchmanExceptionMessage(WatchmanException ex)
        {
            Console.WriteLine("********************************");
            Console.WriteLine("ERROR: {0}", ex.Info());
            Console.WriteLine("********************************\n\n");
        }

        static void ZooExceptionMessage(ZooException ex)
        {
            Console.WriteLine("********************************");
            Console.WriteLine("ERROR: {0}", ex.info());
            Console.WriteLine("********************************\n\n");
        }

        public static Watchman DeserializeJson()
        {

            string json = File.ReadAllText("watchman.json");
            MemoryStream stream = new MemoryStream();
            StreamWriter writer = new StreamWriter(stream);
            writer.Write(json);
            writer.Flush();
            stream.Position = 0;
            DataContractJsonSerializer serializer
                = new DataContractJsonSerializer(typeof(Watchman));
            Watchman result = (Watchman)serializer.ReadObject(stream);
            return result;
        }
        public static Bird[] DeserializeXmlArray()
        {
            Bird[] result;
            using (Stream stream = new FileStream("birds.xml", FileMode.Open))
            {
                DataContractSerializer ser = new DataContractSerializer(typeof(Bird[]));
                result = (Bird[])ser.ReadObject(stream);
            }
            return result;
        }

    }
}
namespace Lab4_Part2
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            File file = new File(new SimpleSaving());

            file.SetAndSaveData("wfwe efwwgw gregwed fwef");
            file.ShowData();

            file.Strategy = new WithoutSpacesSaving();
            file.SetAndSaveData("ggw feww qfsdfewe fewew few -efw -");
            file.ShowData();

            file.Strategy = new CodingSaving();
            file.SetAndSaveData("wefwqq fegwe wegwgfas gfewfa weg");
            file.ShowData();
        }
    }
}
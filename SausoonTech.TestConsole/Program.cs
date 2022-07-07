namespace SausoonTech.TestConsole
{
    using System;
    using Logger;

    internal class Program
    {
        private static void Main(string[] args)
        {
            Logger.Debug("Debug");
            Logger.Info("Info");
            Logger.Warning("Warning");
            Logger.Error("Error", new Exception("Error happens"));

            Console.ReadLine();
        }
    }
}
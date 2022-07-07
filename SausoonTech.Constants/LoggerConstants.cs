namespace SausoonTech.Constants
{
    public static class LoggerConstants
    {
        public const string PATTERN_LAYOUT = "%-5level | %date{yyyy-MM-dd HH:mm:ss} | %message %newline%exception";
        public const string FILE_PATH = "log.txt";
        public const string MAXIMUM_FILE_SIZE = "100MB";
        public const int MAX_SIZE_ROLL_BACKUPS = 5;
    }
}

namespace SausoonTech.Logger
{
    using log4net;

    using System;
    using System.Collections.Concurrent;
    using System.Threading;
    using System.Threading.Tasks;
    using Constants;
    using log4net.Appender;
    using log4net.Config;
    using log4net.Core;
    using log4net.Filter;
    using log4net.Layout;
    using log4net.Repository;

    public static class Logger
    {
        private static readonly ConcurrentQueue<LogRow> logs;

        private static ILog logger;

        static Logger()
        {
            Logger.InitializeLogger();
            Logger.logs = new ConcurrentQueue<LogRow>();
            _ = Task.Run(new Action(Logger.WriteLogs));
        }

        public static void Debug(string message)
        {
            Logger.logs.Enqueue(new LogRow(Level.Debug, message, null));
        }

        public static void Info(string message)
        {
            Logger.logs.Enqueue(new LogRow(Level.Info, message, null));
        }

        public static void Warning(string message)
        {
            Logger.logs.Enqueue(new LogRow(Level.Warn, message, null));
        }

        public static void Error(string message, Exception ex)
        {
            Logger.logs.Enqueue(new LogRow(Level.Error, message, ex));
        }

        private static void WriteLogs()
        {
            while (true)
            {
                if (Logger.logs.TryDequeue(out LogRow logRow))
                {
                    if (logRow.Level == Level.Debug)
                    {
                        Logger.logger.Info(logRow.Message);
                    }
                    else if (logRow.Level == Level.Info)
                    {
                        Logger.logger.Info(logRow.Message);
                    }
                    else if (logRow.Level == Level.Warn)
                    {
                        Logger.logger.Warn(logRow.Message);
                    }
                    else if (logRow.Level == Level.Error)
                    {
                        Logger.logger.Error(logRow.Message, logRow.Exception);
                    }
                }
                else
                {
                    Thread.Sleep(1000);
                }
            }
        }

        private static void InitializeLogger()
        {
            PatternLayout layout = new PatternLayout(LoggerConstants.PATTERN_LAYOUT);

            LevelMatchFilter filter = new LevelMatchFilter();
            filter.LevelToMatch = Level.Debug;
            filter.ActivateOptions();

            RollingFileAppender appender = new RollingFileAppender();
            appender.File = LoggerConstants.FILE_PATH;
            appender.ImmediateFlush = true;
            appender.AppendToFile = true;
            appender.RollingStyle = RollingFileAppender.RollingMode.Size;
            appender.MaximumFileSize = LoggerConstants.MAXIMUM_FILE_SIZE;
            appender.MaxSizeRollBackups = LoggerConstants.MAX_SIZE_ROLL_BACKUPS;
            appender.LockingModel = new FileAppender.MinimalLock();
            appender.Name = "Appender";
            appender.AddFilter(filter);
            appender.Layout = layout;
            appender.ActivateOptions();
            
            ILoggerRepository repository = LoggerManager.CreateRepository("Repository");
            BasicConfigurator.Configure(repository, appender);
            Logger.logger = LogManager.GetLogger("Repository", "Logger");
        }
    }
}
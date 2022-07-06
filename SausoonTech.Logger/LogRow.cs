namespace SausoonTech.Logger
{
    using System;

    using log4net;
    using log4net.Core;

    internal class LogRow
    {
        internal Level Level { get; }
        internal string Message { get; }
        internal Exception Exception { get; }

        internal LogRow(Level level, string message, Exception exception)
        {
            this.Level = level;
            this.Message = message;
            this.Exception = exception;
        }
    }
}
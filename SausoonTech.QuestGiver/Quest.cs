namespace SausoonTech.QuestGiver.Core
{
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;
    using System.Threading.Tasks;

    public class Quest
    {
        public Guid Id { get; set; }
        public Guid Giver { get; set; }
        public Guid Taker { get; set; }
        public string Title { get; set; }
        public string Description { get; set; }
    }
}

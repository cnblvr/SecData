using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace laba4Server
{
    public partial class Form1 : Form
    {
		Messenger m;
        public Form1()
        {
            InitializeComponent();
			m = new Messenger(rtbMain, 45664);
        }
		private void rtbMain_KeyPress(object sender, KeyPressEventArgs e)
		{
			if(e.KeyChar == (char)Keys.Escape)
			{
				Environment.Exit(0);
			}
		}
	}
}

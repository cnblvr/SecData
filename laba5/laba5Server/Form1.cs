using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace laba5Server
{
    public partial class Form1 : Form
    {
		Messenger m;

        public Form1()
        {
            InitializeComponent();
			m = new Messenger(rtbMain, "10.53.24.94", 45664);
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

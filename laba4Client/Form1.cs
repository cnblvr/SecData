using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace laba4Client
{
    public partial class Form1 : Form
    {
		private Cipher cipher;
        public Form1()
        {
            InitializeComponent();
			cipher = new DESCipher(Convert.FromBase64String("YCjdx4YFSJ8="), Convert.FromBase64String("qQYwcSmXwjY="));
        }
        private void send()
        {
			Messenger.Send(cipher.Encrypt(Encoding.Unicode.GetBytes(tbMessage.Text)), 1, "192.168.31.167", 45664);
            tbMessage.Focus();
        }
        private void bSend_Click(object sender, EventArgs e)
        {
            send();
        }
        private void Global_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)Keys.Enter)
                send();
            if (e.KeyChar == (char)Keys.Escape)
            {
                Environment.Exit(0); return;
            }
        }
    }
}

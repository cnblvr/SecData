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

namespace laba5Client
{
    public partial class Form1 : Form
    {
		string ip = "10.53.24.108";
		private byte method = 1; // 1-DES 2-TripleDES 3-Aes 4-RC2
		private Messenger m;
        public Form1()
        {
            InitializeComponent();
			m = new Messenger(method, ip, 45664);
			Messenger.Send(new byte[] {133}, ip, 45664);
		}
        private void send()
        {
			m.SendMessage(tbMessage.Text);
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

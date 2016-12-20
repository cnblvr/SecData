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

namespace laba4Client
{
    public partial class Form1 : Form
    {
		private Cipher cipher;
        public Form1()
        {
            InitializeComponent();
			numericUpDown1.Value = 1;
		}
        private void send()
        {
			if(numericUpDown1.Value==1)
				cipher=new DESCipher(Convert.FromBase64String("YCjdx4YFSJ8="),
						Convert.FromBase64String("qQYwcSmXwjY="));
			else if(numericUpDown1.Value==2)
				cipher=new TripleDESCipher(Convert.FromBase64String("geuSSrBfkjxZbkVm+jFcCGQ+DcW6LwX/"),
						Convert.FromBase64String("jh1zV1OfzoM="));
			else if(numericUpDown1.Value==3)
				cipher=new AesCipher(Convert.FromBase64String("ehp4PuJycxdegB3o4sFAUTDkv+u6Ryipktu0aO/N9mQ="),
						Convert.FromBase64String("XHHAHaiFTgUM5Lx7rFORDg=="));
			else if(numericUpDown1.Value==4)
				cipher=new RC2Cipher(Convert.FromBase64String("SN+Iykxsu6Ya88lpC+2MSA=="),
						Convert.FromBase64String("18madZ7cT7U="));
			byte[] bytes = null;
			if(numericUpDown1.Value != 0)
				bytes = cipher.Encrypt(Encoding.Unicode.GetBytes(tbMessage.Text));
			else
				bytes = Encoding.Unicode.GetBytes(tbMessage.Text);
			Messenger.Send(bytes, Convert.ToByte(numericUpDown1.Value), "127.0.0.1", 45664);
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

		private void numericUpDown1_ValueChanged(object sender, EventArgs e)
		{
			if(numericUpDown1.Value==0)
				label1.Text = "None";
			else if(numericUpDown1.Value==1)
				label1.Text = "DES";
			else if(numericUpDown1.Value==2)
				label1.Text = "TripleDES";
			else if(numericUpDown1.Value==3)
				label1.Text = "Aes";
			else if(numericUpDown1.Value==4)
				label1.Text = "RC2";
		}
	}
}

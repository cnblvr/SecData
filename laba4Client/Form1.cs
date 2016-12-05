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
        byte[] DESKey;
        byte[] DESIV;
        public Form1()
        {
            InitializeComponent();
            Dictionary<string, string> settings;
            try
            {
                settings = Settings.ReadFile("settings.set");
            }
            catch(Exception e) { MessageBox.Show(e.Message); Environment.Exit(1); return; }
            DESKey = Convert.FromBase64String(settings["des_key"]);
            DESIV = Convert.FromBase64String(settings["des_iv"]);
            if (DESKey.Length != 8 || DESIV.Length != 8)
            {
                MessageBox.Show("Секретный ключ или вектор инициализации должны быть длиной 8.");
                Environment.Exit(1); return;
            }
        }
        private void send()
        {
            MessageBox.Show(tbMessage.Text);
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

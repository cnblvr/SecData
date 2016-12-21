using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace laba7
{
	public partial class Login : Form
	{
		private byte tries = 0;
		public Login()
		{
			InitializeComponent();
		}

		private void Global_KeyDown(object sender, KeyEventArgs e)
		{
			if(e.KeyCode == Keys.Escape)
				Application.Exit();
			else if(e.KeyCode == Keys.Enter)
				LoginL();
		}
		private string GetMD5Hash(string username)
		{
			string json = File.ReadAllText("db.json");
			List<Account> accounts = JsonConvert.DeserializeObject<List<Account>>(json);
			if(accounts == null)
				return null;
			foreach(Account acc in accounts)
				if(string.Compare(acc.username, username) == 0)
					return acc.password;
			return null;
		}
		private void antidos()
		{
			if(tries >= 3)
			{
				MessageBox.Show("Превышен лимит входов. Программа будет закрыта.", "", MessageBoxButtons.OK, MessageBoxIcon.None);
				Application.Exit();
			}
		}
		private void LoginL()
		{
			string pass = GetMD5Hash(tbUsername.Text);
			if(pass != null)
			{
				if(string.Compare(pass, CalculateMD5(tbPassword.Text)) == 0)
				{
					MessageBox.Show("Вход успешен.", "", MessageBoxButtons.OK, MessageBoxIcon.None);
					tries = 0;
					return;
				}
				else
				{
					MessageBox.Show("Пароль неверен.", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
					tries++;
					antidos();
					return;
				}
			}
			else
			{
				MessageBox.Show("Такого пользователя не существует.", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
				tries++;
				antidos();
				return;
			}
		}
		private string CalculateMD5(string str)
		{
			MD5 md5 = MD5.Create();
			byte[] hash = md5.ComputeHash(Encoding.Unicode.GetBytes(str));
			StringBuilder sb = new StringBuilder();
			for(int i=0; i<hash.Length; i++)
				sb.Append(hash[i].ToString("x2"));
			return sb.ToString();
		}
		private void bEnter_Click(object sender, EventArgs e)
		{
			LoginL();
		}
		private void llRegistration_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
		{
			Form reg = new Registration();
			reg.ShowDialog();
		}

		private void llRegistration_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
		{
			if(e.KeyCode != Keys.Enter)
				Global_KeyDown(sender, new KeyEventArgs(e.KeyCode));
		}
	}
}

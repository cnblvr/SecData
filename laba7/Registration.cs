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
	public partial class Registration : Form
	{
		public Registration()
		{
			InitializeComponent();
		}

		private void Global_KeyDown(object sender, KeyEventArgs e)
		{
			if(e.KeyCode == Keys.Escape)
				this.Close();
			else if(e.KeyCode == Keys.Enter)
				Register();
		}
		private bool IsAvailableUsername(string username)
		{
			string json = File.ReadAllText("db.json");
			List<Account> accounts = JsonConvert.DeserializeObject<List<Account>>(json);
			if(accounts == null)
				return true;
			foreach(Account acc in accounts)
				if(string.Compare(acc.username, username) == 0)
					return false;
			return true;
		}
		private bool AddAccount(string username, string password)
		{
			string json = File.ReadAllText("db.json");
			List<Account> accounts = JsonConvert.DeserializeObject<List<Account>>(json);
			if(accounts == null)
				accounts = new List<Account>();
			accounts.Add(new Account(username, CalculateMD5(password)));
			File.WriteAllText("db.json", JsonConvert.SerializeObject(accounts));
			return true;
		}
		private void Register()
		{
			if(tbUsername.Text.Length < 3 || tbUsername.Text.Length > 16)
			{
				MessageBox.Show("Выберите имя для вашего аккаунта. Выбирайте мудро, так как позже вы уже не сможете его изменить.", "", MessageBoxButtons.OK, MessageBoxIcon.Stop);
				return;
			}
			if(IsAvailableUsername(tbUsername.Text))
				if(AddAccount(tbUsername.Text, tbPassword.Text))
					MessageBox.Show("Пользователь "+tbUsername.Text+" успешно зарегистрирован.", "", MessageBoxButtons.OK, MessageBoxIcon.Information);
				else
				{
					MessageBox.Show("Пользователь "+tbUsername.Text+" не может быть зарегистрирован.", "", MessageBoxButtons.OK, MessageBoxIcon.Error);
					return;
				}
			else
			{
				MessageBox.Show("Имя пользователя "+tbUsername.Text+" уже занято. Попробуй другое.", "", MessageBoxButtons.OK, MessageBoxIcon.Stop);
				return;
			}
		}
		private void bRegister_Click(object sender, EventArgs e)
		{
			Register();
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
		private void cbShowPassword_CheckedChanged(object sender, EventArgs e)
		{
			if(cbShowPassword.CheckState == CheckState.Checked)
				tbPassword.PasswordChar = '\0';
			else
				tbPassword.PasswordChar = '●';
		}
	}
}

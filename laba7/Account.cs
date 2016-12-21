using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba7
{
	public class Account
	{
		public Account(string username, string password)
		{
			this.username = username;
			this.password = password;
		}
		public string username {get; set;}
		public string password {get; set;}
		public override string ToString()
		{
			return username+":"+password;
		}
	}
}

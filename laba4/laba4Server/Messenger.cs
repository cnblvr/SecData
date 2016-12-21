using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace laba4Server
{
	class Messenger
	{
		private BackgroundWorker bw_Receiver;
		private Socket sockIn;
		private IPEndPoint iepIn;
		private EndPoint epIn;
		private int port;
		private RichTextBox rtb;
		public Messenger(RichTextBox _rtb, int _port)
		{
			port = _port;
			rtb = _rtb;
			bw_Receiver = new BackgroundWorker();
			bw_Receiver.WorkerSupportsCancellation = true;
			bw_Receiver.DoWork += this.bw_Receiver_DoWork;
			bw_Receiver.RunWorkerCompleted += this.bw_Receiver_RunWorkerCompleted;

			sockIn = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
			iepIn = new IPEndPoint(IPAddress.Any, port);
			sockIn.Bind(iepIn);
			epIn = (EndPoint)iepIn;
			sockIn.ReceiveTimeout = 9000;
			bw_Receiver.RunWorkerAsync();
		}
		~Messenger()
		{
			bw_Receiver.CancelAsync();
			sockIn.Close();
		}
		private void bw_Receiver_DoWork(object sender, DoWorkEventArgs e)
		{
			byte[] message_bytes = new byte[256];
			int recv;
			try { recv = sockIn.ReceiveFrom(message_bytes, ref epIn); }
			catch(Exception) { recv = 0; }
			if(recv == 0)
				return;
			byte[] new_bytes = new byte[recv];
			Array.Copy(message_bytes, new_bytes, recv);
			e.Result = new_bytes;
		}
		private void bw_Receiver_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
		{
			bw_Receiver.RunWorkerAsync();
			byte[] bytes = (byte[])e.Result;
			if(bytes != null)
			{
				string message = null;
				Cipher cipher = null;
				if(bytes[0] == 1)
					cipher = new DESCipher(Convert.FromBase64String("YCjdx4YFSJ8="), Convert.FromBase64String("qQYwcSmXwjY="));
				else if(bytes[0] == 2)
					cipher=new TripleDESCipher(Convert.FromBase64String("geuSSrBfkjxZbkVm+jFcCGQ+DcW6LwX/"),
							Convert.FromBase64String("jh1zV1OfzoM="));
				else if(bytes[0] == 3)
					cipher=new AesCipher(Convert.FromBase64String("ehp4PuJycxdegB3o4sFAUTDkv+u6Ryipktu0aO/N9mQ="),
							Convert.FromBase64String("XHHAHaiFTgUM5Lx7rFORDg=="));
				else if(bytes[0] == 4)
					cipher=new RC2Cipher(Convert.FromBase64String("SN+Iykxsu6Ya88lpC+2MSA=="),
							Convert.FromBase64String("18madZ7cT7U="));
				if(bytes[0] == 0) // сделай rsa тут
					message = Encoding.Unicode.GetString(bytes, 1, bytes.Length-1);
				else
				{
					byte[] message_bytes = new byte[bytes.Length-1];
					Array.Copy(bytes, 1, message_bytes, 0, bytes.Length-1);
					message_bytes = cipher.Decrypt(message_bytes);
					message = Encoding.Unicode.GetString(message_bytes, 0, bytes.Length-1);
				}
				if(message == null)
					return;
				rtb.SelectionColor = Color.Gray;
				rtb.AppendText("["+DateTime.Now.ToString("dd.MM.yyyy HH:mm")+"] ");
				if(bytes[0] == 0)
				{
					rtb.SelectionColor = Color.DarkGreen;
					rtb.AppendText("[none] ");
				}
				else if(bytes[0] == 1)
				{
					rtb.SelectionColor = Color.DarkGoldenrod;
					rtb.AppendText("[des] ");
				}
				else if(bytes[0] == 2)
				{
					rtb.SelectionColor = Color.DarkMagenta;
					rtb.AppendText("[tripledes] ");
				}
				else if(bytes[0] == 3)
				{
					rtb.SelectionColor = Color.DarkSalmon;
					rtb.AppendText("[aes] ");
				}
				else if(bytes[0] == 4)
				{
					rtb.SelectionColor = Color.DarkTurquoise;
					rtb.AppendText("[rc2] ");
				}
				rtb.SelectionColor = rtb.ForeColor;
				rtb.AppendText(message);
				rtb.AppendText(Environment.NewLine);
			}
		}
		static public void Send(string message, string ip, int port)
		{
			Socket sockOut = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
			IPEndPoint iepOut = new IPEndPoint(IPAddress.Parse(ip), port);
			byte[] message_bytes = Encoding.ASCII.GetBytes(message);
			try { sockOut.SendTo(message_bytes, iepOut); }
			catch(SocketException e) { MessageBox.Show("Невозможно установить связь с сервером."); }
			catch(Exception e) { sockOut.Close(); return; }
			sockOut.Close();
		}
	}
}

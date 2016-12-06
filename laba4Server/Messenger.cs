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
				if(bytes[0] == 0) // сделай rsa тут
					message = Encoding.Unicode.GetString(bytes, 1, bytes.Length);
				else if(bytes[0] == 1)
				{
					Cipher cipher = new DESCipher(Convert.FromBase64String("YCjdx4YFSJ8="), Convert.FromBase64String("qQYwcSmXwjY="));
					byte[] message_bytes = new byte[bytes.Length-1];
					Array.Copy(bytes, 1, message_bytes, 0, bytes.Length-1);
					message_bytes = cipher.Decrypt(message_bytes);
					message = Encoding.Unicode.GetString(message_bytes, 0, bytes.Length-1);
				}
				if(message == null)
					return;
				rtb.SelectionColor = Color.Gray;
				rtb.AppendText("["+DateTime.Now.ToString("dd.MM.yyyy HH:mm")+"] ");
				rtb.SelectionColor = Color.DarkGreen;
				if(bytes[0] == 0)
					rtb.AppendText("[none] ");
				else if(bytes[0] == 1)
					rtb.AppendText("[des] ");
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

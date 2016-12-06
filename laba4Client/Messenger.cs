using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace laba4Client
{
	class Messenger
	{
		static public void Send(byte[] message, byte cipherAlg, string ip, int port)
		{
			Socket sockOut = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
			IPEndPoint iepOut = new IPEndPoint(IPAddress.Parse(ip), port);
			byte[] bytes = new byte[message.Length + 1];
			bytes[0] = cipherAlg;
			message.CopyTo(bytes, 1);
			try { sockOut.SendTo(bytes, iepOut); }
			catch(SocketException e) { MessageBox.Show("Невозможно установить связь с сервером."); }
			catch(Exception e) { sockOut.Close(); return; }
			sockOut.Close();
		}
	}
}

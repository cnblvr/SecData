using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace laba5Client
{
	class Messenger
	{
		private BackgroundWorker bw_Receiver;
		private Socket sockIn;
		private IPEndPoint iepIn;
		private EndPoint epIn;
		private int port;
		private byte method;
		private Cipher cipher;
        private string keyPublicRSA;
        private bool connected = false;
		private string serverIP = "";
		public Messenger(byte _method, string ip, int _port)
		{
			serverIP = ip;
			port = _port;
			method = _method;

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
			byte[] message_bytes = new byte[999];
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
				if(bytes[0] == 82)
				{
                    MessageBox.Show("Пришёл RSA паблик ключ");
					byte[] mesPublicKey = new byte[bytes.Length-1];
					Array.Copy(bytes, 1, mesPublicKey, 0, bytes.Length-1);
                    keyPublicRSA = Encoding.Unicode.GetString(mesPublicKey, 0, mesPublicKey.Length);
                    RSACryptoServiceProvider rsa = new RSACryptoServiceProvider();
					rsa.FromXmlString(keyPublicRSA);
					if(method == 1)
						cipher = new DESCipher();
					else if(method == 2)
						cipher = new TripleDESCipher();
					else if(method == 3)
						cipher = new AesCipher();
					else if(method == 4)
						cipher = new RC2Cipher();

                    byte[] encSessionKey = rsa.Encrypt(cipher.GetKey(), false);
					byte[] mesEncSessionKey = new byte[encSessionKey.Length+2];
					mesEncSessionKey[0] = 208; // 208 - пересылка сессионного ключа серверу
					mesEncSessionKey[1] = method;
					encSessionKey.CopyTo(mesEncSessionKey, 2);
					Send(mesEncSessionKey, serverIP, port);
				}
                else if(bytes[0] == 59)
                {
                    MessageBox.Show("Клиент принял ключ");
                    RSACryptoServiceProvider rsa = new RSACryptoServiceProvider();
                    rsa.FromXmlString(keyPublicRSA);
                    byte[] encSessionIV = rsa.Encrypt(cipher.GetIV(), false);
                    byte[] mesEncSessionIV = new byte[encSessionIV.Length + 2];
                    mesEncSessionIV[0] = 209; // 209 - пересылка начального вектора серверу
                    mesEncSessionIV[1] = method;
                    encSessionIV.CopyTo(mesEncSessionIV, 2);
                    Send(mesEncSessionIV, serverIP, port);
                }
				else if(bytes[0] == 48)
				{
					connected = true;
					MessageBox.Show("Подключен к серверу");
					// соединение установлено
				}
			}
		}
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
		public void SendMessage(string message)
		{
			if(connected == true)
			{
				byte[] messageBytes = cipher.Encrypt(Encoding.Unicode.GetBytes(message));
				byte[] bytes = new byte[messageBytes.Length+1];
				bytes[0] = 77;
				messageBytes.CopyTo(bytes, 1);
				Send(bytes, serverIP, port);
			}
		}
		static public void Send(byte[] bytes, string ip, int port)
		{
			Socket sockOut = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
			IPEndPoint iepOut = new IPEndPoint(IPAddress.Parse(ip), port);
			try { sockOut.SendTo(bytes, iepOut); }
			catch(SocketException e) { MessageBox.Show("Невозможно установить связь с сервером."); }
			catch(Exception e) { sockOut.Close(); return; }
			sockOut.Close();
		}
	}
}

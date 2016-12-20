using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace laba5Server
{
	class Messenger
	{
		private BackgroundWorker bw_Receiver;
		private Socket sockIn;
		private IPEndPoint iepIn;
		private EndPoint epIn;
		private int port;
		private RichTextBox rtb;
		private RSACryptoServiceProvider rsa;
		private byte method;
		private Cipher cipher = null;
		private byte[] key = null;
		private byte[] iv = null;
		private byte[] publicKey;
		private string ip;
		public Messenger(RichTextBox _rtb, string ip, int _port)
		{
			this.ip = ip;
			rsa = new RSACryptoServiceProvider();
			publicKey = Encoding.Unicode.GetBytes(rsa.ToXmlString(false));

			port = _port;
			rtb = _rtb;
            bw_Receiver = new BackgroundWorker();
            bw_Receiver.WorkerSupportsCancellation = true;
            bw_Receiver.DoWork += this.bw_Receiver_DoWork;
            bw_Receiver.RunWorkerCompleted += this.bw_Receiver_RunWorkerCompleted;

            sockIn =new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
			iepIn=new IPEndPoint(IPAddress.Any, port);
			sockIn.Bind(iepIn);
			epIn=(EndPoint)iepIn;
			sockIn.ReceiveTimeout=9000;
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
				if(bytes[0] == 133 && bytes.Length == 1)
				{ // 133 - клиент просит паблик ключ rsa
                    MessageBox.Show("клиент просит паблик ключ rsa");
					byte[] mesPublicKey = new byte[publicKey.Length+1];
					mesPublicKey[0] = 82; // 82 - значит пересылается паблик ключ rsa клиенту
					publicKey.CopyTo(mesPublicKey, 1);
					Send(mesPublicKey, ip, port);
					return;
				}
				else if(bytes[0] == 208)
                {
                    MessageBox.Show("клиент прислал ключ");
                    method = bytes[1];
					byte[] encSessionKey = new byte[bytes.Length-2];
					Array.Copy(bytes, 2, encSessionKey, 0, encSessionKey.Length);
					key = rsa.Decrypt(encSessionKey, false);
                    Send(new byte[] { 59}, ip, port);
				}
				else if(bytes[0] == 209)
                {
                    MessageBox.Show("клиент прислал вектор");
                    byte[] encSessionIV = new byte[bytes.Length-2];
					Array.Copy(bytes, 2, encSessionIV, 0, encSessionIV.Length);
					iv = rsa.Decrypt(encSessionIV, false);
                    Send(new byte[] { 48 }, ip, port);
                    if (method == 1)
                        cipher = new DESCipher(key, iv);
                    else if (method == 2)
                        cipher = new TripleDESCipher(key, iv);
                    else if (method == 3)
                        cipher = new AesCipher(key, iv);
                    else if (method == 4)
                        cipher = new RC2Cipher(key, iv);
                }
				else if(bytes[0] == 77)
                {
                    byte[] messageBytes = new byte[bytes.Length-1];
					Array.Copy(bytes, 1, messageBytes, 0, messageBytes.Length);
					messageBytes = cipher.Decrypt(messageBytes);
					string message = Encoding.Unicode.GetString(messageBytes, 0, bytes.Length-1);

					if(message == null)
						return;
					rtb.SelectionColor = Color.DarkGray;
					rtb.AppendText("["+DateTime.Now.ToString("dd.MM.yyyy HH:mm")+"] ");
					if(bytes[0] == 0)
						rtb.AppendText("[none] ");
					else if(bytes[0] == 1)
						rtb.AppendText("[des] ");
					else if(bytes[0] == 2)
						rtb.AppendText("[tripledes] ");
					else if(bytes[0] == 3)
						rtb.AppendText("[aes] ");
					else if(bytes[0] == 4)
						rtb.AppendText("[rc2] ");
					rtb.SelectionColor = rtb.ForeColor;
					rtb.AppendText(message);
					rtb.AppendText(Environment.NewLine);
				}
			}
		}
		static public void Send(byte[] message_bytes, string ip, int port)
		{
			Socket sockOut = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
			IPEndPoint iepOut = new IPEndPoint(IPAddress.Parse(ip), port);
			try { sockOut.SendTo(message_bytes, iepOut); }
			catch(SocketException e) { MessageBox.Show("Невозможно установить связь с клиентом."); }
			catch(Exception e) { sockOut.Close(); return; }
			sockOut.Close();
		}
	}
}

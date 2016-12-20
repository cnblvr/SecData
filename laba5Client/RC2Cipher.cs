using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace laba5Client
{
	class RC2Cipher : Cipher
	{
		private RC2 des;
        public RC2Cipher()
        {
            des = new RC2CryptoServiceProvider();
            des.Mode = CipherMode.CBC;
            des.Padding = PaddingMode.Zeros;
			Generate();
        }
		public override byte[] GetKey()
		{
			return des.Key;
		}
		public override byte[] GetIV()
		{
			return des.IV;
		}
        public override void Generate()
        {
            des.GenerateKey();
            des.GenerateIV();
        }
        public override byte[] Encrypt(byte[] data)
        {
            MemoryStream fin = new MemoryStream(data, false);
            MemoryStream fout = new MemoryStream();
            CryptoStream encStream = new CryptoStream(fout, des.CreateEncryptor(des.Key, des.IV), CryptoStreamMode.Write);
            encStream.Write(data, 0, (int)fin.Length);
            encStream.FlushFinalBlock();
            return fout.ToArray();
        }
        public override byte[] Decrypt(byte[] data)
        {
            MemoryStream fin = new MemoryStream(data, false);
            MemoryStream fout = new MemoryStream();
            CryptoStream encStream = new CryptoStream(fout, des.CreateDecryptor(des.Key, des.IV), CryptoStreamMode.Write);
            encStream.Write(data, 0, (int)fin.Length);
            encStream.FlushFinalBlock();
            return fout.ToArray();
        }
	}
}

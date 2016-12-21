using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace laba4Server
{
	class TripleDESCipher : Cipher
	{
		private TripleDES des;
        public TripleDESCipher(byte[] key, byte[] iv)
        {
            des = new TripleDESCryptoServiceProvider();
            des.Mode = CipherMode.CBC;
            des.Padding = PaddingMode.Zeros;
            des.Key = key;
            des.IV = iv;
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

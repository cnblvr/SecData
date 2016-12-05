using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace laba4Client
{
    class DESCipher
    {
        private DES des;
        DESCipher(byte[] key, byte[] iv)
        {
            des = new DESCryptoServiceProvider();
            des.Mode = CipherMode.CBC;
            des.Padding = PaddingMode.Zeros;
            if (key == null)
                des.GenerateKey();
            else
                des.Key = key;
            if (iv == null)
                des.GenerateIV();
            else
                des.IV = iv;
        }
        void Generate()
        {
            des.GenerateKey();
            des.GenerateIV();
        }
        byte[] Encrypt(byte[] data)
        {
            MemoryStream fin = new MemoryStream(data, false);
            MemoryStream fout = new MemoryStream();
            CryptoStream encStream = new CryptoStream(fout, des.CreateEncryptor(des.Key, des.IV), CryptoStreamMode.Write);
            encStream.Write(data, 0, (int)fin.Length);
            encStream.FlushFinalBlock();
            return fout.ToArray();
        }
        byte[] Decrypt(byte[] data)
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

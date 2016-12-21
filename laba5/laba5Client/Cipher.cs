using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace laba5Client

{
	abstract class Cipher
	{
		abstract public byte[] GetKey();
		abstract public byte[] GetIV();
		abstract public void Generate();
		abstract public byte[] Encrypt(byte[] data);
		abstract public byte[] Decrypt(byte[] data);
	}
}

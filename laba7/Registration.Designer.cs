namespace laba7
{
	partial class Registration
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if(disposing&&(components!=null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.bRegister = new System.Windows.Forms.Button();
			this.tbPassword = new System.Windows.Forms.TextBox();
			this.label2 = new System.Windows.Forms.Label();
			this.tbUsername = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.cbShowPassword = new System.Windows.Forms.CheckBox();
			this.SuspendLayout();
			// 
			// bRegister
			// 
			this.bRegister.Location = new System.Drawing.Point(123, 84);
			this.bRegister.Name = "bRegister";
			this.bRegister.Size = new System.Drawing.Size(146, 23);
			this.bRegister.TabIndex = 2;
			this.bRegister.Text = "Зарегистрироваться";
			this.bRegister.UseVisualStyleBackColor = true;
			this.bRegister.Click += new System.EventHandler(this.bRegister_Click);
			this.bRegister.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Global_KeyDown);
			// 
			// tbPassword
			// 
			this.tbPassword.Location = new System.Drawing.Point(123, 38);
			this.tbPassword.Name = "tbPassword";
			this.tbPassword.PasswordChar = '●';
			this.tbPassword.Size = new System.Drawing.Size(146, 20);
			this.tbPassword.TabIndex = 1;
			this.tbPassword.Text = "password";
			this.tbPassword.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Global_KeyDown);
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(8, 38);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(109, 20);
			this.label2.TabIndex = 104;
			this.label2.Text = "Пароль";
			this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
			// 
			// tbUsername
			// 
			this.tbUsername.Location = new System.Drawing.Point(123, 12);
			this.tbUsername.Name = "tbUsername";
			this.tbUsername.Size = new System.Drawing.Size(146, 20);
			this.tbUsername.TabIndex = 0;
			this.tbUsername.Text = "username";
			this.tbUsername.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Global_KeyDown);
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(8, 12);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(109, 20);
			this.label1.TabIndex = 105;
			this.label1.Text = "Имя пользователя";
			this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
			// 
			// cbShowPassword
			// 
			this.cbShowPassword.Location = new System.Drawing.Point(123, 61);
			this.cbShowPassword.Name = "cbShowPassword";
			this.cbShowPassword.Size = new System.Drawing.Size(146, 20);
			this.cbShowPassword.TabIndex = 3;
			this.cbShowPassword.Text = "Показать пароль";
			this.cbShowPassword.UseVisualStyleBackColor = true;
			this.cbShowPassword.CheckedChanged += new System.EventHandler(this.cbShowPassword_CheckedChanged);
			this.cbShowPassword.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Global_KeyDown);
			// 
			// Registration
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(283, 116);
			this.Controls.Add(this.cbShowPassword);
			this.Controls.Add(this.bRegister);
			this.Controls.Add(this.tbPassword);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.tbUsername);
			this.Controls.Add(this.label1);
			this.Name = "Registration";
			this.Text = "Регистрация";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Button bRegister;
		private System.Windows.Forms.TextBox tbPassword;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.TextBox tbUsername;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.CheckBox cbShowPassword;
	}
}
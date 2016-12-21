namespace laba7
{
	partial class Login
	{
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		/// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
		protected override void Dispose(bool disposing)
		{
			if(disposing&&(components!=null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Код, автоматически созданный конструктором форм Windows

		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		private void InitializeComponent()
		{
			this.label1 = new System.Windows.Forms.Label();
			this.tbUsername = new System.Windows.Forms.TextBox();
			this.tbPassword = new System.Windows.Forms.TextBox();
			this.label2 = new System.Windows.Forms.Label();
			this.llRegistration = new System.Windows.Forms.LinkLabel();
			this.bEnter = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(12, 12);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(109, 20);
			this.label1.TabIndex = 99;
			this.label1.Text = "Имя пользователя";
			this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
			// 
			// tbUsername
			// 
			this.tbUsername.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.tbUsername.Location = new System.Drawing.Point(127, 12);
			this.tbUsername.Name = "tbUsername";
			this.tbUsername.Size = new System.Drawing.Size(146, 20);
			this.tbUsername.TabIndex = 0;
			this.tbUsername.Text = "username";
			this.tbUsername.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Global_KeyDown);
			// 
			// tbPassword
			// 
			this.tbPassword.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.tbPassword.Location = new System.Drawing.Point(127, 38);
			this.tbPassword.Name = "tbPassword";
			this.tbPassword.PasswordChar = '●';
			this.tbPassword.Size = new System.Drawing.Size(146, 20);
			this.tbPassword.TabIndex = 1;
			this.tbPassword.Text = "password";
			this.tbPassword.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Global_KeyDown);
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(12, 38);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(109, 20);
			this.label2.TabIndex = 99;
			this.label2.Text = "Пароль";
			this.label2.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
			// 
			// llRegistration
			// 
			this.llRegistration.Location = new System.Drawing.Point(127, 61);
			this.llRegistration.Name = "llRegistration";
			this.llRegistration.Size = new System.Drawing.Size(146, 20);
			this.llRegistration.TabIndex = 3;
			this.llRegistration.TabStop = true;
			this.llRegistration.Text = "Регистрация";
			this.llRegistration.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			this.llRegistration.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.llRegistration_LinkClicked);
			this.llRegistration.PreviewKeyDown += new System.Windows.Forms.PreviewKeyDownEventHandler(this.llRegistration_PreviewKeyDown);
			// 
			// bEnter
			// 
			this.bEnter.Location = new System.Drawing.Point(127, 84);
			this.bEnter.Name = "bEnter";
			this.bEnter.Size = new System.Drawing.Size(146, 23);
			this.bEnter.TabIndex = 2;
			this.bEnter.Text = "Войти";
			this.bEnter.UseVisualStyleBackColor = true;
			this.bEnter.Click += new System.EventHandler(this.bEnter_Click);
			this.bEnter.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Global_KeyDown);
			// 
			// Login
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(285, 117);
			this.Controls.Add(this.bEnter);
			this.Controls.Add(this.llRegistration);
			this.Controls.Add(this.tbPassword);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.tbUsername);
			this.Controls.Add(this.label1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.Name = "Login";
			this.Text = "Аутентификация";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TextBox tbUsername;
		private System.Windows.Forms.TextBox tbPassword;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.LinkLabel llRegistration;
		private System.Windows.Forms.Button bEnter;
	}
}


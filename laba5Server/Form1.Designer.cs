namespace laba5Server
{
    partial class Form1
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
            if (disposing && (components != null))
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
			this.rtbMain = new System.Windows.Forms.RichTextBox();
			this.SuspendLayout();
			// 
			// rtbMain
			// 
			this.rtbMain.BackColor = System.Drawing.Color.Gainsboro;
			this.rtbMain.DetectUrls = false;
			this.rtbMain.Dock = System.Windows.Forms.DockStyle.Fill;
			this.rtbMain.HideSelection = false;
			this.rtbMain.Location = new System.Drawing.Point(0, 0);
			this.rtbMain.Name = "rtbMain";
			this.rtbMain.ReadOnly = true;
			this.rtbMain.ScrollBars = System.Windows.Forms.RichTextBoxScrollBars.ForcedVertical;
			this.rtbMain.Size = new System.Drawing.Size(292, 273);
			this.rtbMain.TabIndex = 0;
			this.rtbMain.Text = "";
			this.rtbMain.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.rtbMain_KeyPress);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(292, 273);
			this.Controls.Add(this.rtbMain);
			this.Name = "Form1";
			this.Text = "Server";
			this.ResumeLayout(false);

        }

		#endregion

		private System.Windows.Forms.RichTextBox rtbMain;
	}
}


﻿namespace laba4Client
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
			this.tbMessage = new System.Windows.Forms.TextBox();
			this.bSend = new System.Windows.Forms.Button();
			this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
			this.label1 = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
			this.SuspendLayout();
			// 
			// tbMessage
			// 
			this.tbMessage.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.tbMessage.Location = new System.Drawing.Point(9, 60);
			this.tbMessage.Name = "tbMessage";
			this.tbMessage.Size = new System.Drawing.Size(283, 20);
			this.tbMessage.TabIndex = 0;
			this.tbMessage.Text = "qwerty123";
			this.tbMessage.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.Global_KeyPress);
			// 
			// bSend
			// 
			this.bSend.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.bSend.Location = new System.Drawing.Point(298, 58);
			this.bSend.Name = "bSend";
			this.bSend.Size = new System.Drawing.Size(120, 23);
			this.bSend.TabIndex = 1;
			this.bSend.Text = "Послать сообщение";
			this.bSend.UseVisualStyleBackColor = true;
			this.bSend.Click += new System.EventHandler(this.bSend_Click);
			this.bSend.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.Global_KeyPress);
			// 
			// numericUpDown1
			// 
			this.numericUpDown1.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.numericUpDown1.Location = new System.Drawing.Point(12, 10);
			this.numericUpDown1.Maximum = new decimal(new int[] {
            4,
            0,
            0,
            0});
			this.numericUpDown1.Name = "numericUpDown1";
			this.numericUpDown1.Size = new System.Drawing.Size(406, 44);
			this.numericUpDown1.TabIndex = 2;
			this.numericUpDown1.ValueChanged += new System.EventHandler(this.numericUpDown1_ValueChanged);
			this.numericUpDown1.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.Global_KeyPress);
			// 
			// label1
			// 
			this.label1.BackColor = System.Drawing.Color.White;
			this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
			this.label1.Location = new System.Drawing.Point(65, 12);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(334, 40);
			this.label1.TabIndex = 3;
			this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(430, 93);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.numericUpDown1);
			this.Controls.Add(this.bSend);
			this.Controls.Add(this.tbMessage);
			this.MaximumSize = new System.Drawing.Size(65000, 120);
			this.Name = "Form1";
			this.Text = "Client";
			this.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.Global_KeyPress);
			((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tbMessage;
        private System.Windows.Forms.Button bSend;
		private System.Windows.Forms.NumericUpDown numericUpDown1;
		private System.Windows.Forms.Label label1;
	}
}


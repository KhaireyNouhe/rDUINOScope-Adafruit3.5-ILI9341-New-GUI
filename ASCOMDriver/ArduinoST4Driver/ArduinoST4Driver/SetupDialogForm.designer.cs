namespace ASCOM.ArduinoST4
{
    partial class SetupDialogForm
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
            if (disposing && (components != null))
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
            this.cmdOK = new System.Windows.Forms.Button();
            this.cmdCancel = new System.Windows.Forms.Button();
            this.commentLabel = new System.Windows.Forms.Label();
            this.picASCOM = new System.Windows.Forms.PictureBox();
            this.comPortComboBox = new System.Windows.Forms.ComboBox();
            this.comPortLabel = new System.Windows.Forms.Label();
            this.traceStateCheckBox = new System.Windows.Forms.CheckBox();
            this.rightAscensionPlusSideralRateLabel = new System.Windows.Forms.Label();
            this.rightAscensionMinusSideralRateLabel = new System.Windows.Forms.Label();
            this.declinationPlusSideralRateLabel = new System.Windows.Forms.Label();
            this.declinationMinusSideralRateLabel = new System.Windows.Forms.Label();
            this.rightAscensionPlusSideralRateTextBox = new System.Windows.Forms.TextBox();
            this.rightAscensionMinusSideralRateTextBox = new System.Windows.Forms.TextBox();
            this.declinationPlusSideralRateTextBox = new System.Windows.Forms.TextBox();
            this.declinationMinusSideralRateTextBox = new System.Windows.Forms.TextBox();
            this.axisSideralRatesGroupBox = new System.Windows.Forms.GroupBox();
            this.axisSideralRatesPanel = new System.Windows.Forms.Panel();
            this.connectionGroupBox = new System.Windows.Forms.GroupBox();
            ((System.ComponentModel.ISupportInitialize)(this.picASCOM)).BeginInit();
            this.axisSideralRatesGroupBox.SuspendLayout();
            this.axisSideralRatesPanel.SuspendLayout();
            this.connectionGroupBox.SuspendLayout();
            this.SuspendLayout();
            // 
            // cmdOK
            // 
            this.cmdOK.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.cmdOK.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.cmdOK.Location = new System.Drawing.Point(281, 164);
            this.cmdOK.Name = "cmdOK";
            this.cmdOK.Size = new System.Drawing.Size(59, 24);
            this.cmdOK.TabIndex = 0;
            this.cmdOK.Text = "OK";
            this.cmdOK.UseVisualStyleBackColor = true;
            this.cmdOK.Click += new System.EventHandler(this.cmdOK_Click);
            // 
            // cmdCancel
            // 
            this.cmdCancel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.cmdCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.cmdCancel.Location = new System.Drawing.Point(281, 194);
            this.cmdCancel.Name = "cmdCancel";
            this.cmdCancel.Size = new System.Drawing.Size(59, 25);
            this.cmdCancel.TabIndex = 1;
            this.cmdCancel.Text = "Cancel";
            this.cmdCancel.UseVisualStyleBackColor = true;
            this.cmdCancel.Click += new System.EventHandler(this.cmdCancel_Click);
            // 
            // commentLabel
            // 
            this.commentLabel.Location = new System.Drawing.Point(12, 9);
            this.commentLabel.Name = "commentLabel";
            this.commentLabel.Size = new System.Drawing.Size(86, 17);
            this.commentLabel.TabIndex = 2;
            this.commentLabel.Text = "Driver setup";
            // 
            // picASCOM
            // 
            this.picASCOM.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.picASCOM.Cursor = System.Windows.Forms.Cursors.Hand;
            this.picASCOM.Image = global::ASCOM.ArduinoST4.Properties.Resources.ASCOM;
            this.picASCOM.Location = new System.Drawing.Point(292, 9);
            this.picASCOM.Name = "picASCOM";
            this.picASCOM.Size = new System.Drawing.Size(48, 56);
            this.picASCOM.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.picASCOM.TabIndex = 3;
            this.picASCOM.TabStop = false;
            this.picASCOM.Click += new System.EventHandler(this.BrowseToAscom);
            this.picASCOM.DoubleClick += new System.EventHandler(this.BrowseToAscom);
            // 
            // comPortTextBox
            // 
            this.comPortComboBox.Location = new System.Drawing.Point(109, 10);
            this.comPortComboBox.Name = "comPortComboBox";
            this.comPortComboBox.Size = new System.Drawing.Size(82, 20);
            this.comPortComboBox.TabIndex = 4;
            // 
            // comPortLabel
            // 
            this.comPortLabel.AutoSize = true;
            this.comPortLabel.Location = new System.Drawing.Point(12, 16);
            this.comPortLabel.Name = "comPortLabel";
            this.comPortLabel.Size = new System.Drawing.Size(50, 13);
            this.comPortLabel.TabIndex = 5;
            this.comPortLabel.Text = "Com Port";
            // 
            // traceStateCheckBox
            // 
            this.traceStateCheckBox.AutoSize = true;
            this.traceStateCheckBox.Location = new System.Drawing.Point(12, 202);
            this.traceStateCheckBox.Name = "traceStateCheckBox";
            this.traceStateCheckBox.Size = new System.Drawing.Size(79, 17);
            this.traceStateCheckBox.TabIndex = 6;
            this.traceStateCheckBox.Text = "Debug Log";
            this.traceStateCheckBox.UseVisualStyleBackColor = true;
            // 
            // rightAscensionPlusSideralRateLabel
            // 
            this.rightAscensionPlusSideralRateLabel.AutoSize = true;
            this.rightAscensionPlusSideralRateLabel.Location = new System.Drawing.Point(6, 10);
            this.rightAscensionPlusSideralRateLabel.Name = "rightAscensionPlusSideralRateLabel";
            this.rightAscensionPlusSideralRateLabel.Size = new System.Drawing.Size(89, 13);
            this.rightAscensionPlusSideralRateLabel.TabIndex = 7;
            this.rightAscensionPlusSideralRateLabel.Text = "RA+ Sideral Rate";
            // 
            // rightAscensionMinusSideralRateLabel
            // 
            this.rightAscensionMinusSideralRateLabel.AutoSize = true;
            this.rightAscensionMinusSideralRateLabel.Location = new System.Drawing.Point(6, 35);
            this.rightAscensionMinusSideralRateLabel.Name = "rightAscensionMinusSideralRateLabel";
            this.rightAscensionMinusSideralRateLabel.Size = new System.Drawing.Size(86, 13);
            this.rightAscensionMinusSideralRateLabel.TabIndex = 8;
            this.rightAscensionMinusSideralRateLabel.Text = "RA- Sideral Rate";
            // 
            // declinationPlusSideralRateLabel
            // 
            this.declinationPlusSideralRateLabel.AutoSize = true;
            this.declinationPlusSideralRateLabel.Location = new System.Drawing.Point(6, 60);
            this.declinationPlusSideralRateLabel.Name = "declinationPlusSideralRateLabel";
            this.declinationPlusSideralRateLabel.Size = new System.Drawing.Size(96, 13);
            this.declinationPlusSideralRateLabel.TabIndex = 9;
            this.declinationPlusSideralRateLabel.Text = "DEC+ Sideral Rate";
            // 
            // declinationMinusSideralRateLabel
            // 
            this.declinationMinusSideralRateLabel.AutoSize = true;
            this.declinationMinusSideralRateLabel.Location = new System.Drawing.Point(6, 85);
            this.declinationMinusSideralRateLabel.Name = "declinationMinusSideralRateLabel";
            this.declinationMinusSideralRateLabel.Size = new System.Drawing.Size(93, 13);
            this.declinationMinusSideralRateLabel.TabIndex = 10;
            this.declinationMinusSideralRateLabel.Text = "DEC- Sideral Rate";
            // 
            // rightAscensionPlusSideralRateTextBox
            // 
            this.rightAscensionPlusSideralRateTextBox.Location = new System.Drawing.Point(103, 5);
            this.rightAscensionPlusSideralRateTextBox.Name = "rightAscensionPlusSideralRateTextBox";
            this.rightAscensionPlusSideralRateTextBox.Size = new System.Drawing.Size(82, 20);
            this.rightAscensionPlusSideralRateTextBox.TabIndex = 11;
            // 
            // rightAscensionMinusSideralRateTextBox
            // 
            this.rightAscensionMinusSideralRateTextBox.Location = new System.Drawing.Point(103, 30);
            this.rightAscensionMinusSideralRateTextBox.Name = "rightAscensionMinusSideralRateTextBox";
            this.rightAscensionMinusSideralRateTextBox.Size = new System.Drawing.Size(82, 20);
            this.rightAscensionMinusSideralRateTextBox.TabIndex = 12;
            // 
            // declinationPlusSideralRateTextBox
            // 
            this.declinationPlusSideralRateTextBox.Location = new System.Drawing.Point(103, 55);
            this.declinationPlusSideralRateTextBox.Name = "declinationPlusSideralRateTextBox";
            this.declinationPlusSideralRateTextBox.Size = new System.Drawing.Size(82, 20);
            this.declinationPlusSideralRateTextBox.TabIndex = 13;
            // 
            // declinationMinusSideralRateTextBox
            // 
            this.declinationMinusSideralRateTextBox.Location = new System.Drawing.Point(103, 80);
            this.declinationMinusSideralRateTextBox.Name = "declinationMinusSideralRateTextBox";
            this.declinationMinusSideralRateTextBox.Size = new System.Drawing.Size(82, 20);
            this.declinationMinusSideralRateTextBox.TabIndex = 14;
            // 
            // axisSideralRatesGroupBox
            // 
            this.axisSideralRatesGroupBox.Controls.Add(this.axisSideralRatesPanel);
            this.axisSideralRatesGroupBox.Location = new System.Drawing.Point(12, 71);
            this.axisSideralRatesGroupBox.Name = "axisSideralRatesGroupBox";
            this.axisSideralRatesGroupBox.Size = new System.Drawing.Size(203, 123);
            this.axisSideralRatesGroupBox.TabIndex = 15;
            this.axisSideralRatesGroupBox.TabStop = false;
            this.axisSideralRatesGroupBox.Text = "Axis Sideral Rates";
            // 
            // axisSideralRatesPanel
            // 
            this.axisSideralRatesPanel.Controls.Add(this.rightAscensionPlusSideralRateLabel);
            this.axisSideralRatesPanel.Controls.Add(this.declinationMinusSideralRateTextBox);
            this.axisSideralRatesPanel.Controls.Add(this.rightAscensionPlusSideralRateTextBox);
            this.axisSideralRatesPanel.Controls.Add(this.declinationMinusSideralRateLabel);
            this.axisSideralRatesPanel.Controls.Add(this.declinationPlusSideralRateTextBox);
            this.axisSideralRatesPanel.Controls.Add(this.rightAscensionMinusSideralRateLabel);
            this.axisSideralRatesPanel.Controls.Add(this.rightAscensionMinusSideralRateTextBox);
            this.axisSideralRatesPanel.Controls.Add(this.declinationPlusSideralRateLabel);
            this.axisSideralRatesPanel.Location = new System.Drawing.Point(6, 13);
            this.axisSideralRatesPanel.Name = "axisSideralRatesPanel";
            this.axisSideralRatesPanel.Size = new System.Drawing.Size(188, 105);
            this.axisSideralRatesPanel.TabIndex = 16;
            // 
            // connectionGroupBox
            // 
            this.connectionGroupBox.Controls.Add(this.comPortLabel);
            this.connectionGroupBox.Controls.Add(this.comPortComboBox);
            this.connectionGroupBox.Location = new System.Drawing.Point(15, 29);
            this.connectionGroupBox.Name = "connectionGroupBox";
            this.connectionGroupBox.Size = new System.Drawing.Size(200, 36);
            this.connectionGroupBox.TabIndex = 16;
            this.connectionGroupBox.TabStop = false;
            this.connectionGroupBox.Text = "Connection";
            // 
            // SetupDialogForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(350, 227);
            this.Controls.Add(this.connectionGroupBox);
            this.Controls.Add(this.axisSideralRatesGroupBox);
            this.Controls.Add(this.traceStateCheckBox);
            this.Controls.Add(this.picASCOM);
            this.Controls.Add(this.commentLabel);
            this.Controls.Add(this.cmdCancel);
            this.Controls.Add(this.cmdOK);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "SetupDialogForm";
            this.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Hide;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "ArduinoST4 Setup";
            this.Load += new System.EventHandler(this.SetupDialogForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.picASCOM)).EndInit();
            this.axisSideralRatesGroupBox.ResumeLayout(false);
            this.axisSideralRatesPanel.ResumeLayout(false);
            this.axisSideralRatesPanel.PerformLayout();
            this.connectionGroupBox.ResumeLayout(false);
            this.connectionGroupBox.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button cmdOK;
        private System.Windows.Forms.Button cmdCancel;
        private System.Windows.Forms.Label commentLabel;
        private System.Windows.Forms.PictureBox picASCOM;
        private System.Windows.Forms.ComboBox comPortComboBox;
        private System.Windows.Forms.Label comPortLabel;
        private System.Windows.Forms.CheckBox traceStateCheckBox;
        private System.Windows.Forms.Label rightAscensionPlusSideralRateLabel;
        private System.Windows.Forms.Label rightAscensionMinusSideralRateLabel;
        private System.Windows.Forms.Label declinationPlusSideralRateLabel;
        private System.Windows.Forms.Label declinationMinusSideralRateLabel;
        private System.Windows.Forms.TextBox rightAscensionPlusSideralRateTextBox;
        private System.Windows.Forms.TextBox rightAscensionMinusSideralRateTextBox;
        private System.Windows.Forms.TextBox declinationPlusSideralRateTextBox;
        private System.Windows.Forms.TextBox declinationMinusSideralRateTextBox;
        private System.Windows.Forms.GroupBox axisSideralRatesGroupBox;
        private System.Windows.Forms.Panel axisSideralRatesPanel;
        private System.Windows.Forms.GroupBox connectionGroupBox;
    }
}
namespace WindowsFormsApp2
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.Panel fileupload;
        private System.Windows.Forms.Label filename;
        private System.Windows.Forms.Panel filecolor;
        private System.Windows.Forms.Button button1;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        private void InitializeComponent()
        {
            this.fileupload = new System.Windows.Forms.Panel();
            this.filename = new System.Windows.Forms.Label();
            this.filecolor = new System.Windows.Forms.Panel();
            this.button1 = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.label6 = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.crossbtn = new System.Windows.Forms.Button();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.pictureBox3 = new System.Windows.Forms.PictureBox();
            this.downloadbtn = new System.Windows.Forms.Button();
            this.panel3 = new System.Windows.Forms.Panel();
            this.fileupload.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).BeginInit();
            this.SuspendLayout();
            // 
            // fileupload
            // 
            this.fileupload.BackColor = System.Drawing.Color.White;
            this.fileupload.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.fileupload.Controls.Add(this.pictureBox1);
            this.fileupload.Location = new System.Drawing.Point(90, 82);
            this.fileupload.Name = "fileupload";
            this.fileupload.Size = new System.Drawing.Size(401, 201);
            this.fileupload.TabIndex = 0;
            // 
            // filename
            // 
            this.filename.Location = new System.Drawing.Point(16, 26);
            this.filename.Name = "filename";
            this.filename.Size = new System.Drawing.Size(260, 32);
            this.filename.TabIndex = 1;
            // 
            // filecolor
            // 
            this.filecolor.BackColor = System.Drawing.Color.White;
            this.filecolor.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.filecolor.Location = new System.Drawing.Point(19, 61);
            this.filecolor.Name = "filecolor";
            this.filecolor.Size = new System.Drawing.Size(332, 10);
            this.filecolor.TabIndex = 2;
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.Color.DarkSlateBlue;
            this.button1.Font = new System.Drawing.Font("Segoe UI Semibold", 10.2F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button1.ForeColor = System.Drawing.SystemColors.Window;
            this.button1.Location = new System.Drawing.Point(231, 323);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(110, 42);
            this.button1.TabIndex = 3;
            this.button1.Text = "Browse";
            this.button1.UseVisualStyleBackColor = false;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::WindowsFormsApp2.Properties.Resources._360_F_530651863_9SmGLwVqD0weDoBiHyNuN8JCDc0t5MgW;
            this.pictureBox1.Location = new System.Drawing.Point(-1, -1);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(401, 201);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Segoe UI Semibold", 10.2F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(272, 297);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(25, 23);
            this.label1.TabIndex = 5;
            this.label1.Text = "or";
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.DarkSlateBlue;
            this.panel1.Controls.Add(this.label6);
            this.panel1.Location = new System.Drawing.Point(3, 3);
            this.panel1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(611, 54);
            this.panel1.TabIndex = 124;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Segoe UI Semibold", 13.8F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.SystemColors.Window;
            this.label6.Location = new System.Drawing.Point(144, 6);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(320, 31);
            this.label6.TabIndex = 0;
            this.label6.Text = "File Upload and Management";
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.panel3);
            this.panel2.Controls.Add(this.pictureBox3);
            this.panel2.Controls.Add(this.downloadbtn);
            this.panel2.Controls.Add(this.pictureBox2);
            this.panel2.Controls.Add(this.crossbtn);
            this.panel2.Controls.Add(this.filename);
            this.panel2.Controls.Add(this.filecolor);
            this.panel2.Location = new System.Drawing.Point(39, 397);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(519, 261);
            this.panel2.TabIndex = 125;
            // 
            // crossbtn
            // 
            this.crossbtn.Location = new System.Drawing.Point(378, 51);
            this.crossbtn.Name = "crossbtn";
            this.crossbtn.Size = new System.Drawing.Size(32, 31);
            this.crossbtn.TabIndex = 3;
            this.crossbtn.UseVisualStyleBackColor = true;
            this.crossbtn.Click += new System.EventHandler(this.crossbtn_Click);
            // 
            // pictureBox2
            // 
            this.pictureBox2.Image = global::WindowsFormsApp2.Properties.Resources.circle_cross_icon_1024x1024_8o50movz;
            this.pictureBox2.Location = new System.Drawing.Point(380, 51);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(30, 31);
            this.pictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox2.TabIndex = 4;
            this.pictureBox2.TabStop = false;
            this.pictureBox2.Click += new System.EventHandler(this.pictureBox2_Click);
            // 
            // pictureBox3
            // 
            this.pictureBox3.Image = global::WindowsFormsApp2.Properties.Resources.pngtree_file_download_icon_png_image_4647924;
            this.pictureBox3.Location = new System.Drawing.Point(429, 51);
            this.pictureBox3.Name = "pictureBox3";
            this.pictureBox3.Size = new System.Drawing.Size(30, 31);
            this.pictureBox3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox3.TabIndex = 6;
            this.pictureBox3.TabStop = false;
            this.pictureBox3.Click += new System.EventHandler(this.pictureBox3_Click);
            // 
            // downloadbtn
            // 
            this.downloadbtn.Location = new System.Drawing.Point(429, 51);
            this.downloadbtn.Name = "downloadbtn";
            this.downloadbtn.Size = new System.Drawing.Size(32, 31);
            this.downloadbtn.TabIndex = 5;
            this.downloadbtn.UseVisualStyleBackColor = true;
            this.downloadbtn.Click += new System.EventHandler(this.downloadbtn_Click);
            // 
            // panel3
            // 
            this.panel3.BackColor = System.Drawing.Color.DarkSlateBlue;
            this.panel3.Location = new System.Drawing.Point(19, 101);
            this.panel3.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(477, 10);
            this.panel3.TabIndex = 125;
            // 
            // Form1
            // 
            this.ClientSize = new System.Drawing.Size(603, 731);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.fileupload);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "File Upload Example";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.fileupload.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.Button crossbtn;
        private System.Windows.Forms.PictureBox pictureBox3;
        private System.Windows.Forms.Button downloadbtn;
        private System.Windows.Forms.Panel panel3;
    }
}

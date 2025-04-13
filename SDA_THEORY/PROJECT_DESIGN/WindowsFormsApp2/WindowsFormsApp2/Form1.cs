using System;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Form1 : Form
    {
        private string uploadedFilePath;
        public Form1()
        {
            InitializeComponent();
            InitializeDragAndDrop();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void InitializeDragAndDrop()
        {

            this.crossbtn.Enabled = false;
            this.crossbtn.Click += new System.EventHandler(this.crossbtn_Click);

            // downloadbtn
            this.downloadbtn.Enabled = false;
            this.downloadbtn.Click += new System.EventHandler(this.downloadbtn_Click);

            // pictureBox2
            this.pictureBox2.Click += new System.EventHandler(this.pictureBox2_Click);

            // pictureBox3
            this.pictureBox3.Click += new System.EventHandler(this.pictureBox3_Click);

            this.fileupload.AllowDrop = true;
            this.fileupload.DragEnter += new DragEventHandler(this.panel1_DragEnter);
            this.fileupload.DragDrop += new DragEventHandler(this.panel1_DragDrop);
            this.fileupload.DragLeave += new EventHandler(this.panel1_DragLeave);
        }

        private void panel1_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effect = DragDropEffects.Copy;
                fileupload.BackColor = Color.Gray;
            }
            else
            {
                e.Effect = DragDropEffects.None;
            }
        }

        private void panel1_DragLeave(object sender, EventArgs e)
        {
            fileupload.BackColor = Color.White;
        }

        private void panel1_DragDrop(object sender, DragEventArgs e)
        {
            string[] files = (string[])e.Data.GetData(DataFormats.FileDrop);
            if (files != null && files.Length > 0)
            {
                uploadedFilePath = files[0];
                filename.Text = Path.GetFileName(uploadedFilePath);
                fileupload.BackColor = Color.White;
                filecolor.BackColor = Color.Green;
                crossbtn.Enabled = true;
                downloadbtn.Enabled = true;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                uploadedFilePath = openFileDialog.FileName;
                filename.Text = Path.GetFileName(uploadedFilePath);
                filecolor.BackColor = Color.Green;
                crossbtn.Enabled = true;
                downloadbtn.Enabled = true;
            }
        }


        private void crossbtn_Click(object sender, EventArgs e)
        {
            uploadedFilePath = null;
            filename.Text = string.Empty;
            filecolor.BackColor = Color.White;
            crossbtn.Enabled = false;
            downloadbtn.Enabled = false;
        }

 
        private void downloadbtn_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrEmpty(uploadedFilePath) && File.Exists(uploadedFilePath))
            {
                SaveFileDialog saveFileDialog = new SaveFileDialog
                {
                    FileName = Path.GetFileName(uploadedFilePath)
                };
                if (saveFileDialog.ShowDialog() == DialogResult.OK)
                {
                    File.Copy(uploadedFilePath, saveFileDialog.FileName, true);
                    MessageBox.Show("File downloaded successfully!", "Download", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }
        }


        private void pictureBox2_Click(object sender, EventArgs e)
        {
            crossbtn_Click(sender, e);
        }

 
        private void pictureBox3_Click(object sender, EventArgs e)
        {
            downloadbtn_Click(sender, e);
        }
    }
}

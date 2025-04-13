using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace cafe_system
{
    public partial class Register : Form
    {
        public Register()
        {
            InitializeComponent();
        }

        private void label13_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void sign_button_Click(object sender, EventArgs e)
        {

            Form1 form = new Form1();
            form.Show();
            this.Hide();
        }

        private void showpass1_CheckedChanged(object sender, EventArgs e)
        {


        }
    }
}

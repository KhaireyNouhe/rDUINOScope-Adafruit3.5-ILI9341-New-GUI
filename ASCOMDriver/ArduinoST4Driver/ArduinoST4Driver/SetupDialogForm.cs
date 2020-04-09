using System;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace ASCOM.ArduinoST4
{
    [ComVisible(false)]					// Form not registered for COM!
    public partial class SetupDialogForm : Form
    {
        public SetupDialogForm()
        {
            InitializeComponent();
            populateSerialComboBox();
            // Initialise current values of user settings from the ASCOM Profile 
            this.comPortComboBox.Text = Telescope.comPort;
            this.traceStateCheckBox.Checked = Telescope.traceState;
            this.rightAscensionPlusSideralRateTextBox.Text = Telescope.rightAscensionSideralRatePlus.ToString();
            this.rightAscensionMinusSideralRateTextBox.Text = Telescope.rightAscensionSideralRateMinus.ToString();
            this.declinationPlusSideralRateTextBox.Text = Telescope.declinationSideralRatePlus.ToString();
            this.declinationMinusSideralRateTextBox.Text = Telescope.declinationSideralRateMinus.ToString();
        }

        /// <summary>
        /// Reads the available COM ports on the computer and adds them to the COM Port combobox
        /// </summary>
        private void populateSerialComboBox()
        {
            string[] serialPorts = System.IO.Ports.SerialPort.GetPortNames();
            foreach (string serialPort in serialPorts)
            {
                this.comPortComboBox.Items.Add(serialPort);
            }
        }

        private void cmdOK_Click(object sender, EventArgs e) // OK button event handler
        {
            // Update the state variables with results from the dialogue
            Telescope.comPort = comPortComboBox.Text;
            Telescope.traceState = traceStateCheckBox.Checked;
            Telescope.rightAscensionSideralRatePlus = Convert.ToDouble(this.rightAscensionPlusSideralRateTextBox.Text);
            Telescope.rightAscensionSideralRateMinus = Convert.ToDouble(this.rightAscensionMinusSideralRateTextBox.Text);
            Telescope.declinationSideralRatePlus = Convert.ToDouble(this.declinationPlusSideralRateTextBox.Text);
            Telescope.declinationSideralRateMinus = Convert.ToDouble(this.declinationMinusSideralRateTextBox.Text);
        }

        private void cmdCancel_Click(object sender, EventArgs e) // Cancel button event handler
        {
            Close();
        }

        private void BrowseToAscom(object sender, EventArgs e) // Click on ASCOM logo event handler
        {
            try
            {
                System.Diagnostics.Process.Start("http://ascom-standards.org/");
            }
            catch (System.ComponentModel.Win32Exception noBrowser)
            {
                if (noBrowser.ErrorCode == -2147467259)
                    MessageBox.Show(noBrowser.Message);
            }
            catch (System.Exception other)
            {
                MessageBox.Show(other.Message);
            }
        }

        private void SetupDialogForm_Load(object sender, EventArgs e)
        {

        }
    }
}